// ------------------------------------------------------
//Workshop 7 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------


#pragma once
#include <iostream>
#include <string>
#include <vector>
#ifndef COVIDCOLLECTION_H_
#define COVIDCOLLECTION_H_

namespace sdds {
	class CovidCollection
	{
		struct Covid
		{
			std::string country;
			std::string city;
			std::string variant;
			std::string year;
			int numberOfCases = 0;
			int numberOfDeaths = 0;
		};

		std::vector<Covid> m_covid;

	public:
		CovidCollection();
		~CovidCollection();
		CovidCollection(const char* fileName);
		void display(std::ostream& out) const;
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
		friend std::ostream& operator<<(std::ostream& out, const Covid& theCovid);

	};

	

}

#endif // !COVIDCOLLECTION_H_
