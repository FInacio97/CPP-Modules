# include "Harl.hpp"

Harl::Harl(void)
{
	this->comp_func[0] = &Harl::debug;
	this->comp_func[1] = &Harl::info;
	this->comp_func[2] = &Harl::warning;
	this->comp_func[3] = &Harl::error;

	this->keywords[0] = "DEBUG";
	this->keywords[1] = "INFO";
	this->keywords[2] = "WARNING";
	this->keywords[3] = "ERROR";
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->keywords[i])
		{
			(this->*comp_func[i])();
			return ;
		}
	}
	std::cout << RED <<"Complaint not found" << RESET << std::endl;
}

void Harl::debug( void )
{
	std::cout << CYAN << DEBUG << RESET << std::endl;
}

void Harl::info( void )
{
	std::cout << CYAN << INFO << RESET << std::endl;
}

void Harl::warning( void )
{	
	std::cout << CYAN << WARNING << RESET << std::endl;
}

void Harl::error( void )
{
	std::cout << CYAN << ERROR << RESET << std::endl;
}
