// ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#include "SpellChecker.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

namespace sdds {
	SpellChecker::SpellChecker()
	{
		m_badWords[0] = '\0';
		m_goodWords[0] = '\0';
		replaceTimes[0] = 0;
		number = 0;
	}

	SpellChecker::SpellChecker(const SpellChecker& c) {
		*this = c;
	}

	SpellChecker& SpellChecker::operator=(const SpellChecker& c) {
		
		if (this != &c)
		{
			for (size_t i = 0; i < 6; i++) {
				replaceTimes[i] = c.replaceTimes[i];
				m_badWords[i] = c.m_badWords[i];
				m_goodWords[i] = c.m_goodWords[i];
			}
		}
		return *this;
	}

	SpellChecker::~SpellChecker()
	{
	}

	/*receives the address of a C - style null - terminated string that holds the name of the file that contains the misspelled words.
	If the file exists, this constructor loads its contents.
	If the file is missing, this constructor throws an exception of type const char*, 
	with the message Bad file name!.Each line in the file has the format BAD_WORD GOOD_WORD; 
	the two fields can be separated by any number of spaces.*/
	SpellChecker::SpellChecker(const char* filename) {
		logic_error error("Bad file name!");
		string word, badw, goodw;
		size_t pos;
		ifstream file(filename);

		
		if (!file)
		{
			throw error;
		}

		do
		{
			getline(file, word);
			
			//Bad word
			pos = word.find(" ", 0);
			badw = word.substr(0, pos);
			m_badWords[number] = badw;
			word = word.substr(pos + 1);


			//Good word
			pos = word.find("\n");
			goodw = trim(word.substr(0, pos));
			m_goodWords[number] = goodw;

			//replaceTimes
			replaceTimes[number] = 0;
			number++;

		} while (file && number <6);
		file.close();
	
	}

	/*this operator searches text and replaces any misspelled word with the correct version.
	It should also count how many times each misspelled word has been replaced.*/
	void SpellChecker::operator()(string& text) {
		
		size_t pos = 0;

		for (size_t i = 0; i < maxWord; i++)
		{
			int badLen = m_badWords[i].length();

			while (text.find(m_badWords[i]) != std::string::npos) {
				pos = text.find(m_badWords[i]);
				text.replace(pos, badLen, m_goodWords[i]);
				replaceTimes[i] ++;
			}
		}
	}

	/*inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance.
	The format of the output is : 
	BAD_WORD: CNT replacements<endl>*/
	void SpellChecker::showStatistics(ostream& out) const {
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < 6; i++)
		{
			out << setw(15) << right << m_badWords[i] << ": " << replaceTimes[i] << " replacements" << endl;
		}
		
	}

	std::string SpellChecker::ltrim(const std::string& s) {
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	std::string SpellChecker::rtrim(const std::string& s) {
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	std::string SpellChecker::trim(const std::string& s) {
		return rtrim(ltrim(s));
	}
}