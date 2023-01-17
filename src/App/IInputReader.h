#pragma once

#include <string>

class IInputReader
{
public:
	virtual std::string Read(std::string const& filename) = 0;

	virtual ~IInputReader() = default;
};
