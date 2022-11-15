#pragma once

#include "Animal.h"
#include "Fish.h"

class Salmon : public Fish
{
	const std::string favourite_phrase;
public:
	Salmon(Reproductivity reproductivity);
	Salmon(const Salmon& d, const Animal& r);
	const std::string getKind() const override;
	Animal* breed(const Animal& partner) const override;
	const std::string toString() const override;
};
