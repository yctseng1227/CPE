/*==========================================
UVa00299 - Train Swapping
============================================
Completion Date: 105/02/01   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
int iCase;			//儲存輸入的測資個數
int iLength;			//儲存輸入測資的長度	
int iNumber[50];			//儲存輸入的測資數字
int iSwapCount;			//儲存交換的次數
int i;				//迴圈變數
int j;				//迴圈變數
int k;				//迴圈變數

//輸入測資個數
cin >> iCase;
for (i=0; i<iCase; i++)
	{
	//初始化
	iSwapCount = 0;

	//輸入測資長度
	cin >> iLength;
	//輸入測資數字
	for (j=0; j<iLength; j++)
		cin >> iNumber[j];

	//利用泡泡排氣法統計排列由小到大交換的次數
	for (j=0; j<iLength; j++)
		for (k=j; k<iLength; k++)
			if (iNumber[j] > iNumber[k])
				{
				swap (iNumber[j], iNumber[k]);
				iSwapCount++;
				}

	//輸出
	cout << "Optimal train swapping takes " << iSwapCount << " swaps." << endl;
	}

return 0;
}
