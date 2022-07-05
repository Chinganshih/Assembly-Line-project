#pragma once
#ifndef Racecar_H_
#define Racecar_H_
#include "Car.h"

namespace sdds {

	class Racecar : public Car
	{
		//the percentage(stored as a number between 0 an 1) by which this Racecar can boost its top speed.
		double m_booster =0;

	public:
		Racecar();
		~Racecar();
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;


	};

	
}

#endif // !Racecar_H_

