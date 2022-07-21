// Name: Ching-An, Shih
// Seneca Student ID: 148221195
// Seneca email: cshih9@myseneca.ca
// Date of completion: 2022/07/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef STATION_H_
#define STATION_H_
#include <string>
#include "Utilities.h"
namespace sdds {

	class Station : public Utilities
	{
		size_t id = 0; //the id of the station (integer)
		std::string name{}; //the name of the item handled by the station (string)
		std::string desc{}; //the description of the station (string)
		size_t m_serialNumber = 0;
		size_t next_serialNumber = 0; //the next serial number to be assigned to an item at this station
		size_t numberOfitem = 0; //the number of items currently in stock
		
		//the maximum number of characters required to print to the screen the item name for any object of type Station.Initial value is 0
		static size_t m_widthField;
		//a variable used to generate IDs for new instances of type Station.
		//Every time a new instance is created, the current value of the id_generator is stored in that instance, and id_generator is incremented.Initial value is 0.
		static size_t id_generator;
			
	public:
		Station();
		Station(const std::string& instr);
		~Station();
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getSerialNumber() const;
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};


}

#endif // !STATION_H_
