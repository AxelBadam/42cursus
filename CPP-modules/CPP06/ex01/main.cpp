#include "Serializer.hpp"

int main()
{
	Data data_ptr;
	data_ptr.str = "HELOO WRDL :)";
	uintptr_t int_ptr = Serializer::serialize(&data_ptr);
	std::cout << "data_ptr is " << &data_ptr << std::endl;
	std::cout << "int_ptr is " <<int_ptr << std::endl;

	std::cout << "-------------------------" << std::endl;

	Data *data_ptr2 = Serializer::deserialize(int_ptr);
	std::cout << "data_ptr is " << &data_ptr << std::endl;
	std::cout << "data_ptr2 is " << data_ptr2 << std::endl;
	std::cout << "int_ptr is " << int_ptr << std::endl;
	std::cout << data_ptr2->str << std::endl;
    return 0;
}
