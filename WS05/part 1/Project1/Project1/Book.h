// ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#pragma once
#ifndef BOOK_H_
#define BOOK_H_

#include <string>

namespace sdds {
	class Book
	{

		std::string author{};
		std::string bookTitle{};
		std::string bookCountry{};
		size_t bookYear = 0;
		double bookPrice = 0.0;
		std::string desc{};

	public:
		Book();
		Book(const Book& b);
		Book& operator=(const Book& b);
		~Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& b);

		//void fixSpelling(T& spellChecker) : 
		//this function calls the overloaded operator() on the instance spellChecker, passing to it the book description.
		//ASSUMPTION : In this design, type T must have an overload of the operator() that accepts a string as a parameter.
		template <typename T> void fixSpelling(T& spellChecker) {
			spellChecker(desc);
		}
	};

	
}
#endif // !BOOK_H_