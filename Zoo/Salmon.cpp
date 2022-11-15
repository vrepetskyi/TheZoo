#include "Animal.h"
#include "Fish.h"
#include "Salmon.h"
#include <cmath>
#include <string>

std::string favourite_phrases[9]{
	"Great fish do not swim in shallow waters", "Remember folks, fish are like relatives. After two days, they stink",
	"A chub is the worst fish that swims", "A river is honored for its fish, not its size",
	"It doesn't matter if the rod is or isn't bent", "I don't exaggerate - I just remember big",
	"If fishing is a religion, fly fishing is high church", "Now I can look at you in peace; I don't eat you anymore",
	"At high tide, fish eat ants; at low tide, ants eat fish" };

Salmon::Salmon(Reproductivity reproductivity) : Fish::Fish(2, reproductivity, 3), favourite_phrase{ favourite_phrases[std::rand() % 9] } {}

Salmon::Salmon(const Salmon& d, const Animal& r) : Fish::Fish(d, r), favourite_phrase{ d.favourite_phrase } {}

const std::string Salmon::getKind() const
{
	return "Salmon";
}

Animal* Salmon::breed(const Animal& partner) const
{
	return new Salmon(*this, partner);
}

const std::string Salmon::toString() const
{
	return Fish::toString() + " Its favourite phrase is \"" + favourite_phrase + "\".";
}
