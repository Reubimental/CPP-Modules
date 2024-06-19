#include "Phonebook.hpp"
#include "Contact.hpp"
#include "main.hpp"
#include <iostream>

Phonebook phonebook;

int	main()
{
	bool exit = false;
	phonebook = Phonebook();
	while (!exit)
	{
		std::string input;
		std::cout << "Please enter a command: EXIT, SEARCH, ADD." << std::endl;
		std::getline(std::cin, input);
		exit = handle_input(input);
	}
}

bool	handle_input(std::string input)
{
	if (input == "EXIT")
	{
		return (true);
	}

	if (input == "ADD")
	{
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		Contact		new_contact;

		input_contact_data("first name", first_name);
		input_contact_data("last name", last_name);
		input_contact_data("nickname", nickname);
		input_contact_data("phone number", phone_number);
		input_contact_data("darkest secret", darkest_secret);

		new_contact.contact_init(first_name, last_name, nickname, phone_number, darkest_secret);
		phonebook.add(new_contact);
	}
	else if (input == "SEARCH")
	{
		phonebook.search();
	}
	return (false);
}

void input_contact_data (const std::string data_name, std::string &data)
{
	std::cout << "Please enter contacts " << data_name << "." << std::endl;
	std::getline(std::cin, data);
}
