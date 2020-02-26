#pragma once

#include <ostream>
#include <string>
#include <string_view>
#include <stack>

// Sample Error class with just a priority and a string error description.
class Error
{
public:
	Error(int priority, std::string_view errMsg) : mPriority(priority), mError(errMsg) {}
	int getPriority() const { return mPriority; }
	std::string_view getErrorString() const { return mError; }

	friend bool operator<(const Error& lhs, const Error& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Error& err);

private:
	int mPriority;
	std::string mError;
};

// Simple ErrorCorrelator class that returns most recent errors first.
class ErrorCorrelator
{
public:
	// Add an error to be correlated.
	void addError(const Error& error);

	// Retrieve the next error to be processed
	Error getError();

private:
	std::stack<Error> mErrors;
};
