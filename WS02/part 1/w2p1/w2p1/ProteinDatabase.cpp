// ------------------------------------------------------
//Workshop 2 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace sdds {

	//a no-argument default constructor
	ProteinDatabase::ProteinDatabase(){	}

	//a 1-argument constructor that receives as parameter a string containing the name of a file from which this member function populates the current object. 
	//This function
	//reads the file to count the number of protein sequence present in the file.
	//In the file, each protein sequence is prefixed by a line starting with a greater than character(">") followed by a description of the origin of the sequence of no more than 131 characters.
	//The protein sequence will begin on the next line for some number of lines.Each line(except the last one) will contain exactly 60 characters.
	//allocates memory for that number of protein sequences in the array
	//re-reads the file and loads the protein sequences(i.e., string of characters not sequence names) into the array.
	ProteinDatabase::ProteinDatabase(string fileName) {
		char c;
		string str;
		ifstream f(fileName);
		int count = 0, i = 0;

		if (f.is_open())
		{
			while (f.good()) {
				f.get(c);
				count++;
				if (c == '>') numberOfString++;
			}
			sequences = new string[numberOfString + 1];
		}
		f.clear();
		f.close();

		ifstream fp(fileName);
		fp.ignore();
		if (fp.is_open())
		{
			while (fp.good() && i < numberOfString)
			{
				getline(fp, str, '>');
				str = str.substr(str.find('\n') + 1);
				str.erase(remove(str.begin(), str.end(), '\n'), str.end());
				sequences[i] = str;
				i++;
			}
		}
		fp.close();
	}

	//Copy Constructor
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& p) {
		int i;
		numberOfString = p.numberOfString;

		for ( i = 0; i < numberOfString; i++)
		{
			delete[] sequences;
			sequences = new string[numberOfString + 1];
			if (p.sequences != nullptr)
			{
				for ( i = 0; i < numberOfString; i++)
				{
					sequences[i] = p.sequences[i];
				}
			}
			
		}
	}
	
	//Copy assignment
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& p) {
		int i;
		numberOfString = p.numberOfString;
			if (this != &p)
			{
				numberOfString = p.numberOfString;
				delete[] sequences;
				sequences = new string[numberOfString + 1];
				if (p.sequences != nullptr)
				{
					for (i = 0; i < numberOfString; i++)
					{
						sequences[i] = p.sequences[i];
					}
				}
			}
		
			return *this;
		}

	//Move Constructor
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& p) noexcept
	{
		*this = move(p);
	}

	//Move Assignment
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& p) noexcept {

		if (this != &p)
		{
			numberOfString = p.numberOfString;
			p.numberOfString = 0;

			delete[] sequences; // deallocate current resource
			sequences = p.sequences;  // copy address to current obje
			p.sequences = nullptr; // initialize source resource
		} 
		
		return *this;
	}

	//a query that returns the number of protein sequences stored in the current object.
	size_t ProteinDatabase::size() {

		return numberOfString;
	}

	//a query that returns a copy of the protein sequence at the index received as the function parameter.
	//If the index is invalid, this function should return an empty string.
	std::string ProteinDatabase::operator[](size_t index) {
		string stringQry;
		size_t number = numberOfString;

		if (index < number)
		{
			stringQry = sequences[index];
		}
		else stringQry = "";

		return stringQry;
	}

	//Deallocate sequence
	ProteinDatabase::~ProteinDatabase()
	{
		delete[] sequences;
	}
}
