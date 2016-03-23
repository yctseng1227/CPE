/*==========================================
UVa00490 - Rotating Sentences
============================================
Completion Date: 105/02/20   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
string sInput;				//儲存 輸入的字串
int iInputLength[100];			//儲存 輸入字串的長度
int iMaxLength;				//儲存 儲存輸入字串中最長的長度
char cStoreInput[100][100];		//儲存 每次輸入的字串
int iCount;				//儲存 計算輸入字串的次數
int i;					//迴圈變數
int j;					//迴圈變數

//初始化
iCount = 0;
iMaxLength = 0;

//輸入字串後儲存 並找出最長的字串長度
while ( getline (cin, sInput) )
	{
	iInputLength[iCount] = sInput.length();

	if (iInputLength[iCount] > iMaxLength)
		iMaxLength = iInputLength[iCount];

	for (i=0; i<iInputLength[iCount]; i++)
		cStoreInput[iCount][i] = sInput[i];

	iCount++;
	}

//輸出
for (i=0; i<iMaxLength; i++)
	{
	for (j=iCount-1; j>=0; j--)
		{
		//若未達每個字串最大長度則輸出該字元
		if (i < iInputLength[j])
			cout << cStoreInput[j][i];

		//否則輸出空格
		else
			//若為輸出該行中的最後一字 則不進行輸出
			if (j != 0)
				cout << " ";
		}
	
	cout << endl;
	}

return 0;
}
