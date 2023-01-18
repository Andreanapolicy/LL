#include <fstream>
#include <sstream>
#include <iostream>
#include "ModelProvider.h"

Model ModelProvider::GetModel(std::string const& filename)
{
	Spreadsheet spreadsheet = GetDataFromFile(filename);

	Model model;

	for(const auto& row : spreadsheet)
	{
		std::stringstream ss_number(row[0]);
		size_t number;
		ss_number >> number;

		char symbol = row[1][0];

		std::vector<char> leadingSymbols;
		std::string symbols = row[2];
		for (auto current_symbol : symbols)
		{
			if (current_symbol != ',')
			{
				leadingSymbols.push_back(current_symbol);
			}
		}

		bool shift = GetField(row[3]);

		bool error = GetField(row[4]);

		std::optional<std::size_t> pointer;
		std::stringstream ss_result(row[5]);
		size_t result = 0;
		ss_result >> result;
		pointer = row[4] == FIELD_NULL ? std::nullopt : std::optional(result);

		bool saveToStack = GetField(row[6]);

		bool endParsing = GetField(row[6]);

		model[number] = {
			.symbol = symbol,
			.leadingSymbols = leadingSymbols,
			.shift = shift,
			.error = error,
			.pointer = pointer,
			.saveToStack = saveToStack,
			.endParsing = endParsing
		};
	}

	return model;
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

bool ModelProvider::GetField(std::string const& field)
{
	if (field == FIELD_YES)
	{
		return true;
	}
	if (field == FIELD_NO)
	{
		return false;
	}

	throw std::runtime_error("Unknown field type");
}
