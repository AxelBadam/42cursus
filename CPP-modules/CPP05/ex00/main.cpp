#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat bur("Jalmari", 151);
	}
	catch(const std::exception& e){
		std::cerr << "Exception caught: Constructor" << std::endl;
	}	
	try
	{
		Bureaucrat bur("Jalmari", 1);
		bur.decrementG();
	}
	catch(const std::exception& e){
		std::cerr << "Exception caught: Decrement" << std::endl;
	}
	try
	{
		Bureaucrat bur("Jalmari", 150);
		bur.incrementG();
	}
	catch(const std::exception& e){
		std::cerr << "Exception caught: Increment" << std::endl;
	}

	Bureaucrat G("Gangsta", 42);
	std::cout << G << std::endl;

	Bureaucrat W;
	std::cout << W << std::endl;
}
