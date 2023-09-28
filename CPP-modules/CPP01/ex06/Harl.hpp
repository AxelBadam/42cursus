#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl
{
	public:
		void complain(std::string level);
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
};

typedef void (Harl::*t_func)(void) const;
enum complaints {DEBUG, INFO, WARNING, ERROR};

#endif