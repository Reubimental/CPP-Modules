#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this == &src) {
        return *this;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    (void)(src);
}

void	calculateTime(std::vector<int> &VSort, std::deque<int> &DSort, double &VTime, double &DTime)
{
    std::clock_t start = std::clock();
    PmergeMe::run(VSort);
    std::clock_t end = std::clock();
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
    VTime = elapsed;
    start = std::clock();
    PmergeMe::run(DSort);
    end = std::clock();
    elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
    DTime = elapsed;
}

void	printResults(std::vector<int> &VSort, std::deque<int> &DSort)
{
    static int i = 0;

    if (!i)
        std::cout << MAG << "Vector " << "before : " << BEFORE;
    else
        std::cout << MAG << "Vector " << "after : " << AFTER;
    typedef typename std::vector<int>::const_iterator Viterator;
    for (Viterator Vit = VSort.begin(); Vit != VSort.end(); ++Vit)
        std::cout << *Vit << " ";
    std::cout << std::endl;

    if (!i)
        std::cout << MAG << "Deque " << " before : " << BEFORE;
    else
        std::cout << MAG << "Deque " << " after : " << AFTER;
    typedef typename std::deque<int>::const_iterator Diterator;
    for (Diterator Dit = DSort.begin(); Dit != DSort.end(); ++Dit)
        std::cout << *Dit << " ";
    std::cout << std::endl;
    i++;
}

int		midPoint(int start, int end)
{
    return (start + (end - start) / 2);
}