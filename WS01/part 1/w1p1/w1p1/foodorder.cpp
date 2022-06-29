// ------------------------------------------------------
//Workshop 1 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "foodorder.h"
#include <iomanip>
using namespace std;

double g_taxrate = 0;
double g_dailydiscount = 0;

namespace sdds {

	void FoodOrder::empty() {
		name[0] = '\0';
		desc = nullptr;
		price = 0;
		isDaily = 0;
	}

	FoodOrder::FoodOrder()
	{
		empty();
	}

	FoodOrder::FoodOrder(const FoodOrder& f) :desc(nullptr) {
		int i;
		for (i = 0; f.name[i] != '\0'; i++) name[i] = f.name[i];
		name[i] = '\0';
		delete[] desc;
		alocpy(desc, f.desc);
		price = f.price;
		isDaily = f.isDaily;
	}

	FoodOrder& FoodOrder::operator=(const FoodOrder& f) {
		int i;
		if (this != &f)
		{
			for (i = 0; f.name[i] != '\0'; i++) name[i] = f.name[i];
			name[i] = '\0';
			delete[] desc;
			alocpy(desc, f.desc);
			price = f.price;
			isDaily = f.isDaily;
		}
		else desc = nullptr;

		return *this;
	}

	FoodOrder::~FoodOrder()
	{
		delete[] desc;
		desc = nullptr;
	}

	void FoodOrder::clear() {
		delete[] desc;
		desc = nullptr;
	}

	istream& FoodOrder::read(istream& istr) {
		int i;
		char inName[10], inDaily;
		string inDesc;
		clear();

		if (istr.good())
		{
			istr.get(inName, 1000, ',');
			for (i = 0; inName[i] != '\0'; i++) name[i] = inName[i];
			name[i] = '\0';
			extractChar(istr, ',');
			if (inName[0] != '\0')
			{
				getline(istr, inDesc, ',');
				alocpy(desc, inDesc.c_str());
				istr >> price;
				extractChar(istr, ',');
				istr >> inDaily;
				if (inDaily == 'Y')
				{
					isDaily = 1;
				}
				else isDaily = 0;
			}

		}
		return istr;
	}

	void FoodOrder::display()const {
		static int counter = 0;
		counter++;
		if (name[0] != '\0')
		{

			cout << left << setw(2) << counter << ". ";
			cout << setw(10) << left << name << "|";
			cout << setw(25) << left << desc << "|";
			cout << setw(12) << fixed << setprecision(2) << left << price * (1 + g_taxrate) << "|";
			if (isDaily == 1)
			{
				cout << setw(13) << right << fixed << setprecision(2) << price * (1 + g_taxrate) - g_dailydiscount << endl;
			}
			else cout << setw(13) << right << endl;

		}
		else cout << counter << ". No Order" << endl;

	}

	istream& operator>>(istream& istr, FoodOrder& f) {
		return f.read(istr);
	}

	void FoodOrder::extractChar(istream& istr, char ch)const {

		if (istr.peek() == ch)
		{
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	void FoodOrder::alocpy(char*& destination, const char* source) {
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

}