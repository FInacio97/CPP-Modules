# ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <locale>
# include <vector>
# include <list>
# include <cstdlib>
# include <utility>

class PmergeMe
{
    public:

        PmergeMe();
        ~PmergeMe();

        void parsing(int ac,char **av);
        void jacobsGenerator();
        void displayListOrVector(int i);

        void sortPairsVector();
        void sortHalfVector(int n);

        void sortPairsList();
        void sortHalfList();

    private:

        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        int _jacobs[33];

        /* vectors */
        std::vector<int> _vec;
        std::vector < std::pair < int, int> > _vecPairs;

        /* lists */
        std::list<int> _lst;
        std::list < std::pair < int, int> > _lstPair;

        int _nbrElements;
        int _remainder;
};

# endif