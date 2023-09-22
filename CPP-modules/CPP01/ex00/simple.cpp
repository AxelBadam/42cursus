#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name) : name(name) {}
		~Zombie(){std::cout << name << " is dead twice" << std::endl;};
		void announce(void)
		{
			std::cout << name << ":" << " sup?" << std::endl;
		}		
	private:
		std::string name;
};

void ann(Zombie *z)
{
	z->announce();
}

int main()
{
	Zombie z("Joppe");
	ann(&z);
	Zombie *x = new Zombie("jouni");
	x->announce();
	delete x;
}
