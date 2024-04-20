# include "Serializer.hpp"

int main()
{
    Data cenas(2344);

    uintptr_t ptr = Serializer::serialize(&cenas);
    Data *cenas2 = Serializer::deserialize(ptr);

    std::cout << "address of cenas by the  original: " << &cenas << std::endl;
    std::cout << "address of cenas by serialization: " << cenas2 << std::endl << std::endl;

    std::cout << "value of cenas by the  original: " << cenas.getValue() << std::endl;
    std::cout << "value of cenas by serialization: " << cenas2->getValue() << std::endl << std::endl;

    cenas.setValue(3);

    std::cout << "value of cenas by the  original: " << cenas.getValue() << std::endl;
    std::cout << "value of cenas by serialization: " << cenas2->getValue() << std::endl << std::endl;

    cenas2->setValue(54);

    std::cout << "value of cenas by the  original: " << cenas.getValue() << std::endl;
    std::cout << "value of cenas by serialization: " << cenas2->getValue() << std::endl << std::endl;
}