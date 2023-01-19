#include "ModelProvider.h"
#include <fstream>
#include <iostream>
#include <sstream>

Model ModelProvider::GetModel(std::string const& filename)
{
	Spreadsheet spreadsheet = GetDataFromFile(filename);

	Model model;

	for (auto const& row : spreadsheet)
	{
		std::stringstream ss_number(row[0]);
		size_t number;
		ss_number >> number;

		auto const symbol = row[1];

		auto const leadingSymbols = GetLeadingSymbols(row[2]);

		bool shift = GetBoolField(row[3]);
		bool error = GetBoolField(row[4]);

		std::optional<std::size_t> pointer;
		if (row[5] != FIELD_NULL)
		{
			pointer = GetIntField(row[5]);
		}

		bool saveToStack = GetBoolField(row[6]);
		bool endParsing = GetBoolField(row[7]);

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

std::vector<char> ModelProvider::GetLeadingSymbols(std::string const& field)
{
	std::vector<char> result;
	for (auto&& current_symbol : field)
	{
		if (current_symbol == '0')
		{
			result.push_back(EMPTY_SYMBOL);
		}
		else if (current_symbol != ',')
		{
			result.push_back(current_symbol);
		}
	}

	return result;
}

bool ModelProvider::GetBoolField(std::string const& field)
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

std::size_t ModelProvider::GetIntField(std::string const& field)
{
	std::size_t result;

	std::stringstream stream(field);
	stream >> result;

	return result;
}
