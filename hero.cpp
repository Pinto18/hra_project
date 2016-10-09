//////////////////////////////////////////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Garrett Palmquist, Nick Dipinto
// Hero Class Implementation
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef HERO_CPP
#define HERO_CPP

#include <string>
#include <iostream>
#include <vector>
#include "hero.hpp"

const std::string livingStatus = "UNKNOWN";
const std::string city = "UNKNOWN";
//const float successRate = 0;

// Set Status Mutator
int Hero::setLivingStatus(std::string s)
{
  livingStatus = s;
  return 0;
}

//Set City Mutator
int Hero::setCity(std::string c)
{
  city = c;
  return 0;
}

// Calculating the success rate
float Hero::calcSuccessRate() 
{
  int missions = 0;
  int successfulMissions = 0;
  int successRate = 0;
  if(!metaMissions.empty())
    {
      std::vector<Mission*>::iterator sri;
      for (sri = metaMissions.begin(); sri != metaMissions.end(); sri++)
        {
          missions++;
          if((*sri)->getSuccess() == "w")
            successfulMissions++;
        }
  
      successRate = (successfulMissions/missions) * 100;
     return successRate;
   }
  else
    return 0;
}


//Overloaded << operator function
std::ostream& operator <<(std::ostream& outs, Hero& h)
{
  // Printing out MetaHuman Attributes  
  outs << "//////////////////////////////////////////////////////////////////" << std::endl
       << "Metahuman     : " << h.getName() << std::endl
       << "Alias         : " << h.getAlias() << std::endl
       << "Status        : " << h.getStatus() <<std::endl
       << "Age           : " << h.getAge() << std::endl
       << "Race          : " << h.getRace() << std::endl
       << "Gender        : " << h.getGender() << std::endl
       << "Vulnerability : " << h.getVulnerability() << std::endl
       << "Mortality     : " << h.getLivingStatus() << std::endl
       << "City          : " << h.getCity() << std::endl
       << "Success Rate  : " << h.calcSuccessRate() << std::endl
       << "Threat Level  : " << h.computeThreatLevel(h.metaHumanPowers) << std::endl
       << "Origin        : " << h.getOrigin() << std::endl;
       
       
  // Printing out the PowerGrid
  outs << h.metaHumanPowers << std::endl;
  
  //Printing out all of the MetaHuman's missions
  std::vector<Mission*>::const_iterator i; // an iterator i for the associated missions
  for (i = h.metaMissions.begin(); i < h.metaMissions.end(); i++)
    {
      outs << **i << std::endl;
    }
    
  return outs;
}

#endif

