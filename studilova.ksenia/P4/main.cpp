#include <iostream>

namespace studilova 
{
    size_t string_length(const char* str);
}

size_t studilova::string_length(const char* str)
{
    size_t len = 0;
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        len++;
    }
    return len;
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

    if (!input_string)
    {
        std::cerr << "Memory allocation error\n";
        return 1;
    }

    size_t input_len = studilova::string_length(input_string);
}
