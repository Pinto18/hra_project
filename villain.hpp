//////////////////////////////////////////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Garrett Palmquist, Nick Dipinto
// Villain Class Declaration
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VILLAIN_HPP
#define VILLAIN_HPP

#include "metahuman.hpp"
#include <string>

class Villain:public MetaHuman
{
  private:
    int threatLevel;
    float killRatio;
    
  public:
  
    //Accessor Functions
    int getThreatLevel() const {return threatLevel;}
    float getKillRatio() const {return killRatio;}
    
    //Mutator Functions
    int setThreatLevel(int);
    
    //Other Functions
    float calcKillRatio();
    friend std::ostream& operator <<(std::ostream& outs, const Villain&);  //Overloaded operator << function
    
};

#endif