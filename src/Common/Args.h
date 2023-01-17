#pragma once

#include <string>

struct Args
{
	std::string modelFilename;
	std::string inputFilename;
};

Args ParseArgs(int argc, char** argv);
