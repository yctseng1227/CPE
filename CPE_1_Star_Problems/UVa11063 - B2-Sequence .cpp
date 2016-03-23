/*==========================================
UVA11063 - B2-Sequence
============================================
Completion Date: 105/01/18	by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;				//配合題意輸出測資編號
int iElementCount;		//儲存輸入資料個數
int iElement[100];		//儲存輸入資料
int iElementSum[100];	//儲存兩兩相加的值
int i;					//迴圈變數
int j;					//迴圈變數
bool bB2_Sequence;		//判斷是否為B2-Sequence
int iCount;				//迴圈內計算相加次數

//編號初始化
iCase = 0;

while (cin >> iElementCount)
	{
	//將各值初始化
	bB2_Sequence = true;
	iCount = 0;
	iElement[0] = 1;

	//輸入
	for (i=1; i<=iElementCount; i++)
		{
		cin >> iElement[i];
		//若輸入值小於1則不合題目規則
		if (iElement[i] < 1)
			bB2_Sequence = false;
		}

	//若前面的值比後面的值大則違反B2-Sequence規則
	for (i=1; i<iElementCount; i++)
		if (iElement[i] > iElement[i+1])
			bB2_Sequence = false;

	//將輸入的值兩兩相加
	for (i=1; i<iElementCount; i++)
		for (j=i; j<=iElementCount; j++)
			{
			iElementSum[iCount] = iElement[i] + iElement[j];
			iCount++;
			}

	//若兩兩相加的值重複則違反B2-Sequence規則
	for (i=0; i<iCount-1; i++)
		for (j=i+1; j<iCount; j++)
			if (iElementSum[i] == iElementSum[j])
				bB2_Sequence = false;

	//輸出
	if (bB2_Sequence)
		cout << "Case #" << ++iCase << ": It is a B2-Sequence." << endl << endl;
	else
		cout << "Case #" << ++iCase << ": It is not a B2-Sequence." << endl << endl;
	}

return 0;
}