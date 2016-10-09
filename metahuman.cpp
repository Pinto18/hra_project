//////////////////////////////////////////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Garrett Palmquist, Nick Dipinto
// Metahuman Class Implementation
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef METAHUMAN_CPP
#define METAHUMAN_CPP

#include <string>
#include <iostream>
#include "metahuman.hpp"


const std::string nameConst = "";
const std::string aliasConst = "";
const int ageConst = 0;
const std::string raceConst = "";
const std::string genderConst = "";
const std::string vulnerabilityConst = "";
const std::string originConst = "";
const std::string defaultStatus ="";
// Class constructor
MetaHuman::MetaHuman()
{
  name = nameConst;
  alias = aliasConst;
  age = ageConst;
  race = raceConst;
  gender = genderConst;
  vulnerability = vulnerabilityConst;
  origin = originConst;
  threatLevel = 0;
  status = defaultStatus;
}
  

// Class destructor
MetaHuman::~MetaHuman() {}


// setName Function
int MetaHuman::setName(std::string n)
{
  name = n;
  return 0;
}

//setAlias Function
int MetaHuman::setAlias(std::string a)
{
  alias = a;
  return 0;
}

// setAge Function
int MetaHuman::setAge(int a)
{
  age = a;
  return 0;
}

// setRace Function
int MetaHuman::setRace(std::string r)
{
  race = r;
  return 0;
}

// setGender Function
int MetaHuman::setGender(std::string g)
{
  gender = g;
  return 0;
}

//setVulnerability Function
int MetaHuman::setVulnerability(std::string v)
{
  vulnerability = v;
  return 0;
}
 
//setOrigin Function
int MetaHuman::setOrigin(std::string o)
{
  origin = o;
  return 0;
}

//setStatus Function
int MetaHuman::setStatus(std::string s)
{
   status = s;
   return 0;
}

double MetaHuman::computeThreatLevel(const Power_Grid& pg) const
{
  double tl = 0.0; 
  const double threatLevelWeight = ((100/6)/7);        // ((threat level max)/num of powers)/highest power rating possible)
                                                       // A metahuman with 7's in every category would have a threat level
                                                       // of 100, or a perfect score.
  tl = pg.get_intelligence_level() * threatLevelWeight + 
                pg.get_strength_level() * threatLevelWeight +
                pg.get_speed_level() * threatLevelWeight +
                pg.get_durability_level() * threatLevelWeight +
                pg.get_EP_level() * threatLevelWeight +
                pg.get_fighting_level() * threatLevelWeight;
                
//  threatLevel = tl;
  return tl;
  
}


// adding a new mission
int MetaHuman::addMission(Mission* newMission)
{
  this->metaMissions.push_back(newMission);
  return 0;
}

//adding a power
int MetaHuman::addPower(std::string p)
{
   this->metaHumanPowers.add_power(p);
   return 0;
}

int MetaHuman::removePower(int numRemoved)
{
   this->metaHumanPowers.remove_power(numRemoved);
   return 0;
}

int MetaHuman::updatePowerGrid(int intel, int str, int sp, int dur, int ep, int f)
{
   this->metaHumanPowers.set_intelligence_level(intel);
   this->metaHumanPowers.set_strength_level(str);
   this->metaHumanPowers.set_speed_level(sp);
   this->metaHumanPowers.set_durability_level(dur);
   this->metaHumanPowers.set_EP_level(ep);
   this->metaHumanPowers.set_fighting_level(f);
   return 0;
}


//Overloaded << operator function
std::ostream& operator <<(std::ostream& outs, const MetaHuman& mh)
{

  // Printing out MetaHuman Attributes  
  outs << "//////////////////////////////////////////////////////////////////" << std::endl
       << "Metahuman     : " << mh.getName() << std::endl
       << "Alias         : " << mh.getAlias() << std::endl
       << "Status        : " << mh.getStatus() <<std::endl
       << "Age           : " << mh.getAge() << std::endl
       << "Race          : " << mh.getRace() << std::endl
       << "Gender        : " << mh.getGender() << std::endl
       << "Vulnerability : " << mh.getVulnerability() << std::endl
       << "Threat Level  : " << mh.computeThreatLevel(mh.metaHumanPowers) << std::endl
       << "Origin        : " << mh.getOrigin() << std::endl;
       
       
  // Printing out the PowerGrid
  outs << mh.metaHumanPowers << std::endl;
  
  //Printing out all of the MetaHuman's missions
  std::vector<Mission*>::const_iterator i; // an iterator i for the associated missions
  for (i = mh.metaMissions.begin(); i < mh.metaMissions.end(); i++)
    {
      outs << *i << std::endl;
    }
    
  return outs;
}

#endif

