#include "Animal.h"
#include <cmath>
#include <iostream>
#include <string>

std::string names[100] = {
	"Genie", "Max", "Shorty", "Gavin", "Moocher", "Daphne", "Bonnie", "Lefty", "Peanuts", "Austin", "Montana", "Ringo",
	"Gretchen", "Freeway", "Salty", "Silver", "Beauty", "Princess", "Maggie", "Riggs", "Butterscotch", "Poochie", "Piglet",
	"Elliot", "Mattie", "Poppy", "Pedro", "Odie", "Bugsy", "Mindy", "Goober", "Ziggy", "Pinky", "Yin", "Patch", "Homer",
	"Boots", "Papa", "Deacon", "Coal", "Diego", "Monster", "Gator", "Rowdy", "Ferris", "Whiskers", "Bits", "Casper", "Sparkle",
	"Godiva", "Goose", "Dee", "Missy", "Mack", "Buffy", "Buddy", "Arnie", "Tiki", "Dunn", "Maverick", "Blackjack", "Turbo",
	"Kane", "Cotton", "Sheena", "Thor", "Clover", "Haley", "Mikey", "Scout", "Buzzy", "Mercle", "Rocco", "Sherman", "Bitsy",
	"Nickie", "Onyx", "Nibby", "Casey", "Cupcake", "Elmo", "Dexter", "Nitro", "Waddles", "Skip", "Gunther", "Zack", "Skye",
	"Snowflake", "Cody", "Sailor", "Chewie", "Sierra", "Sassie", "Peanut", "Benny", "Moochie", "Toni", "Wesley", "Bessie"
};

Animal::Animal(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy) :
	expected_breedings{ expected_breedings }, reproductivity{ reproductivity }, cubs_per_pregnancy{ cubs_per_pregnancy }
{
	name = names[std::rand() % 100];
	breedings = expected_breedings < 2 ? 1 : std::rand() % (expected_breedings - 1) + 1;
}

Animal::Animal(const Animal& d, const Animal& r) :
	name{ d.name.substr(0, std::ceil(d.name.length() / 2)) + r.name.substr(std::floor(r.name.length() / 2), r.name.length()) },
	expected_breedings{ (int)std::ceil((d.expected_breedings + r.expected_breedings) / 2) },
	cubs_per_pregnancy{ (int)std::ceil((d.cubs_per_pregnancy + r.cubs_per_pregnancy) / 2) },
	reproductivity{
		d.reproductivity != Reproductivity::ANY &&
		d.getKind() != r.getKind() ?
			Reproductivity::CANNOT_REPRODUCE :
			d.reproductivity } {}

const std::string Animal::getName() const
{
	return name;
}

bool Animal::isGrown() const
{
	return breedings > 0;
}

bool Animal::isOld() const
{
	return
		reproductivity != Reproductivity::ANY &&
		breedings == expected_breedings;
}

bool Animal::isTooOld() const
{
	return breedings > expected_breedings;
}

const Reproductivity Animal::getReproductivity() const
{
	return reproductivity;
}

const int Animal::getCubsPerPregnancy() const
{
	return cubs_per_pregnancy;
}

const int Animal::operator++()
{
	return ++breedings;
}

const std::string Animal::toString() const
{
	std::string result = this->getKind() + " " + name + " has been breeded " + std::to_string(breedings) + " time(s)";

	// DLC paywall
	if (reproductivity == Reproductivity::ANY)
		return result + '.';

	std::string reproduction_message;
	switch (reproductivity)
	{
	case Reproductivity::CANNOT_REPRODUCE:
		reproduction_message = "is a hybrid, therefore cannot reproduce";
		break;
	case Reproductivity::CAN_REPRODUCE:
		reproduction_message = "can reproduce";
		break;
	case Reproductivity::SELF_REPRODUCTIVE:
		reproduction_message = "can reproduce even without partner";
		break;
	}

	return
		result + " and is expected to be breeded " + std::to_string(expected_breedings) +
		" times in total. It " + reproduction_message + '.';
}
