#pragma once

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

struct Rule
{
	char symbol;
	bool isTerminal;
	std::vector<char> leadingSymbols;
	bool shift;
	bool error;
	std::optional<std::size_t> pointer;
	bool saveToStack;
	bool endParsing;
};

using Model = std::unordered_map<std::size_t, Rule>;

class IModelProvider
{
public:
	virtual Model GetModel(std::string const& filename) = 0;

	virtual ~IModelProvider() = default;
};
