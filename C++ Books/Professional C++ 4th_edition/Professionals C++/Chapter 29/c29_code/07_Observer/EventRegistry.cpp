#include "EventRegistry.h"
#include <iostream>

using namespace std;

// Define the static map.
map<int, vector<Listener*>> EventRegistry::sListenerMap;

void EventRegistry::registerListener(int message, Listener* listener)
{
	// Chapter 17 explains std::map. Note that if you specify a key
	// using [] to access it, and there is not yet an entry in the map for
	// that key, a new entry is created.
	sListenerMap[message].push_back(listener);
}

void EventRegistry::handleMessage(int message)
{ 
    // Check to see if the message has *any* listeners. This check is required
    // because otherwise, accessing sListenerMap[message] would create
    // a new entry when it’s not yet in the map. See Chapter 17.
	if (sListenerMap.count(message) == 0)
		return;

	for (auto& listener : sListenerMap[message]) {
		listener->handleMessage(message);
	}
}
