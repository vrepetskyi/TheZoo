#pragma once

#include "Animal.h"
#include "Bird.h"

class Eagle : public Bird
{
	const std::string favourite_drone;
public:
	Eagle(Reproductivity reproductivity);
	Eagle(const Eagle& d, const Animal& r);
	const std::string getKind() const override;
	Animal* breed(const Animal& partner) const override;
	const std::string toString() const override;
};
