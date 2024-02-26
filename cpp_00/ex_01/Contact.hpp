#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

# ifndef CONTACT_HPP
# define CONTACT_HPP

# define CONTACT_BREAK 	"\e[0;32m ===========| CONTACTS LIST |============ \e[0m"
# define TABLE_HEADER "\e[0;36m Index   | Name     | Sirname  | Nickname \e[0m"
# define LINE_BREAK  "\e[0;36m------------------------------------------\e[0m"
# define CONTENT_BREAKE "\e[0;36m ======================================== \e[0m"
# define INDEX "\e[0;32mPlease insert contact's index\e[0m"
# define INDEX_ERR "\e[0;31mPlease insert contact's index from 0 to 7\e[0m"
# define NO_ENTRIES "\e[0;31mNO ENTRIES YET...\e[0m"
# define INVALID_CONTACT "\e[0;31mInvalid contact: cannot contain empty feilds\e[0m"
# define EMPTY_CONTACT "\e[0;31mEmpty contact\e[0m"
# define ENTER_FNAME "\e[0;32mEnter name:\e[0m"
# define ENTER_SNAME "\e[0;32mEnter sirname:\e[0m"
# define ENTER_NICK "\e[0;32mEnter nickname:\e[0m"
# define ENTER_CONTACT "\e[0;32mEnter contact:\e[0m"
# define ENTER_SECRET "\e[4;35mEnter darkest secret:\e[0m"

//	COLOURS

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"
class Contact
{
	public:

		Contact(void);
		void set_info(std::string content, int i);
		bool print_table_line(int index);
		void print_contact_info(void);

	private:

		std::string info[5];
};

# endif