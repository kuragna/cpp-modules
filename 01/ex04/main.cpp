#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     line;
    std::string     filename;
    
    if ((argc - 1) != 3)
    {
        std::cerr << "Error: invalid arguments\n";
        std::cout << "Usage: ./sed filename string1 string2\n";
        return 1;
    }
    infile.open(argv[1]); 
    if (!infile.is_open())
    {
        std::cerr << "Error: could not open " << argv[1] << std::endl;
        return 1;
    }
    filename = argv[1];
    outfile.open(filename + ".replace");
    if (!outfile.is_open())
    {
        std::cerr << "Error: could not open " << argv[1] << ".replace" << std::endl;
        return 1;
    }
    while (std::getline(infile, line))
    {
        //std::cout << line << std::endl;
        if (line == argv[2])
            outfile.write(argv[3], std::strlen(argv[3]));
        else
            outfile.write(line.c_str(), line.length());
        outfile.write("\n", 1);
    }
    infile.close();
    outfile.close();
    return 0;
}