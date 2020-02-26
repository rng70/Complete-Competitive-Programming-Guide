#include <iostream>
#include <string>

using namespace std;

int main()
{
	//string str1 = "Hello "World"!";    // Error!
	string str2 = "Hello \"World\"!";
	string str3 = R"(Hello "World"!)";

/*
	string str4 = "Line 1
Line 2 with \t";    // Error!
*/

	string str5 = R"(Line 1
Line 2 with \t)";

	//string str6 = R"(The characters )" are embedded in this string)";    // Error!
	string str7 = R"-(The characters )" are embedded in this string)-";

	return 0;
}
