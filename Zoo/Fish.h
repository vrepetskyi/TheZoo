#pragma once

#include "Animal.h"

class Fish : public Animal
{
	const std::string oil_spill_suffered_from;
public:
	Fish(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy);
	Fish(const Fish& d, const Animal& r);
	virtual const std::string toString() const override = 0;
};
