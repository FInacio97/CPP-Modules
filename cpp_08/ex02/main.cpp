# include "MutantStack.hpp"
# include <list>

int main()
{
    {
        std::cout << "+++++++ Mutantstack ++++++++\n";
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);

        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);

    }
    {
        std::cout << "\n+++++++ list ++++++++\n";
        std::list<int> mstack;
        
        mstack.push_back(5);
        mstack.push_back(17);
        
        {
        std::list<int>::iterator it = mstack.end();
        it--;
        std::cout << *(it) << std::endl;

        }
        
        mstack.pop_back();
        
        std::cout << mstack.size() << std::endl;
        
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);

        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(mstack);

    }

    {
        std::cout << "\n+++++++ My test ++++++++\n";
        MutantStack<int> a;

        a.push(1);
        a.push(2);
        a.push(3);
        a.push(4);
        a.push(5);
        a.push(6);
        a.push(7);

        MutantStack<int>::iterator it;

        std::cout << "\n++ Iterator ++\n";
        for (it = a.begin(); it != a.end(); it++)
            std::cout << *it << std::endl;

        // MutantStack<int>::const_iterator cit = a.begin();    // Should not compile
        // *cit = 4;

        MutantStack<int>::reverse_iterator rit = a.rbegin();

        // rit--;

        std::cout << "\n++ Reverse Iterator ++\n";
        for (; rit != a.rend(); rit++)
            std::cout << *rit << std::endl;
        // MutantStack<int>::const_reverse_iterator crit = a.begin();    // Should not compile
        // *crit = 4;
    }
}

/*

        1 2 3 4 5 6 7 end
*/