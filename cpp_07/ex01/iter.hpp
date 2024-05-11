# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T *t, size_t length, F f)
{
    for (size_t i = 0; i < length; i++)
        f(t[i]);
}

# endif
