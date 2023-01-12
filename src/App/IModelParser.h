#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct Entry
{
	char symbol;
	std::vector<char> leadingSymbols;
	bool shift;
	bool error;
	std::size_t pointer;
	bool saveToStack;
	bool endParsing;
};

using Model = std::unordered_map<std::size_t, Entry>;

class IModelParser
{
public:
	virtual Model Parse(std::string const& filename) = 0;
};
