#pragma once
#ifndef CHILD_H_
#define CHILD_H_
#include "Toy.h"

namespace sdds {
	class Toy;
	class Child
	{
		//Add a Child module to your project that defines a class named Child.
		//This class should have attributes to store a nameand an age, and maintain a dynamically allocated array of pointers of type Toy : const sdds::Toy** (each element of the array points to an object of type Toy).
		std::string name{};
		int age = 0;
		size_t count = 0;
		const sdds::Toy** toys = nullptr;

	public:
		Child();
		Child(const Child& c);
		Child(Child&& c) noexcept;
		Child& operator=(const Child& c);
		Child& operator=(Child&& c)noexcept;
		~Child();
		Child(std::string name, int age, const Toy* intoys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& ostr, const Child& c);

	};
}

#endif // !CHILD_H_
