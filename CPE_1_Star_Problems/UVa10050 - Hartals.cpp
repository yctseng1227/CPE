/*==========================================
UVa10050 - Hartals
============================================
Completion Date: 105/01/21   by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;				//儲存資料組個數
int iDay;				//儲存要測試天數的範圍
int iParty;				//儲存政黨個數
int iHartalBegin[100];			//儲存各政黨不工作的起始天
int iTotal;				//儲存不工作的總天數
bool bHartalDays[3650];			//判斷該天是否要工作
int i;					//迴圈變數
int j;					//迴圈變數
int k;					//迴圈變數

//輸入資料組個數
cin >> iCase;
for (i=0; i<iCase; i++)
	{
	//輸入
	cin >> iDay;
	cin >> iParty;
	for (j=0; j<iParty; j++)
		cin >> iHartalBegin[j];

	//初始化
	for (j=0; j<iDay; j++)
  		bHartalDays[j] = false;
	iTotal = 0;

	//判斷哪幾天不工作
	for (j=1; j<=iDay; j++)
		{
		//如遇週五or週六 必須要工作所以不予計算
		if (j%7==6 || j%7==0)
			continue;
		//不工作的那幾天為true
		for (k=0; k<iParty; k++)
			if (j % iHartalBegin[k] == 0)
				bHartalDays[j-1] = true;
		}

	//計算不工作的總天數
	for (j=0; j<iDay; j++)
		if (bHartalDays[j])
			iTotal++;

	//輸出
	cout << iTotal << endl;
	}
return 0;
}
