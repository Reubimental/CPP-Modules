#pragma once

# include "Contact.hpp"

class	Phonebook
{
	private:
		static const unsigned int	PHONEBOOK_SIZE = 8;	
		Contact 					contact_data_[PHONEBOOK_SIZE];
		unsigned int				num_contacts_;
		void						rotate_contacts();
	public:
		Phonebook();
		~Phonebook();
		void		add(Contact);
		void		search(void);
		void		print_contact(Contact contact);
		int			print_phonebook(Contact contacts[8]);
		std::string	add_spaces(int n);
		std::string	fix_width(std::string str, long unsigned max);
};
