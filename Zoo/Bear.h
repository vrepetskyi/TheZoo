#pragma once

#include "Animal.h"
#include "Mammal.h"

class Bear : public Mammal
{
	const std::string favourite_berry;
public:
	Bear(Reproductivity reproductivity);
	Bear(const Bear& d, const Animal& r);
	const std::string getKind() const override;
	Animal* breed(const Animal& partner) const override;
	const std::string toString() const override;
};
