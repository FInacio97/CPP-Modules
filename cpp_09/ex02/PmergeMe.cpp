# include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _nbrElements(-1), _remainder(-1) {}
PmergeMe::PmergeMe(const PmergeMe &src) : _nbrElements(-1), _remainder(-1) {(void)src;}
PmergeMe &PmergeMe::operator=(const PmergeMe &src) {(void)src; return(*this);}
PmergeMe::~PmergeMe() {}

void PmergeMe::parsing(int ac,char **av)
{
    std::cout << "DO THE FOCKING PARSING!!!!!!!\n\n\n";

    int i = 0;
    int num;

    while (++i < ac)
    {
        num = static_cast<int>(std::atoi(av[i]));
        _vec.push_back(num);
        _dq.push_back(num);
    }

    _nbrElements = _vec.size();
    // {
    //     std::vector<int>::iterator it = _vec.begin();
    //     for (; it != _vec.end(); it++)
    //         std::cout << *it << std::endl;
    // }

    // {
    //     std::list<int>::iterator it = _lst.begin();
    //     for (; it != _lst.end(); it++)
    //         std::cout << *it << std::endl;
    // }
}

void PmergeMe::jacobsGenerator()
{
    _jacobs[0] = 0;
    _jacobs[1] = 1;
    _jacobs[2] = 1;

    int i = 2;
    while (++i < 33)
        _jacobs[i] = _jacobs[i - 1] + (_jacobs[i - 2] * 2);

    // i = -1;
    // while (++i < 33)
    //     std::cout << "element[" << i << "] " << _jacobs[i] << std::endl;
}

// void PmergeMe::sortPairsVector()
// {
//     int vec_size = _vec.size();

//     if (vec_size % 2 != 0)
//     {
//         _remainder = _vec.back();
//         _vec.pop_back();
//         vec_size--;
//     }
//     displayListOrVector(0);

//     for (int i = 0; i < vec_size; i += 2)
//     {
//         if (_vec[i] < _vec[i + 1])
//             _vecPairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
//         else
//             _vecPairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));
//     }

//     for (int i = 0; i < (vec_size / 2); i++)
//         std::cout << _vecPairs[i].first << " | " << _vecPairs[i].second << std::endl;
// }

// void PmergeMe::sortHalfVector(int i)
// {
//     if (i == 0)
//     {
//         _vec.clear();
//         _vec.push_back(_vecPairs[i].second);
//         PmergeMe::sortHalfVector(i + 1);
//     }
//     else if (i == _nbrElements / 2)
//         return ;
//     else
//     {
//         _vec.insert(std::lower_bound(_vec.begin(), _vec.end(), _vecPairs[i].second), _vecPairs[i].second);
//         PmergeMe::sortHalfVector(i + 1);   
//     }
// }

// void PmergeMe::sorterVector(int maxValue, int toInsert)
// {
//     std::vector<int>::iterator end;

//     for (unsigned long int i = 0; i < _vec.size(); i++)
//     {
//         if (_vec[i] == maxValue)
//             end = _vec.begin() + i;
//     }
//     if (maxValue == -1)
//         end = _vec.end();
//     _vec.insert(std::lower_bound(_vec.begin(), end, toInsert), toInsert);
// }

// void PmergeMe::sortWithJacobsFirstElementsVector()
// {

//     sorterVector(_vecPairs[0].second, _vecPairs[0].first);

//     sorterVector(_vecPairs[1].second, _vecPairs[1].first);
 
//     std::cout << "\n\n++++++++++ for index: 0 ++++++++++\n";
//     displayElements(_vec);

//     sortWithJacobsVector(3);
// }

// void PmergeMe::sortWithJacobsVector(int jacobsIndex)
// {
//     std::cout << "\n\n++++++++++ for index: " << jacobsIndex << "++++++++++\n";
//     if (jacobsIndex == 0)
//     {
//         sortWithJacobsFirstElementsVector();
//         return ;
//     }

//     int i = _jacobs[jacobsIndex];
//     std::cout << "starting index: " << i << std::endl;

//     while ((int)_vecPairs.size() <= i)
//     {
//         i--;
//         std::cout << "vecPair size: " << _vecPairs.size() << std::endl;
//         std::cout << "index: " << i << std::endl;
//     }

//     std::cout << "index: " << i << std::endl;

    
    
    
//     if (i >= (static_cast<int>(_vecPairs.size())))
//         return;
        
//     std::cout << "\n\n";

//     std::cout << "here\n";
//     std::cout << "jacos index - 1: " << jacobsIndex - 1 << std::endl;
//     for (; i > _jacobs[jacobsIndex - 1]; i--)
//     {
//         std::cout << "inserting element[" << i << "]\n";
//         sorterVector(_vecPairs[i].second, _vecPairs[i].first);
//     }
//     displayElements(_vec);

//     if (_jacobs[jacobsIndex] > (int)_vecPairs.size())
//         return ;
//     sortWithJacobsVector(jacobsIndex + 1);
//     if(jacobsIndex == 3 && _remainder != -1)
//     {
//         std::cout << "remainder: " << _remainder << std::endl;
//         sorterVector(-1, _remainder);
//     }
// }

// // void PmergeMe::displayListOrVector(int n)
// // {
// //     std::cout << "Number of elements: " << _vec.size() << std::endl;
// //     if (n == 0)
// //     {
// //         for (size_t i = 0; i < _vec.size(); i++)
// //             std::cout << _vec[i] << ", ";
// //         std::cout << std::endl;
// //     }
// // }

// bool PmergeMe::isSorted()
// {
//     if ((int)_vec.size() != _nbrElements)
//     {
//         std::cout << "wrong values\n";
//         return (false);
//     }
    
//     for (int i = 0; i < (int)_vec.size() - 1; i++)
//     {
//         if (_vec[i] > _vec[i + 1])
//         {
//             std::cout << "wrong order: " << _vec[i] <<  " " << _vec[i + 1] << std::endl;
//             return (false);
//         }
//     }
//     return (true);
// }

// void PmergeMe::FordJohnson()
// {
    
//     sortPairs(_vec, _vecPairs);
//     sortHalfElements(0, _vec, _vecPairs);
//     displayElements(_vec);
//     sortWithJacobs(0, _vec, _vecPairs);

//     sortPairs(_dq, _dqPairs);
//     sortHalfElements(0, _dq, _dqPairs);
//     displayElements(_dq);
//     sortWithJacobs(0, _dq, _dqPairs);

//     if (isSorted(_vec))
//         std::cout << "Is sorted\n";
//     else
//         std::cout << "Is NOT sorted\n";

//     if (isSorted(_dq))
//         std::cout << "Is sorted\n";
//     else
//         std::cout << "Is NOT sorted\n";
// }

void PmergeMe::sorting()
{
    long    timeVector;
    long    timeDeque;
    long    timeStamp;


    std::cout <<  "Before: ";
    displayElements(_vec);

    timeStamp = clock();
    FordJohnson(_vec, _vecPairs);
    timeVector = clock() - timeStamp;
    std::cout <<  "After: ";
    displayElements(_vec);
    timeStamp = clock();
    FordJohnson(_dq, _dqPairs);
    timeDeque = clock() - timeStamp;

    std::cout << "Time to process a range of " << _nbrElements
         << " with std::vector: " << timeVector << " us\n";
    std::cout << "Time to process a range of " << _nbrElements
         << " with std::deque: " << timeDeque << " us\n";
}