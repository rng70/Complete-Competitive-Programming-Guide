#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    // Create a vector of strings, using uniform initialization
    vector<string> myVector = { "A first string", "A second string" };

	// Add some strings to the vector using push_back()
    myVector.push_back("A third string");
    myVector.push_back("The last string in the vector");
    
	// Print the elements using a range-based for loop
    for (const auto& str : myVector)
        cout << str << endl;
    
	// Iterate over the elements in the vector and print them once more
	for (auto iterator = cbegin(myVector);
		iterator != cend(myVector); ++iterator) {
		cout << *iterator << endl;
    }
    
	return 0;
}
