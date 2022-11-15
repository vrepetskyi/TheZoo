#pragma once

#include "Animal.h"
#include "Zoo.h"
#include <vector>

class AnimalBreeder
{
	float p_breed;
	float p_extinct;
	bool use_strict;
public:
	AnimalBreeder(float p_breed, float p_extinct, bool use_strict = false);
	const std::string breed(Zoo<Animal>& zoo) const;
};
