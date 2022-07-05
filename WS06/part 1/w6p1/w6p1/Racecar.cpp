// ------------------------------------------------------
//Workshop 6 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include "Racecar.h"

using namespace std;

namespace sdds {

	Racecar::Racecar()
	{
		m_booster = 0.0;
	}

	Racecar::~Racecar()
	{
	}

	//calls the constructor from Car to build the subobject, 
	//and then it extracts the last field from the stream containing the booster bonus.
	//The input format for a racecar is TAG, MAKER, CONDITION, TOP_SPEED, BOOSTER
	Racecar::Racecar(istream& in):Car(in) {
		
		string booster;
	
		getline(in, booster, '\n');
		m_booster = stod(trim(booster));
		addBooster(m_booster);

	}

	//calls Car::display() to print the information about the car, 
	//and adds* at the end.The format should be | MAKER | CONDITION | TOP_SPEED | *
	void Racecar::display(std::ostream& out) const  {

		Car::display(out);
		if (m_booster > 0)
		{
			out << "*";
		}

	}

	//Returns the top speed of the car, including any booster effects.
	double Racecar::topSpeed() const {
		return Car::topSpeed();
	}
}