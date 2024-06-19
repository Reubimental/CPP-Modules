#pragma once

#include <iostream>
#include <string>

struct Data
{
	int	n;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
		~Serializer();
};
