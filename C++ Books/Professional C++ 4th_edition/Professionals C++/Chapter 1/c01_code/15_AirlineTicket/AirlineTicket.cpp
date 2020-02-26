#include "AirlineTicket.h"

using namespace std;

AirlineTicket::AirlineTicket()
	: mPassengerName("Unknown Passenger")
	, mNumberOfMiles(0)
	, mHasEliteSuperRewardsStatus(false)
{
}

AirlineTicket::~AirlineTicket()
{
	// Nothing much to do in terms of cleanup
}

int AirlineTicket::calculatePriceInDollars() const
{
	if (getHasEliteSuperRewardsStatus()) {
		// Elite Super Rewards customers fly for free!
		return 0;
	}

	// The cost of the ticket is the number of miles times
	// 0.1. Real airlines probably have a more complicated formula!
	return static_cast<int>(getNumberOfMiles() * 0.1);
}

const string& AirlineTicket::getPassengerName() const
{
	return mPassengerName;
}

void AirlineTicket::setPassengerName(const string& name)
{
	mPassengerName = name;
}

int AirlineTicket::getNumberOfMiles() const
{
	return mNumberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
	mNumberOfMiles = miles;
}

bool AirlineTicket::getHasEliteSuperRewardsStatus() const
{
	return mHasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
	mHasEliteSuperRewardsStatus = status;
}
