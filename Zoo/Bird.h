#pragma once

#include "Animal.h"

class Bird : public Animal
{
	const bool can_fly;
public:
	Bird(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy, bool can_fly);
	Bird(const Bird& d, const Animal& r);
	virtual const std::string toString() const override = 0;
};
