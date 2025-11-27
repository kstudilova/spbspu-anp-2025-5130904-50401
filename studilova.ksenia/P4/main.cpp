#include <iostream>

namespace studilova 
{

}


int main()
{
    const size_t max_input_size = 10000;
    char* input_string = new char[max_input_size];

    if (!std::cin.getline(input_string, max_input_size))
    {
        std::cerr << "Error: ";
        delete[] input_string;
        return 1;
    }
}