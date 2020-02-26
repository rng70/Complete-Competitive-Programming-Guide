#include <iostream>
#include <initializer_list>

using namespace std;

int makeSum(initializer_list<int> lst)
{
	int total = 0;
	for (const auto& value : lst) {
		total += value;
	}
	return total;
}

int main()
{
	cout << makeSum({ 1, 2, 3 }) << endl;

	return 0;
}
