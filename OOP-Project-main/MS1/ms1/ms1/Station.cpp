// Name: Ching-An, Shih
// Seneca Student ID: 148221195
// Seneca email: cshih9@myseneca.ca
// Date of completion: 2022/07/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {

	size_t Station::id_generator;
	size_t Station::m_widthField;

	Station::Station()
	{
	}

	Station::~Station()
	{
	}

	Station::Station(string& str) {

		string strserialNumber, strQuantity;
		size_t next_pos = 0;
		bool more = 1;

		//NAME
		name = Utilities::extractToken(str, next_pos = 0, more);
		str = str.substr(next_pos);
		
		//starting serial number
		strserialNumber = Utilities::extractToken(str, next_pos = 0 , more);
		m_serialNumber = stoi(strserialNumber);
		str = str.substr(next_pos);

		//quantity in stock
		strQuantity = Utilities::extractToken(str, next_pos = 0, more);
		numberOfitem = stoi(strQuantity);
		str = str.substr(next_pos);

		//before extracting description, it updates Station::m_widthField to the maximum value of Station::m_widthFieldand Utilities::m_widthField.
		if (Utilities::getFieldWidth() > m_widthField)
		{
			m_widthField = Utilities::getFieldWidth();
		}
		//description
		desc = Utilities::extractToken(str, next_pos =0, more);

		id_generator++;
		id = id_generator;
	}

	//returns the name of the current Station object
	const std::string& Station::getItemName() const {
		return name;
	}

	//returns the next serial number to be used on the assembly lineand increments m_serialNumber
	size_t Station::getNextSerialNumber() {
		
		return m_serialNumber++;
	}

	//returns the remaining quantity of items in the Station object
	size_t Station::getQuantity() const {
		return numberOfitem;
	}

	//subtracts 1 from the available quantity; should not drop below 0.
	void Station::updateQuantity() {
		if (numberOfitem -1 >=0) numberOfitem--;
	}

	void Station::display(std::ostream& os, bool full) const {
		//if the second parameter is false, this function inserts only the ID, name, and serial number in the format :
		//ID | NAME | SERIAL |

		os << setfill('0') << setw(3) << id << " | ";
		os << setfill(' ') << setw(m_widthField+1) << left <<  name << " | ";
		os << setfill('0') << setw(6) <<right << m_serialNumber << " | ";

		if (full)
		{
			//if the second parameter if true, this function inserts the information in the following format : 
			//ID | NAME | SERIAL | QUANTITY | DESCRIPTION
			os << setfill(' ') << setw(4) << right << numberOfitem << " | ";
			os << desc;
		}
		//this function terminates the printed message with an endline
		os << endl;

	}
}