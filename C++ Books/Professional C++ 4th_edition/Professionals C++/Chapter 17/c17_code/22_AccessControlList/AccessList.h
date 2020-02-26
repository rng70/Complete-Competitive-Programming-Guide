#pragma once

#include <set>
#include <string>
#include <string_view>
#include <list>
#include <initializer_list>

class AccessList
{
public:
	// Default constructor
	AccessList() = default;

	// Constructor to support uniform initialization.
	AccessList(const std::initializer_list<std::string_view>& initlst);

	// Adds the user to the permissions list.
	void addUser(std::string_view user);

	// Removes the user from the permissions list.
	void removeUser(std::string_view user);

	// Returns true if the user is in the permissions list.
	bool isAllowed(std::string_view user) const;

	// Returns a list of all the users who have permissions.
	std::list<std::string> getAllUsers() const;

private:
	std::set<std::string> mAllowed;
};
