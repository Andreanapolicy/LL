#pragma once

#include "../App/IModelProvider.h"

class ModelProvider : public IModelProvider
{
public:
	Model GetModel(std::string const& filename) override;

private:
	using Spreadsheet = std::vector<std::vector<std::string>>;

	static auto const CSV_SEPARATOR = ';';
	constexpr static auto const FIELD_NO = "No";
	constexpr static auto const FIELD_YES = "Yes";
	constexpr static auto const FIELD_NULL = "NULL";

	static Spreadsheet GetDataFromFile(std::string const& filename);
	bool GetField(std::string const& field);
};
