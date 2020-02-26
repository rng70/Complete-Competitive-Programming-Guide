#include "TestListener.h"
#include "EventRegistry.h"

TestListener::TestListener()
{
    // Subscribe to event 0.
	EventRegistry::registerListener(0, this);
}

void TestListener::handleMessage(int message) 
{
    switch (message) {
        case 0:
            mMessage0Received = true;
            break;
        default:
            mUnknownMessageReceived = true;
            break;
    }
}

bool TestListener::hasReceivedMessage0() const
{
	return mMessage0Received;
}

bool TestListener::hasReceivedUnknownMessage() const
{
	return mUnknownMessageReceived;
}
