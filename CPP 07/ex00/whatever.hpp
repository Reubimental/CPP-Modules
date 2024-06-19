#pragma once

#include <iostream>
#include <string>

// template<typename> means you can exchange the template type for any data type, and the code will still be applicable.

template< typename x >

const x &min(const x &a, const x &b)
{
	if (a < b)
		return (a);
	return (b);
}

template< typename X >

const X &max(const X &a, const X &b)
{
	if (a > b)
		return (a);
	return (b);
}

template< typename S >

void	swap(S &a, S &b)
{
	S temp = a;
	a = b;
	b = temp;
}