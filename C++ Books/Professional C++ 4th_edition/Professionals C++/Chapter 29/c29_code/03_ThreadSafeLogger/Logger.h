#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <string_view>
#include <mutex>

// Definition of a multithread-safe singleton logger class.
class Logger final
{
public:
	enum class LogLevel {
		Error,
		Info,
		Debug
	};

	// Returns a reference to the singleton Logger object.
	static Logger& instance();

	// Sets the log level.
	void setLogLevel(LogLevel level);

	// Logs a single message at the given log level.
	void log(std::string_view message,
		LogLevel logLevel);

	// Logs a vector of messages at the given log level.
	void log(const std::vector<std::string>& messages,
		LogLevel logLevel);

private:
	// Private constructor and destructor.
	Logger();
	~Logger();

	// Prevent copy/move construction.
	Logger(const Logger&) = delete;
	Logger(Logger&&) = delete;

	// Prevent copy/move assignment operations.
	Logger& operator=(const Logger&) = delete;
	Logger& operator=(Logger&&) = delete;

	// Converts a log level to a human readable string.
	std::string_view getLogLevelString(LogLevel level) const;

	static const char* const kLogFileName;
	std::ofstream mOutputStream;
	LogLevel mLogLevel = LogLevel::Error;

	// Logs message. The thread should own a lock on sMutex
	// before calling this function.
	void logHelper(std::string_view message,
		LogLevel inLogLevel);

	static std::mutex sMutex;
};
