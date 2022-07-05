// ------------------------------------------------------
//Workshop 6 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------


#include "Car.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

namespace sdds {

	Car::Car()
	{
		maker[0] = '\0';
		carCondition = '\0';
		speed = 0.0;
	}

	/*Car::Car(const Car& c) {
		*this = c;
	}

	Car& Car::operator=(const Car& c) {
		if (this != &c && c.maker[0] != '\0')
		{
			maker = c.maker;
			carCondition = c.carCondition;
			speed = c.speed;
		}

		return *this;
	}*/

	Car::Car(istream& istr) {
		logic_error error("Invalid record!");
		string tag, str_condition, str_speed;

		getline(istr, tag, ',');
		tag = trim(tag);
		
		if (tag == "c" || tag == "C" || tag == "r" || tag == "R")
		{
			getline(istr, maker, ',');
			maker = trim(maker);

			getline(istr, str_condition, ',');
			str_condition = trim(str_condition);
			carCondition = str_condition[0];

			//the token representing the condition the car is empty(no characters or only blanks) :
			//consider that the car is new
			//the token representing the condition of the car is a different character than n, u, or b:
			//generate an exception to inform the client that this record is invalid
			if (carCondition == '\0')
			{
				carCondition = 'n';
			}
			else if (carCondition != 'n' && carCondition != 'u' && carCondition != 'b') {
				
				throw error;
			}

			/*the token representing the top speed is not a number :
			generate an exception to inform the client that this record is invalid*/
			if (tag == "r" || tag == "R")
			{
				getline(istr, str_speed, ',');
			}else getline(istr, str_speed, '\n');
			
			str_speed = trim(str_speed);
			str_speed.erase(remove(str_speed.begin(), str_speed.end(), ','), str_speed.end());

			if (!str_speed.empty() && std::all_of(str_speed.begin(), str_speed.end(), ::isdigit))
			{
				speed = stod(str_speed);
			}
			else throw error;

		}

	}

	Car::~Car()
	{
	}

	//a query that returns new, used or broken, representing the condition of the car
	std::string Car::condition() const {
		string fullCon;

		switch (carCondition)
		{
		case 'n':
			fullCon = "new";
			break;
		case 'u':
			fullCon = "used";
			break;
		case 'b':
			fullCon = "broken";
			break;
		}
		
		return fullCon;
	}

	double Car::topSpeed() const {
		return speed;
	}

	Car& Car::addBooster(double booster) {

		speed *= (1+booster);
		return *this;
	}

	void Car::display(std::ostream& out) const {
		out << "| " << setw(10) << right << maker << " | ";
		out << setw(6) << left << condition() << " | ";
		out << setw(6) << setprecision(2) << fixed << speed << " |";
	}

	string Car::ltrim(const string& s)
	{
		size_t start = s.find_first_not_of(" ");
		return (start == std::string::npos) ? "" : s.substr(start);
	}

	string Car::rtrim(const string& s)
	{
		size_t end = s.find_last_not_of(" ");
		return (end == std::string::npos) ? "" : s.substr(0, end + 1);
	}

	string Car::trim(const string& s) {
		return rtrim(ltrim(s));
	}
}

