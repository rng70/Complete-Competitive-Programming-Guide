#ifndef LOGGER_H
#define LOGGER_H

#include <string_view>
//#include "Preferences.h"
class Preferences;  // forward declaration

class Logger 
{
public:
	static void setPreferences(const Preferences& prefs);
	static void logError(std::string_view error);
}; 

#endif // LOGGER_H
