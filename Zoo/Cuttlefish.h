#pragma once

#include "Animal.h"
#include "Fish.h"

class Cuttlefish : public Fish
{
	const int tentacles_number;
public:
	Cuttlefish(Reproductivity reproductivity);
	Cuttlefish(const Cuttlefish& d, const Animal& r);
	const std::string getKind() const override;
	Animal* breed(const Animal& partner) const override;
	const std::string toString() const override;
};
