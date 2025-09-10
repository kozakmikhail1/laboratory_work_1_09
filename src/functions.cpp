#include "functions.h"
#include "string.h"

char * Get_Line()
{
  char *str{};
  char symbol;

  while(std::cin.get(symbol), symbol != '\n')
  {
    int lenght = Find_Lenght(str);
    auto temp = new char [lenght + 2];
    for(int i = 0;i < lenght;i++)
    {
      temp[i] = str[i];
    }
    temp[lenght] = symbol;
    temp[lenght + 1] = '\0';

    delete[] str;
    str = temp;
  }
  return str;
}
int Find_Lenght(const char *str_)
{
  if(str_ == nullptr)
    return 0;
  int size = 0;
  while(str_[size] != '\0')
  {
    size++;
  }
  return size;
}

int getDigit() 
{
    int check = 0;

    while (true) {
        check = std::cin.get();

        if (check != '\n' && check != EOF) {
            if (isdigit(check) == 1 && std::cin.get() == '\n') {
                return check - '0';
            }

            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
        }

        std::cout << C_RED << "\nError, invalid input. Please try again: " << C_WHITE;
    }
}
