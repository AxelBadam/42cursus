#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap Markus("Markus");
	ScavTrap Jouni("Jouni");
	ScavTrap cpy(Markus);
	FragTrap Jesse("Jesse");

	Markus.guardGate();
	cpy.guardGate();
	Jesse.highFivesGuys();

	for (int i = 0; i < 11; i++)
		{
			Jouni.attack("Markus");
			if (Jouni.getE() > 0)
				Markus.takeDamage(Jouni.getAtck());
			Markus.beRepaired(10);
		}

}