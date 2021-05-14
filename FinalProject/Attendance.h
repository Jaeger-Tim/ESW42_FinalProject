#pragma once

/**
* Author: Tim Jäger
* Email: tim.jager2001@gmail.com
*
* Content:
*	- AttendanceStruct (struct)
*	- getAttendance
*
* Dependencies:
*	- iostream
*	- vector
*	- string
*
*	- TJ
*	- User
*
* AttendanceStruct is a structure that is used to link all the days a user was pressent to
* their UUID.
*
* The getAttendance function is used for the interactive menu, to register the users attendance.
*/

#include <iostream>
#include "TJ.h"

#include <vector>
#include <string>

#include "User.h"

struct AttendanceStruct {
	long userUUID;
	std::vector<TJ::simpleDate> attendanceDays;
};

void getAttendance(std::vector<AttendanceStruct>& attendance, std::vector<User>& users);