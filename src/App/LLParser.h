#pragma once

#include "IInputReader.h"
#include "IModelProvider.h"
#include <memory>

class LLParser
{
public:
	LLParser(std::unique_ptr<IModelProvider>&& modelProvider, std::unique_ptr<IInputReader>&& inputReader);

	void Parse(std::string const& modelFilename, std::string const& inputFilename);

private:
	static char GetInputChar(std::string const& input, std::size_t position);
	static bool CharacterMatches(char ch, std::vector<char> const& leadingSymbols);

	std::unique_ptr<IModelProvider> m_modelProvider;
	std::unique_ptr<IInputReader> m_inputReader;
};
