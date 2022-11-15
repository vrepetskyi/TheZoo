#pragma once

#include "Animal.h"
#include "Mammal.h"

class Hare : public Mammal
{
	const std::string fur_type;
public:
	Hare(Reproductivity reproductivity);
	Hare(const Hare& d, const Animal& r);
	const std::string getKind() const override;
	Animal* breed(const Animal& partner) const override;
	const std::string toString() const override;
};
