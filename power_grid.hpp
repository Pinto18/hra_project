//Power_Grid.hpp -- Power Grid Class Declaration
//Nicholas DiPinto
//CS225 Group Assignment

#ifndef POWER_GRID_HPP_
#define POWER_GRID_HPP_

//Pre Processor Directives/////
#include <string>
#include <vector>
//////////////////////////////

class Power_Grid
{
   private:
      // each max variable will describe the limits of their corresponding skill
      int intelligence_level;  //how quickly can the metahuman process information
      int strength_level;  //the maximum amount of weight the meta human can lift
      int speed_level;  //how fast the meta human can run
      int durability_level;  //how invulnerable is the meta human
      int EP_level;  //the level of the meta humans energy projection skills
      int fighting_level;  //how skilled is the meta human at combatives
      std::vector<std::string> powers; //methumans can have any number of powers and they can always change so we are making this a vector  
   public:
      Power_Grid();  //default constructor
      ~Power_Grid();  //default destructor
      int set_intelligence_level(int);
      int set_strength_level(int);
      int set_speed_level(int);
      int set_durability_level(int);
      int set_EP_level(int);
      int set_fighting_level(int);
      int get_intelligence_level() const {return intelligence_level;};
      int get_strength_level() const {return strength_level;};
      int get_speed_level() const {return speed_level;};
      int get_durability_level() const {return durability_level;};
      int get_EP_level() const {return EP_level;};
      int get_fighting_level() const {return fighting_level;};
      int add_power(std::string);
      int remove_power(int index);
      int print_stars(int) const;
      friend std::ostream& operator<<(std::ostream&, const Power_Grid&);
};
#endif
