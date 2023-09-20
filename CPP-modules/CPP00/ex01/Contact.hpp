#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class Contact
{
	public:
	 	std::string get_fname(void) const;
		std::string get_lname(void) const;
		std::string get_nname(void) const;
		std::string get_phone(void) const;
		std::string get_secret(void) const;			
		int			hasData() const;
		void		set_fname(std::string str);
		void		set_lname(std::string str);
		void		set_nname(std::string str);
		void		set_phone(std::string str);
		void		set_secret(std::string str);
		
	private:	
    	std::string _fname;
		std::string _lname;
		std::string _nname;
    	std::string _phone;
		std::string _secret;
};

#endif
