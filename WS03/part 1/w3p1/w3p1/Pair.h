// ------------------------------------------------------
//Workshop 3 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#pragma once
#ifndef PAIR_H
#define PAIR_H_
#include <string>

namespace sdds {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair() {};
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		Pair(const Pair& P);
		Pair& operator=(const Pair& P);
		friend bool operator==(const Pair& L, const Pair& R);
		friend unsigned operator-(const Pair& L, const Pair& R);
		friend std::ostream& operator<<(std::ostream& ostr, const Pair& P) ;
		
	};
	
	
}
#endif // !PAIR_H

