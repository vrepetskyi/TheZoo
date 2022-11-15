#pragma once

#include "Animal.h"
#include "Bird.h"

class Penguin : public Bird
{
	int swimming_speed;
public:
	Penguin(Reproductivity reproductivity);
	Penguin(const Penguin& d, const Animal& r);
	const std::string getKind() const override;
	const int operator++();
	Animal* breed(const Animal& partner) const override;
	const std::string toString() const override;
};
