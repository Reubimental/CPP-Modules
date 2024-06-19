#include "type_identify.hpp"

Base	*generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return (new A());
			break ;
		case 1:
			std::cout << "Generated B" << std::endl;
			return (new B());
			break ;
		case 2:
			std::cout << "Generated C" << std::endl;
			return (new C());
			break ;
		default:
			perror("Error with random generator.\n");
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Identified A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identified B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identified C." << std::endl;
	else
		std::cout << "Unknown Type." << std::endl;
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

void	identify(Base &p)
{
	while (i < 3)
	{
		void	*type;
		Base 	&temp = (Base &)type;
		try
		{
			switch (i)
			{
				case 0:
					temp = dynamic_cast<A &>(p);
					break ;
				case 1:
					temp = dynamic_cast<B &>(p);
					break ;
				case 2:
					temp = dynamic_cast<C &>(p);
					break ;
				default:
					std::cout << "Unknown Type." << std::endl;
				(void)temp;
			}
		}
		catch (std::exception &e)
		{
			// std::cout << "exception caught: " << e.what() << std::endl;
			// std::cout << "Could not dynamically cast to " << classes[i] << std::endl;
			i++;
			identify(p);
			return ;
		}
		std::cout << classes[i] << " is the identified type." << std::endl;
		i = 0;
		break ;
	}
}