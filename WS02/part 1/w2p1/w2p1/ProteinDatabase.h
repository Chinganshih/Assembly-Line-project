// ------------------------------------------------------
//Workshop 2 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#pragma once
#include <string>
#ifndef PROTEINDATABASE_H_
#define PROTEINDATABASE_H_

namespace sdds {

	class ProteinDatabase
	{
		int numberOfString = 0;
		std::string* sequences = nullptr;
		
	public:
		ProteinDatabase();
		ProteinDatabase(std::string fileName);
		ProteinDatabase(const ProteinDatabase& p);
		ProteinDatabase& operator=(const ProteinDatabase& p);
		//move-constructor
		ProteinDatabase(ProteinDatabase&& p) noexcept;
		//move-assignment
		ProteinDatabase& operator=(ProteinDatabase&& p) noexcept;
		size_t size();
		std::string operator[](size_t index);
		~ProteinDatabase();

	};

	
}

#endif // !PROTEINDATABASE_H_
