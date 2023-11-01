#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	try{
		Bureaucrat bur("Jalmari", 150);
		bur.incrementG();
	}
	catch(const std::exception& e){
		std::cerr << "Exception caught: Increment" << std::endl;
	}

	Bureaucrat G("Gangsta", 42);
	std::cout << G << std::endl;

	Form F("Form", 2, 10);
	std::cout << F << std::endl;

	// exception thrown
	G.signForm(F);
	//should be signed
	Bureaucrat bur("Jalmari", 2);
	bur.signForm(F);

	std::cout << F << std::endl;


}
