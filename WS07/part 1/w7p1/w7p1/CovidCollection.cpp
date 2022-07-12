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
				m_covid[numberOfindex].numberOfDeaths = stoi(trim(str.substr(85, 5)));
				numberOfindex++;
			}
			
		}
	}

	void CovidCollection::display(std::ostream& out) const {
		for_each(m_covid.begin(), m_covid.end(), [](Covid c)
		{
			cout << c;
		});
	}

	ostream& operator<<(std::ostream& out, const CovidCollection::Covid& theCovid) {
		out << "| " << setw(20) << left << theCovid.country << "  | ";
		out << setw(15) << left << theCovid.city << " | ";
		out << setw(20) << left << theCovid.variant << " | ";
		out << setw(6) << right << theCovid.year << " | ";
		out << setw(4) << right << theCovid.numberOfCases << " | ";
		out << setw(3) << theCovid.numberOfDeaths << " |" << endl;

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