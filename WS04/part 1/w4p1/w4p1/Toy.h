// ------------------------------------------------------
//Workshop 4 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------


#pragma once
#include <string>
#ifndef TOY_H_
#define TOY_H_

namespace sdds {
	class Toy
	{
		int id = 0;
		char* name{};
		int numItems = 0;
		double price = 0.0;
		double tax = 0.13;

	public:
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);
		void alocpy(char*& destination, const char* source);
		Toy();
		Toy(const Toy& t);
		Toy(Toy&& t) noexcept;
		Toy& operator=(const Toy& t);
		Toy& operator=(Toy&& t) noexcept;
		~Toy();
		Toy(const std::string& toy);
		void update(int numItems);
		friend std::ostream& operator<<(std::ostream& ostr, const Toy& t);

	};

	
}

#endif // !TOY_H_
