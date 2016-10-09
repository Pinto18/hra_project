//////////////////////////////////////////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Garrett Palmquist, Nick Dipinto
// Hero Class Declaration
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HERO_HPP
#define HERO_HPP

#include "metahuman.hpp"
#include <string>

class Hero:public MetaHuman
{
  private:
    std::string livingStatus; 
    std::string city;
    float successRate;
    
      
  public:
    
    //Accessors
    std::string getLivingStatus() const {return livingStatus;}
    std::string getCity() const {return city;}
    float getSuccessRate() const {return successRate;}
    
    //Mutators
    int setLivingStatus(std::string);
    int setCity(std::string);
    
    //Other Functions
    float calcSuccessRate();
    friend std::ostream& operator <<(std::ostream& outs, Hero&);  //Overloaded operator << function
};

#endif
    
  
  
  
