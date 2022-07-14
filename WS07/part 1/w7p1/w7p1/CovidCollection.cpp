// ------------------------------------------------------
//Workshop 7 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#include "CovidCollection.h"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <list>
#include <numeric>

using namespace std;
namespace sdds {
	CovidCollection::CovidCollection()
	{
	}

	CovidCollection::~CovidCollection()
	{
	}


	//a custom constructor that receives as a parameter the name of the file containing the information about the covid details of various cities to be added to the collection.
	//This function should load into the attributes all the covid details in the file.
	CovidCollection::CovidCollection(const char* fileName) {
		static int numberOfindex = 0;
		ifstream file(fileName);
		string str;

		if (!file)
		{
			throw string("Unable to open [") + fileName + "] file";
		}

		while (!file.eof())
		{

			getline(file, str);
			if (str != "")
			{
				m_covid.push_back(Covid());
				m_covid[numberOfindex].country = trim(str.substr(0, 25));
				m_covid[numberOfindex].city = trim(str.substr(25, 25));
				m_covid[numberOfindex].variant = trim(str.substr(50, 25));

				if (stoi(trim(str.substr(75, 5))) >= 2019)
				{
					m_covid[numberOfindex].year = trim(str.substr(75, 5));
				}
				m_covid[numberOfindex].numberOfCases = stoi(trim(str.substr(80, 5)));
				m_covid[numberOfindex].m_deaths = stoi(trim(str.substr(85, 5)));
				numberOfindex++;
			}

		}
	}

	//update this function to display the total casesand deaths of the entire collection.
	void CovidCollection::display(std::ostream& out) const {
		int totalCase, totalDeath;

		for_each(m_covid.begin(), m_covid.end(), [](Covid c){ cout << c << endl; });
		totalCase = accumulate(m_covid.begin(), m_covid.end(), 0, [](const int& result, const Covid& c) {return result + c.numberOfCases;});
		totalDeath = accumulate(m_covid.begin(), m_covid.end(), 0, [](const int& result, const Covid& c) {return result + c.m_deaths;});
		
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << std::setw(80) << right << "Total Cases Around the World:  " << totalCase << " |\n";
		out << "|" << std::setw(80) << right << "Total Deaths Around the World:  " << totalDeath << " |\n";
	}

	//receives as a parameter the name of the field used to sort the collection of covids in ascending order.
	//The parameter can have one of the values country, variant, cases or deaths.DO NOT USE MANUAL LOOPS!
	void CovidCollection::sort(const char* name) {
		string strname = name;
		if (strname == "country")
		{
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& c1, const Covid& c2) {
				return  c1.country < c2.country; });
		}
		else if (strname == "variant") {
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& c1, const Covid& c2) {
				return  c1.variant < c2.variant; });
		}
		else if (strname == "cases") {
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& c1, const Covid& c2) {
				return  c1.numberOfCases < c2.numberOfCases; });
		}
		else if (strname == "deaths")
		{
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& c1, const Covid& c2) {
				return  c1.m_deaths < c2.m_deaths; });
		}

	}


	//removes the token[None] from the variant field of the covids that do not have a valid variant
	void CovidCollection::cleanList() {
		
		transform(m_covid.begin(), m_covid.end(), m_covid.begin(), [](Covid& c) {
			(c.variant == "[None]") ? c.variant = "" : c.variant = c.variant;
			return c;
			});
	}

	//receives the name of a variant as a parameter, and returns true if the collection contains any city with that variant.
	bool CovidCollection::inCollection(const char* name) const {

		return (find_if(m_covid.begin(), m_covid.end(), [name](const Covid& c) { return c.variant == name; }) != m_covid.end()) ? true:  false;
	}

	
	ostream& operator<<(std::ostream& out, const CovidCollection::Covid& theCovid) {
		out << "| " << setw(20) << left << theCovid.country << "  | ";
		out << setw(15) << left << theCovid.city << " | ";
		out << setw(20) << left << theCovid.variant << " | ";
		out << setw(6) << right << theCovid.year << " | ";
		out << setw(4) << right << theCovid.numberOfCases << " | ";
		out << setw(3) << theCovid.m_deaths << " |";

		return out;
	}

	string CovidCollection::ltrim(const string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	string CovidCollection::rtrim(const string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	string CovidCollection::trim(const string& s) {
		return rtrim(ltrim(s));
	}
}