// ------------------------------------------------------
//Workshop 4 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------
#include "Child.h"
#include <string>
#include <iostream>
#include "Toy.h"
using namespace std;

namespace sdds {

	Child::Child()
	{
		name[0] = '\0';
		age = 0;
		count = 0;
		toys = nullptr;
	}

	Child::Child(const Child& c) {
		*this = c;
	}

	Child::Child(Child&& c) noexcept {
		*this = move(c);
	}

	Child& Child::operator=(const Child& c) {
		size_t i;

		if (this != &c)
		{
			for (i = 0; i < count; i++)
			{
				delete toys[i];
			}
			delete[] toys;
			toys = new const Toy * [c.count];

			for (i = 0; i < c.count; i++)
			{
				toys[i] = new Toy(*c.toys[i]);
			}
			
			count = c.count;
			age = c.age;
			name = c.name;
		}
		return *this;
	}

	Child& Child::operator=(Child&& c) noexcept {
		size_t i;

		if (this != &c)
		{
			delete[] toys;
			toys = new const Toy * [c.count];
			for (i = 0; i < c.count; i++)
			{
				toys[i] = c.toys[i];
				c.toys[i] = nullptr;
			}
			age = c.age;
			count = c.count;
			name = c.name;
			c.age = 0;
			c.count = 0;
			c.name = '\0';
			
		}

		return *this;
	}

	Child::~Child()
	{
		size_t i;
		for (i = 0; i < count; i++)
		{
			delete toys[i];
		}
		delete[] toys;
	}

	//a constructor that receives as a parameter a nameand an age, and an array of pointers to objects of type Toy(i.e., each element of the array is a pointer).
	Child::Child(string name, int age, const Toy* intoys[], size_t count) {
		size_t i;

		if (name[0] != '\0')
		{
			for (i = 0; i < this->count; i++)
			{
				delete toys[i];
			}
			delete[] toys;
			toys = new const Toy * [count];
			for (i = 0; i < count; i++)
			{
				toys[i] = new Toy(*intoys[i]);
			}
			this->name = name;
			this->age = age;
			this->count = count;
		}

	}

	//a query that returns the number of toys stored in the array attribute.
	size_t Child::size() const {
		return count;
	}

	ostream& operator<<(ostream& ostr, const Child& c) {
		size_t i;
		static int times = 0;
		times++;

		ostr << "--------------------------" << endl;


		if (c.count == 0)
		{
			ostr << "Child " << times << ":  0 years old:" << endl;
			ostr << "--------------------------" << endl;
			ostr << "This child has no toys!" << endl;
		}
		else {
			ostr << "Child " << times << ": " << c.name << " " << c.age << " years old:" << endl;
			ostr << "--------------------------" << endl;
			for (i = 0; i < c.count; i++)
			{
				ostr << *c.toys[i];
			}
		}

		ostr << "--------------------------" << endl;
		return ostr;
	}
}
