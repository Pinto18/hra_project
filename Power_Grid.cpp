//Power_Grid.cpp -- Power Grid Class Implementation
//Nicholas DiPinto
//CS225 Group Assignment

#ifndef POWER_GRID_CPP_
#define POWER_GRID_CPP_

//Pre Processor Directives//////////////
#include <string>
#include <vector>
#include <iostream>
#include "power_grid.hpp"
///////////////////////////////////////

//Global Constants/////////////////////
const int DEF_INTELLIGENCE = 0;
const int DEF_STRENGTH = 0;
const int DEF_SPEED = 0;
const int DEF_DURABILITY = 0;
const int DEF_EP = 0;
const int DEF_FIGHTING = 0;
//////////////////////////////////////

//Constructor Methods/////////////////////
Power_Grid::Power_Grid() : intelligence_level(DEF_INTELLIGENCE), strength_level(DEF_STRENGTH), speed_level(DEF_SPEED),
                           durability_level(DEF_DURABILITY), EP_level(DEF_EP), fighting_level(DEF_FIGHTING)
{
}
/////////////////////////////////////////

//Destructor Methods ////////////////////
Power_Grid::~Power_Grid()
{
}
///////////////////////////////////////

//Modifier Methods ///////////////////
int Power_Grid::set_intelligence_level(int intelligence_ranking)
{
   this->intelligence_level = intelligence_ranking;
   return 0;
}
int Power_Grid::set_strength_level(int strength_ranking)
{
   this->strength_level = strength_ranking;
   return -0;
}
int Power_Grid::set_speed_level(int speed_rating)
{
   this->speed_level = speed_rating;
   return 0;
}
int Power_Grid::set_durability_level(int durability_rating)
{
   this->durability_level = durability_rating;
   return 0;
}
int Power_Grid::set_EP_level(int EP_ranking)
{
   this->EP_level = EP_ranking;
   return 0;
}
int Power_Grid::set_fighting_level(int combatives_rating)
{
   this->fighting_level = combatives_rating;
   return 0;
}
/////////////////////////////////////

//Other Functions //////////////////
int Power_Grid::add_power(std::string new_power)
{
   powers.reserve(powers.size() + 1);
   this->powers.push_back(new_power);
   return 0;
}

int Power_Grid::remove_power(int index)
{
   std::string temp = powers[powers.size() - 1];  // temporarily create a copy of the last element of the powers vector
   powers[powers.size() - 1] = powers[index - 1]; // place the power to be removed at the end of the vector
   powers[index - 1] = temp;                      // put the temp variable back into the powers vector
   powers.resize(powers.size() - 1);              // resize function will remove the last element, power to be deleted, from the vector
   return 0;
}

int Power_Grid::print_stars(int power_ranking) const
{
   for(int num_stars = 0; num_stars < 7; num_stars++)  //for loop will add in blank spaces where stars would be if a meta human does not max out on a category in the power grid
   {  
      if(num_stars < power_ranking)
         std::cout<<"*|";
      else 
         std::cout<<" |";
   } 
   return 0;
}
///////////////////////////////////

//Friend Functions ///////////////
std::ostream& operator<<(std::ostream& outs, const Power_Grid& grid)
{
   outs<<std::endl
       <<"Known Powers: "<<std::endl;
   for(int index = 0; index < grid.powers.size(); index++)
      outs<<(index + 1)<<". "<<grid.powers[index]<<std::endl;

   outs<<std::endl
       <<"====================================="<<std::endl
       <<"|   POWER GRID        |1|2|3|4|5|6|7|"<<std::endl
       <<"====================================="<<std::endl
       <<"|Intelligence("<<grid.get_intelligence_level()<<")      |"; 
          grid.print_stars(grid.intelligence_level); 
          outs<<std::endl
       <<"====================================="<<std::endl
       <<"|Strength("<<grid.get_strength_level()<<")          |"; 
          grid.print_stars(grid.strength_level);
          outs<<std::endl
       <<"====================================="<<std::endl
       <<"|Speed("<<grid.get_speed_level()<<")             |"; 
          grid.print_stars(grid.speed_level);
          outs<<std::endl
       <<"====================================="<<std::endl
       <<"|Durability("<<grid.get_durability_level()<<")        |"; 
          grid.print_stars(grid.durability_level);
          outs<<std::endl
       <<"====================================="<<std::endl
       <<"|Energy Projection("<<grid.get_EP_level()<<") |"; 
           grid.print_stars(grid.EP_level);
           outs<<std::endl
       <<"====================================="<<std::endl
       <<"|Fighting Skills("<<grid.get_fighting_level()<<")   |"; 
          grid.print_stars(grid.fighting_level);
          outs<<std::endl
       <<"====================================="<<std::endl;
   return outs;    
}
/////////////////////////////////
#endif
