#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    // ตัวแปรสำหรับการเก็บ หมายเลข account และ รหัสผ่าน
    int in_account_num, in_account_passwd;

    cout << "Enter your account number : ";
    cin >> in_account_num;

    cout << "Enter your password : ";
    cin >> in_account_passwd;
    //////////////////////////////////////////////
    // ส่วนนี้เจต้องไป while loop ข้อมูลเอานะในการเช็ค account กับ password
    /////////////////////////////////////////////

    // convert integer to string
    string in_account_num_conv = to_string(in_account_num);

    string find_customer = in_account_num_conv + "\\Bank Account Details.txt";
    //string find_customer = "customersnumber.txt";

    // อ่านไฟล์
    ifstream MyReadFile(find_customer);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, find_customer))
    {
        // Output the text from the file
        cout << find_customer << endl;
    }

    // Close the file
    MyReadFile.close();
}
