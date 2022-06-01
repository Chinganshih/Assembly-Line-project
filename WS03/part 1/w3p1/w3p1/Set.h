#pragma once
#ifndef SET_H_
#define SET_H_
#include "Collection.h"
#include <cmath>
namespace sdds {

	template<typename T>
	class Set : public Collection<T, 100>
	{
	public:
		Set(){};
		~Set() {};

		bool add(const T& item) {
			bool isAdded = 0, isExist = 0;
			T m_obj;
			for (unsigned i = 0; i <= this->size(); i++)
			{
				m_obj = this->operator[](i);
				if (m_obj == item) isExist = 1;
			}

			if (!isExist)
			{
				Collection<T, 100>::add(item);
				isAdded = 1;
			}

			return isAdded;
		}
	};

	template<>
	class Set<double>:public Collection<double, 100> {
	public:
		bool add(const double& item) {
			bool isAdded = 1, isExist = 0;
			double m_obj;
			for (unsigned i = 0; i <= this->size(); i++)
			{
				m_obj = this->operator[](i);
				if (m_obj == item) isExist = 1;

				if (fabs(m_obj - item) <= 0.01)
				{
					isExist = 1;
				}
			}

			if (!isExist)
			{
				Collection<double, 100>::add(item);
			}

			return isAdded;
		}
	};
}

#endif // !SET_H_
