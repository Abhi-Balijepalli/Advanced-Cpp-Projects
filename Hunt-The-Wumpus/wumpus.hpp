#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include<iostream>
#include"event.hpp"
#include<string>
using std::string;
class Wumpus: public Event{	
		public:
			Wumpus();
			void set_name_event();
			string percept();
			string encounter();
};
#endif
