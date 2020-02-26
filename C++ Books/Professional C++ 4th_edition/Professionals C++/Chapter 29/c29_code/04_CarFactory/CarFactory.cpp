#include "CarFactory.h"

// Increment the number of cars in production and return the new car.
std::unique_ptr<Car> CarFactory::requestCar()
{
	mNumCarsInProduction++;
	return createCar();
}

int CarFactory::getNumCarsInProduction() const
{
	return mNumCarsInProduction;
}

std::unique_ptr<Car> FordFactory::createCar()
{
	return std::make_unique<Ford>();
}

std::unique_ptr<Car> ToyotaFactory::createCar()
{
	return std::make_unique<Toyota>();
}
