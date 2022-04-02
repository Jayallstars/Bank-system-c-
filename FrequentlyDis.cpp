#include <iostream>
using namespace std;
int main(){
    int n = 0,count;
    cout << "Enter size of the array : ";
    cin >> n;
    int arr[n];
    cout << "\nEnter elements in array : \n";
    for (int i = 0; i < n; i++){
            cin >> arr[i];
    }
    int flag[n] = {0};
    cout << "\nFrequency of all elements of the array : ";
    for (int i =0; i < n; i++){
        count = 0;
        if(flag[i] != 1){
            for(int j = 0; j < n; j++){
                if (arr[i] == arr[j]){
                    count++;
                    flag[j] = 1;
                }
            }
            if (count > 1 || count == 1){
                cout << "\n" << arr[i] << " occurs " << count << " times ";
            }
        }
    }
    return 0;

}