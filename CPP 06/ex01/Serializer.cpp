#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default Serializer Created." << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	(void)src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destroyed." << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}