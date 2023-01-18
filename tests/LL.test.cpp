#define CATCH_CONFIG_MAIN

#include "../src/App/LLParser.h"
#include "../src/Infrastructure/InputReader.h"
#include "../src/Infrastructure/ModelProvider.h"
#include "catch.hpp"

TEST_CASE("valid end2end cases")
{
	std::string const modelFilename = "../model/table.csv";

	std::string const testFile = GENERATE("simple");
	auto const inputFilename = "files/" + testFile + ".txt";

	LLParser parser(
		std::make_unique<ModelProvider>(),
		std::make_unique<InputReader>());

	WHEN("parsing a file")
	{
		THEN("it passes")
		{
			REQUIRE_NOTHROW(parser.Parse(modelFilename, inputFilename));
		}
	}
}

TEST_CASE("invalid end2end cases")
{
	std::string const modelFilename = "../model/table.csv";

	std::string const testFile = GENERATE("invalid-end");
	auto const inputFilename = "files/" + testFile + ".txt";

	LLParser parser(
		std::make_unique<ModelProvider>(),
		std::make_unique<InputReader>());

	WHEN("parsing a file")
	{
		THEN("it throws an exception")
		{
			REQUIRE_THROWS(parser.Parse(modelFilename, inputFilename));
		}
	}
}
