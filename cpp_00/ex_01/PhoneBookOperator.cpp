# include "PhoneBookOperator.hpp"

int	main()
{
	std::string	buffer;
	PhoneBook	phone_book;


	std::cout << CONTENT_BREAKE << std::endl;
	std::cout << GREATINGS_1 << std::endl << GREATINGS_2 << std::endl;
	std::cout << CONTENT_BREAKE << std::endl;
	while (1)
	{
		std::cout << ADD << std::endl << SEARCH << std::endl << EXIT << std::endl;
		std::getline(std::cin, buffer);
	 	if (std::cin.eof())
			break ;
		if (buffer == "EXIT")
			break;
		else if (buffer == "ADD")
			 phone_book.add_contact();
		else if (buffer == "SEARCH")
			phone_book.search_contact();
		else
			std::cout << INVALID_ARG << std::endl;
		if (std::cin.eof())
			break ;
	}
	std::cout << EXIT_MSG << std::endl;

}