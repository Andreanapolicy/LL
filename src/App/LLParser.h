#pragma once

#include "IModelProvider.h"
#include <memory>

class LLParser
{
public:
	LLParser(std::unique_ptr<IModelProvider>&& modelProvider);

	void Parse(std::string const& modelFilename, std::string const& input);

private:
	static bool CharacterMatches(char ch, std::vector<char> const& leadingSymbols);

	std::unique_ptr<IModelProvider> m_modelProvider;
};
