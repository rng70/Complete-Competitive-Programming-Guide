#pragma once

#include "Listener.h"

class TestListener : public Listener
{
    public:
        TestListener();
        void handleMessage(int message);
		bool hasReceivedMessage0() const;
		bool hasReceivedUnknownMessage() const;

private:
        bool mMessage0Received = false;
        bool mUnknownMessageReceived = false;
};
