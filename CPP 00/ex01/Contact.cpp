/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <rkabzins@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:32:23 by rkabzins          #+#    #+#             */
/*   Updated: 2023/03/07 13:32:24 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::contact_init(const std::string &first_name, const std::string &last_name, const std::string &nickname,
					const std::string &phone_number, const std::string &darkest_secret)
{
	this->first_name_ = first_name;
	this->last_name_ = last_name;
	this->nickname_ = nickname;
	this->phone_number_ = phone_number;
	this->darkest_secret_ = darkest_secret;
}


std::string Contact::getFirstName() const
{
	return (this->first_name_);
}

std::string Contact::getLastName() const
{
	return (this->last_name_);
}

std::string Contact::getNickname() const
{
	return (this->nickname_);
}

std::string Contact::getPhoneNumber() const
{
	return (this->phone_number_);
}

std::string Contact::getDarkestSecret() const
{
	return (this->darkest_secret_);
}

void Contact::setFirstName(std::string str)
{
	this->first_name_ = str;
}

void Contact::setLastName(std::string str)
{
	this->last_name_ = str;
}

void Contact::setNickname(std::string str)
{
	this->nickname_ = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->phone_number_ = str;
}

void Contact::setDarkestSecret(std::string str)
{
	this->darkest_secret_ = str;
}
