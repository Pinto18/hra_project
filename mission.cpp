//////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Nicholas DiPinto, Garrett Palmquist
// File created by: Garrett Palmquist
// Mission Class Implementation
//////////////////////////////////////////////////////////////////

#ifndef MISSION_CPP
#define MISSION_CPP

#include <string>
#include <iostream>
#include "mission.hpp"

const std::string constMissionName = "N/A";
const std::string constThreatName = "UNKNOWN";
const int constThreatLevel = 0;
const std::string constLocation = "N/A";
const std::string constStatus = "N/A";  //can be past or current
const std::string constSuccess = "N/A"; //can be pending, win, or loss. Could/should this be a bool or something else to help w/ calculations?

// Class constructor
Mission::Mission()
{
  missionName = constMissionName;
  threatName = constThreatName;
  threatLevel = constThreatLevel;
  location = constLocation;
  status = constStatus;
  success = constSuccess;
}

// Class destructor
Mission::~Mission()
{
}


// Set Mission Name
int Mission::setMissionName(std::string n)
{
	missionName = n;
  	return 0;
}

//Set Threat Name
int Mission::setThreatName(std::string t)
{
  	threatName = t;
  	return 0;
}

//Set Threat Level
int Mission::setThreatLevel(int lev)
{
  	threatLevel = lev;
  	return 0;
}

//Set Location
int Mission::setLocation(std::string loc)
{
  	location = loc;
  	return 0;
}

//Set Mission Status
int Mission::setStatus(std::string s)
{
  	status = s;
  	return 0;
}

//Set Mission Success
int Mission::setSuccess(std::string s)
{
  	success = s;
  	return 0;
}

//Set number of people killed
int Mission::setPeopleKilled(int p)
{
    peopleKilled = p;
    return 0;
}

//Overloaded << operator
std::ostream& operator <<(std::ostream& outs, const Mission& m)
{
  outs << "//////////////////////////////////////////////////////////////////" << std::endl
       << "Mission       : " << m.getMissionName() << std::endl
       << "Threat        : " << m.getThreatName() << std::endl
       << "Threat Level  : " << m.getThreatLevel() << std::endl
       << "Location      : " << m.getLocation() << std::endl
       << "Status        : " << m.getStatus() << std::endl
       << "Success       : " << m.getSuccess() << std::endl
       << "People Killed : " << m.getPeopleKilled() << std::endl;
       
  return outs;
       
}

#endif
// end missions.cpp