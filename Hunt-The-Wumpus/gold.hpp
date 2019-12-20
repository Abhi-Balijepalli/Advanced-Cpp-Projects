#ifndef GOLD_HPP
#define GOLD_HPP
#include<iostream>
#include"event.hpp"

class Gold : public Event {	
		public:
			Gold();
			void set_name_event();
			string percept();
			string encounter();
};

#endif
