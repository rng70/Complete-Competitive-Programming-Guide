#include <cstdlib>
#include <memory>

using namespace std;

int* malloc_int(int value)
{
    int* p = (int*)malloc(sizeof(int));
    *p = value;
    return p;
}

int main()
{
	auto deleter = [](int* p){ free(p); };
	unique_ptr<int, decltype(deleter)> myIntSmartPtr(malloc_int(42), deleter);

    return 0;
}
