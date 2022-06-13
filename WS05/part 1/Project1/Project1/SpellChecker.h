// ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#pragma once
#ifndef SPELLCHECKER_H_
#define SPELLCHECKER_H_
#include <string>
#define maxWord 6

namespace sdds {

	class SpellChecker
	{
		//m_badWords: an array with 6 misspelled words	
		//m_goodWords : an array with the correct spelling of those 6 words
		std::string m_badWords[maxWord];
		std::string m_goodWords[maxWord];
		size_t replaceTimes[maxWord];
		size_t number = 0;

	public:
		SpellChecker();
		SpellChecker(const SpellChecker& c);
		SpellChecker& operator=(const SpellChecker& c);
		~SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& intext);
		void showStatistics(std::ostream& out) const;
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
	};
}

#endif // !SPELLCHECKER_H_
