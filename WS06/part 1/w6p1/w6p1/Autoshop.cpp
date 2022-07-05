// ------------------------------------------------------
//Workshop 6 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#include "Autoshop.h"
#include <iostream>
#include <vector>
using namespace std;

namespace sdds {
	Autoshop::Autoshop()
	{
	}

	//This function should iterate over the objects stored in the vector, 
	//and delete each one of them(note that the first portion has a memory leak because the dynamically allocated vehicles were not deleted anywhere).
	Autoshop::~Autoshop()
	{
		for (Vehicle* car : m_vehicle)
		{
			delete car;
		}
		m_vehicle.clear();
	}

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicle.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		//error appeared -> Since display is const, you can use a const iterator
		//solution : add const_iterator instead of iterator
		vector<Vehicle*>::const_iterator i;

		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (i = m_vehicle.begin(); i != m_vehicle.end(); i++)
		{
			(*i)->display(out);
			out << endl;
		}

		out << "--------------------------------" << endl;
	}
}