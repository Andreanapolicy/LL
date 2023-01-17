#pragma once

#include "../App/IModelProvider.h"

class ModelProvider : public IModelProvider
{
public:
	Model GetModel(std::string const& filename) override;
};
