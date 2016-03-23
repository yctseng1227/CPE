/*==========================================
UVa10929 - You can say 11
============================================
Completion Date: 104/12/15	by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
string sNumber;    //儲存輸入的字串
int iOddSum;       //儲存奇位數的和
int iEvenSum;      //儲存偶位數的和
int i;             //迴圈變數
int iNumberLength; //儲存輸入字串的長度

while (cin >> sNumber)
	{
	//奇位數和歸零
	iOddSum = 0;
	//偶位數和歸零
	iEvenSum = 0;
		
	//當輸入0時結束程式
	if (sNumber == "0")
		break;

	//得出字串的長度
	iNumberLength = sNumber.length();

	for (i=0; i<iNumberLength; i++)
		{
		//由於陣列位置從0開始 所以奇位數為%2=0
		//奇位數的和
		if (i%2 == 0)
			iOddSum += (sNumber[i]-48);
		//偶位數的和
		if (i%2 == 1)
			iEvenSum += (sNumber[i]-48);
		}

	//判斷11倍數的規則："奇位數和"與"偶位數和"的差若為11k或0即成立
	if ((iOddSum-iEvenSum) % 11 == 0)
		cout <<  sNumber << " is a multiple of 11.\n";
	else
		cout <<  sNumber << " is not a multiple of 11.\n";
	}
return 0;
}
