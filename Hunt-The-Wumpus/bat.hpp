#ifndef BAT_HPP
#define BAT_HPP
#include<iostream>
#include"event.hpp"

using namespace std;

class Bat : public Event{
		public:
			Bat();
			void set_name_event();
			
			string percept();
			string encounter();


};

#endif
