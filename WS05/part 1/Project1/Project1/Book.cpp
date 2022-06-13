// ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#include "Book.h"
#include <istream>
#include <iomanip>

using namespace std;

namespace sdds {

	Book::Book()
	{
		author[0] = '\0';
		bookTitle[0] = '\0';
		bookCountry[0] = '\0';
		bookYear = 0;
		bookPrice = 0.0;
		desc[0] = '\0';
	}

	Book::Book(const Book& b) {
		*this = b;
	}

	Book& Book::operator=(const Book& b) {
		
		if (this != &b)
		{
			author = b.author;
			bookTitle = b.bookTitle;
			bookCountry = b.bookCountry;
			bookYear = b.bookYear;
			bookPrice = b.bookPrice;
			desc = b.desc;
		}
		return *this;
	}

	Book::~Book()
	{
	}

	//a query that returns the title of the book
	const std::string& Book::title() const {
		return bookTitle;
	}

	//a query that returns the publication country
	const std::string& Book::country() const {
		return bookCountry;
	}

	//a query that returns the publication year
	const size_t& Book::year() const {
		return bookYear;
	}

	//a function that returns the price by reference, allowing the client code to update the price
	double& Book::price() {
		return bookPrice;
	}

	std::string Book::ltrim(const std::string& s) {
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	std::string Book::rtrim(const std::string& s) {
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	std::string Book::trim(const std::string& s) {
		return rtrim(ltrim(s));
	}

	//a constructor that receives a reference to an unmodifiable string that contains information about the book; 
	//this constructor extracts the information about the book from the string by parsing itand stores the tokens in the object's attributes. 
	//The string always has the following format:
	//AUTHOR, TITLE, COUNTRY, PRICE, YEAR, DESCRIPTION
	Book::Book(const std::string& strBook) {
		string str = strBook;
		string str_author, str_title, str_country, str_year, str_price, str_desc;
		size_t pos=0;

		//read author
		pos = str.find(",");
		str_author = trim(str.substr(0, pos));
		author = str_author;
		str = str.substr(pos + 1);

		//read title
		pos = str.find(",");
		str_title = trim(str.substr(0, pos));
		bookTitle = str_title;
		str = str.substr(pos + 1);

		//read country
		pos = str.find(",");
		str_country = trim(str.substr(0, pos));
		bookCountry = str_country;
		str = str.substr(pos + 1);

		//read price
		pos = str.find(",");
		str_price = trim(str.substr(0, pos));
		bookPrice = stod(str_price);
		str = str.substr(pos + 1);

		//read year
		pos = str.find(",");
		str_year = trim(str.substr(0, pos));
		bookYear = stoi(str_year);
		str = str.substr(pos + 1);

		//read description
		pos = str.find("\n");
		str_desc = trim(str.substr(0, pos));
		desc = str_desc;

	}

	/*overload the insertion operator to insert the content of a book object into an ostream object, in the following format:
	AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION
	the author printed on a field of size 20;
	the title printed on a field of size 22;
	the country printed on a field of size 5;
	the year printed on a field of size 4;
	the price printed on a field of size 6, with 2 decimal digits;
	see alignment in the sample output.*/
	ostream& operator<<(ostream& ostr, const Book& b) {
		
		ostr << setw(20) << right << b.author << " | ";
		ostr << setw(22) << right << b.bookTitle << " | ";
		ostr << setw(5) << right << b.bookCountry << " | ";
		ostr << setw(4) << right << b.bookYear << " | ";
		ostr << setw(6) << setprecision(2) << fixed << right << b.bookPrice << " | ";
		ostr << b.desc << endl;

		return ostr;
	}
}