#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(345);
	mstack.push(3);
	mstack.push(1);
	mstack.push(87);
	mstack.push(23);
	mstack.push(37);
	mstack.push(0);
	mstack.push(-37);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// std::list tests
	std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "std::list top: " << lst.back() << std::endl;

    lst.pop_back();

    std::cout << "std::list size: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(345);
    lst.push_back(3);
    lst.push_back(1);
    lst.push_back(87);
    lst.push_back(23);
    lst.push_back(37);
    lst.push_back(0);
    lst.push_back(-37);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;
    while (lit!= lite)
    {
        std::cout << "std::list element: " << *lit << std::endl;
        ++lit;
    }

	std::stack<int> s(mstack);
	return 0;
}