/*==========================================
UVa10235 - Simply Emirp
============================================
Completion Date: 105/01/25	by Geneyozakura
==========================================*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int iInput;				//儲存輸入的測資
int iReverseInput;		//儲存測資反轉後的數字
int iTemp;				//儲存反轉時的暫存數字
int iReverse[10000];	//儲存反轉時的暫存陣列
int iCount;				//陣列計次
int i;					//迴圈變數
bool bIsPrime;			//判斷測資是否為質數
bool bIsEmirp;			//判斷測資是否為反質數

while (cin >> iInput)
	{
	//初始化
	bIsPrime = true;
	bIsEmirp = true;
	iReverseInput = 0;
	
	//判斷是否為質數
	for (i=2; i<iInput; i++)
		if (iInput%i == 0)
			{
			bIsPrime = false;
			bIsEmirp = false;
			}

	//若為質數 則判斷是否為反質數
	if (bIsPrime)
		{
		//反轉前準備
		iCount = 0;
		iTemp = iInput;

		//進行反轉
		while (iTemp != 0)
			{
			iReverse[iCount] = iTemp%10;
			iTemp /= 10;
			iCount++;
			}
		for (i=0; i<iCount; i++)
			iReverseInput += ( iReverse[i]*pow( 10 ,(iCount-1)-i ) );

		//判斷反轉後的數字是否為質數
		for (i=2; i<iReverseInput; i++)
			if (iReverseInput%i == 0)
				bIsEmirp = false;

		//若反轉前後的數字相同 則不為反質數
		if (iInput == iReverseInput)
			bIsEmirp = false;
		}

	//輸出
	if (!bIsPrime)
		cout << iInput << " is not prime." << endl;
	else if (bIsEmirp)
		cout << iInput << " is emirp." << endl;
	else
		cout << iInput << " is prime." << endl;
	}

return 0;
}