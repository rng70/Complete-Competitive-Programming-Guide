// Maintains a directory of Listeners and their corresponding events. Also
// handles transmission of an event to the appropriate Listener.

#pragma once

#include "Listener.h"
#include <vector>
#include <map>

class EventRegistry
{
    public:
		// The registry does not become the owner of the given listener,
		// so a naked pointer is ok.
        static void registerListener(int message, Listener* listener);
        static void handleMessage(int message);

    private:
        static std::map<int, std::vector<Listener*>> sListenerMap;
};
