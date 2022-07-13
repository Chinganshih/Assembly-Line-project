// Name: Ching-An, Shih
// Seneca Student ID: 148221195
// Seneca email: cshih9@myseneca.ca
// Date of completion: 2022/07/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <stdexcept>
using namespace std;

namespace sdds {

	char Utilities::m_delimiter;

	Utilities::Utilities()
	{
	}

	Utilities::~Utilities()
	{
	}

	//sets the field width of the current object to the value of parameter newWidth
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	//returns the field width of the current object
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	//extracts a token from string str referred to by the first parameter.
	//Note: in this application, str represents a single line that has been read from an input file.
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		logic_error error("   ERROR: No token.");
		string copystr, token;
		int pos=0;

		//uses the delimiter to extract the next token from str starting at position next_pos.
		copystr = str.substr(next_pos);
		pos = copystr.find(m_delimiter);
		if(pos >= 0) pos += next_pos;

		//reports an exception if a delimiter is found at next_pos.
		if (pos == (int)next_pos)
		{
			more = false;
			throw error;
		}
		else
		{
			//If successful, return a copy of the extracted token found(without spaces at the beginning / end), 
			//update next_pos with the position of the next token, and set more to true (false otherwise).
			token = trim(copystr.substr(0, pos - next_pos));
			next_pos = pos + 1;
			(next_pos <=0 ) ? more = false : more = true;

			//updates the current object's m_widthField data member 
			//if its current value is less than the size of the token extracted.
			if (m_widthField < token.length())
			{
				m_widthField = token.length();
			}
		}
		
		return token;
	}

	// Here's the definition of the static function outside of the class.  
	//Note we don't use the static keyword here.
	//sets the delimiter for this class to the character received
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	//returns the delimiter for this class.
	char Utilities::getDelimiter() {
		return m_delimiter;
	}

	string Utilities::ltrim(const string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	string Utilities::rtrim(const string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	string Utilities::trim(const string& s) {
		return rtrim(ltrim(s));
	}


}