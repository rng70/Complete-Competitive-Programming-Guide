#include <string>

const std::string message = "Test";
const std::string& foo()
{
	return message;
}

int main()
{
	auto f1 = foo();
	const auto& f2 = foo();
	decltype(foo()) f3 = foo();
	decltype(auto) f4 = foo();
}
