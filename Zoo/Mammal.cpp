#include "Animal.h"
#include "Mammal.h"

Mammal::Mammal(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy, std::string natural_habitat) :
	Animal::Animal(expected_breedings, reproductivity, cubs_per_pregnancy),
	natural_habitat{ natural_habitat } {}

Mammal::Mammal(const Mammal& d, const Animal& r) :
	Animal::Animal(d, r), natural_habitat{ d.natural_habitat } {}

const std::string Mammal::toString() const
{
	return Animal::toString() + " Its natural habitat is " + natural_habitat + '.';
}
