#include <iostream>
#include <string.h>
using namespace std;

char * convertDate(char date[20]);

int main(){
    char date[20];
    cout << "Input Date(dd/mm/yyyy) : ";
    cin >> date;
    cout << convertDate(date);
    return 0;
}

char * convertDate(char date[20]){
    static char day[20];
        if (date[0] >= 48 && date[0] <= 57){
            day[0] = date[0];
            if (date[1] >= 48 && date[1] <= 57){
                day[1] = date[1];
                if (date[2] == '/'){
                    day[2] = ' ';
                    if (date[3] == '0' && date[4] == '1'){
                            day[3] = 'J';
                            day[4] = 'a';
                            day[5] = 'n';
                            day[6] = 'u';
                            day[7] = 'a';
                            day[8] = 'r';
                            day[9] = 'y';
                            if (date[5] == '/'){
                                    day[10] = ' ';
                                    day[11] = date[6];
                                    day[12] = date[7];
                                    day[13] = date[8];
                                    day[14] = date[9];
                            }
                    }
                    else if (date[3] == '0' && date[4] == '2'){
                            day[3] = 'F';
                            day[4] = 'e';
                            day[5] = 'b';
                            day[6] = 'u';
                            day[7] = 'a';
                            day[8] = 'r';
                            day[9] = 'y';
                    }
                    else if (date[3] == '0' && date[4] == '3'){
                            day[3] = 'M';
                            day[4] = 'a';
                            day[5] = 'r';
                            day[6] = 'c';
                            day[7] = 'h';
                    }
                    else if (date[3] == '0' && date[4] == '4'){
                            day[3] = 'A';
                            day[4] = 'p';
                            day[5] = 'r';
                            day[6] = 'i';
                            day[7] = 'l';
                    }
                    else if (date[3] == '0' && date[4] == '5'){
                            day[3] = 'M';
                            day[4] = 'a';
                            day[5] = 'y';
                    }
                    else if (date[3] == '0' && date[4] == '6'){
                            day[3] = 'J';
                            day[4] = 'u';
                            day[5] = 'n';
                            day[6] = 'e';
                    }
                    else if (date[3] == '0' && date[4] == '7'){
                            day[3] = 'J';
                            day[4] = 'u';
                            day[5] = 'l';
                            day[6] = 'y';
                    }
                    else if (date[3] == '0' && date[4] == '8'){
                            day[3] = 'A';
                            day[4] = 'u';
                            day[5] = 'g';
                            day[6] = 'u';
                            day[7] = 's';
                            day[8] = 't';
                    }
                    else if (date[3] == '0' && date[4] == '9'){
                            day[3] = 'S';
                            day[4] = 'e';
                            day[5] = 'p';
                            day[6] = 't';
                            day[7] = 'e';
                            day[8] = 'm';
                            day[9] = 'b';
                            day[10] = 'e';
                            day[11] = 'r';
                    }
                    else if (date[3] == '1' && date[4] == '0'){
                            day[3] = 'O';
                            day[4] = 'c';
                            day[5] = 't';
                            day[6] = 'o';
                            day[7] = 'b';
                            day[8] = 'e';
                            day[9] = 'r';
                    }
                    else if (date[3] == '1' && date[4] == '1'){
                            day[3] = 'N';
                            day[4] = 'o';
                            day[5] = 'v';
                            day[6] = 'e';
                            day[7] = 'm';
                            day[8] = 'b';
                            day[9] = 'e';
                            day[10] = 'r';
                    }
                    else if (date[3] == '1' && date[4] == '2'){
                            day[3] = 'D';
                            day[4] = 'e';
                            day[5] = 'c';
                            day[6] = 'e';
                            day[7] = 'm';
                            day[8] = 'b';
                            day[9] = 'e';
                            day[10] = 'r';
                    }
                }
            
        }
        }
        return day;
}