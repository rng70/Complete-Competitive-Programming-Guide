#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <string_view>

// Definition of a singleton logger class, implemented with static methods.
class Logger final
{
public:
	enum class LogLevel {
		Error,
		Info,
		Debug
	};

	// Sets the log level.
	static void setLogLevel(LogLevel level);

	// Logs a single message at the given log level.
	static void log(std::string_view message,
		LogLevel logLevel);

	// Logs a vector of messages at the given log level.
	static void log(const std::vector<std::string>& messages,
		LogLevel logLevel);

	// Closes the log file.
	static void teardown();

private:
	// Deleted constructor and destructor.
	Logger() = delete;
	~Logger() = delete;

	static void init();

	// Converts a log level to a human readable string.
	static std::string_view getLogLevelString(LogLevel level);

	static const char* const kLogFileName;
	static bool sInitialized;
	static std::ofstream sOutputStream;
	static LogLevel mLogLevel;
};
