#include <iostream>
using namespace std;

int genAccNum(int &digit);

int main() {
    int a = 1;
    genAccNum(a);
    cout << a << endl;
    char store;
    cout << a << endl;
    cout << "back to gen" << endl;
    cin >> store;
    if (store == 'b'){
        genAccNum(a);
    }  
    return 0; 
}

int genAccNum(int &digit){
      digit += 1;
      char store;
      cout << digit << endl;
      cout << "back" << endl;
      cin >> store;
      if (store == 'b'){
        main();
      }
      return digit;
}

void function(int &a){
    char store;
    cout << a << endl;
    cout << "back" << endl;
    cin >> store;
    if (store == 'b'){
        main();
    }
    
}

void function1(int &a){
    char store;
    cout << "back" << endl;
    cin >> store;
    if (store == 'b'){
        main();
    }
}