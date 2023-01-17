#pragma once

#include "../App/IModelProvider.h"

class ModelProvider : public IModelProvider
{
public:
	Model GetModel(std::string const& filename) override;

private:
	using Spreadsheet = std::vector<std::vector<std::string>>;

	static auto const CSV_SEPARATOR = ' ';

	static Spreadsheet GetDataFromFile(std::string const& filename);
};
