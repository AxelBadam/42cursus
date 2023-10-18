#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Jouni("Jouni");
	ClapTrap Markus("Markus");
	ClapTrap Mursu;

	for (int i = 0; i < 11; i++)
		{
			Jouni.attack("Markus");
			if (Jouni.getE() > 0)
				Markus.takeDamage(Jouni.getAtck());
			Markus.beRepaired(1);
		}
}