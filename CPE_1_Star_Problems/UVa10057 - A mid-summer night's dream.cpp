/*==========================================
UVa10057 - A mid-summer night’s dream 
============================================
Completion Date: 105/01/24	by Geneyozakura
==========================================*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int iCase;					//儲存 測資個數
int iDreamNum[100000];		//儲存 夢到的數字
int iCombinationLockCode;	//儲存 符合題目中算式的A值
int iMiniSum;				//儲存 A值代入算式後的結果
int iCount;					//儲存 夢到數字中代入算式後等於MiniSum的個數
int iTest;					//儲存 其他值代入算式後的結果
int iOtherCount;			//儲存 1~65536中代入算式後等於MiniSum的個數
int i;						//迴圈變數
int j;						//迴圈變數

while (cin >> iCase)
	{
	//初始化
	iMiniSum = 0;
	iCount = 0;
	iOtherCount = 0;
	
	//輸入夢到的一串數字
	for (i=0; i<iCase; i++)
		cin >> iDreamNum[i];

	//利用泡泡排序法將各值由小至大排序
	for (i=0; i<iCase; i++)
		for (j=0; j<iCase; j++)
			if (iDreamNum[i] > iDreamNum[j])
				swap (iDreamNum[i], iDreamNum[j]);

	//取得中位數 此值即為題目所求的A值
	iCombinationLockCode = iDreamNum[ iCase/2 ];

	//將A值代入算式得出最小值結果
	for (i=0; i<iCase; i++)
		iMiniSum += abs (iCombinationLockCode - iDreamNum[i]);

	//將測資代入算式後檢驗
	for (i=0; i<iCase; i++)
		{
		//將測資代入算式後得出答案
		iTest = 0;
		for (j=0; j<iCase; j++)
			iTest += abs (iDreamNum[i] - iDreamNum[j]);

		//計算 (測資中代入算式後得出的答案與最小值結果相同) 的次數 
		if (iMiniSum == iTest)
			iCount++;
		}

	//將 1~65536 代入算式後檢驗
	for (i=1; i<65536; i++)
		{
		//將 1~65536 代入算式後得出答案
		iTest = 0;
		for (j=0; j<iCase; j++)
			iTest += abs (i - iDreamNum[j]);

		//計算 (其他值代入算式後得出的答案與最小值結果相同) 的次數 
		if (iMiniSum == iTest)
			iOtherCount++;
		}
	
	//輸出
	cout << iCombinationLockCode << " " << iCount << " " << iOtherCount << endl;
	}

return 0;
}