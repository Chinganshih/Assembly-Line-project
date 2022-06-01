// ------------------------------------------------------
//Workshop 3 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#pragma once

#ifndef Collection_H_
#define Collection_H_
#include <iostream>
#include "Pair.h"

namespace sdds {

	//T: the type of any element in the collection
	//CAPACITY : the capacity of the collection(a non - type parameter; an integer without sign).
	//This is the maximum number of elements that can be added to the collection
	template <typename T, size_t capacity>
	class Collection
	{
		T m_obj[capacity]{};
		size_t currentNumber{ 0 };
		T dummy;

	public:
		//Constructor
		Collection<T, capacity>() {};
		
		//Copy Constructor
		Collection<T, capacity>(const Collection<T, capacity>& C) {
			currentNumber = C.currentNumber;
			for (unsigned i = 0; i < currentNumber; i++) m_obj[i] = C.m_obj[i];
		}

		//Copy Assignment
		Collection<T, capacity>& operator=(const Collection<T, capacity>& C) {
		
			if (C.currentNumber && this != &C){
				currentNumber = C.currentNumber;
				for (unsigned i = 0; i < currentNumber; i++) m_obj[i] = C.m_obj[i];
			}
			return *this;
		}

		//Destructor
		virtual ~Collection() {};

		//a query that returns the current number of elements in the collection
		size_t size()const { return currentNumber; };

		//display() : a query that receives as the parameter an output stream(with default value std::cout) 
		//and inserts into the stream all items from the collection(see the sample output for formatting hints).
		void display(std::ostream& ostr = std::cout) const{
			ostr << "----------------------" << std::endl;
			ostr << "| Collection Content |" << std::endl;
			ostr << "----------------------" << std::endl;
			for (unsigned i = 0; i < currentNumber; i++)
			{
				ostr << m_obj[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
		}

		

		//mutator that adds a copy of the parameter to the collection if there still is capacity.
		//If the item has been added, this function return true; false otherwise.
		virtual bool add(const T& item) {
			bool isAdded = 0;

			if (currentNumber <  capacity)
			{
				m_obj[currentNumber] = item;
				currentNumber++;
				isAdded = 1;
			}
			return isAdded;
		}

		//a query that receives an index as parameterand returns a copy of the element stored in the collection at the specified index.
		//If the index is not valid(outside the boundaries of the collection), this query returns the dummy object.
		T& operator[](unsigned i)  { return (i > capacity) ? dummy : m_obj[i]; }
		
	};
	
	template <> 
	class Collection<Pair, 100>
	{
		Pair m_obj[100]{};
		size_t currentNumber{ 0 };
		static Pair dummy;
	public:
		//Constructor
		Collection() {};

		//Copy Constructor
		Collection(const Collection<Pair, 100>& C) {
			currentNumber = C.currentNumber;
			for (unsigned i = 0; i < currentNumber; i++) m_obj[i] = C.m_obj[i];
		}

		//Copy Assignment
		Collection<Pair, 100>& operator=(const Collection<Pair, 100>& C) {

			if (C.currentNumber && this != &C) {
				currentNumber = C.currentNumber;
				for (unsigned i = 0; i < currentNumber; i++) m_obj[i] = C.m_obj[i];
			}
			return *this;
		}

		//Destructor
		virtual ~Collection() {};

		//a query that returns the current number of elements in the collection
		size_t size()const { return currentNumber; };

		//display() : a query that receives as the parameter an output stream(with default value std::cout) 
		//and inserts into the stream all items from the collection(see the sample output for formatting hints).
		void display(std::ostream& ostr = std::cout) const {
			ostr << "----------------------" << std::endl;
			ostr << "| Collection Content |" << std::endl;
			ostr << "----------------------" << std::endl;
			for (unsigned i = 0; i < currentNumber; i++)
			{
				ostr << m_obj[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
		}

		//mutator that adds a copy of the parameter to the collection if there still is capacity.
		//If the item has been added, this function return true; false otherwise.
		virtual bool add(const Pair& item) {
			bool isAdded = 0;

			if (currentNumber < 100)
			{
				m_obj[currentNumber] = item;
				currentNumber++;
				isAdded = 1;
			}
			return isAdded;
		}

		//a query that receives an index as parameterand returns a copy of the element stored in the collection at the specified index.
		//If the index is not valid(outside the boundaries of the collection), this query returns the dummy object.
		Pair& operator[](unsigned i){ 
			return (i > currentNumber) ? dummy : m_obj[i]; 
		}

	};
	Pair Collection<Pair, 100>::dummy = Pair("No Key", "No Value");
	
}

#endif // !Collection_H_


