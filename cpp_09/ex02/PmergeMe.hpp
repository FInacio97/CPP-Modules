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

        bool isNumber(const std::string &str);
        bool checkOverflow(std::string token);
        void doubleCheck(int ac);
        void parsing(int ac,char **av);
        void jacobsGenerator();
        void sorting();


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

        for (int i = 0; i < vec_size; i += 2)
        {
            if (cont[i] < cont[i + 1])
                pair.push_back(std::make_pair(cont[i], cont[i + 1]));
            else
                pair.push_back(std::make_pair(cont[i + 1], cont[i]));
        }

    }

    template <typename P>
    void orderPairs(unsigned long i, P &pair)
    {
        if (i >= pair.size())
            return ;

        for (unsigned long j = i + 1; j < pair.size(); j++)
        {
            if (pair[i].second > pair[j].second)
            {
                std::pair<int, int> temp = pair[i];
                pair[i] = pair[j];
                pair[j] = temp;
            }
        }
        orderPairs(i + 1, pair);
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

        if (pair.size() > 1)
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

        if (i >= (int)pair.size())
            i = (int)pair.size() - 1;
        // while ((int)pair.size()  i)
        // {
        //     i--;
        //     // std::cout << "vecPair size: " << pair.size() << std::endl;
        //     // std::cout << "index: " << i << std::endl;
        // }

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
        
    }

    template <typename C>
    bool isSorted(C &cont)
    {
        if ((int)cont.size() != _nbrElements)
        {
            std::cout << "wrong values\n";
            return (false);
        }

        for (int i = 0; i < (int)cont.size() - 1; i++)
        {
            if (cont[i] > cont[i + 1])
            {
                std::cout << "wrong order: " << cont[i] <<  " " << cont[i + 1] << std::endl;
                return (false);
            }
        }
        return (true);
    }

    template <typename C, typename P>
    void FordJohnson(C &cont, P &pair)
    {
        sortPairs(cont, pair);
        cont.clear();
        orderPairs(0, pair);

        for (unsigned long i = 0; i < pair.size(); i++)
            cont.push_back(pair[i].second);
        // sortHalfElements(0, cont, pair);
        // displayElements(cont);
        sortWithJacobs(0, cont, pair);
        if(_remainder != -1)
            sorter(-1, _remainder, cont);

        if (isSorted(cont))
            std::cout << "Is sorted\n";
        else
            std::cout << "Is NOT sorted\n";
    }
};

# endif