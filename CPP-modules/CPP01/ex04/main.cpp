#include <iostream>
#include <fstream>
#include <cstdlib>

int SearchAndReplace(std::ifstream& infile, std::ofstream& outfile, std::string toFind, std::string toInsert)
{
    std::string line;

    while (getline(infile, line))
    {
        int i = line.find(toFind);
        while (i != -1)
        {
			line.erase(i, toFind.length());
			line.insert(i, toInsert);
            i = line.find(toFind, i + toInsert.length());
        }
        outfile << line << std::endl;
    }
    return 1;
}


int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <input_file> <to_find> <to_insert>" << std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cerr << "Error: can't open Infile\n";
		return 1;
	}
	std::string end = ".replace";
	std::ofstream outfile(av[1] + end);
	if (!outfile.is_open())
	{
		std::cout << "Error: can't open Outfile\n";
		return 1;
	}
	SearchAndReplace(infile, outfile, av[2], av[3]);
	infile.close();
	outfile.close();
	return 0;
}
