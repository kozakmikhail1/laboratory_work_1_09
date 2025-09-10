#include "string.h"
#include "functions.h"


String::String() : date(nullptr), lenght(0), capacity(0){} 

String::String(char * input_str) : lenght(Find_Lenght(input_str)), capacity(lenght + 1)
{
  int index = 0;
  date = new char[capacity];
  for(;index < Find_Lenght(input_str);index++)
  {
    date[index] = input_str[index];
  }
}

void String::Show()
{
  if(date == nullptr)
    return;
  for(int i = 0;date[i] != '\n' && date[i] != '\0';i++)
    std::cout << date[i];
  std::cout << std::endl;
}

void String::Fill()
{

  date = Get_Line();
  lenght = Find_Lenght(date);
  capacity = lenght;
}

void String::Concatenate_strs(String* str)
{
  capacity += str->Get_Lenght();
  auto temp = new char [capacity];
  int index = 0;

  for(;index < lenght;index++)
  {
    temp[index] = date[index];
  }
  delete[] date;
  date = temp;

  for(int i = 0;i < str->Get_Lenght();i++ )
  {
    date[index] = str->Get_Symbol(i);
    index++;
  }
  date[index] = '\0';
}
