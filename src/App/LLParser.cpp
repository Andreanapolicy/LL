#include "LLParser.h"
#include <stack>

LLParser::LLParser(std::unique_ptr<IModelProvider>&& modelProvider)
	: m_modelProvider(std::move(modelProvider))
{
}

void LLParser::Parse(std::string const& modelFilename, std::string const& input)
{
	auto const model = m_modelProvider->GetModel(modelFilename);

	std::size_t i = 0;
	std::stack<std::size_t> stack;
	stack.push(1);

	while (!stack.empty())
	{
		auto&& leftSide = model.at(stack.top());
		if (!CharacterMatches(input.at(i), leftSide.leadingSymbols))
		{
			throw std::runtime_error("exp is incorrect");
		}

		for (auto&& pointer : leftSide.pointers)
		{
			auto&& rightSide = model.at(pointer);
			// TODO
		}

		stack.pop();
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
