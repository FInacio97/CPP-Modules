# include "Serializer.hpp"

int main()
{
    Data cenas(2344);

    uintptr_t ptr = Serializer::serialize(&cenas);
    Data *cenas2 = Serializer::deserialize(ptr);

    std::cout << "address of cenas by cenas:         " << &cenas << std::endl;
    std::cout << "address of cenas by serialization: " << cenas2 << std::endl;

}