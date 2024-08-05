#pragma once

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>

#define START(x) x + 1
#define BEFORE  "\e[0;31m"
#define AFTER  "\e[0;32m"
#define MAG "\e[0;35m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &src);
		PmergeMe(const PmergeMe &src);

		template <typename Container>
		static void mergeInsertSort(Container &container, int start, int end);

		template <typename Container>
		static void mergeSort(Container &container, int start, int mid, int end);

		template <typename Container>
		static void insertSort(Container &container, int start, int end);

		template <typename Container>
		static void run(Container &container);
};

void	calculateTime(std::vector<int> &VSort, std::deque<int> &DSort, double &VTime, double &DTime);
void	printResults(std::vector<int> &VSort, std::deque<int> &DSort);
int		midPoint(int start, int end);

template <typename Container>
void PmergeMe::mergeInsertSort(Container &container, int start, int end)
{
	int	newEnd;
	if (start < end)
	{
		if ((end - start) < 10)
			insertSort(container, start, end);
		else
		{
			newEnd = start + (end - start) / 2;
			mergeInsertSort(container, start, newEnd);
			mergeInsertSort(container, newEnd + 1, end);
			mergeSort(container, start, newEnd, end);
		}
	}
}

template <typename Container>
void	PmergeMe::mergeSort(Container &container, int start, int mid, int end)
{
	int	i, j, k;

	Container left(container.begin() + start, container.begin() + mid + 1);
	Container right(container.begin() + mid + 1, container.begin() + end + 1);

	i = 0;
	j = 0;
	k = start;
	while (i < (int)left.size() && j < (int)right.size())
	{
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	while (i < (int)left.size())
		container[k++] = left[i++];
	while (j < (int)right.size())
		container[k++] = right[j++];
}

template <typename Container>
void	PmergeMe::insertSort(Container &container, int start, int end)
{
	for (int index = start + 1; index <= end; index++)
	{
		typename Container::value_type temp = container[index];
		int	j = index - 1;
		while (j >= start && container[j] > temp)
		{
			container[j + 1] = container[j];
			j--;
		}
		container[j + 1] = temp;
	}
}

template <typename Container>
void	PmergeMe::run(Container &container)
{
	mergeInsertSort(container, 0, container.size() - 1);
}