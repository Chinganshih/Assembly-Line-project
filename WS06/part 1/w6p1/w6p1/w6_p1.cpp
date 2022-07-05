//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include "Utilities.h"
//#include "Utilities.h"
//#include "Autoshop.h"
//#include "Autoshop.h"
//
//
//void loadData(const char* filename, sdds::Autoshop& as)
//{
//	std::ifstream file(filename);
//	if (!file)
//	{
//		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
//		return;
//	}
//	while (file)
//	{
//		sdds::Vehicle* aVehicle = sdds::createInstance(file);
//		if (aVehicle)
//			as += aVehicle;
//	}
//}
//
//// ws cars.txt
//int main()
//{
//	std::cout << "Command Line:\n";
//	std::cout << "--------------------------\n";
//	int argc = 2;
//	const char* argv[] = { "ws", "cars.txt", nullptr };
//	for (int i = 0; i < argc; i++)
//		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
//	std::cout << "--------------------------\n\n";
//
//	sdds::Autoshop as;
//	loadData(argv[1], as);
//	as.display(std::cout);
//
//	return 0;
//}
