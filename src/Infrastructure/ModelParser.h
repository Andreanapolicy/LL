#pragma once

#include "../App/IModelParser.h"

class ModelParser : public IModelParser
{
public:
	Model Parse(std::string const& filename) override;
};
