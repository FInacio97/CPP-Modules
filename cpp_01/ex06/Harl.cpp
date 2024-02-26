# include "Harl.hpp"

Harl::Harl(void)
{
	this->keywords[0] = "DEBUG";
	this->keywords[1] = "INFO";
	this->keywords[2] = "WARNING";
	this->keywords[3] = "ERROR";
}

void Harl::complain(std::string level)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (level == this->keywords[i])
			break ;
	}

	switch (i)
	{
		case 0:
			this->debug();
			// fall through
		case 1:
			this->info();
			// fall through
		case 2:
			this->warning();
			// fall through
		case 3:
			this->error();
			break ;
		default:
			std::cout << CYAN << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug( void )
{
	std::cout << YELLOW << "[ DEBUG ]" << std::endl;
	std::cout << CYAN << DEBUG << RESET << std::endl;
}

void Harl::info( void )
{
	std::cout << YELLOW << "[ INFO ]" << std::endl;
	std::cout << CYAN << INFO << RESET << std::endl;
}

void Harl::warning( void )
{	
	std::cout << YELLOW << "[ WARNING ]" << std::endl;
	std::cout << CYAN << WARNING_1 << std::endl << WARNING_2 << RESET << std::endl;
}

void Harl::error( void )
{
	std::cout << YELLOW << "[ ERROR ]" << std::endl;
	std::cout << CYAN << ERROR << RESET << std::endl;
}