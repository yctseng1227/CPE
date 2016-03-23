/*==========================================
UVa11005 - Cheapest Base
============================================
Completion Date: 105/03/19   by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;			//儲存測資個數
int iCharactersCost[36];		//儲存0-9,A-Z之字元所需花費價格
int iQueryCase;				//儲存測試數字個數
int iQueryNumber;			//儲存測試數字
int iNumberCost[37];			//儲存轉換2-36進位所需的花費
int iCheapestCost;			//儲存最便宜的價格
int iCheapestBase[37];			//儲存最便宜的進位
int iTemp;				//儲存暫存測試數字
int i;					//迴圈變數
int j;					//迴圈變數
int k;					//迴圈變數
int m;					//陣列計次
int iIndex;				//儲存測資輸出的編號
bool bSpace;				//判斷輸出是否需要空白
bool bEndline;				//判斷輸出是否需要換行

//初始化
iIndex = 1;
bEndline = false;

cin >> iCase;
while (iCase--)
	{
	//輸入0-9,A-Z每個字元之價格
	for (i=0; i<36; i++)
		cin >> iCharactersCost[i];

	//輸出測資編號 (判斷換行)
	if (bEndline)
		cout << endl;
	else
		bEndline = true;
	cout << "Case " << iIndex++ << ":" << endl;

	//處理測試數字
	cin >> iQueryCase;
	for (i=0; i<iQueryCase; i++)
		{
		//初始化
		iCheapestCost = 100;
		bSpace = false;
		m = 0;
		for (k=0; k<=36; k++)
			{
			iNumberCost[k] = 0;
			iCheapestBase[k] = 0;
			}
		
		cin >> iQueryNumber;
		
		//將測試數字分別轉換成2-36進位並儲存
		//同時取得最便宜的花費
		for (j=2; j<=36; j++)
			{
			iTemp = iQueryNumber;
			
			do
				iNumberCost[j] +=  iCharactersCost[ iTemp%j ];
				while (iTemp /= j);
			
			if (iNumberCost[j] < iCheapestCost)
				iCheapestCost = iNumberCost[j];	
			}

		//比較其他進位是否同樣便宜的花費
		for (k=2; k<=36; k++)
			if (iNumberCost[k] == iCheapestCost)
				iCheapestBase[m++] = k;

		//輸出 (判斷空白)
		cout << "Cheapest base(s) for number " << iQueryNumber << ": ";
		for (k=0; k<36; k++)
			{
			if (iCheapestBase[k] == 0)
				break;

			if (bSpace)
				cout << " " << iCheapestBase[k];
			else
				{
				cout << iCheapestBase[k];
				bSpace = true;
				}
			}

		cout << endl;
		}
	}
	
return 0;
}
