#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;



Account::Account(int initial_deposit)
{
    (void) initial_deposit;
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount = _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts += 1;

    std::cout << "`" << __FUNCTION__ << "` -> ";
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount" << _amount;
    std::cout << ";created\n";
}
Account::~Account(void)
{
    std::cout << "`" << __FUNCTION__ << "` -> ";
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed\n";
};

void    Account::makeDeposit(int deposit)
{
    std::cout << "`" << __FUNCTION__ << "` -> ";
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    _nbDeposits += 1;
    _totalAmount += deposit;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl; 
    (void) deposit;
};

bool    Account::makeWithdrawal(int withdrawal)
{
    (void) withdrawal;
    std::cout << "`" << __FUNCTION__ << "` -> ";
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
};

int Account::checkAmount(void) const
{
    std::cout << "`" << __FUNCTION__ << "`\n";
    return 1;
};

void    Account::displayStatus(void) const
{
    std::cout << "`" << __FUNCTION__ << "` -> ";
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
};

void    Account::displayAccountsInfos(void)
{
    std::cout << "`" << __FUNCTION__ << "` -> ";
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
    std::cout << timeString;
};