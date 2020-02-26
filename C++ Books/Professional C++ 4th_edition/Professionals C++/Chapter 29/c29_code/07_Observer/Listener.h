// Mixin class for objects that are able to respond to events.

#pragma once

class Listener
{
    public:
		virtual ~Listener() = default;  // Always a virtual destructor!
		virtual void handleMessage(int message) = 0;
};
