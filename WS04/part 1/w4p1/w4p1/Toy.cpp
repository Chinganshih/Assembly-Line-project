// ------------------------------------------------------
//Workshop 4 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include "Toy.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;

namespace sdds {

	Toy::Toy()
	{
		id = 0;
		name = nullptr;
		numItems = 0;
		price = 0.0;
		tax = 0.13;
	}

	Toy::Toy(const Toy& t) {
		*this = t;
	}

	Toy::Toy(Toy&& t) noexcept {
		*this = move(t);
	}

	Toy& Toy::operator=(const Toy& t) {
		if (this != &t)
		{
			delete[] name;
			alocpy(name, t.name);
			id = t.id;
			numItems = t.numItems;
			price = t.price;
			tax = t.tax;

		}
		return *this;
	}

	Toy& Toy::operator=(Toy&& t) noexcept {
		if (this != &t)
		{
			delete[] name;
			name = t.name;
			t.name = nullptr;
			id = t.id;
			numItems = t.numItems;
			price = t.price;
			tax = t.tax;
			t.id = 0;
			t.numItems = 0;
			t.price = 0;
			t.tax = 0;
		}
		return *this;
	}

	Toy::~Toy()
	{
		delete[] name;
	}

	string Toy::ltrim(const string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	string Toy::rtrim(const string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	string Toy::trim(const string& s) {
		return rtrim(ltrim(s));
	}

	Toy::Toy(const string& toy) {
		string str = toy;
		string str_id, str_name, str_num, str_price;
		int pos;

		//read ID
		pos = str.find(":");
		str_id = trim(str.substr(0, pos));
		id = stoi(str_id);
		str = str.substr(pos + 1);

		//read name
		pos = str.find(":");
		str_name = trim(str.substr(0, pos));
		alocpy(name, str_name.c_str());
		str = str.substr(pos + 1);

		//numItems
		pos = str.find(":");
		str_num = trim(str.substr(0, pos));
		numItems = stod(str_num);
		str = str.substr(pos + 1);

		//price
		pos = str.find(":");
		str_price = trim(str.substr(0, pos));
		price = stod(str_price);
	}

	//a modifier that receives as a parameter the number of toys of this type to be ordered and updates the number of items attribute with the received value.
	//Assume the parameter is correct and doesn't require validation.
	void Toy::update(int numItems) {
		this->numItems = numItems;
	}

	void Toy::alocpy(char*& destination, const char* source) {
		/*Safely allocates memory in destinationand copies the source into it.
		deletes the destination dynamic arrayand sets it to null
		if the source is not null
		Allocates memory in the destination to the size of the sourceand copies the source into it.*/

		if (source != nullptr)
		{
			destination = new char[strlen(source) + 1];
			strcpy(destination, source);
		}
		else {
			delete[] destination;
			destination = nullptr;
		}
	}

	ostream& operator<<(ostream& ostr, const Toy& t) {
		double totalPrice = t.numItems * t.price;
		
		ostr << "Toy" << setw(8) << t.id << ":";
		ostr << setw(18) << right << t.name;
		ostr << setw(3) << right << t.numItems << " items";;
		ostr << setw(8) << right << t.price << "/item  subtotal:";
		ostr << setw(7) << right << totalPrice << " tax:";
		ostr << setw(6) << setprecision(2) << fixed << right << totalPrice * t.tax << " total:";
		ostr << setw(7) << setprecision(2) << fixed << right << totalPrice * (1 + t.tax) << endl;

		return ostr;
	}

}