#include <iostream>
#include <string>
#include <cctype>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool validate_password(string password){
  char c;
  int c_alp = 0;
  int c_up = 0;
  int c_dig = 0;
  int c_spe = 0;
  for (int i = 0; i < password.length(); i++){
    c = password[i];
    if (islower(c))
      c_alp = c_alp + 1;
    else if (isupper(c))
      c_up = c_up + 1;
    else if (isdigit(c))
      c_dig = c_dig + 1;
    else
      c_spe = c_spe + 1;
  }
  if ((password.length() >= 8) && (c_alp >= 2) && (c_up >= 1) && (c_dig >= 1) && (c_spe >= 1)){
    cout << password << " is a valid password!\n";
    return true;
  }
  else{
    if (password.length() < 8){
      cout << "Password needs to be  at least 8 characters long\n";
      return false;
    }
    else if (c_alp < 2){
      cout << "Password needs to contain at least two lower characters\n";
      return false;
    }
    else if (c_up < 1){
      cout << "Password needs to contain at least one upper character\n";
      return false;
    }
    else if (c_dig < 1){
      cout << "Password needs to have at least 1 digit\n";
      return false;
    }
    else if (c_spe < 1){
      cout << "Password needs to have at least 1 special character, e.g, !@#$%&.\n";
      return false;
    }
    else
      return false;
  }
}

int choice_array(){
  //srand(time(NULL));
  int i = rand() % 5;
  if (i == 0)
      i++;
  return i;
}

int getkey(){
  //srand(time(NULL));
  int i = rand() % 26;
  return i;
}

int main(){
  int choice, key;
  int password_length = 0;
  string password = "";
  string password_val = "";
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string esp_symbol = "!@#$%&";
  string number = "0123456789";
  srand(time(NULL));

  do{
    cout << "\n---------------------------------------------------\n";
    cout << "  Password Validator and Random Password Generator\n";
    cout << "---------------------------------------------------\n\n";
    cout << "    1. Validate Password" << "\n";
    cout << "    2. Generate Password" << "\n";
    cout << "    3. Exit" << "\n\n";
    cout << "Press key 1, 2, or 3: ";
    cin >> choice;

    if (choice == 1){
      cout << "Enter Password:  ";
      cin >> password_val;
      validate_password(password_val);
    }
    else if (choice == 2){
      cout << "Enter the lenght of your desired password:  ";
      cin >> password_length;
      for (int x=0; x < password_length; x++){
        int option = choice_array();
        cout << option;
        switch(option){
          case 1:
            key = getkey();
            password = password + alphabet[key];
            break;
          case 2:
            key = getkey();
            password = password + ALPHABET[key];
            break;
          case 3:
            key = getkey();
            key = key % 10;
            password = password + number[key];
            break;
          case 4:
            key = getkey();
            key = key % 6;
            password = password + esp_symbol[key];
            break;
        }
      }
      cout << "Your new password is: " << password;
      password = "";
    }
  } while(choice != 3);
  return 0;
}
