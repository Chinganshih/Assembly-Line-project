// ------------------------------------------------------
//Workshop 3 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#include <iostream>
#include "Pair.h"
#include <iomanip>
#include <cmath>
using namespace std;

namespace sdds {
	
	Pair::Pair(const Pair& P) {
		m_key = P.m_key;
		m_value = P.m_value;
	}

	Pair& Pair::operator=(const Pair & P){
		if (this != &P)
		{
			m_key = P.m_key;
			m_value = P.m_value;
		}
		return *this;
	}

	ostream& operator<<(ostream& ostr, const Pair& P) {
		
		ostr << setw(20) << right << P.m_key <<  ": ";
		ostr << P.m_value;

		return ostr;
	}

	bool operator==(const Pair& L, const Pair& R) {
		bool isSame = 0;
		if (L.m_key == R.m_key)
		{
			isSame = 1;
		}
		return isSame;
	}

	unsigned operator-(const Pair& L, const Pair& R) {
		
		return fabs(L - R);
	}
}
