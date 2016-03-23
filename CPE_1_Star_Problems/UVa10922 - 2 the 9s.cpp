/*==========================================
UVa10922 - 2 the 9s
============================================
Completion Date: 105/01/21   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
string sInput;			//儲存輸入的字串
int iInputLength;		//儲存輸入字串的長度
bool bNineDegree;		//判斷是否為9-degree
int iCount;			//儲存位數加總的次數
int iSum;			//儲存位數加總的值
int iTemp;			//暫存變數
int i;				//迴圈變數

while (cin >> sInput)
	{
	//得出輸入字串的長度
	iInputLength = sInput.length();
	
	//初始化
	bNineDegree = true;
	iSum = 0;
	iCount = 0;
	
	//輸入0則結束程式
	if (sInput[0] == '0')
		break;
	
	//判斷是否為9的倍數
	for (i=0; i<iInputLength; i++)
		iSum += (sInput[i]-'0');
	if (iSum%9 != 0)
		bNineDegree = false;
	
	//若為9的倍數 則計算各個位數加總直到9的次數
	if (bNineDegree)
		{
		iTemp = iSum;
		iSum = 0;
		while (1)
			{
			//加總後若為9 則跳出迴圈
			if (iTemp == 9)
				{
				iCount++;
				break;
				}

			//各個位數加總
			while (iTemp > 0)
				{
				iSum += iTemp%10;
            	iTemp /= 10;
				}

			//第N次加總後為9的倍數 次數+1
			if (iSum%9 == 0)
				iCount++;

			//還原後再進行N+1次的計算
			iTemp = iSum;
			iSum = 0;
			}
		}

	//輸出
	if (bNineDegree)
		cout << sInput << " is a multiple of 9 and has 9-degree " << iCount << "." << endl;
	else
		cout << sInput << " is not a multiple of 9." << endl;
	}
return 0;
}
