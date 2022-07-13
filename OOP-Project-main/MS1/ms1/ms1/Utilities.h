// Name: Ching-An, Shih
// Seneca Student ID: 148221195
// Seneca email: cshih9@myseneca.ca
// Date of completion: 2022/07/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#pragma once
#include <string>
#ifndef UTILITIES
#define UTILITIES

namespace sdds {

	

	class Utilities
	{
		size_t m_widthField = 1; //specifies the length of the token extracted; used for display purposes; default value is 1
		static char m_delimiter; //separates the tokens in any given std::string object.All Utilities objects in the system share the same delimiter.
	
	public:
		Utilities();
		~Utilities();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
	};

}

#endif // !UTILITIES
