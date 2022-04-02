#include <cstdlib>
#include <cstring>
#include <direct.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

const std::string currentDateTime();

class Bank {
private:
  bool loginStatus = false;
  bool flag = false;
  bool flag2 = false;
  char directoryName[10];
  char qt_menu;
  char name[20];
  char lname[20];
  string nameAcc;
  string IdNumber;
  string forgotIdNumber;
  string birthDate;
  string telNum;
  string accType;
  string address;
  string userName;
  string userNameSignIn;
  string cusAccNumber;
  unsigned long customerAccNumber;
  unsigned long customerAccNumber2;
  int age;
  int choiceAccType;
  int passWord;
  int passWordSignIn;
  int confirmPassWord;
  int forgetConfirmPass;
  int startAccNum;
  int initial = 0, deposit = 0, withdraw = 0, totalDeposit = 0,
      totalWithdraw = 0;

public:
  Bank() {}
  void mainMenu();
  void menu();
  void create();
  void signIn();
  void depo();
  void check();
  void withd();
  void accDetails();
  void forgotPassword();
  void stateMent();
  void dailyReport();
  void depositReport();
  void withdrawReport();
  void stateMentReportFromAccNum();
  int CheckCreateAccount();
  int userpass();
  char *convertToChar(string convert);
  void rememberDataAfterLogout();
};

void Bank::menu() { // เมนูหลัก
  int choice;
  cout << "*************************************************************"
       << endl;
  cout << endl;
  cout << "\n\t BANK MANAGEMENT SYSTEM  \n" << endl;
  cout << "\t Choose from menu below " << endl;
  cout << "\t 1.Create account " << endl;
  cout << "\t 2.Log in (First time login)" << endl;
  cout << "\t 3.Log in (Already have an account) " << endl;
  cout << endl;
  cout << "*************************************************************"
       << endl;
  cout << endl;
  cout << "\tYour choice : ";
  cin >> choice;

  if (choice == 1) {
    withdraw = 0;
    deposit = 0;
    totalDeposit = 0;
    totalWithdraw = 0;
    initial = 0;
    create();
  } else if (choice == 2) {
    signIn();
  } else if (choice == 3) {
    userpass();
  }
}

void Bank::mainMenu() { // เมนูรอง
  int choice;
  cout << "*************************************************************"
       << endl;
  cout << endl;
  cout << "\n\t BANK MANAGEMENT SYSTEM  \n" << endl;
  cout << "\t Choose from menu below " << endl;
  cout << "\t 1.Deposit balance " << endl;
  cout << "\t 2.Withdraw balance " << endl;
  cout << "\t 3.Check balance " << endl;
  cout << "\t 4.Account details " << endl;
  cout << "\t 5.Daily report " << endl;
  cout << "\t 6.Deposit report " << endl;
  cout << "\t 7.Withdraw report " << endl;
  cout << "\t 8.Statment report " << endl;
  cout << "\t 9.Logout \n" << endl;
  cout << endl;
  cout << "*************************************************************"
       << endl;
  cout << endl;
  cout << "\tYour choice : ";
  cin >> choice;

  if (choice == 1) {
    depo();
  } else if (choice == 2) {
    withd();
  } else if (choice == 3) {
    check();
  } else if (choice == 4) {
    accDetails();
  } else if (choice == 5) {
    dailyReport();
  } else if (choice == 6) {
    depositReport();
  } else if (choice == 7) {
    withdrawReport();
  } else if (choice == 8) {
    stateMent();
  } else if (choice == 9) {
    rememberDataAfterLogout();
    menu();
  }
}

void Bank::create() { // สร้าง Account
  
  fstream customerFile;
  customerAccNumber = (CheckCreateAccount()+1);
  cusAccNumber = to_string(customerAccNumber);
  _mkdir(convertToChar(cusAccNumber));
  cout << "\n\t Your Account Number : " << customerAccNumber;
  customerFile.open("Useraccnum.txt", ios::app);
  if (customerFile.is_open()) {
    customerFile << "\n" << customerAccNumber;
  }
  customerFile.close();
  cout << "\n\t Enter your username : ";
  cin >> userName;
  cout << "\t Enter your password : ";
  cin >> passWord;
  do {
    cout << "\t Confirm your password : ";
    cin >> confirmPassWord;
  } while (passWord != confirmPassWord);
  cout << "\t Enter your name and lastname: ";
  cin >> name >> lname;
  cout << "\t Enter your identification number : ";
  cin >> IdNumber;
  cout << "\t Enter your age : ";
  cin >> age;
  cout << "\t Enter your birthdate (DD/MM/YY) : ";
  cin >> birthDate;
  cin.ignore();
  cout << "\t Enter your address : ";
  getline(cin, address);
  cout << "\t Enter your telephone number : ";
  cin >> telNum;
  cout << "\n\t Choose your account type : ";
  cout << "\n\t 1.(Saving Deposit Account) ";
  cout << "\n\t 2.(Fixed Deposit Account) ";
  cout << "\n\t 3.(Current Account) ";
  cout << "\n\t 4.(Foreign Currency Deposit Account) \n";
  cout << endl;
  cout << "*************************************************************"
       << endl;
  cout << "\n\t Your choice : ";
  cin >> choiceAccType;
  if (choiceAccType == 1) {
    accType = "Saving Deposit Account ";
  } else if (choiceAccType == 2) {
    accType = "Fixed Deposit Account ";
  } else if (choiceAccType == 3) {
    accType = "Current Account ";
  } else if (choiceAccType == 4) {
    accType = "Foreign Currency Deposit Account ";
  }
  customerFile.open(cusAccNumber + "\\Bank Account Details.txt", ios::out);
  if (customerFile.is_open()) {
    customerFile
        << "********************BANK ACCOUNT DEATAILS******************"
        << endl;
    customerFile << "\n Your Account Number : " << customerAccNumber;
    customerFile << "\n Your username : " << userName;
    customerFile << "\n Your password : " << passWord;
    customerFile << "\n Your name and lastname: " << name << lname;
    customerFile << "\n Your identification number : " << IdNumber;
    customerFile << "\n Your age : " << age;
    customerFile << "\n Your birthdate (DD/MM/YY) : " << birthDate;
    customerFile << "\n Your address : " << address;
    customerFile << "\n Your telephone number : " << telNum;
    customerFile << "\n Your account type : " << accType;
    customerFile << endl;
  }
  customerFile.close();
  customerFile.open(cusAccNumber + "\\Statement report.txt", ios::out);
  if (customerFile.is_open()) {
    customerFile << "********************STATEMENT REPORT******************"
                 << endl;
    customerFile << "\n Your Account Number : " << customerAccNumber;
    customerFile << "\n Your name and lastname: " << name << " " << lname;
    customerFile << "\n Your account type : " << accType << endl;
    customerFile.close();
  }
  customerFile.close();
  customerFile.open(cusAccNumber + "\\Daily report.txt", ios::out);
  if (customerFile.is_open()) {
    customerFile << "********************DAILY REPORT******************"
                 << endl;
    customerFile << "\n Your Account Number : " << customerAccNumber;
    customerFile << "\n Your name and lastname: " << name << " " << lname;
    customerFile << "\n Your account type : " << accType << endl;
    customerFile.close();
  }
  customerFile.open(cusAccNumber + "\\Deposit report.txt", ios::out);
  if (customerFile.is_open()) {
    customerFile << "********************DEPOSIT REPORT******************"
                 << endl;
    customerFile << "\n Your Account Number : " << customerAccNumber;
    customerFile << "\n Your name and lastname: " << name << " " << lname;
    customerFile << "\n Your account type : " << accType << endl;
    customerFile.close();
  }
  customerFile.open(cusAccNumber + "\\Withdraw report.txt", ios::out);
  if (customerFile.is_open()) {
    customerFile << "********************WITHDRAW REPORT******************"
                 << endl;
    customerFile << "\n Your Account Number : " << customerAccNumber;
    customerFile << "\n Your name and lastname: " << name << " " << lname;
    customerFile << "\n Your account type : " << accType << endl;
    customerFile.close();
  }
  cout << endl;
  cout << "\tSuccess to create account!\n";
  cout << "\tYou can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    menu();
  }
}

void Bank::signIn() { // log in ครั้งเเรก
  int count = 3;
  cout << "\n\t Enter your username : ";
  cin >> userNameSignIn;
  cout << "\t Enter your password : ";
  cin >> passWordSignIn;
  if ((userName == userNameSignIn) && (passWord == passWordSignIn)) {
    cout << "\n\t Login successful ! ";
    mainMenu();
  } else if (userName == userNameSignIn) {
    if (passWord != passWordSignIn) {
      do {
        cout << "\n\t Your password incorrect ! ";
        cout << "\n\t You can enter wrongly " << count << " more times ";
        cout << "\n\t Enter your username : ";
        cin >> userNameSignIn;
        cout << "\t Enter your password : ";
        cin >> passWordSignIn;
        count--;
      } while (passWord != passWordSignIn && count != 0);
      if (passWord == passWordSignIn) {
        mainMenu();
      }
      cout << "\n\t Back to menu pls press 'b' : ";
      cin >> qt_menu;
      if (qt_menu == 'b') {
        menu();
      }
    }
  } else if (userName != userNameSignIn) {
    if (passWord == passWordSignIn) {
      do {
        cout << "\n\t Your username incorrect ! ";
        cout << "\n\t You can enter wrongly " << count << " more times ";
        cout << "\n\t Enter your username : ";
        cin >> userNameSignIn;
        cout << "\t Enter your password : ";
        cin >> passWordSignIn;
        count--;
      } while (userName != userNameSignIn && count != 0);
      if (userName == userNameSignIn) {
        mainMenu();
      }
      cout << "\n\t Back to menu pls press 'b' : ";
      cin >> qt_menu;
      if (qt_menu == 'b') {
        menu();
      }
    }
  } else {
    cout << "\n\t You need to create account first!! ";
    cout << "\n\t Back to menu pls press 'b' : ";
    cin >> qt_menu;
    if (qt_menu == 'b') {
      menu();
    }
  }
}

void Bank::depo() { // ฝากเงิน
  cout << "\n\t Enter your account number : ";
  cin >> customerAccNumber2;
  if (customerAccNumber2 == customerAccNumber) {
    cout << "\n\t Enter deposit amount TH/Bath : ";
    cin >> deposit;
    totalDeposit += deposit;
    flag = true;
    cout << endl;
    initial += deposit;
    fstream customerFile;
    customerFile.open(cusAccNumber + "\\Statement report.txt", ios::app);
    if (customerFile.is_open()) {
      customerFile << " " << currentDateTime() << " // Deposit = " << deposit << endl;
      customerFile.close();
    }
    customerFile.open(cusAccNumber + "\\Daily report.txt", ios::app);
    if (customerFile.is_open()) {
      customerFile << " " << currentDateTime() << " // Deposit = " << deposit << endl;
      customerFile.close();
    }
    customerFile.open(cusAccNumber + "\\Deposit report.txt", ios::app);
    if (customerFile.is_open()) {
      customerFile << " " << currentDateTime() << " // Deposit = " << deposit << endl;
      customerFile.close();
    }
    cout << "\tSuccess to deposit balance!\n";
  } else {
    cout << "\tYou account number is wrong! ";
    cout << "\tFailed to deposit!\n";
  }
  cout << "\tYou can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

void Bank::withd() { // ถอนเงิน
  cout << "\n\t Enter your account number : ";
  cin >> customerAccNumber2;
  if (customerAccNumber2 == customerAccNumber) {
    cout << "\n\t Enter withdraw amount TH/Bath : ";
    cin >> withdraw;
    if (initial >= withdraw && initial != 0) {
      initial -= withdraw;
      totalWithdraw += withdraw;
      fstream customerFile;
      customerFile.open(cusAccNumber + "\\Statement report.txt", ios::app);
      if (customerFile.is_open()) {
        customerFile << " " << currentDateTime() << " // Withdraw = " << withdraw << endl;
      customerFile.close();
      }
      customerFile.open(cusAccNumber + "\\Daily report.txt", ios::app);
      if (customerFile.is_open()) {
        customerFile << " " << currentDateTime() << " // Withdraw = " << withdraw << endl;
        customerFile.close();
      }
      customerFile.open(cusAccNumber + "\\Withdraw report.txt", ios::app);
      if (customerFile.is_open()) {
        customerFile << " " << currentDateTime() << " // Withdraw = " << withdraw << endl;
        customerFile.close();
      }
      cout << "\tSuccess to withdraw!\n";
    } else {
      cout << "\tYou balance is not enough! ";
    }
  } else {
    cout << "\tYou account number is wrong! ";
    cout << "\tFailed to Withdraw!\n";
  }
  cout << endl;
  cout << "\tYou can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

void Bank::check() { // check ยอดเงินคงเหลือ
  if (flag == true) {
    cout << "\n\tTotal available fund : " << initial << endl;
    cout << endl;
    flag = false;
  } else {
    cout << "\n\tTotal available fund : " << initial << endl;
    cout << endl;
    flag = false;
  }
  cout << "\tSuccess to Check Balance!\n";
  cout << "\tYou can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

void Bank::accDetails() { // รายละเอีด account
  fstream customerFile;
  customerFile.open(cusAccNumber + "\\Bank Account Details.txt", ios::in);
  if (customerFile.is_open()) {
        string line;
        while (getline(customerFile, line)) {
                 cout << line << endl;
        }
    customerFile.close();
  }
  cout << " Your total deposit = " << totalDeposit << endl;
  cout << " Your total withdraw = " << totalWithdraw << endl;
  cout << " Your total balance = " << initial << endl;
  cout << "\n*************************************************************" << endl;
  cout << "\n\tSuccess to Display Account Details\n";
  cout << "\tYou can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

void Bank::stateMent() { // ดู statement
  fstream customerFile;
  customerFile.open(cusAccNumber + "\\Statement report.txt", ios::in);
  if (customerFile.is_open()) {
    string line;
    while (getline(customerFile, line)) {
      cout << line << endl;
    }
    customerFile.close();
  }
  cout << " Your total deposit = " << totalDeposit << endl;
  cout << " Your total withdraw = " << totalWithdraw << endl;
  cout << " Your total balance = " << initial << endl;
  cout << "\n*************************************************************";
  cout << endl;
  cout << "\t Statement report success!\n";
  cout << "\t You can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

void Bank::dailyReport() { // รายงานรายวัน
  fstream customerFile;
  customerFile.open(cusAccNumber + "\\Daily report.txt", ios::in);
  if (customerFile.is_open()) {
    string line;
    while (getline(customerFile, line)) {
      cout << line << endl;
    }
    customerFile.close();
  }
  cout << " Your total deposit = " << totalDeposit << endl;
  cout << " Your total withdraw = " << totalWithdraw << endl;
  cout << " Your total balance = " << initial << endl;
  cout << endl << endl;
  cout << "\t Deposit report success!\n";
  cout << "\t You can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

void Bank::depositReport() { // รายงานฝาก
  fstream customerFile;
  customerFile.open(cusAccNumber + "\\Deposit report.txt", ios::in);
  if (customerFile.is_open()) {
    string line;
    while (getline(customerFile, line)) {
      cout << line << endl;
    }
    customerFile.close();
  }
  cout << " Your total deposit = " << totalDeposit << endl;
  cout << " Your total balance = " << initial << endl;
  cout << endl << endl;
  cout << "\t Deposit report success!\n";
  cout << "\t You can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

void Bank::withdrawReport() { // รายงานถอน
  fstream customerFile;
  customerFile.open(cusAccNumber + "\\Withdraw report.txt", ios::in);
  if (customerFile.is_open()) {
    string line;
    while (getline(customerFile, line)) {
      cout << line << endl;
    }
    customerFile.close();
  }
  cout << " Your total withdraw = " << totalWithdraw << endl;
  cout << " Your total balance = " << initial << endl;
  cout << endl << endl;
  cout << "\t Wtihdraw report success!\n";
  cout << "\t You can exit to menu pls press 'q' : ";
  cin >> qt_menu;
  cout << endl;
  if (qt_menu == 'q') {
    mainMenu();
  }
}

const std::string currentDateTime() { // เรียกเวลาปัจจุบัน
  time_t now = time(0);
  struct tm tstruct;
  char buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
  return buf;
}

int Bank::userpass() { // login เเบบมี account เเล้ว
    char login_password[20];
    char stored_password[20];
    char login_username[20];
    char stored_username[20];
    char stored_accountnumber[10];
    int stored_totalDeposit;
    int stored_totalWithdraw;
    int stored_totalBalance;

    cout << "\tEnter your account number : ";
    cin >> customerAccNumber;
    cusAccNumber = to_string(customerAccNumber);
    fstream pull(cusAccNumber+ "\\Userpass.txt", ios::in);
    if (!pull) {
      cout << "\tFile not loaded!" << endl;
      return -1;
    }
    cout << "\tEnter your username: ";
    cin >> login_username;
    while (strcmp(login_username, stored_username)) {

      // if login and stored usernames are equal, function strcmp returns 0,
      // at first loop they are certainly not, so it is: while(1)

      pull >> stored_username;
      userName = stored_username;
      if (pull.eof()) { // if it is the end of file
        cout << "\tUsername does not exist. " << endl;
        return -1;
      }
    }
    pull >> stored_password;
    pull >> stored_accountnumber;
    pull >> stored_totalDeposit;
    pull >> stored_totalWithdraw;
    pull >> stored_totalBalance;
    passWord = atoi(stored_password);
    totalDeposit = stored_totalDeposit;
    totalWithdraw = stored_totalWithdraw;
    initial = stored_totalBalance;
    cusAccNumber = stored_accountnumber;
    customerAccNumber = atoi(cusAccNumber.c_str());
    // since username and password are in the same line, password next to
    // correctly inputted username is saved in stored_password

    cout << "\tEnter your password: ";
    // now user enters password to confirm username
    cin >> login_password;
    while (strcmp(stored_password, login_password)) {
      cout << "\tWrong password. " << endl;
      cout << "\tTry again: ";
      cin >> login_password;
    }
    cout << "\tLogin successful." << endl;
    cout << "\tYou can exit to menu pls press 'q' : ";
    cin >> qt_menu;
    cout << endl;
      if (qt_menu == 'q') {
            mainMenu();
      }
      return 0;
}

int Bank::CheckCreateAccount() { // check การสร้าง account จาก รหัส account number บรรทัดสุดท้าย
    int accountnum;
    string filename = "Useraccnum.txt";
    ifstream fin;
    fin.open(filename);
    if(fin.is_open()) {
        fin.seekg(-1,ios_base::end);                // go to one spot before the EOF

        bool keepLooping = true;
        while(keepLooping) {
            char ch;
            fin.get(ch);                            // Get current byte's data

            if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                fin.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        string lastLine;            
        getline(fin,lastLine);                      // Read the current line   // Display it
        accountnum = atoi(lastLine.c_str());
        fin.close();
    }
    return accountnum;
}

void Bank::rememberDataAfterLogout(){ // บันทึกข้อมูล ก่อนที่จะ logout ออก
  fstream customerFile;
  customerFile.open(cusAccNumber+ "\\Userpass.txt", ios::out);
  if (customerFile.is_open()){
        customerFile << userName << " " << passWord << " " << cusAccNumber << " " << totalDeposit << " " << totalWithdraw << " " << initial << endl;
  }
  customerFile.close();
}

char *Bank::convertToChar(string convert) { // convert string to char array
  char *firstCharArray = new char[convert.length()];
  for (int i = 0; i < convert.length(); i++) {
    firstCharArray[i] = convert[i];
  }
  firstCharArray[10] = '\0';
  return firstCharArray;
}

int main() {
  Bank B;
  B.menu();
  return 0;
}