#include "Animal.h"
#include "Fish.h"
#include <cmath>

std::string oil_spills[14]{
	"Persian Gulf", "BP Deepwater Horizon", "Ixtoc I", "Atlantic Empress", "Komi Pipeline", "Castillo de Bellver", "ABT Summer",
	"Amoco Cadiz", "MT Haven Tanker", "Odyssey", "The Sea Star", "Nowruz", "The Torrey Canyon", "Exxon Valdez" };

Fish::Fish(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy) :
	Animal::Animal(expected_breedings, reproductivity, cubs_per_pregnancy),
	oil_spill_suffered_from{ oil_spills[std::rand() % 14] } {}

Fish::Fish(const Fish& d, const Animal& r) :
	Animal::Animal(d, r), oil_spill_suffered_from{ d.oil_spill_suffered_from } {}

const std::string Fish::toString() const
{
	return Animal::toString() + " It has suffered from " + oil_spill_suffered_from + " oil spill.";
}
