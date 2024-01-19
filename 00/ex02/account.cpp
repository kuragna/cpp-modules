#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
#define INFO() std::cout << __FILE__ << ":" << __LINE__ << " `" << __FUNCTION__ << "` -> "

// TODO: Destructor

Account::Account(int initial_deposit)
{
	//Account::_displayTimestamp();
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts += 1;

    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created\n";
}
Account::~Account(void)
{
	//Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed\n";
};

void    Account::makeDeposit(int deposit)
{
	//Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    _totalAmount += deposit;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl; 
};

bool    Account::makeWithdrawal(int withdrawal)
{
	//Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    if (checkAmount() < withdrawal)
    {
        std::cout << ";withdrawal:refused\n";
        return false;
    }
    std::cout << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
};

int Account::checkAmount(void) const
{
    return _amount;
};

void    Account::displayStatus(void) const
{
	//Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
};

void    Account::displayAccountsInfos(void)
{
	//Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
};

void    Account::_displayTimestamp(void)
{
    const size_t    size = sizeof("[yyyymmdd_hhmmss]");
    const std::time_t time = std::time(nullptr);
    char    timeString[size];

    std::strftime(timeString, size, "[%Y%m%d_%H%M%S]", std::gmtime(&time));
    std::cout << timeString << " ";
};