#pragma once
#ifndef CONFIRMORDER_H_
#define CONFIRMORDER_H_
#include "Toy.h"

namespace sdds {
	class ConfirmOrder
	{
		const sdds::Toy** toys = nullptr;
		size_t count = 0;

	public:
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& o);
		ConfirmOrder(ConfirmOrder&& o) noexcept;
		ConfirmOrder& operator=(const ConfirmOrder& o);
		ConfirmOrder& operator=(ConfirmOrder&& o)noexcept;
		~ConfirmOrder();
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& o);
	

	};

}

#endif // !CONFIRMORDER_H_

