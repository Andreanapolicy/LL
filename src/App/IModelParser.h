#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct Entry
{
	char symbol;
	bool isTerminal;
	std::vector<char> leadingSymbols;
	bool shift;
	bool error;
	std::vector<std::size_t> pointers; // For alternatives, e.g. <F> -> -<F>| (<EXP>) | a | b | 8 | 3
	bool saveToStack;
	bool endParsing;
};

using Model = std::unordered_map<std::size_t, Entry>;

class IModelParser
{
public:
	virtual Model Parse(std::string const& filename) = 0;
};
