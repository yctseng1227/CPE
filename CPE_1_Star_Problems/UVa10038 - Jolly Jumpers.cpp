/*==========================================
UVa10038 - Jolly Jumpers 
============================================
Completion Date: 105/01/18	by Geneyozakura
==========================================*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int iCase;				//儲存數字的個數
int iInput[3000];		//儲存輸入的數字
int iDifference[3000];	//儲存前後相減的數字
int i;					//迴圈變數
bool bSequence[3000];	//判斷相減數字的序列
bool bJolly;			//判斷是否為Jolly


while (cin >> iCase)
	{
	//初始化
	for (i=1; i<iCase; i++)
		bSequence[i] = false;
	bJolly = true;

	//輸入
	for (i=0; i<iCase; i++)
		cin >> iInput[i];

	for (i=0; i<iCase-1; i++)
		{
		//將相減的數存入iDifference陣列
		iDifference[i] = abs(iInput[i] - iInput[i+1]);
		//將iDifference陣列相對應的序列數字轉成true
		bSequence[ iDifference[i] ] = true;
		}

	//輸出
	for (i=1; i<iCase; i++)
		//序列中出現false(相減的數字並不在1~(n-1)之中)
		if (bSequence[i] == false)
			{
			cout << "Not jolly" << endl;
			bJolly = false;
			break;
			}
	if (bJolly)
		cout << "Jolly" << endl;
	}

return 0;
}