// ------------------------------------------------------
//Workshop 6 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

namespace sdds {


	//This function should extract data from the parameter; if the first non - blank character is c or C, 
	//the this function should dynamically create an instance of type Car passing the stream to the constructor, 
	//and return it to the client.
	Vehicle* createInstance(std::istream& in) {
		Vehicle* car = nullptr;
		string str, tag;
		int pos;

		getline(in, str, '\n');
		stringstream sstr(str);

		//tag
		pos = str.find(",");
		tag = str.substr(0, pos);
		tag.erase(remove(tag.begin(), tag.end(), ' '),tag.end());
		sstr.seekg(0);

		

		if (tag == "c" || tag == "C")
		{
			car = new Car(sstr);
		}
		else if (tag == "r" || tag == "R") {
			car = new Racecar(sstr);
		}
		else {
			logic_error error("Unrecognized record type: [" + tag + "]");
			throw error;
		}

		return car;
	}
}