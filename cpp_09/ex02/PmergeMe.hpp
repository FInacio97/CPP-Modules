# ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <locale>
# include <vector>
# include <deque>
# include <cstdlib>
# include <utility>
# include <climits>

class PmergeMe
{
    public:

        PmergeMe();
        ~PmergeMe();

        void parsing(int ac,char **av);
        void jacobsGenerator();
        // void displayListOrVector(int i);

        // void FordJohnson();
        void sorting();

        // void sortPairsVector();
        // void sortHalfVector(int n);
        // void sortWithJacobsVector(int i);
        // void sortWithJacobsFirstElementsVector();
        // void sorterVector(int maxValue, int toInsert);


        // bool isSorted();

    private:

        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        int _jacobs[33];

        /* vectors */
        std::vector<int> _vec;
        std::vector < std::pair < int, int> > _vecPairs;

        /* deque */
        std::deque<int> _dq;
        std::deque < std::pair < int, int> > _dqPairs;

        int _nbrElements;
        int _remainder;


    /* +++++++++++++++ Template Functions ++++++++++++++++++ */

    template <typename C, typename P>
    void sortPairs(C &cont, P &pair)
    {
        int vec_size = cont.size();

        if (vec_size % 2 != 0)
        {
            _remainder = cont.back();
            cont.pop_back();
            vec_size--;
        }
        // displayElements(cont);

        for (int i = 0; i < vec_size; i += 2)
        {
            if (cont[i] < cont[i + 1])
                pair.push_back(std::make_pair(cont[i], cont[i + 1]));
            else
                pair.push_back(std::make_pair(cont[i + 1], cont[i]));
        }

        // for (int i = 0; i < (vec_size / 2); i++)
        //     std::cout << pair[i].first << " | " << pair[i].second << std::endl;
    }

    template <typename C, typename P>
    void sortHalfElements(int i, C &cont, P &pair)
    {
        if (i == 0)
        {
            cont.clear();
            cont.push_back(pair[i].second);
            sortHalfElements(i + 1, cont, pair);
        }
        else if (i == _nbrElements / 2)
            return ;
        else
        {
            cont.insert(std::lower_bound(cont.begin(), cont.end(), pair[i].second), pair[i].second);
            sortHalfElements(i + 1, cont, pair);   
        }
    }

    template <typename C>
    void displayElements(C &cont)
    {
        // std::cout << "Number of elements: " << cont.size() << std::endl;
        for (size_t i = 0; i < cont.size(); i++)
            std::cout << cont[i] << " ";
        std::cout << std::endl;
    }

    template <typename C>
    void sorter(int maxValue, int toInsert, C &cont)
    {
        typename C::iterator end;

        for (unsigned long int i = 0; i < cont.size(); i++)
        {
            if (cont[i] == maxValue)
                end = cont.begin() + i;
        }
        if (maxValue == -1)
            end = cont.end();
        cont.insert(std::lower_bound(cont.begin(), end, toInsert), toInsert);
    }

    template <typename C, typename P>
    void sortWithJacobsFirstElements(C &cont, P &pair)
    {

        sorter(pair[0].second, pair[0].first, cont);

        sorter(pair[1].second, pair[1].first, cont);
    
        // std::cout << "\n\n++++++++++ for index: 0 ++++++++++\n";
        // displayElements(cont);

        sortWithJacobs(3, cont, pair);
    }

    template <typename C, typename P>
    void sortWithJacobs(int jacobsIndex, C &cont, P &pair)
    {
        // std::cout << "\n\n++++++++++ for index: " << jacobsIndex << "++++++++++\n";
        if (jacobsIndex == 0)
        {
            sortWithJacobsFirstElements(cont, pair);
            return ;
        }

        int i = _jacobs[jacobsIndex];
        // std::cout << "starting index: " << i << std::endl;

        while ((int)pair.size() <= i)
        {
            i--;
            // std::cout << "vecPair size: " << pair.size() << std::endl;
            // std::cout << "index: " << i << std::endl;
        }

        // std::cout << "index: " << i << std::endl;




        if (i >= (static_cast<int>(pair.size())))
            return;

        // std::cout << "\n\n";

        // std::cout << "here\n";
        // std::cout << "jacos index - 1: " << jacobsIndex - 1 << std::endl;
        for (; i > _jacobs[jacobsIndex - 1]; i--)
        {
            // std::cout << "inserting element[" << i << "]\n";
            sorter(pair[i].second, pair[i].first, cont);
        }
        // displayElements(cont);

        if (_jacobs[jacobsIndex] > (int)pair.size())
            return ;
        sortWithJacobs(jacobsIndex + 1, cont, pair);
        if(jacobsIndex == 3 && _remainder != -1)
        {
            // std::cout << "remainder: " << _remainder << std::endl;
            sorter(-1, _remainder, cont);
        }
    }

    template <typename C>
    bool isSorted(C &cont)
    {
        if ((int)cont.size() != _nbrElements)
        {
            // std::cout << "wrong values\n";
            return (false);
        }

        for (int i = 0; i < (int)cont.size() - 1; i++)
        {
            if (cont[i] > cont[i + 1])
            {
                // std::cout << "wrong order: " << cont[i] <<  " " << cont[i + 1] << std::endl;
                return (false);
            }
        }
        return (true);
    }

    template <typename C, typename P>
    void FordJohnson(C &cont, P &pair)
    {
        sortPairs(cont, pair);
        sortHalfElements(0, cont, pair);
        // displayElements(cont);
        sortWithJacobs(0, cont, pair);

        if (isSorted(cont))
            std::cout << "Is sorted\n";
        else
            std::cout << "Is NOT sorted\n";
    }
};

# endif