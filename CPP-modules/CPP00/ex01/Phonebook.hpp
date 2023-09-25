#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

typedef enum 
{
	EXIT,
	ADD,
	SEARCH,
	ERROR
} t_cmd;

class Phonebook
{
	public:
		Phonebook() : _i(0) {}
    	void add();
    	void search();
		void print(Contact contact);
		void view_contacts(Contact contacts[8]);

	
	private:
		Contact _contacts[8];
		int		_i;
		int		_count;

};

#endif
