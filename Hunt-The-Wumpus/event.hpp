

#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
using std::string;
class Event{
	protected:
		string name_event;
	public:
		virtual void set_name_event() = 0;
		string get_name_event();
		virtual string percept() = 0;
		virtual string encounter() =0;

};
#endif
