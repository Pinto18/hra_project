//////////////////////////////////////////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Garrett Palmquist, Nick Dipinto
// Villain Class Implementation
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef VILLAIN_CPP
#define VILLAIN_CPP

#include <string>
#include <iostream>
#include "villain.hpp"

//const int threatLevel = 0;
//const float killRatio = 0;

// Set Status Mutator
int Villain::setThreatLevel(int tl)
{
  threatLevel = tl;
  return 0;
}

float Villain::calcKillRatio()
{
  killRatio = 0;
  std::vector<Mission*>::iterator pki;
  for(pki = metaMissions.begin(); pki != metaMissions.end(); pki++)
    {
      killRatio += (*pki)->getPeopleKilled();
    }
  return killRatio;
}

 //Overloaded operator << function
std::ostream& operator <<(std::ostream& outs, const Villain& v)
{
  outs << "//////////////////////////////////////////////////////////////////" << std::endl
       << "Metahuman     : " << v.getName() << std::endl
       << "Alias         : " << v.getAlias() << std::endl
       << "Age           : " << v.getAge() << std::endl
       << "Status        : " << v.getStatus() << std::endl
       << "Race          : " << v.getRace() << std::endl
       << "Gender        : " << v.getGender() << std::endl
       << "Vulnerability : " << v.getVulnerability() << std::endl
       << "Threat Level  : " << v.getThreatLevel() << std::endl
       << "Kill Ratio    : " << v.getKillRatio() << std::endl
       << "Origin        : " << v.getOrigin() << std::endl;
       
  // Printing out the PowerGrid
  outs << v.metaHumanPowers << std::endl;
  
  //Printing out all of the MetaHuman's missions
  std::vector<Mission*>::const_iterator i; // an iterator i for the associated missions
  for (i = v.metaMissions.begin(); i < v.metaMissions.end(); i++)
    {
      outs << *i << std::endl;
    }
    
  return outs;
}

#endif
