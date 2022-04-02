#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
int main() {
  char login_password[20];
  char stored_password[20];
  char login_username[20];
  char stored_username[20];

  fstream pull("users.txt", ios::in);
  if (!pull) {
    cout << "File not loaded!" << endl;
    return -1;
  }
  cout << "Username: ";
  cin >> login_username;
  while (strcmp(login_username, stored_username)) {

    // if login and stored usernames are equal, function strcmp returns 0,
    // at first loop they are certainly not, so it is: while(1)

    pull >> stored_username;
    if (pull.eof()) { // if it is the end of file
      cout << "Username does not exist. " << endl;
      return -1;
    }
  }
  pull >> stored_password;

  // since username and password are in the same line, password next to
  // correctly inputted username is saved in stored_password

  cout << "Password: ";
  // now user enters password to confirm username
  cin >> login_password;
  while (strcmp(stored_password, login_password)) {
    cout << "Wrong password. " << endl;
    cout << "Try again: ";
    cin >> login_password;
  }
  cout << "Login successful." << endl;
  return 0;
}