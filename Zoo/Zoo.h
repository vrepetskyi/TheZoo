#pragma once

#include <iostream>
#include <vector>
#include <string>

// The class is generic... Therefore all implementations are here.

template <class T>
class Zoo
{
	std::vector<T*> animals;
public:
	~Zoo();
	Zoo& operator+=(T* animal);
	Zoo& operator-=(const T* animal);
	std::vector<T*>& getAnimals();
	const std::string toString() const;
	// operator<< is overloaded only for demonstational purposes.
	friend std::ostream& operator<<(std::ostream& os, const Zoo& zoo) { return os << zoo.toString(); }
};

template <class T>
Zoo<T>::~Zoo()
{
	for (T* animal : animals)
	{
		delete animal;
	}
}

template <class T>
std::vector<T*>& Zoo<T>::getAnimals()
{
	return animals;
}

template <class T>
Zoo<T>& Zoo<T>::operator+=(T* animal)
{
	animals.push_back(animal);
	return *this;
}

template <class T>
Zoo<T>& Zoo<T>::operator-=(const T* animal)
{
	animals.erase(std::remove(animals.begin(), animals.end(), animal), animals.end());
	delete animal;
	return *this;
}

template <class T>
const std::string Zoo<T>::toString() const
{
	std::string result;
	for (int i{}; i < animals.size(); i++)
	{
		if (!animals[i]->isGrown())
			result += "CUB\t";

		if (animals[i]->isOld())
			result += "OLD\t";

		result += std::to_string(i + 1) + ". " + animals[i]->toString() + "\n\n";
	}
	return result;
}
