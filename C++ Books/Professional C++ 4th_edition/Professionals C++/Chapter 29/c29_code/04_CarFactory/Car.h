#include <iostream>

class Car
{
public:
	virtual ~Car() = default;  // Always a virtual destructor!
	virtual void info() const = 0;
};

class Ford : public Car
{
public:
	virtual void info() const override { std::cout << "Ford" << std::endl; }
};

class Toyota : public Car
{
public:
	virtual void info() const override { std::cout << "Toyota" << std::endl; }
};
