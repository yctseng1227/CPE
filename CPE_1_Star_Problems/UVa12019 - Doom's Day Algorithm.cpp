/*==========================================
UVa12019 - Doom's Day Algorithm
============================================
Completion Date: 104/11/24  by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;               //儲存輸入測資的個數 
int iMonth;              //儲存輸入的月份 
int iDay;                //儲存輸入的日期 
int i, j;                //迴圈變數
int iMonthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                         //儲存各月份的天數 
int iDaySum;             //儲存天數總和 
int iWeek;               //儲存星期幾 

//輸入測資個數 
cin >> iCase;

for (i=0; i<iCase; i++)
    {
    //輸入月份及日期 
    cin >> iMonth >> iDay;
    
    //將天數總和歸零 
    iDaySum = 0;
    
    //將直到輸入月份之前的所有月份天數加總 
    for (j=1; j<iMonth; j++)
    	iDaySum += iMonthDay[j];
    
    //將上述加總的天數再加上輸入的日期 
    iDaySum += iDay;
    
    //一星期七天 因此mod7求輸入的月份日期為星期幾 
    iWeek = iDaySum % 7;
    
    //輸出星期幾 
    switch (iWeek)
        {
        case 0:
            cout << "Friday" << endl;
            break;
        case 1:
            cout << "Saturday" << endl;
            break;
        case 2:
            cout << "Sunday" << endl;
            break;
        case 3:
            cout << "Monday" << endl;
            break;
        case 4:
            cout << "Tuesday" << endl;
            break;
        case 5:
            cout << "Wednesday" << endl;
            break;
        case 6:
            cout << "Thursday" << endl;
        }
    }
return 0;
}