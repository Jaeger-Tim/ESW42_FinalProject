#pragma once

/**
* Author: Tim Jäger
* Email: tim.jager2001@gmail.com
*
* Content:
*	- createUser (function)
*	- listUsers (function)
*	- deleteUser (function)
*
* Dependencies:
*	- User
*
* createUser: this function contains an interactive menu to create a user and returns it
* 
* listUsers: this function creates and displays all users in a vector
* 
* deleteUser: this function shows an interactive menu to select and delete a user from
*			  a vector that has been passed
*/

#include "User.h"

namespace TJ {
	User createUser();
	void listUsers(std::vector<User> users);
	void deleteUser(std::vector<User>& users);
}