#include "LLParser.h"
#include <stack>

LLParser::LLParser(std::unique_ptr<IModelProvider>&& modelProvider, std::unique_ptr<IInputReader>&& inputReader)
	: m_modelProvider(std::move(modelProvider))
	, m_inputReader(std::move(inputReader))
{
}

void LLParser::Parse(std::string const& modelFilename, std::string const& inputFilename)
{
	auto model = m_modelProvider->GetModel(modelFilename);
	auto const input = m_inputReader->Read(inputFilename);

	std::size_t inputPos = 0;
	std::size_t currentRulePos = 1;
	Rule& currentRule = model.at(1);

	std::stack<std::size_t> stack;

	while (!currentRule.endParsing)
	{
		if (!CharacterMatches(input.at(inputPos), currentRule.leadingSymbols))
		{
			if (currentRule.error)
			{
				throw std::runtime_error("exp is incorrect");
			}
			else
			{
				currentRule = model.at(++currentRulePos);
			}

			continue;
		}

		if (currentRule.shift)
		{
			++inputPos;
		}

		if (currentRule.saveToStack)
		{
			stack.push(currentRulePos + 1);
		}

		if (currentRule.pointers.empty())
		{
			if (stack.empty())
			{
				throw std::runtime_error("exp is incorrect");
			}

			currentRulePos = stack.top();
			currentRule = model.at(currentRulePos);
			stack.pop();
		}
		else
		{
			currentRulePos = currentRule.pointers.at(0);
			currentRule = model.at(currentRulePos);
		}
	}

	if (inputPos < input.length())
	{
		throw std::runtime_error("exp is incorrect");
	}
}

bool LLParser::CharacterMatches(char ch, std::vector<char> const& leadingSymbols)
{
	return std::any_of(
		leadingSymbols.begin(),
		leadingSymbols.end(),
		[ch](char symbol) {
			return ch == symbol;
		});
}
