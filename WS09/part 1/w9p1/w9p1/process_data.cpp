// ------------------------------------------------------
//Workshop 9 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------


#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include "process_data.h"
using namespace std;
using namespace std::placeholders;
namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.


		ifstream binary_file(filename, ios::binary);
		int numberOfdata = 0;

		if (binary_file)
		{
			binary_file.read((char*)&total_items, sizeof(int));
			data = new int[total_items + 1];

			while (!binary_file.eof() && binary_file.good())
			{
				binary_file.read((char*)&data[numberOfdata], sizeof(int));
				numberOfdata++;
			}


			binary_file.close();

			std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
			std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
				<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
				<< data[total_items - 1] << "]\n";

		}
		else std::cout << "Cannot open the file!";
	

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}

	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.
	int ProcessData::operator()(std::string targetFile, double& avg, double& var) {
		ofstream outfile(targetFile, ios::binary);

		std::vector<thread> threads(num_threads);
		std::vector<thread> threadsVar(num_threads);

		auto computeAvgFactorFn = bind(computeAvgFactor, _1, _2, total_items, _3);
		

		for (int i = 0; i < num_threads; i++)
		{
			threads[i] = thread(computeAvgFactorFn, &data[p_indices[i]], p_indices[i+1] - p_indices[i], ref(averages[i]));
		}
	
		for (auto& th : threads )
		{
			th.join();
		}
		
		for (int i = 0; i < num_threads; i++)
		{
			avg += averages[i];
		}

		auto computeVarFactorFn = bind(computeVarFactor, _1, _2, total_items, avg, _3);
		
		for (int i = 0; i < num_threads; i++)
		{
			threadsVar[i] = thread(computeVarFactorFn, &data[p_indices[i]], p_indices[i + 1] - p_indices[i], ref(variances[i]));
		}

		for (auto& th : threadsVar)
		{
			th.join();
		}

		for (int i = 0; i < num_threads; i++)
		{
			var += variances[i];
		}

		outfile.write((char*)&total_items, sizeof(int));
		for (int i = 0; i < total_items; i++)
		{
			outfile.write((char*)&data[i], sizeof(int));
		}

		outfile.close();
		return 1;
	}




}