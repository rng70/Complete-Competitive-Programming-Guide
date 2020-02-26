#include "AccessList.h"
using namespace std;

AccessList::AccessList(const initializer_list<string_view>& initlst)
{
	for (auto& user : initlst) {
		addUser(user);
	}
}

void AccessList::addUser(string_view user)
{
	mAllowed.insert(string(user));
}

void AccessList::removeUser(string_view user)
{
	mAllowed.erase(string(user));
}

bool AccessList::isAllowed(string_view user) const
{
	return (mAllowed.count(string(user)) != 0);
}

list<string> AccessList::getAllUsers() const
{
	list<string> users;
	users.insert(end(users), begin(mAllowed), end(mAllowed));
	return users;
}
