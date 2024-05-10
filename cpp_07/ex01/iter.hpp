# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
// TODO: WE changed the second arg to size_t!
void iter(T *t, size_t length, F f)
{
	// TODO: HERE AS WELL: WE changed i to size_t!
    for (size_t i = 0; i < length; i++)
        f(t[i]);
}

# endif
