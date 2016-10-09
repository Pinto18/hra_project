//////////////////////////////////////////////////////////////////////////////////////////////////////
// CS225 Group Project
// Evelyn Brown, Garrett Palmquist, Nick Dipinto
// Metahuman Class Declaration
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef METAHUMAN_HPP
#define METAHUMAN_HPP

#include "mission.hpp"
#include "power_grid.hpp"
#include <vector>

class MetaHuman
{
private:
    std::string name;                    // The actual name of the metahuman
    std::string alias;                   // The alias (Captain America, Black Widow)
    int age;                             // Age of the superhero
    std::string race;                    // Race of the superhero (can also be of alien race)
    std::string gender;                  // Gender of the superhero
    std::string vulnerability;           // Any vulnerabilities of the superhero
    std::string origin;                  // A short paragraph of their origin story
    double threatLevel;                  // The threat level of an individual, computed by the computeThreatLevel function
    std::string status;                  // Whether the meta human is a hero or a villain   
public:

    MetaHuman();
    virtual ~MetaHuman();
    

    //Accessor functions
    std::string getName() const {return name;};
    std::string getAlias() const {return alias;};
    int getAge() const {return age;};
    std::string getRace() const {return race;};
    std::string getGender() const {return gender;};
    std::string getVulnerability() const {return vulnerability;};
    std::string getOrigin() const {return origin;};
    Power_Grid& getPowerGrid() {return metaHumanPowers;};
    double getThreatLevel() const {return threatLevel;};
    std::string getStatus() const {return status;};
    
    
    //Mutator functions
    int setName(std::string);
    int setAlias(std::string);
    int setAge(int);
    int setRace(std::string);
    int setGender(std::string);
    int setVulnerability(std::string);
    int setOrigin(std::string);
    int setStatus(std::string);
    int addMission(Mission*);
    int addPower(std::string);
    int removePower(int); 
   
    //Other functions
    double computeThreatLevel(const Power_Grid&) const;
    friend std::ostream& operator<<(std::ostream& outs, const MetaHuman&);  //Overloaded operator << function
    int updatePowerGrid(int, int, int, int, int, int);

protected:
    // Creating a vector of powers
    Power_Grid metaHumanPowers;
    std::vector<Mission*>metaMissions;  // A vector of associated Missions
    
};

#endif
