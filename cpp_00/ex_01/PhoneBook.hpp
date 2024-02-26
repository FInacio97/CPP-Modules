# include "Contact.hpp"

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	public:

		PhoneBook(void);
		void add_contact(void);
		void search_contact();
	
	private:

		Contact		contacts[8];
		std::string new_info[5];
		int			overwrite_index;

		void 	save_info(void);
		int		kinda_atoi(std::string str);
		bool 	print_contact_table(void);
};

#endif