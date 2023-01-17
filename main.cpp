#include "src/App/LLParser.h"
#include "src/Infrastructure/ModelProvider.h"
#include <fstream>
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
		std::ifstream input(args.inputFilename);

		if (!input.is_open())
		{
			throw std::runtime_error("Cannot open input file");
		}

		std::string data((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

		LLParser parser(std::make_unique<ModelProvider>());
		parser.Parse(args.modelFilename, data);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
