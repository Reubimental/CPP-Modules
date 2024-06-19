/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:32:10 by rkabzins          #+#    #+#             */
/*   Updated: 2023/03/07 13:32:14 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook()
{
	num_contacts_ = 0;
}

Phonebook::~Phonebook()
{
}


void	Phonebook::add(Contact contact)
{
	if (num_contacts_ == PHONEBOOK_SIZE)
	{
		rotate_contacts();
	}
	else
	{
		num_contacts_++;
	}
	this->contact_data_[num_contacts_ - 1] = contact;
	print_phonebook(this->contact_data_);
}

void	Phonebook::rotate_contacts()
{
	for(unsigned int i = 1; i < PHONEBOOK_SIZE; i++)
	{
		contact_data_[i - 1] = contact_data_[i];
	}
}

int	Phonebook::print_phonebook(Contact contacts[8]) 
{
	char		c;
	int			i;
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].getFirstName().size() && ++i)
		{
			str = c;
			str = fix_width(str, 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1  - '0'].getFirstName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].getLastName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_width(contacts[c - 1 - '0'].getNickname(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
	return (i);
}

void	Phonebook::search(void)
{
	std::string	str;

	if (!print_phonebook(this->contact_data_))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->contact_data_[str[0] - 1 - '0'].getFirstName().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print_contact(this->contact_data_[str[0] - 1 - '0']);
}

std::string	Phonebook::fix_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

std::string	Phonebook::add_spaces(int n)
{
	std::string	str;

	while (n--)
		str.append(" ");
	return (str);
}

void	Phonebook::print_contact(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}