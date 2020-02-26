#include <iostream>
#include "TestListener.h"
#include "EventRegistry.h"

using namespace std;

int main()
{
	TestListener tl;

	EventRegistry::handleMessage(0);
	EventRegistry::handleMessage(1);
	EventRegistry::handleMessage(2);

	if (!tl.hasReceivedMessage0()) {
		cout << "TEST FAILED: Message 0 was not received" << endl;
	} else if (tl.hasReceivedUnknownMessage()) {
		cout << "TEST FAILED: TestListener received unknown message" << endl;
	} else {
		cout << "TEST PASSED" << endl;
	}

	return 0;
}
