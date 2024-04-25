#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack();
        MutantStack(const MutantStack &src);
        MutantStack &operator=(const MutantStack &src);
        ~MutantStack();

    private:
};


# endif