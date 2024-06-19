#pragma once

#include <string>

class	Contact
{
	private:
		std::string first_name_;
		std::string	last_name_;
		std::string nickname_;
		std::string	phone_number_;
		std::string	darkest_secret_;
	public:
		Contact();
		~Contact();
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void	contact_init(const std::string &first_name, const std::string &last_name, const std::string &nickname,
					const std::string &phone_number, const std::string &darkest_secret);
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickname(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);
};
