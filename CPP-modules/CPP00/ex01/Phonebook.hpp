#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

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
    	void add();
    	void search();
		void print(Contact contact);
		void print_val(void);
		void view_contacts(Contact contacts[8]);
		Phonebook() : _i(0) {}
	
	private:
		Contact _contacts[8];
		int		_i;
		int		_count;

};

#endif
