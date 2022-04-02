#include <corecrt_wtime.h>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	char time_string[100];

    cout << "Input Date(dd/mm/yyyy) : ";
    cin >> curr_time;
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, 50, "Today is %B %d, %Y", curr_tm);
	strftime(time_string, 50, "Current time is %T", curr_tm);
	
	cout << date_string << endl;
	cout << time_string << endl;
	
	return 0;
}
