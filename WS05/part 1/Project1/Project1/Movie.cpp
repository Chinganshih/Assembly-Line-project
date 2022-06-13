// ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#include "Movie.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

namespace sdds {
	Movie::Movie()
	{
		mtitle[0] = '\0';
		myear = 0;
		mdesc[0] = '\0';
	}

	Movie::Movie(const Movie& m) {
		*this = m;
	}

	Movie& Movie::operator=(const Movie& m) {
		if (this != &m)
		{
			mtitle = m.mtitle;
			myear = m.myear;
			mdesc = m.mdesc;
		}
		return *this;
	}

	Movie::~Movie()
	{
	}

	//a query that returns the title of the mo
	const string& Movie::title() const {
		return mtitle;
	}

	//receives the movie through a reference to a string.This constructor extracts the information about the movie from the stringand stores the tokens in the attributes.
	//The received string always has the following format :
	//TITLE, YEAR, DESCRIPTION
	Movie::Movie(const string& strMovie) {
		string str = strMovie;
		string title, year, desc;
		size_t pos;

		//read Title
		pos = str.find(",");
		title = trim(str.substr(0, pos));
		mtitle = title;
		str = str.substr(pos + 1);

		//read Year
		pos = str.find(",");
		year = trim(str.substr(0, pos));
		myear = stoi(year);
		str = str.substr(pos + 1);

		//read Description
		pos = str.find("\n");
		desc = trim(str.substr(0, pos));
		mdesc = desc;
	}

	//overload the insertion operator to insert the content of a movie object into an ostream object, in the following format :
	//TITLE | YEAR | DESCRIPTION
	//the title printed on a field of size 40;
	//the year printed on a field of size 4;
	ostream& operator<<(ostream& ostr, const Movie& m) {
		ostr << setw(40) << right << m.mtitle << " | ";
		ostr << setw(4) << m.myear << " | ";
		ostr << m.mdesc << endl;
		return ostr;
	}

	std::string Movie::ltrim(const std::string& s) {
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	std::string Movie::rtrim(const std::string& s) {
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	std::string Movie::trim(const std::string& s) {
		return rtrim(ltrim(s));
	}
}