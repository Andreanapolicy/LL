#include "InputReader.h"
#include <fstream>

std::string InputReader::Read(std::string const& filename)
{
	std::ifstream input(filename);

	if (!input.is_open())
	{
		throw std::runtime_error("Cannot open input file");
	}

	std::string result;
	if (!std::getline(input, result))
	{
		throw std::runtime_error("No input provided");
	}

	return result;
}
