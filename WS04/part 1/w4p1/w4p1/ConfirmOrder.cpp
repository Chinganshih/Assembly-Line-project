// ------------------------------------------------------
//Workshop 4 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#include "ConfirmOrder.h"
#include "Toy.h"
#include <iostream>
using namespace std;

namespace sdds {

	ConfirmOrder::ConfirmOrder()
	{
		toys = nullptr;
		count = 0;
	}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& o) {
		*this = o;
	}

	ConfirmOrder::ConfirmOrder(ConfirmOrder&& o) noexcept {
		*this = move(o);
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& o) {
		size_t i;
		if (this != &o)
		{
			delete[] toys;
			toys = new const Toy * [o.count];
			for ( i = 0; i < o.count; i++)
			{
				toys[i] = o.toys[i];
			}
			count = o.count;
		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& o)noexcept {
		size_t i;
		if (this != &o)
		{
			delete[] toys;
			toys = new const Toy * [o.count];
			for ( i = 0; i < o.count; i++)
			{
				toys[i] = o.toys[i];
			}
			count = o.count;
			o.count = 0;
		}
		return *this;
	}

	ConfirmOrder::~ConfirmOrder()
	{
		delete[] toys;
	}

	/*adds the toy toy to the array by adding its address.
	if the address of toy is already in the array, this operator does nothing
	resizes the array to make room for toy if necessary
	stores the address of toy in the array(your function should not make copies of the toy itself)*/
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		bool isExist = 0;
		size_t i;
		const Toy** temp;

		//if the address of toy is already in the array, this operator does nothing
		for ( i = 0; i < count; i++)
		{
			if (toys[i] == &toy) isExist = 1;
		}
		
		if (!isExist)
		{
			temp = new const Toy * [count + 1];
			temp[count] = &toy;
			for ( i = 0; i < count ; i++)
			{
				temp[i] = toys[i];
			}
			delete[] toys;
			toys = temp;
			count++;
		}

		return *this;
	}

	/*removes the toy toy from the array by removing its address
	if the address of toy is not in the array, this operator does nothing
	searches the array for the address of toy, sets the pointer in the array to nullptr if toy is found.To challenge yourself, try to actually resize the array.*/
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		bool isExist = 0;
		size_t i, found;
		const Toy** temp;
		
		//if the address of toy is already in the array, this operator does nothing
		for (i = 0; i < count; i++)
		{
			if (toys[i] == &toy) {
				isExist = 1;
				found = i;
				count--;
			}
		}

		if (isExist)
		{
			temp = new const Toy * [count];
			for ( i = 0; i < count; i++)
			{
				if (i >= found)
				{
					temp[i] = toys[i+1];
				}
				else temp[i] = toys[i];
			}
			delete[] toys;
			toys = temp;
		}
		return *this;
	}

	ostream& operator<<(ostream& ostr, const ConfirmOrder& o) {
		size_t i;

		ostr << "--------------------------" << endl;
		ostr << "Confirmations to Send" << endl;
		ostr << "--------------------------" << endl;

		if (o.count == 0)
		{
			ostr << "There are no confirmations to send!" << endl;
		}
		else
		{
			for ( i = 0; i < o.count; i++)
			{
				ostr << *o.toys[i];
			}
		}

		ostr << "--------------------------" << endl;

		return ostr;
	}
}