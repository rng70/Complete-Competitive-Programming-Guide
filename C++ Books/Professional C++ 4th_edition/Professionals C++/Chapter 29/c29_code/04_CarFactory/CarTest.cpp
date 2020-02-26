#include "CarFactory.h"
#include <vector>
#include <memory>

using namespace std;

CarFactory* getLeastBusyFactory(const vector<unique_ptr<CarFactory>>& factories)
{
	if (factories.size() == 0)
		return nullptr;

	CarFactory* bestSoFar = factories[0].get();

	for (size_t i = 1; i < factories.size(); i++) {
		if (factories[i]->getNumCarsInProduction() <
			bestSoFar->getNumCarsInProduction()) {
			bestSoFar = factories[i].get();
		}
	}

	return bestSoFar;
}


int main()
{
	vector<unique_ptr<CarFactory>> factories;

	// Create 3 Ford factories and 1 Toyota factory. 
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<ToyotaFactory>());

	// To get more interesting results, preorder some cars.
	factories[0]->requestCar();
	factories[0]->requestCar();
	factories[1]->requestCar();
	factories[3]->requestCar();

	// Build 10 cars from the least busy factory.
	for (size_t i = 0; i < 10; i++) {
		CarFactory* currentFactory = getLeastBusyFactory(factories);
		auto theCar = currentFactory->requestCar();
		theCar->info();
	}

	return 0;
}
