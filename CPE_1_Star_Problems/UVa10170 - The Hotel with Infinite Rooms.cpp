/*==========================================
UVa10170 - The Hotel with Infinite Rooms
============================================
Completion Date: 104/12/08   by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
long long int lliCheckInNum;		//儲存入住的人數 
long long int lliDay;			//儲存指定的天數 
long long int lliTempCheckInNum;		//暫存當時入住的人數 
	
while (cin >> lliCheckInNum >> lliDay)
	{
	//將輸入的入住人數暫存於當時入住的人數 
	lliTempCheckInNum = lliCheckInNum;
	
	//將入住的人數累加直到大於指定的天數
	while (lliTempCheckInNum < lliDay)
		{	
		lliCheckInNum++;
		lliTempCheckInNum += lliCheckInNum;
		}
		
	cout << lliCheckInNum << endl;
	}	
return 0;
}
