#pragma once

#include <string>
#include <iostream>

template<typename arr>

class	Array
{
	private:
		arr	*_array;
		unsigned int	_size;
	public:
		Array(): _size(0)
		{
			std::cout << "Default Array Created with size: " << this->_size << std::endl;
			this->_array = new arr[this->_size];
		}

		Array(unsigned int n): _size(n)
		{
			std::cout << "Array Created with size: " << this->_size << std::endl;
			this->_array = new arr[this->_size];
		}

		Array(const Array &src): _size(src.size())
		{
			std::cout << "Array of size " << this->_size << " copied." << std::endl;
			this->_array = NULL;
			*this = src;
		}

		~Array()
		{
			if (this->_array != NULL)
				delete [] this->_array;
		}

		Array &operator=(const Array &src)
		{
			if (this->_array != NULL)
				delete [] this->_array;
			if (src.size() != 0)
			{
				this->_size = src.size();
				this->_array = new arr[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}

		arr &operator[](unsigned int index)
		{
			if (index >= this->_size || this->_array == NULL)
			{
				std::cout << "index: " << index << std::endl;
				throw Array<arr>::InvalidIndexException();
			}
			return (this->_array[index]);
		}

		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		size_t	size() const
		{
			return (this->_size);
		}
};

template<typename arr>
const char	*Array<arr>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}