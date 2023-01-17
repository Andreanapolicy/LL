#include <fstream>
#include <sstream>
#include "ModelProvider.h"

Model ModelProvider::GetModel(std::string const& filename)
{
	return {};
}

ModelProvider::Spreadsheet ModelProvider::GetDataFromFile(std::string const& filename)
{
	std::ifstream input(filename);
	if (!input.is_open())
	{
		throw std::runtime_error("failed to open input file for reading");
	}

	Spreadsheet spreadsheet;
	std::string row;
	std::string cell;

	while (std::getline(input, row))
	{
		std::istringstream iss(row);
		std::vector<std::string> rows;

		while (std::getline(iss, cell, CSV_SEPARATOR))
		{
			rows.push_back(cell);
		}

		spreadsheet.push_back(rows);
	}

	return spreadsheet;
}