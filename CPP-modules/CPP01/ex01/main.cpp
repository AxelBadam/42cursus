#include "Zombie.hpp"

int main(void)
{
	int N = 5;

	Zombie *z = zombieHorde(N, "EsaPekka");
	for (int i = 0; i < N; i++)
		z[i].annouce();
	delete[] z;
}




