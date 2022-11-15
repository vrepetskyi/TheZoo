#include "Animal.h"
#include "Bird.h"
#include "Penguin.h"
#include <cmath>
#include <string>

Penguin::Penguin(Reproductivity reproductivity) : Bird::Bird(4, reproductivity, 1, false), swimming_speed{ rand() % 9 + 16 } {}

// Its evolution, baby. Each generation can increase speed by up to 4 km/h.
Penguin::Penguin(const Penguin& d, const Animal& r) : Bird::Bird(d, r), swimming_speed{ rand() % 9 + 16 + (d.swimming_speed - 16) / 20 * 4 } {}

const std::string Penguin::getKind() const
{
	return "Penguin";
}

// And its growth.
const int Penguin::operator++()
{
	swimming_speed += rand() % 4;
	return Animal::operator++();
}

Animal* Penguin::breed(const Animal& partner) const
{
	return new Penguin(*this, partner);
}

const std::string Penguin::toString() const
{
	return Bird::toString() + " Its swimming speed is " + std::to_string(swimming_speed) + " km/h.";
}
