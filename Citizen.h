#ifndef CITIZEN_H_
#define CITIZEN_H_
#include <string>
using namespace std;




class Citizen   //creates a citizen with a name, id, and favorite color
{
private:  //creates a name, an id, and a favorite color for a citizen
	string firstname;
	string lastname;
	int id;
	string favcolor;
public:
	Citizen(int ID, string Firstname, string Lastname, string FavColor)   //constructor that creates a citizen with a name, id and favorite color
	{
		firstname = Firstname;
		lastname = Lastname;
		id = ID;
		favcolor = FavColor;
	}

	Citizen(Citizen* citizen)   //creates a new citizen by copying data from a passed in citizen
	{
		if (citizen != NULL)
		{
			firstname = citizen->getfirstname();
			lastname = citizen->getlastname();
			id = citizen->getid();
			favcolor = citizen->getfavcolor();
		}
	}


	string getfirstname()   //returns a citizen's first name
	{
		return firstname;
	}
	string getlastname()  //returns a citizen's last name
	{
		return lastname;
	}


	int getid()   //returns a citizens id
	{
		return id;
	}


	void setfavcolor(string FavColor)   //allows user to enter a favorite color for a citizen
	{
		favcolor = FavColor;
	}
	string getfavcolor()  //allows user to retreive the favorite color of a citizen
	{
		return favcolor;
	}


};







#endif //CITIZEN_H_