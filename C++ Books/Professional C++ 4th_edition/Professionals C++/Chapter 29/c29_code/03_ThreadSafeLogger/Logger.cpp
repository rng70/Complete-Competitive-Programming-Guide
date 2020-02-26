#include "Logger.h"
#include <stdexcept>

using namespace std;

const char* const Logger::kLogFileName = "log.out";

mutex Logger::sMutex;

Logger& Logger::instance()
{
	static Logger instance;
	return instance;
}

Logger::Logger()
{
	mOutputStream.open(kLogFileName, ios_base::app);
	if (!mOutputStream.good()) {
		throw runtime_error("Unable to initialize the Logger!");
	}
}

Logger::~Logger()
{
	mOutputStream << "Logger shutting down." << endl;
	mOutputStream.close();
}

void Logger::setLogLevel(LogLevel level)
{
	mLogLevel = level;
}

string_view Logger::getLogLevelString(LogLevel level) const
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

	lock_guard<mutex> guard(sMutex);
	logHelper(message, logLevel);
}

void Logger::log(const vector<string>& messages, LogLevel logLevel)
{
	if (mLogLevel < logLevel) {
		return;
	}

	lock_guard<mutex> guard(sMutex);
	for (const auto& message : messages) {
		logHelper(message, logLevel);
	}
}

void Logger::logHelper(string_view message, LogLevel logLevel)
{
	mOutputStream << getLogLevelString(logLevel).data()
		<< ": " << message << endl;
}
