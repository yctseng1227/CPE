/*=======================================
UVa11470 - Square Sums
=========================================
Completion Date: 105/05/23
=======================================*/
#include <iostream>
using namespace std;
int main()
{
int index = 1;		// 依題目顯示編號
int iSize;		// 儲存 輸入的正方形邊長大小
int iSquare[10][10];	// 儲存 輸入正方形內的測資
int iSum[5];		// 儲存 正方形的外圈和
int i, j;		// 迴圈變數
int iSeed;		// 計算用的種子
int iLoop;		// 計算用迴圈次數

while (cin >> iSize)
	{
	//遇零結束
	if (iSize == 0)
		return 0;
		
	//初始化
	for (i=0; i<5; i++)
		iSum[i] = 0;
		
	//輸入
	for (i=0; i<iSize; i++)
		for (j=0; j<iSize; j++)
			cin >> iSquare[i][j];
			
	//計算需要跑的迴圈次數
	if (iSize%2 == 1)
		iLoop = (iSize+1)/2;
	else
		iLoop = iSize/2;
	
	//設定種子數值
	iSeed = iSize;
	while (iLoop--)
		{
		//計算上下之和
		for (i=iSize-iSeed; i<iSeed; i++)
			{
			iSum[iSize-iSeed] += iSquare[iSize-iSeed][i];
			iSquare[iSize-iSeed][i] = 0; //為防止相同位置的數字重複相加
			iSum[iSize-iSeed] += iSquare[iSeed-1][i];			
			iSquare[iSeed-1][i] = 0; //防止相同位置的數字重複相加
			}	
		//計算左右之和
		for (i=iSize-(iSeed-1); i<iSeed-1; i++)
			{
			iSum[iSize-iSeed] += iSquare[i][iSize-iSeed];
			iSum[iSize-iSeed] += iSquare[i][iSeed-1];
			}
			
		iSeed--;
		}	
	//輸出
	cout << "Case " << index++ << ":";
	for (i=0; i<5; i++)
		{
		if (iSum[i] == 0) break;
		cout << " " << iSum[i];
		}
	cout << endl;
	}
	
return 0;
}