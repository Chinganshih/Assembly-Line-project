// ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#pragma once
#ifndef COLLECTION_H_
#define COLLECTION_H_
#include "Book.h"
#include "Movie.h"
#include <string>

namespace sdds {

	template <typename T>
	class Collection
	{
		std::string cname{};
		T* citems{};
		size_t csize;
		void (*observer)(const Collection<T>&, const T&) {};
	
	public:
		Collection() {};
		Collection(const std::string& name) {
			//sets the name of the collection to the string referred to by the parameterand sets all other attributes to their default value
			this->cname = name;
			csize = 0;
			citems = nullptr;
		}
		~Collection() { delete[] citems; };
		
		const std::string& name() const {
			//a query that returns the name of the collection.
			return cname;
		}; 
		
		size_t size() const {
			//a query that returns the number of items in the collection.
			return csize; 
		} 

		void setObserver(void (*inobserver)(const Collection<T>& , const T&)) {
		/*stores the address of the callback function(observer) into an attribute.
		This parameter is a pointer to a function that returns void and accepts two parameters :
		a collection and an item that has just been added to the collection.
		This function is called when an item is added to the collection.*/
			observer = inobserver;
		}

		/*adds a copy of item to the collection, only if the collection doesn't contain an item with the same title. If item is already in the collection, this function does nothing. If the item is not yet in the collection, this function:
		resizes the array of items to accommodate the new item
		if an observer has been registered, this operator calls the observer function passing the current object(*this) and the new item as arguments.
		*/
		Collection<T>& operator+=(const T& item) {
			bool isExisted = 0;
			T* temp;
			for (size_t i = 0; i < csize; i++)
			{
				if (citems[i].title() == item.title())
				{
					isExisted = 1;
				}
			}

			if (!isExisted)
			{
				temp = new T [csize + 1];
				temp[csize] = item;
				for (size_t i = 0; i < csize; i++)
				{
					temp[i] = citems[i];
				}
				delete[] citems;
				citems = temp;
				csize++;

				if (observer != nullptr) observer(*this, item);
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			//if the index is out of range, this operator throws an exception of type std::out_of_range with the message Bad index[IDX].Collection has[SIZE] items..
			//Use operator + to concatenate strings.
			if (idx >= csize)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(csize) + "] items.");
			}
			
			return citems[idx];	
		}

		T* operator[](const std::string& title) const {
			size_t index = 0;

			for (size_t i = 0; i < csize; i++)
			{
				if (title == citems[i].title()) {
					index = i;
				}
			}
			
			return (index) ? &citems[index] : nullptr;
		}

		friend std::ostream& operator<<(std::ostream& ostr, const Collection<T>& t) {
			for (size_t i = 0; i < t.size(); i++)
			{
				ostr << t[i];
			}
			return ostr;
		}
	};
}
#endif // !COLLECTION_H_
