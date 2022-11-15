#include "Animal.h"
#include "AnimalBreeder.h"
#include "AnimalFactory.h"
#include "IAnimalFactory.h"
#include "StrictAnimalFactory.h"
#include "Zoo.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

void simulateZoo(std::vector<std::string>& log)
{
	std::srand((unsigned int)std::time(0));
	std::cout << std::fixed << std::setprecision(2);

	std::cout << "The Zoo by @vrepetskyi\n\n";

	bool use_strict;
	std::cout << "use strict? (hybrids cannot reproduce, animals die of old age, multiple cubs per breeding) ";
	std::cin >> use_strict;

	int animals_number;
	std::cout << "How many animals are there in our zoo? ";
	std::cin >> animals_number;

	if (animals_number < 1)
	{
		throw std::runtime_error("Animal husbandry is not your calling");
	}

	Zoo<Animal> zoo;

	IAnimalFactory* animal_factory;
	if (use_strict)
		animal_factory = new StrictAnimalFactory();
	else
		animal_factory = new AnimalFactory();

	for (int i{}; i < animals_number; i++)
	{
		zoo += animal_factory->createRandom();
	}
	log.push_back("Initial state\n" + zoo.toString());

	delete animal_factory;

	float p_breed, p_extinct;
	std::cout
		<< "Mister B, our animal interactions manager, is a bit lazy.\n"
		<< "Should we insist on his hard work? (specify p_breed and p_extinct) ";
	std::cin >> p_breed >> p_extinct;

	if (p_breed > 1 || p_breed < 0 || p_extinct > 1 || p_extinct < 0)
	{
		throw std::runtime_error("That doesn't seem reasonable");
	}

	AnimalBreeder breeder(p_breed, p_extinct, use_strict);
	int counter{};
	while (zoo.getAnimals().size() < 100)
	{
		if (++counter > 10)
			throw std::runtime_error("Years have passed, but our Zoo is still way too small");

		std::string log_message = "Breeding " + std::to_string(counter) + '\n';

		if (zoo.getAnimals().size() < 1)
			throw std::runtime_error("Nice job! Our Zoo went extinct");

		log_message += breeder.breed(zoo);
		std::cout << '\n' + log_message + '\n';

		log_message += ":\n\n" + zoo.toString();
		log.push_back(log_message);
	}

	std::cout << "\nWow! Our Zoo has become really big! \\(~o~)/\n";
}

void inspectorLoop()
{
	std::vector<std::string> log;
	try
	{
		simulateZoo(log);
	}
	catch (const std::runtime_error& e)
	{
		std::cout << '\n' << e.what() << "... (~_~;)\n";
	}
	catch (...)
	{
		std::cout << "\nHm, an unexpected error occured! Sorry...\n";
	}

	std::cout << '\n';

	while (true)
	{
		int state_index;
		std::cout << "Enter the breeding number details about you would like to see (0 = initial state, -1 = exit): ";
		std::cin >> state_index;

		if (state_index < 0)
			break;

		int last_index = log.size() - 1;
		if (state_index > last_index)
		{
			std::cout << "The last breeding number is " << last_index << "\n\n";
			continue;
		}

		std::cout << '\n' + log[state_index];
	}
}

void mainLoop()
{
	while (true)
	{
		inspectorLoop();

		bool restart;
		std::cout << "Try again? ";
		std::cin >> restart;

		if (!restart)
			break;

		std::cout << '\n';
	}
}

int main()
{
	mainLoop();
	return 0;
}
