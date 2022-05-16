// ------------------------------------------------------
//Workshop 2 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP345 NEE
//-----------------------------------------------------------

#pragma once
#include <chrono>
#include <string>
#ifndef TIMEDTASK_H_
#define TIMEDTASK_H_
#define MAX_EVENT 10 //the maximum number of event objects at 10

namespace sdds {

	class TimedTask
	{
		int record=0; //the number of records currently stored

		//the start time for the current task (an object of type std::chrono::steady_clock::time_point
		std::chrono::time_point<std::chrono::steady_clock> startTime;

		//the end time for the current task(an object of type std::chrono::steady_clock::time_point).
		std::chrono::time_point<std::chrono::steady_clock> endTime;

		//an array of Task of structure type.The structure should contain the following fields
		struct Task
		{
			std::string taskName; //a string with the task name.
			std::string unitTime; //a string with the units of time
			std::chrono::steady_clock::duration duration; //the duration of the task (an object of type std::chrono::steady_clock::duration;
		};

		Task task[MAX_EVENT];

	public:
		TimedTask();
		TimedTask(const TimedTask& t);
		TimedTask& operator=(const TimedTask& t);
		~TimedTask();
		TimedTask& startClock();
		TimedTask& stopClock();
		TimedTask& addTask(const char* inTaskName = nullptr);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& t);
	};

}


#endif // !TIMEDTASK_H_
