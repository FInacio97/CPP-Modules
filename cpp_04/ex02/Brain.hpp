# include <string>
# include <iostream>

# ifndef BRAIN_HPP
# define BRAIN_HPP

# define CYAN "\e[0;36m"
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define PURPLE "\e[4;35m"
# define RESET "\e[0m"

class Brain
{
	public:

		Brain(void);
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		~Brain(void);

		std::string getIdea(int i) const;
		void		setIdeas(const unsigned int index, const std::string &idea);

	private:
	
		std::string _ideas[100];
};

# endif