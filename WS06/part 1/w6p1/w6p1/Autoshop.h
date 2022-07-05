#pragma once
#ifndef AUTOSHOP_H_
#define AUTOSHOP_H_
#include "Vehicle.h"
#include <vector>
#include <list>

namespace sdds {
	
	class Autoshop
	{
		//a vector that store all the vehicles available at this autoshop
		std::vector<Vehicle*> m_vehicle;

	public:
		Autoshop();
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		/*a template function that iterates over the vehicles stored in the m_vehicles, 
		and adds to the second parameter all vehicles for which the test is true.
		The first parameter(test) can be a lambda expression, a pointer to a function, or a functor that matches the prototype :*/
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			std::vector<Vehicle*>::iterator i;

			for (i = m_vehicle.begin(); i != m_vehicle.end(); i++)
			{
				if (test(*i))
				{
					vehicles.push_back(*i);
				}

			}
			
		}
	};

	
}

#endif // !AUTOSHOP_H_

