#include "ModelProvider.h"

Model ModelProvider::GetModel(std::string const& filename)
{
	Model model;

	// TODO: remove mock model, implement parsing
	model[1] = {
		'S', { 'a', 'c' }, false, true, { 2 }, false, false
	};
	model[2] = {
		'A', { 'a', 'c' }, false, true, { 5 }, true, false
	};
	model[3] = {
		'B', { 'b' }, false, true, { 10 }, true, false
	};
	model[4] = {
		'F', { 'F' }, true, true, std::nullopt, false, true
	};
	model[5] = {
		'A', { 'a' }, false, false, { 7 }, false, false
	};
	model[6] = {
		'A', { 'c' }, false, true, { 8 }, false, false
	};
	model[7] = {
		'a', {
				 'a',
			 },
		true, true, std::nullopt, false, false
	};
	model[8] = {
		'c', { 'c' }, true, true, { 9 }, false, false
	};
	model[9] = {
		'A', { 'a', 'c' }, false, true, { 5 }, false, false
	};
	model[10] = {
		'B', { 'b' }, false, true, { 11 }, false, false
	};
	model[11] = {
		'b', { 'b' }, true, true, { 12 }, false, false
	};
	model[12] = {
		'A', { 'a', 'c' }, false, true, { 5 }, false, false
	};

	return model;
}
