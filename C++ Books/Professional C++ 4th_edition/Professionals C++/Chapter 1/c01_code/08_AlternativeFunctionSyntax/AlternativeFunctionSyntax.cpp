#include <iostream>

using namespace std;

auto func(int i) -> int
{
    return i + 2;
}

auto main() -> int
{
    cout << func(3) << endl;

	return 0;
}
