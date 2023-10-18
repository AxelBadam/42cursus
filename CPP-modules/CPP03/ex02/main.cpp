#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap Markus("Markus");
	ScavTrap Jouni("Jouni");
	ScavTrap cpy(Markus);
	FragTrap Jesse("Jesse");
	FragTrap asd;

	std::cout << std::endl;

	Markus.guardGate();
	cpy.guardGate();
	Jesse.highFivesGuys();

	std::cout << std::endl;

	for (int i = 0; i < 11; i++)
		{
			Jouni.attack("Markus");
			if (Jouni.getE() > 0)
				Markus.takeDamage(Jouni.getAtck());
			Markus.beRepaired(10);
		}

	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		Jesse.takeDamage(30);
		Jesse.beRepaired(10);
	}		
	
	std::cout << std::endl;	
}