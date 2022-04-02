#include <iostream>
using namespace std;
int main(){
    int a[5][100];
    int count = 1;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 5; j++) {
                a[i][j] = count++;
                cout << a[i][j] << endl;
                if (a[i][j] % 5 == 0){
                    cout << "\n";
                }
        }
    }
}