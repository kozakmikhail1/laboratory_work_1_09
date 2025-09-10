#pragma once
#include <iostream>

class String 
{
  private : 

  char *date;
  int lenght;
  int capacity;

  public:
  String();
  explicit String(char *str);

  int Get_Lenght(){return lenght;}
  char Get_Symbol(int index){return date[index];}

  void Show();
  void Fill();
  void Concatenate_strs(String* str);
};