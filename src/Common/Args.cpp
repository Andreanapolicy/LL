#include "Args.h"

#include <stdexcept>

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
