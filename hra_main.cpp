//////////////////////////////////////////////////////////////////
//
// HERO REGISTRATION ACT
//
// Main .cpp file
// Project by: Evelyn Brown, Nicholas DiPinto, and Garrett Palmquist
// 
//
/////////////////////////////////
// Classes, Inclusions, etc.
/////////////////////////////////
using namespace std;
#include <iostream>
#include <string>
#include <unistd.h>
#include <sstream>  // allows use of istream, etc.
#include <vector>   // allows use of vector objects, etc.
#include <fstream>  // allows use of file input
#include "metahuman.hpp"
#include "hero.hpp"
#include "villain.hpp"
#include "mission.hpp"
#include "power_grid.hpp"
/////////////////////////////////
// Function Prototypes
/////////////////////////////////
int displayMenu();
int processMenuInput(char, vector<MetaHuman*>&, vector<Mission*>&);
int printMetaHumanVector(vector<MetaHuman*>&);
int printAllMissions(vector<Mission*>&);
int recommendMetaHumans(vector<MetaHuman*>&, Mission*&);
/////////////////////////////////
// Global variables
/////////////////////////////////
bool interactive = true;
bool exitFlag = false;

vector<MetaHuman*>::iterator  metaPtr;
vector<Mission*>::iterator missionPtr;      
/////////////////////////////////
// Main Function
int main()
{
	/////////////////
	// Variables
	char menuInput;

	vector<MetaHuman*> metaHumanPtrs;
	vector<Mission*> missionPtrs;
	metaPtr = metaHumanPtrs.begin();
	missionPtr = missionPtrs.begin();        
	/////////////////
	// Program body
	cout << endl;
	interactive = isatty(STDIN_FILENO); //can this be the argument for the if-loop?
	if(interactive) displayMenu();
 
  while (!exitFlag)
	{
		cout << endl << "Menu: ";
		cin >> menuInput;
  cin.ignore(1, '\n');
		processMenuInput(menuInput, metaHumanPtrs, missionPtrs);
	}
	cout << "Program end." << endl << endl;
	for(metaPtr = metaHumanPtrs.begin(); metaPtr != metaHumanPtrs.end(); metaPtr++)
		delete *metaPtr;
	return 0;
}

/////////////////////////////////
// Display Main Menu
int displayMenu()
{
	cout << "//////////////////////////////////////////////////////" << endl
	     << "//H  : Create a new Hero." << endl
       << "//V  : Create a new Villain." << endl
	     << "//P  : Create a new power and add it to a metahuman." << endl
	     << "//R  : Remove a power from a meta human." << endl
       << "//M  : Create a new mission." << endl
	     << "//A  : Assign a mission to a Hero." << endl
	     << "//U  : Update a meta human's power grid." << endl
	     << "//S  : Search through Meta Humans by name." << endl
	     << "//D  : Display all Heroes' information." << endl
	     << "//Q  : Quit the program." << endl
	     << "//////////////////////////////////////////////////////" << endl;
	return 0;
}

/////////////////////////////////
// Process Menu Input
int processMenuInput(char inputChar, vector<MetaHuman*>& mhpv, vector<Mission*>& mpv)
{

	switch(toupper(inputChar))
	{
		cout << endl;
		/////////////////
		// New Hero
		case 'H':
		{
			string newName, newSecretID, newGender, newRace, newWeakness, newOrigin, newLS, newCity;
			int newAge;
			MetaHuman* temp = new Hero();
			mhpv.push_back(temp);
			metaPtr = (mhpv.end() - 1);

			cout << "Enter the hero's name: ";
			getline(cin, newName);
			cout << "Enter the hero's secret identity: ";
			getline(cin, newSecretID);
			cout << "Enter the hero's gender: ";
			getline(cin, newGender);

			//////// Age entry using try/catch ////////
			// User is prompted to enter age. If age is
			// not an integer (i.e. a string) then the 
			// input fails and the user is prompted to
			// re-enter a valid input.
			bool intEntered = false;
			bool success;
			cin.exceptions(istream::failbit);
			do{
				try
				{
					cout << "Enter the hero's age: ";
					cin >> newAge;
					if (newAge)
						intEntered = true;
				}
				catch (ios_base::failure &fail)
				{
					success = false;
					cout << "Invalid entry -- please enter an integer." << endl;
					cin.clear();
					string tmp;
					getline(cin, tmp);
				}
			}while(intEntered == false);
			cin.ignore(1, '\n');

			cout << "Enter the hero's race: ";
			getline(cin, newRace);
			cout << "Enter the hero's weakness: ";
			getline(cin, newWeakness);
			cout << "Enter the hero's source of power: ";
			getline(cin, newOrigin);
			cout << "Is the hero alive or dead? : ";
			getline(cin, newLS);
			cout << "Enter the hero's city: ";
			getline(cin, newCity);

			(*metaPtr)->setName(newName);
 		  (*metaPtr)->setAlias(newSecretID);
			(*metaPtr)->setGender(newGender);
			(*metaPtr)->setAge(newAge);
			(*metaPtr)->setRace(newRace);
			(*metaPtr)->setVulnerability(newWeakness);
			(*metaPtr)->setOrigin(newOrigin);
			(*metaPtr)->setStatus("Hero");
			(static_cast<Hero*>(*metaPtr))->setLivingStatus(newLS);
			(static_cast<Hero*>(*metaPtr))->setCity(newCity);
        }
		break;

		/////////////////
		// New Villain
		case 'V':
		{
			string newName, newSecretID, newGender, newRace, newWeakness, newOrigin;
			int newAge;
			MetaHuman* temp = new Villain();
			mhpv.push_back(temp);
			metaPtr = (mhpv.end() - 1);

			cout << "Enter the villain's name: ";
			getline(cin, newName);
			cout << "Enter the villain's secret identity: ";
			getline(cin, newSecretID);
			cout << "Enter the villain's gender: ";
			getline(cin, newGender);

			//////// Age entry using try/catch ////////
			// User is prompted to enter age. If age is
			// not an integer (i.e. a string) then the 
			// input fails and the user is prompted to
			// re-enter a valid input.
			bool intEntered = false;
			bool success;
			cin.exceptions(istream::failbit);
			do{
				try
				{
					cout << "Enter the villain's age: ";
					cin >> newAge;
					if (newAge)
						intEntered = true;
				}
				catch (ios_base::failure &fail)
				{
					success = false;
					cout << "Invalid entry -- please enter an integer." << endl;
					cin.clear();
					string tmp;
					getline(cin, tmp);
				}
			}while(intEntered == false);
			cin.ignore(1, '\n');
			
			cout << "Enter the villain's race: ";
			getline(cin, newRace);
			cout << "Enter the villain's weakness: ";
			getline(cin, newWeakness);
			cout << "Enter the villain's source of power: ";
			getline(cin,newOrigin);

			(*metaPtr)->setName(newName);
			(*metaPtr)->setAlias(newSecretID);
			(*metaPtr)->setGender(newGender);
			(*metaPtr)->setAge(newAge);
			(*metaPtr)->setRace(newRace);
			(*metaPtr)->setVulnerability(newWeakness);
			(*metaPtr)->setOrigin(newOrigin);
			(*metaPtr)->setStatus("Villain");
   }
   break;

		/////////////////
		// New Power
		case 'P':
		{
      int listNum;
      string newPower;

			cout << "Who do you want to add a power to?" << endl;
      printMetaHumanVector(mhpv);
			cout << "Select the number of the meta human from the list above you want to add a power to: ";
      cin >> listNum;
			cin.ignore(1, '\n');
      (*metaPtr) = mhpv[listNum - 1];
			cout<< "Enter his/her new power: ";
      getline(cin, newPower);
      (*metaPtr)->addPower(newPower);                        
		}
		break;
		
		/////////////////
		//Remove a Power
		case 'R':
		{
			int listNum, powerNum;
      
			
			cout << "Who do you want to remove a power from?" << endl;
			printMetaHumanVector(mhpv);
			cout << "Select the number of the meta human from the list above you want to remove a power from: ";
			cin >> listNum;
			cin.ignore(1, '\n');
			cout << mhpv[listNum - 1]->getPowerGrid();
			cout << "Select the number of the power you want to remove: ";
			cin >> powerNum;
			cin.ignore(1, '\n');
      *metaPtr = mhpv[listNum - 1];
      (*metaPtr)->getPowerGrid().remove_power(powerNum);
      
		}
		break;
		/////////////////
		// New Mission
		case 'M':
		{
			string newName, newThreat, newLocation, newStatus, newSuccess;
			int newThreatLevel, newPeopleKilled;
			Mission* temp = new Mission();
			mpv.push_back(temp);
			missionPtr = (mpv.end() -1);

			cout << "Enter the name of the mission: ";
			getline(cin,newName);
			cout << "Enter the name of the threat associated with the mission: ";
			getline(cin,newThreat);
			cout << "Enter the level of danger for the mission: ";
			cin >> newThreatLevel;
			cin.ignore(1, '\n');
			cout << "Enter the location of the threat: ";
			getline(cin,newLocation);
			cout << "Enter the status of the mission: ";
			getline(cin,newStatus);
			cout << "Enter whether or not the mission has succeeded: ";
			getline(cin,newSuccess);
			cout << "Enter the number of people killed by the threat: ";
			cin >> newPeopleKilled;
			cin.ignore(1, '\n');

			(*missionPtr)->setMissionName(newName);
			(*missionPtr)->setThreatName(newThreat);
			(*missionPtr)->setThreatLevel(newThreatLevel);
			(*missionPtr)->setLocation(newLocation);
			(*missionPtr)->setStatus(newStatus);
			(*missionPtr)->setSuccess(newSuccess);
			(*missionPtr)->setPeopleKilled(newPeopleKilled);
      
      cout << **missionPtr;
		}
		break;

		/////////////////
		// Assignment
		case 'A':
		{
			int missionNum, mhNum;
			
			cout << "Here are the list of missions: " << endl;
			printAllMissions(mpv);
			cout << "Select the number from list above of the mission you would like to have assigned: ";
			cin >> missionNum;
			cin.ignore(1, '\n');
			cout << "Here are the meta humans that can handle this threat: " << endl;
			recommendMetaHumans(mhpv, mpv[missionNum - 1]);
			cout << "Enter the number of the meta human to take on the mission: ";
			cin >> mhNum;
			cin.ignore(1, '\n');	
			*metaPtr = mhpv[mhNum - 1];

			if((*metaPtr)->getStatus() != "hero" && (*metaPtr)->getStatus() != "Hero")//check if the metahuman is a hero  
				cout << "ERROR: This meta human cannot be assigned a mission because he/she not a hero." << endl;
      
      //check if the hero is alive
			else if((static_cast<Hero*>(*metaPtr))->getLivingStatus() == "dead" || (static_cast<Hero*>(*metaPtr))->getLivingStatus() == "Dead") 
				cout << "ERROR: This hero cannot be assigned a mission because he/she is dead." << endl;
			else
				(*metaPtr)->addMission(mpv[missionNum - 1]);
		}
		break;

		/////////////////
		//Update Power Grid
		case 'U':
		{
			int listNum, setInt, setStrength, setSpeed, setDurability, setEP, setFighting;
			
			cout << "Select which meta human's power grid you want to update: " << endl;
			printMetaHumanVector(mhpv);
			cout << "Select the number of the meta human from the list above: ";
			cin >> listNum;
			*metaPtr = mhpv[listNum - 1];

			cout << "Enter the new intelligence level: ";
			cin >> setInt;
			cin.ignore(1, '\n');
			cout << "Enter the new strength level: ";
			cin >> setStrength;
			cin.ignore(1, '\n');
			cout << "Enter the new speed level: ";
			cin >> setSpeed;
			cin.ignore(1, '\n');
			cout << "Enter the new durability level: ";
			cin >> setDurability;
			cin.ignore(1, '\n');
			cout << "Enter the new energy projection level: ";
			cin >> setEP;
			cin.ignore(1, '\n');
			cout << "Enter the new fighting level: ";
			cin >> setFighting;
			cin.ignore(1, '\n');
			(*metaPtr)->updatePowerGrid(setInt, setStrength, setSpeed, setDurability, setEP, setFighting);	
		}
		break;
		/////////////////
		// Search Heroes
		case 'S':
		{
			string searchName;
			
			metaPtr = mhpv.begin();
			cout << "Enter the name of the Meta Human: ";
			getline(cin,searchName);
			while(metaPtr != mhpv.end())
			{
			   if(searchName != (*metaPtr)->getName())
			   {    
			      metaPtr++;
			      continue;
			   }
			   else
			      break;
			}
			if(metaPtr == mhpv.end())
			   cout << "ERROR: There is no meta human in our records by that name." << endl;
			else if ((*metaPtr)->getStatus() == "Hero")
         cout << *(static_cast <Hero*> (*metaPtr));
      else if ((*metaPtr)->getStatus() == "Villain")          
            cout << *(static_cast <Villain*> (*metaPtr));
		}
		break;

		/////////////////
		// Display All Meta Humans
		case 'D':
		{
			for(metaPtr = mhpv.begin(); metaPtr != mhpv.end(); metaPtr++)
        {
          
        if ((*metaPtr)->getStatus() == "Hero")
          { 
            cout << *(static_cast <Hero*> (*metaPtr));
          }
        if ((*metaPtr)->getStatus() == "Villain")
          {            
            cout << *(static_cast <Villain*> (*metaPtr));
          }
        }
        
		}
		break;

		/////////////////
		// Quit
		case 'Q':
		{
			exitFlag = true;
		}
		break;

		/////////////////
		// Default
		default:
		{
			cout << "Invalid entry; please pick one of the following options: " << endl;
			displayMenu();
		}
		break;


	} // end switch
	return 0;
    }
	
    int printMetaHumanVector(vector<MetaHuman*>& mh)
    {
	    int listNum = 1;
      cout << "/////////////////////////////////////////////////////" << endl;
	    for(metaPtr = mh.begin(); metaPtr != mh.end(); metaPtr++)
	      {
		      cout<< listNum << ". " << (*metaPtr)->getName() <<endl;
		      listNum++;
	      }
      cout << "/////////////////////////////////////////////////////" << endl;
	    return 0;
    }
 
     int printAllMissions(vector<Mission*>& missionsRef)
     {
	     int listNum = 1;
       cout << "///////////////////////////////////////////////////////" << endl;
	     for(missionPtr = missionsRef.begin(); missionPtr != missionsRef.end(); missionPtr++)
	       {
		       cout << listNum << ". " << (*missionPtr)->getMissionName() << endl;
		       listNum++; 
	       }
	     cout << "///////////////////////////////////////////////////////" << endl;
	     return 0;
     }

     int recommendMetaHumans(vector<MetaHuman*>& mhv, Mission*& missionRef)
     {
	     double missionThreat;
	     int listNum = 1;
           
       //check if mission has a villain assigned as the threat
	     
	     if(((*metaPtr)->getName() == (missionRef->getThreatName()) && (metaPtr != mhv.end()))) 
	        missionThreat = (*metaPtr)->computeThreatLevel((*metaPtr)->getPowerGrid());
                 
	     else   //this mission's threat is either unknown or just a natural disaster, any hero can handle this threat
	       {
	         printMetaHumanVector(mhv);
	         return 0;
        }
	    cout << "/////////////////////////////////////////////" << endl;
         
	    for(metaPtr = mhv.begin(); metaPtr != mhv.end(); metaPtr++)
	      {
	        if(((*metaPtr)->getStatus() == "hero" || (*metaPtr)->getStatus() == "Hero") &&  
              (static_cast<Hero*>(*metaPtr))->getThreatLevel() >= static_cast<float>(missionThreat))
	          {
              cout << listNum << ". " << (*metaPtr)->getName() << endl;
	            listNum++;
            }
	        cout << "/////////////////////////////////////////////" << endl;
	        return 0;
        }
     }
