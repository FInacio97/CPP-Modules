# include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _nbrElements(-1), _remainder(-1) {}
PmergeMe::PmergeMe(const PmergeMe &src) : _nbrElements(-1), _remainder(-1) {(void)src;}
PmergeMe &PmergeMe::operator=(const PmergeMe &src) {(void)src; return(*this);}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isNumber(const std::string &str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it))
        it++;
    return (!str.empty() && it == str.end());
}

bool PmergeMe::checkOverflow(std::string token)
{
    const std::string maxInt = "2147483647";

    token.erase(0, token.find_first_not_of('0'));
    if (token.empty())
        return (false);
    if (token.length() > maxInt.size())
        return (false);
    if (token.length() < maxInt.size())
        return (true);
    return (token.compare(maxInt) <= 0);
}

void PmergeMe::doubleCheck(int ac)
{
    for (int i = 0; i < ac - 2; i++)
    {
        for (int j = i + 1; j < ac - 1; j++)
            if (_vec[i] == _vec[j])
                throw std::exception();
    }
}

void PmergeMe::parsing(int ac,char **av)
{
    int i = 0;
    int num;

    while (++i < ac)
    {
        if (!isNumber(av[i]) || !checkOverflow(av[i]))
            throw (std::exception());
        num = static_cast<int>(std::atoi(av[i]));
        _vec.push_back(num);
        _dq.push_back(num);
    }
    doubleCheck(ac);

    _nbrElements = _vec.size();
}

void PmergeMe::jacobsGenerator()
{
    _jacobs[0] = 0;
    _jacobs[1] = 1;
    _jacobs[2] = 1;

    int i = 2;
    while (++i < 33)
        _jacobs[i] = _jacobs[i - 1] + (_jacobs[i - 2] * 2);
}


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