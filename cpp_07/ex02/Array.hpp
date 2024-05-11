# ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    public:
        Array(void);
        ~Array(void);
        Array(unsigned int n);
        Array(const Array &src);

        Array &operator=(const Array &src);
		
		T				&operator[](const size_t i);
		const T			&operator[](const size_t i)	const;

        unsigned int size() const;

        class OutOfBoundsException: public std::exception{
            public:
                virtual const char *what() const throw();
        };

    private:

        T           *_array;
        unsigned int _size;
};

# include "Array.tpp"

# endif