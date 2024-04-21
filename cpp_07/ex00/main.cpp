# include "whatever.hpp"
# include <string>

int main()
{
    {
        int x = 1;
        int y = 2;

        swap(x, y);

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;

        int z = min(x, y);

        std::cout << "value of z: " << z << std::endl;

        z = max(x, y);

        std::cout << "value of z: " << z << std::endl;
    }

    {
        char x = 'x';
        char y = 'y';

        swap(x, y);

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    }

    {
        float x = 1;
        float y = 2;

        swap(x, y);

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    }


    std::cout << "\n++++++++++++ Subject's test +++++++++++\n";
    {
        int a = 2;
        int b = 3;
        
        ::swap( a, b );
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        return 0;
}
}