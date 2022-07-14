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
#include <algorithm>
#include <list>
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
			int m_deaths = 0;
			

		}covid;

		std::vector<Covid> m_covid;
		
	public:
		CovidCollection();
		~CovidCollection();
		CovidCollection(const char* fileName);
		void display(std::ostream& out) const;
		void sort(const char* name);
		void cleanList();
		bool inCollection(const char* name) const;
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
		friend std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
		
		std::list<Covid> getListForCountry(const char* country) const {
			std::list<Covid> newcovid;

			std::copy_if(m_covid.begin(), m_covid.end(), back_inserter(newcovid), [country](const Covid& c) { return c.country == country; });
		
			return newcovid;
		}

		std::list<Covid> getListForVariant(const char* variant) const {
			std::list<Covid> newcovid;
			
			std::copy_if(m_covid.begin(), m_covid.end(), back_inserter(newcovid), [variant](const Covid& c) { return c.variant == variant; });
			
			return newcovid;
		}
	};

}

#endif // !COVIDCOLLECTION_H_
