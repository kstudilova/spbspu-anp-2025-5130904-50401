#include <iostream>
#include <cstddef>

namespace studilova 
{
  char* readLine();
  size_t stringLength(const char* str);
  size_t extractCommonChars(const char* input, char* output, size_t output_size);
  size_t removeVowels(const char* input, char* output, size_t output_size);
}

char* studilova::readLine()
{
  const size_t first_capacity = 32;
  size_t capacity = first_capacity;
  size_t length = 0;

  char* buffer = nullptr;
  try {
    buffer = new char[capacity];
  } catch (...) {
    return nullptr;
  }

  char ch;
  while (std::cin.get(ch) && ch != '\n')
  {
    if (length + 1 >= capacity)
    {
      size_t new_capacity = capacity * 2;
      char* new_buffer = nullptr;
      try {
        new_buffer = new char[new_capacity];
      } catch (...) {
        delete[] buffer;
        return nullptr;
      }

      for (size_t i = 0; i < length; ++i)
      {
        new_buffer[i] = buffer[i];
      }

      delete[] buffer;
      buffer = new_buffer;
      capacity = new_capacity;
    }

    buffer[length] = ch;
    length++;
  }

  if (length == 0)
  {
    if (std::cin.eof())
    {
      delete[] buffer;
      return nullptr;
    }
    else
    {
      buffer[0] = '\0';
      return buffer;
    }
  }

  buffer[length] = '\0';
  return buffer;
}

size_t studilova::stringLength(const char* str)
{
  size_t len = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    len++;
  }
  return len;
}

size_t studilova::extractCommonChars(const char* input, char* output, size_t output_size)
{

}

size_t studilova::removeVowels(const char* input, char* output, size_t output_size)
{

}

int main()
{
  char* input_string = nullptr;
  char* result1 = nullptr;
  char* result2 = nullptr;

  input_string = studilova::readLine();

  if (!input_string)
  {
    std::cerr << "Input error" << "\n";
    return 1;
  }

  size_t input_len = studilova::stringLength(input_string);

  result1 = new char[input_len + 1];
  result2 = new char[input_len + 1];

  studilova::extractCommonChars(input_string, result1, input_len + 1);
  studilova::removeVowels(input_string, result2, input_len + 1);



  std::cout << result1 << "\n";
  std::cout << result2 << "\n";
}
