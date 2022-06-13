// ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#pragma once
#ifndef MOVIE_H_
#define MOVIE_H_
#include <string>

namespace sdds {
	class Movie
	{
		std::string mtitle{};
		size_t myear;
		std::string mdesc{};

	public:
		Movie();
		Movie(const Movie& m);
		Movie& operator=(const Movie& m);
		~Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& m);
		template <typename T> void fixSpelling(T& spellChecker) {
			spellChecker(mdesc);
			spellChecker(mtitle);
		}
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
	};

	
}

#endif // !MOVIE_H_
