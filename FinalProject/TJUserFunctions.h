#pragma once

#include "User.h"

namespace TJ {
	User createUser();
	void listUsers(std::vector<User> users);
	void deleteUser(std::vector<User>& users);
}