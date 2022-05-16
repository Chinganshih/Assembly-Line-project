// ------------------------------------------------------
//Workshop 2 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "TimedTask.h"
#include <string.h>
#include <iomanip>

using namespace std;

namespace sdds {

	static int numberRecord = 0;

	//Default constructor
	TimedTask::TimedTask() {}

	//Deallocator
	TimedTask::~TimedTask() {}
	

	TimedTask::TimedTask(const TimedTask& t) {
		int i;

		record = t.record;
		startTime = t.startTime;
		endTime = t.endTime;
		for ( i = 0; !t.task[i].taskName.empty(); i++)
		{
			task[i].taskName = t.task[i].taskName;
			task[i].unitTime = t.task[i].unitTime;
			task[i].duration = t.task[i].duration;
		}
	}

	TimedTask& TimedTask::operator=(const TimedTask& t) {
		int i;
		
		if (this != &t)
		{
			record = t.record;
			startTime = t.startTime;
			endTime = t.endTime;
			for (i = 0; !t.task[i].taskName.empty(); i++)
			{
				task[i].taskName = t.task[i].taskName;
				task[i].unitTime = t.task[i].unitTime;
				task[i].duration = t.task[i].duration;
			}
		}
		return *this;
	}

	//a modifier that starts the timer for an event
	TimedTask& TimedTask::startClock() {
		startTime = std::chrono::steady_clock::now();
		return *this;
	}

	//a modifier that stops the timer for an event
	TimedTask& TimedTask::stopClock() {
		endTime = std::chrono::steady_clock::now();
		return *this;
	}

	//a modifier that receives the address of a C-style null-terminated string that holds the name of the task. 
	//This function will update the next time-record in the array:
	//stores into the name attribute the C-style string received as parameter
	//stores "nanoseconds" as the units of time
	//calculates and stores the duration of the event(use std::chrono::duration_cast<std::chrono::nanoseconds>()
	TimedTask& TimedTask::addTask(const char* inTaskName) {
		
		task[record].taskName = inTaskName;
		task[record].unitTime = "nanoseconds";
		task[record].duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
		record++;
		numberRecord++;

		return *this;
	}

	//a friend insertion operator that receives a reference to an std::ostream object and a TimedTaskobject. 
	//This operator should insert in the std::ostream object the records from the array in the following format:
	ostream& operator<<(ostream& ostr, const TimedTask& t) {
		int i;

		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;

		for ( i = 0; i < numberRecord; i++)
		{
			ostr << setw(21) << left << t.task[i].taskName << " ";
			ostr << setw(13) << right << t.task[i].duration.count() << " ";
			ostr << t.task[i].unitTime;
			ostr << endl;
		}

		ostr << "--------------------------" << endl;
		return ostr;
	}
}