#pragma once

#include "../App/IModelProvider.h"

class ModelProvider : public IModelProvider
{
public:
	Model GetModel(std::string const& filename) override;

private:
	using Spreadsheet = std::vector<std::vector<std::string>>;

	static constexpr auto CSV_SEPARATOR = ';';
	static constexpr auto FIELD_NO = "No";
	static constexpr auto FIELD_YES = "Yes";
	static constexpr auto FIELD_NULL = "NULL";

	static Spreadsheet GetDataFromFile(std::string const& filename);

	static bool GetBoolField(std::string const& field);
	static std::size_t GetIntField(std::string const& field);
};
