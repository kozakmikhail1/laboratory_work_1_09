#include "menu.h"

void Print_message_menu() {
  std::cout << "\n\tMENU" << std::endl;
  std::cout << "1.Creating string" << std::endl;
  std::cout << "2.Filling string" << std::endl;
  std::cout << "3.String output" << std::endl;
  std::cout << "4.Strings concatenate" << std::endl;
  std::cout << "5.Exit" << std::endl;
}

void Print_message_create_menu() {
  std::cout << "\nChoose which constructor to use to create matrices"
            << std::endl;
  std::cout << "1.Creating a default string" << std::endl;
  std::cout << "2.Creating a string with start value" << std::endl;
  std::cout << "3.Return to the main menu" << std::endl;
}

void Menu() {
  String *str_first = nullptr;
  String *str_second = nullptr;
  bool is_create = false;

  while (true) {
    Print_message_menu();
    std::cout << "\o{33}[33m""Enter the operation number ""\o{33}[0m" << std::endl;
    int choose = getDigit();

    switch (choose) {
    case 1: 
      delete str_first;
      delete str_second;
      str_first = nullptr;
      str_second = nullptr;

      Menu_Create_String(&str_first, &str_second);
      is_create = (str_first != nullptr && str_second != nullptr);
      break;

    case 2:
      if (is_create) {
        std::cout << "The first string" << std::endl;
        str_first->Fill();
        std::cout << "The second string" << std::endl;
        str_second->Fill();
      } else {
        std::cout << C_RED << "Error: strings not filled." << C_WHITE
                  << std::endl;
      }
      break;

    case 3: 
      if (is_create) {
        std::cout << "The first string" << std::endl;
        str_first->Show();
        std::cout << "The second string" << std::endl;
        str_second->Show();
      } else {
        std::cout << C_RED << "Error: strings not filled." << C_WHITE
                  << std::endl;
      }
      break;

    case 4: 
      if (!is_create) {
        std::cout << C_RED << "Error: strings not filled." << C_WHITE
                  << std::endl;
        break;
      }

      
      std::cout << "First string before subtraction" << std::endl;
      str_first->Show();
      str_first->Concatenate_strs(str_second);
      std::cout << "First string after concotanate" << std::endl;
      str_first->Show();
      
      break;

    case 5: 
      delete str_first;
      delete str_second;
      str_first = nullptr;
      str_second = nullptr;
      return;

    default:
      std::cout << C_RED << "Invalid choice, please try again." << C_WHITE
                << std::endl;
      break;
    }
  }
}

void Menu_Create_String(String **str_1, String **str_2) {
  delete *str_1;
  delete *str_2;
  *str_1 = nullptr;
  *str_2 = nullptr;
  Print_message_create_menu();
  while (true) {
    std::cout << "Enter the operation number " << std::endl;
    int choose = getDigit();

    switch (choose) {
    case 1:
    {
      *str_1 = new String();
      *str_2 = new String();
      return;
    }
    case 2:
    {
      std::cout << "The first string" << std::endl;
      char * input_user = nullptr;
      input_user = Get_Line();
      *str_1 = new String(input_user);

      std::cout << "The secound string" << std::endl;
      input_user = Get_Line();
      *str_2 = new String(input_user);
      return;
    }
    case 3:
      return;
    default:
      std::cout << C_RED << "You make mistake, try again" << C_WHITE
                << std::endl;
      break;
    }
  }
}
