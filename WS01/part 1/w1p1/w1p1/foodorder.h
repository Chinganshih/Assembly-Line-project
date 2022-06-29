// ------------------------------------------------------
//Workshop 1 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------


#pragma once
#ifndef FOODORDER_H_
#define FOODORDER_H_
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {

	class FoodOrder
	{
	
	private:
		char name[10];
		char* desc{};
		double price;
		bool isDaily;
		void empty();

	public:
		FoodOrder();
		FoodOrder& operator=(const FoodOrder& f);
		FoodOrder(const FoodOrder& f);
		void clear();
		std::istream& read(std::istream& istr);
		void display()const;
		void extractChar(std::istream& istr, char ch) const;
		void alocpy(char*& destination, const char* source);
		~FoodOrder();
	};
	
}

#endif // !FOODORDER_H_

