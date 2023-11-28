#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    srand(time(nullptr));
    int randomChoice = rand() % 3;
    switch (randomChoice) 
	{
        case 0:
		{
			A *classA = new A;
			return classA;
		}
        case 1:
		{
            B *classB = new B;
			return classB;
		}
        case 2:
		{
			C *classC = new C;
			return classC;
		}
		default:
			return NULL;
    }

}

void identify(Base* p) 
{
    if (dynamic_cast<A *>(p)) {
        std::cout << "type is A" << std::endl;
        return;
    }
    if (dynamic_cast<B *>(p)) {
        std::cout << "type is B" << std::endl;
        return;
    }
    if (dynamic_cast<C *>(p)) {
        std::cout << "type is C" << std::endl;
        return;
    }
    std::cout << "type is unknown" << std::endl;
}

void identify(Base& p)
{
	try{	
		(void)dynamic_cast<A &>(p);
		std::cout << "type is A" << std::endl;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "type is B" << std::endl;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "type is C" << std::endl;
	}
	catch (std::bad_cast &e) {}
}

int main()
{
	Base *p = generate();
	identify(p);
	identify(*p);

    return 0;
}
