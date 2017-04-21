#ifndef CITY_H_
#define CITY_H_
#include <string>
#include <vector>
#include <fstream>
#include "Citizen.h"
using namespace std;




class City  ///Creates a city with a name and a number of citizens that were created with the Citizen class
{
private:   //set up a name for the city and a population for the city
	string cityname;
	vector<Citizen*> population;
	
public:

	City(string Cityname) //creates a city with a name. Restores population from a file.
	{
		cityname = Cityname;
		string FileName;
		string filename = "\\\\cs1\\2019\\morren19\\CS172-1\\Exams\\Exam 2\\CS172Exam 2\\";
		FileName = filename + cityname + "pop.txt";
		//below gets a population for the city
		ifstream infile(FileName);
		if (infile.is_open())
		{
			int Id;
			string Fname, Lname, FavCol;
			while (infile >> Id >> Fname >> Lname >> FavCol)
			{
				Citizen* citizen = new Citizen(Id, Fname, Lname, FavCol);
				population.push_back(citizen);
			}
		}
	}

	
	~City()  //DESTROYS THE CITY, but saves the citizens
	{
		string FileName;
		string filename = "\\\\cs1\\2019\\morren19\\CS172-1\\Exams\\Exam 2\\CS172Exam 2\\";
		FileName = filename + cityname + "pop.txt";
		ofstream outfile(FileName);
		if (outfile.is_open())
		{
			for (int y = 0; y < population.size(); y++)
			{
				outfile << population[y]->getid() << " "
					<< population[y]->getfirstname() << " "
					<< population[y]->getlastname() << " "
					<< population[y]->getfavcolor() << endl;

				delete population[y];
			}
		}
		else
		{
			for (int y = 0; y < population.size(); y++)
			{
				delete population[y];
			}
		}
	}


	string getcityname()  //returns city name
	{
		return cityname;
	}

	int populationSize()   //returns the size of this city's population
	{
		return population.size();
	}

	
	Citizen* getCitizenAtIndex(int index)   //Returns the citizen at the given index
	{
		if (index >= 0 && index < population.size())
		{
			return population[index];
		}
		else
		return NULL;
	}


	void addCitizen(Citizen* citizen)  //adds a citizen to the city
	{
		Citizen* c = new Citizen(citizen);
		population.push_back(citizen);
	}


	Citizen* getCitizenWithId(int ID)  //gets a citizen by its ID
	{
		for (int i = 0; i < population.size(); i++)
		{
			if (population[i]->getid() == ID)
			{
				return population[i];
			}
			else
				return NULL;
		}
	}


	
	vector<Citizen*> getCitizensForFavoriteColor(string Favcolor) /// returns all the citizens that have a certain favorite color
	{
		vector <Citizen*> FavColorPeeps;
		for (int x = 0; x < population.size(); x++)
		{
			if (population[x]->getfavcolor() == Favcolor)
			{
				FavColorPeeps.push_back(population[x]);
			}
			return FavColorPeeps;
		}
	}

};




















#endif //CITY_H_
