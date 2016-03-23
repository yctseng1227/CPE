/*==========================================
UVa00948 - Fibonaccimal Base
============================================
Completion Date: 104/12/29   by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;			//儲存輸入測資個數 
int FibSequence[40];		//儲存費氏數列
int iNumber;			//儲存輸入測資 
int FibBase[40];			//儲存儲存以費氏數列為底的結果 
int iTemp;			//暫存Number的值
bool OneDetect;			//輸出時偵測1 
int i;				//迴圈變數
int j;				//迴圈變數


//將費氏數列存入陣列
for (i=0; i<40; i++)
		FibSequence[i] = 0;
FibSequence[0] = 0;
FibSequence[1] = 1;
for (i=0; i<38; i++)
	FibSequence[i+2] = FibSequence[i] + FibSequence[i+1];

//輸入測資個數 
cin >> iCase;
for (i=0; i<iCase; i++)
	{
	//設定偵測1的旗標
	OneDetect = false;
	
	//將費氏數列為底的結果歸零
	for (j=0; j<40; j++)
		FibBase[j] = 0;
	
	//輸入測資
	cin >> iNumber;
	
	//將Number的值給Temp做運算
	iTemp = iNumber; 
	for (j=39; j>1; j--)
		if (iTemp >= FibSequence[j])
			{
			iTemp -= FibSequence[j];
			FibBase[j]++;
			}
	
	//輸出
	cout << iNumber << " = ";
	for (j=39; j>1; j--)
		{
		//將費氏數列為底的結果 遇到1則開始輸出
		if (FibBase[j] == 1)
			OneDetect = true;
		if (OneDetect)
			cout << FibBase[j];
		}
	cout << " (fib)" << endl;
	}
return 0;
}
