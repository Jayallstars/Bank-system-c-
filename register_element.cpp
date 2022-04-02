#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string filename = "Userpass.txt";
    ifstream file_operation;
    file_operation.open(filename);
    if(file_operation.is_open()) {
        file_operation.seekg(-1,ios_base::end);                 // go to one spot before the EOF

        bool loop_status = true;
        while(loop_status) {
            char ch;
            file_operation.get(ch);                             // Get current byte's data เรียกดูข้อมูลในไฟล์ทั้งหมด

            if((int)file_operation.tellg() <= 1) {              // หากข้อมูลอยู่ที่หรือก่อน 0 ไบต์ รออัพเดท comment เพิ่มเติม
                file_operation.seekg(0);                        // บรรทัดแรกคือบรรทัดสุดท้าย รออัพเดท comment เพิ่มเติม
                loop_status = false;                            // หยุด loop
            }
            else if(ch == '\n') {                               // ถ้ามีข้อมูลขึ้นบรรทัดใหม่
                loop_status = false;                            // หยุด loop 
            }
            else {                                              // หากข้อมูลไม่ใช่การขึ้นบรรทัดใหม่หรือที่ 0 byte
                file_operation.seekg(-2,ios_base::cur);         // ย้ายไปยังด้านหน้าของข้อมูลนั้น จากนั้นไปที่ด้านหน้าของข้อมูลก่อนหน้านั้น
            }
        }

        string lastLine;                                        // ตัวแปรเก็บข้อมูลบรรทัดสุดท้ายในไฟล์ accountdata.txt
        getline(file_operation,lastLine);                       // อ่านบรรทัดปัจจุบันหรือ ตัวแปร lastline
        // cout << lastLine << '\n';                            // แสดงข้อมูล่าสุด

        file_operation.close();                                 // ปิดการอ่านไฟล์

        stringstream geek(lastLine);                            // ไมรู้ว้อยเดียวมาเติม ERR_COMM
 
    
    // it to the integer last_line_result
    int last_line_result = 0;                                   // กำหนดตัวแปร last_line_result = 0 กัน Error
    geek >> last_line_result;
    // reference https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    //https://stackoverflow.com/questions/11876290/c-fastest-way-to-read-only-last-line-of-text-file
    //https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
    //cout << "Last Line : " << last_line_result;                 // cout ข้อมูลล่าสุดออกมาเช็คผลลัพธ์
    
    // register automatic gen account number
    /* last_line_result += 1; */
    // view account number
    cout << "account number : "  << last_line_result << endl;
    /////////////////////////////////////////////////////////
    // เจต้องใส่โค้ดรับอินพุตตรงนี้นะ หรือจะใส่ตรงอื่นก็ได้
    // last_line_result จะเป็นตัวแปรที่เก็บเลขบัญชีของลูกค้าที่จะสมัครใหม่
    ////////////////////////////////////////////////////////
    // process write account number to account number file storage


    return 0;
}
}


////////////////////////////////////
//Original code
///////////////////////////////////
// #include <iostream>
// #include <fstream>
// #include <sstream>

// using namespace std;

// int main()
// {
//     string filename = "test.tlast_line_resultt";
//     ifstream file_operation;
//     file_operation.open(filename);
//     if(file_operation.is_open()) {
//         file_operation.seekg(-1,ios_base::end);                // go to one spot before the EOF

//         bool loop_status = true;
//         while(loop_status) {
//             char ch;
//             file_operation.get(ch);                            // Get current byte's data

//             if((int)file_operation.tellg() <= 1) {             // If the data was at or before the 0th byte
//                 file_operation.seekg(0);                       // The first line is the last line
//                 loop_status = false;                // So stop there
//             }
//             else if(ch == '\n') {                   // If the data was a newline
//                 loop_status = false;                // Stop at the current position.
//             }
//             else {                                  // If the data was neither a newline nor at the 0 byte
//                 file_operation.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
//             }
//         }

//         string lastLine;            
//         getline(file_operation,lastLine);                      // Read the current line
//         cout << "Result: " << lastLine << '\n';     // Display it

//         file_operation.close();
//     }

//     return 0;
// }

