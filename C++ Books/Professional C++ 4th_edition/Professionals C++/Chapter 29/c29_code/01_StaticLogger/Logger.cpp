#include "Logger.h"
#include <stdexcept>

using namespace std;

const char* const Logger::kLogFileName = "log.out";
bool Logger::sInitialized = false;
ofstream Logger::sOutputStream;
Logger::LogLevel Logger::mLogLevel = Logger::LogLevel::Error;

void Logger::setLogLevel(LogLevel level)
{
	mLogLevel = level;
}

string_view Logger::getLogLevelString(LogLevel level)
{
	switch (level) {
	case LogLevel::Error:
		return "ERROR";
	case LogLevel::Info:
		return "INFO";
	case LogLevel::Debug:
		return "DEBUG";
	}
	throw runtime_error("Invalid log level.");
}

void Logger::log(string_view message, LogLevel logLevel)
{
	if (mLogLevel < logLevel) {
		return;
	}

	if (!sInitialized) {
		init();
	}

	// Print the message and flush the stream with endl.
	sOutputStream << getLogLevelString(logLevel).data()
		<< ": " << message << endl;

}

void Logger::log(const vector<string>& messages, LogLevel logLevel)
{
	if (mLogLevel < logLevel) {
		return;
	}

	for (const auto& message : messages) {
		log(message, logLevel);
	}
}

void Logger::teardown()
{
	if (sInitialized) {
		sOutputStream << "Logger shutting down." << endl;
		sOutputStream.close();
		sInitialized = false;
	}
}

void Logger::init()
{
	if (!sInitialized) {
		sOutputStream.open(kLogFileName, ios_base::app);
		if (!sOutputStream.good()) {
			throw runtime_error("Unable to initialize the Logger!");
		}
		sInitialized = true;
	}
}
