#include <iostream>

int	main()
{
	std::string	string;
	std::string	*stringPTR;
	std::string	&stringREF = string;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::cout << std::endl;
	std::cout << "string address: " << &string << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "string value: " << string << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
}

// this prints the address, denoted with '&', of string.
// then, it prints the address being stored in stringPTR as a value
// then, it prints the address of the variable being referenced by stringREF, denoted by '&'
// It's important to note that stringPTR is a variable that holds the address of string,
// whereas stringREF is just a reference to the variable of string.
// in this example, stringREF and string should have the same address, which is the same as the value of stringPTR.

// after this, the value of string is printed. This should be "HI THIS IS BRAIN"
// then, the value at the address of both stringPTR and stringREF is printed.
// these should both be "HI THIS IS BRAIN"

// The difference between them, is that stringPTR is going to a variable that contains an address,
// and stringREF IS the address.

// an interesting thing to note, as that stringREF cannot be declared and initialized separately, as this would mean it was being initially assigned to null.
// so, stringREF must be declared and initialized immediately to the reference/address of a variable.