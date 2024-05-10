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
        T &operator[](int i);
		
		// TODO: I GUESS U NEED THOSE
		// THEY AERE THE SAME BUT ONE IS CONST
		// T				&operator[](const size_t i)	throw(std::exception);
		// const T			&operator[](const size_t i)	const throw(std::exception);
		// SUBJECT PAGE 8
		// 
		// EVALUATION SHEET NEEDS A CONST AND A NONCONST [] OPERATOR
		// Elements must be accessible for reading and writing through the operator[]
		// (or reading only if the instance is const). Access to an element which is
		// out of range must throw an std::exception.

        unsigned int size() const;

        class OutOfBoundsException: public std::exception{
            public:
                virtual const char *what() const throw()
                {
                    return ("Index out of bounds\n");
                }
        };

    private:

        T           *_array;
        unsigned int _size;
};

# include "Array.tpp"

# endif