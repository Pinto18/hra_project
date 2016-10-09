//////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Nicholas DiPinto, Garrett Palmquist
// File created by: Garrett Palmquist
// Mission Class Declaration
//////////////////////////////////////////////////////////////////

#ifndef MISSION_HPP
#define MISSION_HPP

#include <string>

class Mission
{
  private:
    std::string missionName; 
    std::string threatName;
    int threatLevel;
    std::string location;
    std::string status;
    std::string success;
    int peopleKilled;

  public:
    Mission();
    ~Mission();
  
    //Accessor functions
    std::string getMissionName() const {return missionName;}
    std::string getThreatName() const {return threatName;}
    int getThreatLevel() const {return threatLevel;}
    std::string getLocation() const {return location;}
    std::string getStatus() const {return status;}
    std::string getSuccess() const {return success;}
    int getPeopleKilled() const {return peopleKilled;}
    
    //Mutator functions
    int setMissionName(std::string);
    int setThreatName(std::string);
    int setThreatLevel(int);
    int setLocation(std::string);
    int setStatus(std::string);
    int setSuccess(std::string);
    int setPeopleKilled(int);
    
    //Other functions
    friend std::ostream& operator <<(std::ostream& outs, const Mission&);
};

#endif
// end mission.hpp
