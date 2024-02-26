# include <iostream>
# include <string>

# ifndef HARL
# define HARL

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable! I want to speak to the manager now."


class Harl
{

	typedef void(Harl::*complains_function)();
	
	public:

		Harl(void);

		void complain( std::string level );

	private:

		complains_function comp_func[4];
		std::string keywords[4];

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};


# endif