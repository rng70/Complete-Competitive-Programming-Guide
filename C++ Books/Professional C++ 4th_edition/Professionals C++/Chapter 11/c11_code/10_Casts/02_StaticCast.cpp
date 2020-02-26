class Base
{
public:
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	virtual ~Derived() {}
};

int main()
{
	int i = 3;
	int j = 4;
	double result = static_cast<double>(i) / j;


	Base* b;
	Derived* d = new Derived();

	b = d; // Don't need a cast to go up the inheritance hierarchy
	d = static_cast<Derived*>(b); // Need a cast to go down the hierarchy

	Base base;
	Derived derived;

	Base& br = derived;
	Derived& dr = static_cast<Derived&>(br);

	return 0;
}
