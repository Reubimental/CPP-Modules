#include "Harl.hpp"

Harl::Harl()
{
 	levels[0] = "DEBUG";
 	levels[1] = "INFO";
 	levels[2] = "WARNING";
 	levels[3] = "ERROR";
	message_function_[0] = &Harl::debug;
	message_function_[1] = &Harl::info;
	message_function_[2] = &Harl::warning;
	message_function_[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << std::endl;
	std::cout << MAGENTA << "[DEBUG]   " << DEFAULT << std::endl;
	std::cout << "I can't believe it! The supermarket rearranged their shelves, " << std::endl;
	std::cout << "and now I have to spend an extra 30 seconds searching for my" << std::endl;
	std::cout << "favourite brand of toothpast. This is infuriating!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << std::endl;
	std::cout << GRAY << "[INFO]   " << DEFAULT << std::endl;
	std::cout << "This is unbelievable! The remote control for my TV has decided" << std::endl;
	std::cout << "to play Hide and Seek with me, disappearing into the abyss of my couch cushions." << std::endl;
	std::cout << "I've been searching for it for a solid five minutes now, and I'm on the verge" << std::endl;
	std::cout << " of losing my mind." << std::endl;
	std::cout << "How can something so essential vanish into thin air?" << std::endl;
	std::cout << "It's driving me insane!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << std::endl;
	std::cout << YELLOW << "[WARNING]   " << DEFAULT << std::endl;
	std::cout << "What in the name of all things logical is happening?" << std::endl;
	std::cout << "I just spent an eternity untangling a bundle of headphones," << std::endl;
	std::cout << "only to have them rebel against me and table themselves up once again!" << std::endl;
	std::cout << "It's an infuriating cycle of torment, a cruel dance of wires mocking" << std::endl;
	std::cout << "my very existence. I can feel the blood vessels in my forehead" << std::endl;
	std::cout << "throbbing with anger. It's a maddening spectacle that defies all reason." << std::endl;
	std::cout << "I am at my wit's end!" << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << std::endl;
	std::cout << RED << "[ERROR]   " << DEFAULT << std::endl;
	std::cout << "THIIS IS IT! I CAN'T TAKE IT ANYMORE! MY LATEST GRIEVENCE" << std::endl;
	std::cout << "IS UNFORGIVABLE! THE WORLD HAS CONSPIRED AGAINST ME!" << std::endl;
	std::cout << "YOU SEE, I PURCHASED A BRAND NEW UMBRELLA," << std::endl;
	std::cout << "ONLY TO DISCOVER T HAT IT MALICIOUSLY REFUSED TO OPEN" << std::endl;
	std::cout << "WHEN I DESPERATELY NEEDED IT! RAIN POURED DOWN UPON ME, " << std::endl;
	std::cout << "SOAKING ME TO THE BONE, AS I STRUGGLED WITH THAT ACCURSED CONTRAPTION!" << std::endl;
	std::cout << "I TRIED TWISTING, SHAKING, EVEN BEGGING, BUT NOTHING WORKED!" << std::endl;
	std::cout << "IT WAS LIKE A DEMONIC PARASITE SUCKING THE JOY OUT OF MY LIFE!" << std::endl;
	std::cout << "I...... I...." << std::endl;
	std::cout << "(Scoff)" << std::endl;
	std::cout << "I CAN'T CONTINUE! MY WRITING HAS DESCENDED INTO INCOHERENT RAGE!" << std::endl;
	std::cout << "FIX THIS! NOW!" << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	for ( ; i <= NUM_OF_LEVELS; i++)
	{
		if (levels[i] == level)
		{
			break ;
		}
	}
	switch(i)
	{
		case 0:
			this->debug();
			break ;
		case 1:
			this->info();
			break ;
		case 2:
			this->warning();
			break ;
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably wants to talk to my manager ]" << std::endl;
	}
}
