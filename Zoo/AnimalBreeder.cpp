#include "AnimalBreeder.h"
#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

AnimalBreeder::AnimalBreeder(float p_breed, float p_extinct, bool use_strict)
	: p_breed{ p_breed }, p_extinct{ p_extinct }, use_strict{ use_strict }
{
	std::cout
		<< "He is the primary cause of "
		<< (1 / p_breed - 1) * 100 << "% lower birth rate and "
		<< p_extinct * 100 << "% maternal death.\n";
}

const std::string AnimalBreeder::breed(Zoo<Animal>& zoo) const
{
	// Check, whether there are animals capable of reproduction in the future.
	if (use_strict)
	{
		int self_reproductive{}, can_reproduce{};
		for (Animal* animal : zoo.getAnimals())
		{
			if (animal->getReproductivity() == Reproductivity::SELF_REPRODUCTIVE)
			{
				self_reproductive++;
				break;
			}

			if (animal->getReproductivity() == Reproductivity::CAN_REPRODUCE)
				can_reproduce++;
		}
		if (self_reproductive < 1 && can_reproduce < 2)
			throw new std::runtime_error("There are no more animals capable of reproduction in the Zoo");
	}

	// Make every animal older.
	for (Animal* animal : zoo.getAnimals())
	{
		++(*animal);
	}

	// Used reverse iteration order to avoid
	// pointer problems after element removal.
	// No need for cub filtering, because they
	// are added to the end.
	int were_born{}, maternal_deaths{}, deaths_of_old_age{};
	for (int i = zoo.getAnimals().size() - 1; i >= 0; i--)
	{
		Animal& animal = *zoo.getAnimals()[i];

		// Try to breed the animal.
		if (animal.getReproductivity() != Reproductivity::CANNOT_REPRODUCE &&
			std::rand() % 100 < p_breed * 100)
		{
			std::vector<Animal*> reproductive_animals;
			for (Animal* candidate : zoo.getAnimals())
			{
				if (candidate->isGrown() &&
					(!use_strict ||
						candidate->getReproductivity() != Reproductivity::CANNOT_REPRODUCE &&
						(candidate != &animal || animal.getReproductivity() == Reproductivity::SELF_REPRODUCTIVE)))
					reproductive_animals.push_back(candidate);
			}

			if (reproductive_animals.size() > 0)
			{
				const Animal& partner = *(reproductive_animals[std::rand() % reproductive_animals.size()]);
				for (int c{}; c < (use_strict ? animal.getCubsPerPregnancy() : 1); c++)
				{
					zoo += std::rand() % 2 ? animal.breed(partner) : partner.breed(animal);
					were_born++;
				}

			}

		}

		// Check if it survives the breeding.
		if (std::rand() % 100 < p_extinct * 100)
		{
			zoo -= &animal;
			maternal_deaths++;
			continue;
		}

		// Check if it's too old.
		if (use_strict && animal.isTooOld())
		{
			zoo -= &animal;
			deaths_of_old_age++;
			continue;
		}
	}

	return
		std::to_string(were_born) + " cub(s) were born, " + std::to_string(maternal_deaths) + " maternal" +
		(use_strict ? " and " + std::to_string(deaths_of_old_age) + " of old age" : "") + " death(s) occured. " +
		"Now our Zoo consists of " + std::to_string(zoo.getAnimals().size()) + " animal(s)";
}
