/*==========================================
UVa10268 - 498-bis
============================================
Completion Date: 105/01/31	by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
int iXValue;		//儲存輸入的X值
string sAList;		//儲存輸入的個各個A值字串
int iAListLength;	//儲存輸入各個A值字串的長度
int iAValue;		//儲存字串中各個A值(char) 轉換成的A值(int)
int iCount;			//儲存統計A值得個數(題意中的N值)
int iResult;		//儲存導數的結果
int i;				//迴圈變數
bool bNegative;		//判斷A值是否為負數

while (cin >> iXValue)
	{
	//初始化
	iCount = 1;
	iResult = 0;
	bNegative = false;
	
	//輸入A值字串前必須吃下換行符號
	getline(cin, sAList);
	
	//輸入A值字串	
	getline(cin, sAList);
	//得出A值字串的長度
	iAListLength = sAList.length();

	//統計輸入A值的個數
	for (i=0; i<iAListLength; i++)
		if (sAList[i] == ' ')
			iCount++;

	for (i=0; i<iAListLength; i++)
		{
		//若遇空格則進行下一個A值的運算
		if (sAList[i] == ' ')
			continue;
			
		//若遇到負號 則字串中下一個值為負值
		if (sAList[i] == '-')
			{
			bNegative = true;
			i++;
			}

		//轉換A值(char)成 A值(int)以方便下列計算
		iAValue = sAList[i] - '0';

		//依照題目所提供的多項式函數進行計算
		iCount--;
		if (bNegative)
			{
			iResult -= iAValue * (iCount) * pow( iXValue, (iCount-1) );
			bNegative = false;
			}
		else
			iResult += iAValue * (iCount) * pow( iXValue, (iCount-1) );
		}

	//輸出
	cout << iResult << endl;
	}

return 0;
}