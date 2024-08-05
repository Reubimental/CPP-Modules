#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class VectorNotFound : public std::exception
{
	public:
		char const * what() const throw()
		{
			return ("Can't find it!");
		}
};

template<typename T>
int	*easyfind(T haystack, int needle)
{
	typename	T::iterator it;

	if((it = std::find(haystack.begin(), haystack.end(), needle)) == haystack.end())
		throw VectorNotFound();
	return (&(*it));
}