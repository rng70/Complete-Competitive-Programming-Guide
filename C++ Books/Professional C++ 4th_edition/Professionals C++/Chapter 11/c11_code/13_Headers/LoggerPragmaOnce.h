#pragma once

#include <string_view>
#include "Preferences.h"

class Logger 
{
public:
	static void setPreferences(const Preferences& prefs);
	static void logError(std::string_view error);
}; 
