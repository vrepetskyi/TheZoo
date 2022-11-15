#pragma once

#include <iostream>

enum class Reproductivity
{
	ANY,
	SELF_REPRODUCTIVE,
	CAN_REPRODUCE,
	CANNOT_REPRODUCE,
};

class Animal
{
	std::string name;
	int breedings{}; // - kind of age; not in years, because animals have different pregnancy period.
	const int expected_breedings; // - expected life duration.
	Reproductivity reproductivity;
	const int cubs_per_pregnancy;
public:
	Animal(int expected_breedings, Reproductivity reproductivity, int cubs_per_pregnancy);
	Animal(const Animal& d, const Animal& r);
	virtual const std::string getKind() const = 0;
	const std::string getName() const;
	const Reproductivity getReproductivity() const;
	const int getCubsPerPregnancy() const;
	bool isGrown() const;
	bool isOld() const;
	bool isTooOld() const;
	virtual const int operator++();
	virtual Animal* breed(const Animal& partner) const = 0;
	virtual const std::string toString() const = 0;
};
