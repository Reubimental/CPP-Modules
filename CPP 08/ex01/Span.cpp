#include "Span.hpp"

Span::Span(): _maximum(0)
{
}

Span::Span(unsigned int N): _maximum(N)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	Span::addNumber(int N)
{
	if (_span.size() < _maximum)
		_span.push_back(N);
	else
		throw(Span::TooManyNumbers());
}

int	Span::shortestSpan()
{
	if (_span.size() <= 1)
		throw(Span::NotEnoughNumbers());

	std::vector<int> temp(this->_span);
	std::sort (temp.begin(), temp.end());

	unsigned int ret = UINT_MAX;
	std::vector<int>::iterator temp_it = temp.begin();
	std::vector<int>::iterator temp_it_next = temp.begin() + 1;
	while (temp_it_next != temp.end())
	{
		if ((unsigned int)(*temp_it_next - *temp_it) < ret)
			ret = *temp_it_next - *temp_it;
		++temp_it_next;
		++temp_it;
	}
	return (ret);
}

int	Span::longestSpan()
{
	if (_span.size() <= 1)
		throw(Span::NotEnoughNumbers());
	
	std::vector<int> temp(this->_span);
	int	low, high;

	std::sort (temp.rbegin(), temp.rend());
	high = *temp.begin();

	std::sort (temp.begin(), temp.end());
	low = *temp.begin();

	return (high - low);
}

static int	randomInt(size_t size)
{
	int	i;

	i = (rand() % size) + 1;
	return (i);
}

void	Span::fill()
{
	size_t	start = _span.size();

	while (start < _maximum)
	{
		usleep(50);
		_span.push_back(randomInt(_maximum));
		start++;
	}
}
