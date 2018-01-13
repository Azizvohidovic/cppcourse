#include <iostream>

int main()
{
    int a;
    std::cout << "Input drink number: ";
    std::cin >> a;

    switch (a)
    {
    case 1:
        std::cout << "water" << std::endl;
        break;

    case 2:
        std::cout << "cocacola" << std::endl;
        break;

    case 3:
        std::cout << "coffee" << std::endl;
        break;
    case 4:
        std::cout << "tea" << std::endl;
        break;
    case 5:
        std::cout << "milk" << std::endl;
        break;
    case 6:
        std::cout << "soda" << std::endl;
        break;
    default:
        std::cout << "no such drink" << std::endl;
    }
}