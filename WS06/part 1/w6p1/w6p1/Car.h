#pragma once
#ifndef CAR_H_
#define CAR_H_
#include "Vehicle.h"
#include <string>

namespace sdds {
	
	class Car : public Vehicle
	{
		std::string maker{};
		char carCondition{};
		double speed = 0.0;

	public:
		Car();
		/*Car(const Car& c);
		Car& operator=(const Car& c);*/
		Car(std::istream& istr);
		~Car();
		std::string condition() const;
		double topSpeed() const;
		Car& addBooster(double booster);
		void display(std::ostream& out) const;
		std::string ltrim(const std::string& s);
		std::string rtrim(const std::string& s);
		std::string trim(const std::string& s);

		

	};
	
}

#endif // !CAR_H_
