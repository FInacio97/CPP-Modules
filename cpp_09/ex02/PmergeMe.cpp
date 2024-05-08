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
        _lst.push_back(num);
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

void PmergeMe::sortPairsVector()
{
    int vec_size = _vec.size();

    if (vec_size % 2 != 0)
    {
        _remainder = _vec.back();
        _vecPairs.pop_back();
    }

    for (int i = 0; i < vec_size; i += 2)
    {
        if (_vec[i] < _vec[i + 1])
            _vecPairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
        else
            _vecPairs.push_back(std::make_pair(_vec[i + 1], _vec[i]));
    }

    for (int i = 0; i < (vec_size / 2); i++)
        std::cout << _vecPairs[i].first << " | " << _vecPairs[i].second << std::endl;
}

void PmergeMe::sortHalfVector(int i)
{
    if (i == 0)
    {
        _vec.clear();
        _vec.push_back(_vecPairs[i].second);
        PmergeMe::sortHalfVector(i + 1);
    }
    else if (i == _nbrElements / 2)
        return ;
    else
    {
        _vec.insert(std::lower_bound(_vec.begin(), _vec.end(), _vecPairs[i].second), _vecPairs[i].second);
        PmergeMe::sortHalfVector(i + 1);   
    }
}

void PmergeMe::sorterVector(int maxValue, int toInsert)
{
    std::vector<int>::iterator end;

    for (unsigned long int i = 0; i < _vec.size(); i++)
    {
        if (_vec[i] == maxValue)
            end = _vec.begin() + i;
    }
    _vec.insert(std::lower_bound(_vec.begin(), end, toInsert), toInsert);
}

void PmergeMe::sortWithJacobsFirstElementsVector()
{

    sorterVector(_vecPairs[0].second, _vecPairs[0].first);

    sorterVector(_vecPairs[1].second, _vecPairs[1].first);
 
    std::cout << "\n\n++++++++++ for index: 0 ++++++++++\n";
    displayListOrVector(0); 

    sortWithJacobsVector(3);
}

void PmergeMe::sortWithJacobsVector(int jacobsIndex)
{
    if (jacobsIndex == 0)
    {
        sortWithJacobsFirstElementsVector();
        return ;
    }

    int i = _jacobs[jacobsIndex];

    while (_nbrElements <= i)
        i--;

    
    std::cout << "\n\n++++++++++ for index: " << jacobsIndex << "++++++++++\n";
    displayListOrVector(0); 
    
    
    if (_jacobs[jacobsIndex] >= (static_cast<int>(_vec.size() / 2)))
        return;
        
    std::cout << "\n\n";

    for (; i != _jacobs[jacobsIndex - 1]; i--)
    {
        std::cout << "inserting element[" << i << "]\n";
        sorterVector(_vecPairs[i].second, _vecPairs[i].first);
    }


    
    sortWithJacobsVector(jacobsIndex + 1);
}

void PmergeMe::displayListOrVector(int n)
{
    std::cout << "Number of elements: " << _vec.size() << std::endl;
    if (n == 0)
    {
        for (size_t i = 0; i < _vec.size(); i++)
            std::cout << _vec[i] << ", ";
        std::cout << std::endl;
    }
}