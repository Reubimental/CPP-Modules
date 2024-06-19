#pragma once

#include <iostream>
#include <string>

template<typename it>

void	iter(it *array, size_t length, void (*F)(it &))
{
	if (array == NULL || F == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		F(array[i]);
}
