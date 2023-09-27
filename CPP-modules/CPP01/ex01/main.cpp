#include "Zombie.hpp"

int main(void)
{
	const int N = 6;

	Zombie *z = zombieHorde(N, "EsaPekka");
	for (int i = 0; i < N; i++)
		z[i].annouce();
	delete[] z;
}




