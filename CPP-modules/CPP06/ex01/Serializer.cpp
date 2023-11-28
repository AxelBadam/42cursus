#include "Serializer.hpp"

Serializer::Serializer(){}  


Serializer::Serializer(Serializer const &cpy) {
	(void)cpy;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=(Serializer const &rhs)
{
    if (this != &rhs)
    {
		(void)rhs;  
    }
    return (*this);
}

uintptr_t  Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
