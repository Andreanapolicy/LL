#include "src/App/LLParser.h"
#include "src/Infrastructure/InputReader.h"
#include "src/Infrastructure/ModelProvider.h"
#include <iostream>

namespace
{
struct Args
{
	std::string modelFilename;
	std::string inputFilename;
};

Args ParseArgs(int argc, char** argv)
{
	if (argc != 3)
	{
		throw std::invalid_argument("invalid parameters");
	}

	return {
		.modelFilename = argv[1],
		.inputFilename = argv[2],
	};
}
} // namespace

int main(int argc, char** argv)
{
	try
	{
		auto const args = ParseArgs(argc, argv);

		LLParser parser(
			std::make_unique<ModelProvider>(),
			std::make_unique<InputReader>());

		parser.Parse(args.modelFilename, args.inputFilename);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
