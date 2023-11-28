#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <cstdint>
#include <iostream>

struct Data
{
	std::string str;
	int i;
};

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
    Serializer();
    Serializer(const Serializer &other);
    ~Serializer();
    Serializer& operator=(const Serializer &other);
    
};

#endif
