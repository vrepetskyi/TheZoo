#pragma once

#include "Animal.h"

class Mammal : public Animal
{
	const std::string natural_habitat;
public:
	Mammal(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy, std::string natural_habitat);
	Mammal(const Mammal& d, const Animal& r);
	virtual const std::string toString() const override = 0;
};
