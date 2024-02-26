#include "Contact.hpp"

Contact::Contact(void)
{
	this->info[0] = "Empty";
	this->info[1] = "Empty";
	this->info[2] = "Empty";
	this->info[3] = "Empty";
	this->info[4] = "Empty";
}

// void Contact::print_info(std::string index)
// {
// 	int empty_chars;
// 	int i;
// 	std::string spaces = "         ";

// 	std::cout << "index   " << index;
// 	for (i = 0; i <= 2; i++)
// 	{
// 		empty_chars = 10 - this->info[i].length();
// 		if (empty_chars < 0)
// 			std::cout << "|" << this->info[i].substr(0, 9) <<  ".";
// 		else if (empty_chars == 0)
// 			std::cout << "|" << this->info[i];
// 		else
// 			std::cout << "|" << spaces.substr(0, empty_chars) << this->info[i];
// 	}
// 	std::cout << std::endl;
// }	


void Contact::set_info(std::string content, int i)
{
	this->info[i] = content;
}

bool Contact::print_table_line(int index)
{
	int empty_chars;
	int i;
	std::string spaces = "         ";
	std::string to_print;

	std::cout << LINE_BREAK << std::endl;
	if (this->info[0] == "Empty")
		return (false);
	to_print = spaces.substr(0, 8);
	to_print += index + 48;
	for (i = 0; i <= 2; i++)
	{
		empty_chars = 10 - this->info[i].length();
		if (empty_chars < 0)
			to_print += "|" + this->info[i].substr(0, 9) +  ".";
		else if (empty_chars == 0)
			to_print += "|" + this->info[i];
		else
			to_print += "|" + spaces.substr(0, empty_chars) + this->info[i];
	}
	std::cout << CYAN << to_print << RESET << std::endl;
	return (true);
}

void Contact::print_contact_info(void)
{
	if (this->info[0] == "Empty")
	{
		std::cout << EMPTY_CONTACT << std::endl;
		return ;
	}
	std::cout << GREEN << "First name:      " << CYAN << this->info[0] << RESET << std::endl;
	std::cout << GREEN << "Last name:       " << CYAN << this->info[1] << RESET << std::endl;
	std::cout << GREEN << "Nickname:        " << CYAN << this->info[2] << RESET << std::endl;
	std::cout << GREEN << "Contact:         " << CYAN << this->info[3] << RESET << std::endl;
	std::cout << GREEN << "darkest secret:  " << CYAN << this->info[4] << RESET << std::endl;
}