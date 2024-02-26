# include "PhoneBook.hpp"

PhoneBook::PhoneBook (void)
{
	new_info[0] = "Empty";
	new_info[1] = "Empty";
	new_info[2] = "Empty";
	new_info[3] = "Empty";
	new_info[4] = "Empty";
	this->overwrite_index = 0;
}

void PhoneBook::add_contact(void)
{	
	std::cout << ENTER_FNAME << std:: endl;
	std::getline(std::cin, this->new_info[0]);
	if (std::cin.eof())
			return ;
	std::cout << ENTER_SNAME << std:: endl;
	std::getline(std::cin, this->new_info[1]);
	if (std::cin.eof())
			return ;
	std::cout << ENTER_NICK << std:: endl;
	std::getline(std::cin, this->new_info[2]);
	if (std::cin.eof())
			return ;
	std::cout << ENTER_CONTACT << std:: endl;
	std::getline(std::cin, this->new_info[3]);
	if (std::cin.eof())
			return ;
	std::cout << ENTER_SECRET << std:: endl;
	std::getline(std::cin, this->new_info[4]);
	if (std::cin.eof())
			return ;
	this->save_info();
}

void PhoneBook::save_info(void)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (this->new_info[i][0] == 0)
		{
			std::cout << INVALID_CONTACT << std::endl;
			return ;
		}
	}
	for (i = 0; i < 5; i++)
		this->contacts[this->overwrite_index].set_info(new_info[i], i);
	if (this->overwrite_index == 7)
		this->overwrite_index = 0;
	else
		this->overwrite_index++;
}

void PhoneBook::search_contact(void)
{
	std::string char_index;
	int			num_index;

	if (this->print_contact_table() == false)
		return ;
	std::cout << INDEX << std::endl;
	while (1)
	{
		std::getline(std::cin, char_index);
		if (std::cin.eof())
			return ;
		num_index = kinda_atoi(char_index);
		if (num_index >= 0 && num_index < 8)
			break ;
		std::cout << INDEX_ERR << std::endl;
	}
	this->contacts[num_index].print_contact_info();
}

bool PhoneBook::print_contact_table(void)
{
	int i;

				std::cout << "here" << std::endl;
	std::cout << CONTACT_BREAK << std::endl;
	std::cout << TABLE_HEADER << std::endl;
	for (i = 0; i < 8; i++)
	{
		// std::cout << LINE_BREAK << std::endl;
		if (this->contacts[i].print_table_line(i) == false)
		{
			if (i == 0)
			{
				std::cout << NO_ENTRIES << std::endl;
				std::cout << LINE_BREAK << std::endl;
				return (false);
			}
			break ;
		}
	}
	if (i == 8)
		std::cout << LINE_BREAK << std::endl;
	return (true);
}

int PhoneBook::kinda_atoi(std::string str)
{
	if (str.length() != 1 || (str[0] < '0' && str[0] > '7'))
		return (-1);
	return (str[0] - 48);
	
}