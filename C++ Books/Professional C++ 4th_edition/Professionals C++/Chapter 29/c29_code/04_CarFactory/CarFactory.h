// For this example, the Car class is assumed to already exist.
#include "Car.h"
#include <memory>

class CarFactory
{
public:
	virtual ~CarFactory() = default;  // Always a virtual destructor!
	std::unique_ptr<Car> requestCar();
	int getNumCarsInProduction() const;

protected:
	virtual std::unique_ptr<Car> createCar() = 0;

private:
	int mNumCarsInProduction = 0;
};

class FordFactory : public CarFactory
{
protected:
	virtual std::unique_ptr<Car> createCar() override;
};

class ToyotaFactory : public CarFactory
{
protected:
	virtual std::unique_ptr<Car> createCar() override;
};
