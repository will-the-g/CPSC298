

#include <iostream>

int main()
{
    char* p_cArray = new char[2]; // allocate array of two characters
    
    *(p_cArray + 0) = 'A';
    *(p_cArray + 1) = '#';
    for (int i = 0; i < 2; i++){
        std::cout << "p_cArray[0]: " << p_cArray[i] << std::endl;
    }
    char* p_c = p_cArray;
    p_c++;
    std:cout << "p_c[0]: " << p_c[0] << std::endl;

}