#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw ": Please enter arguments to sort.";
		std::vector<int> VSort;
		std::deque<int> DSort;
		double			VSortTime;
		double			DSortTime;
		int				num;
		for (int index = 1; index < argc; index++)
		{
			std::stringstream readstring(argv[index]);
			if (!(readstring >> num) || !(readstring.eof()))
				throw "";
			if (num < 0)
				throw ": Negative Number!";
			VSort.push_back(num);
			DSort.push_back(num);
		}
		std::cout << std::endl;
		printResults(VSort, DSort);
		calculateTime(VSort, DSort, VSortTime, DSortTime);
		std::cout << std::endl;
		std::cout << BLUE << "      +------------------------+" << std::endl;
		std::cout << "      |" << RED << "         Process" << BLUE << "        |" << std::endl;
		std::cout << "      +------------------------+" << RESET << std::endl;
		std::cout << std::endl;
		printResults(VSort, DSort);
		std::cout << std::endl << YELLOW << "Time to process a range of " << argc - 1 << " elements with std::vector : " << VSortTime << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque :  " << DSortTime << " us" << RESET << std::endl;
	}
	catch (const char *errorMsg)
	{
		std::cout << "Error " << errorMsg << std::endl;
	}
}