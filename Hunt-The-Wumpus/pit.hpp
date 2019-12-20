#ifndef PIT_HPP
#define PIT_HPP
#include<iostream>
#include"event.hpp"

class Pit:public Event{
		public:
			Pit();
			void set_name_event();		
			string percept();
			string encounter();


};

#endif
