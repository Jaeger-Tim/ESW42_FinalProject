#pragma once

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