#pragma once

#include "../App/IInputReader.h"

class InputReader : public IInputReader
{
public:
	std::string Read(std::string const & filename) override;
};
