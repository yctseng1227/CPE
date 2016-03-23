/*==========================================
UVa10062 - Tell me the frequencies!
============================================
Completion Date: 105/01/23   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
string sInput;			//儲存輸入的字串
int iInputLength;		//儲存輸入字串長度
int iCount[96];			//儲存字元(ASCII 32~127)出現的次數
int iOutput[1000][96];		//儲存輸出時編排的陣列 ([次數][字元])
int i;				//迴圈變數
int j;				//迴圈變數
int k;				//陣列計次
bool bEndline;			//判斷是否需要換行

//初始化
bEndline = false;

while ( getline(cin, sInput) )
	{
	//取得輸入字串的長度
	iInputLength = sInput.length();

	//初始化
	for (i=0; i<96; i++)
		iCount[i] = 0;
	for (i=0; i<1000; i++)
		for (j=0; j<96; j++)
			iOutput[i][j] = 0;

	//統計各字元出現的次數
	for (i=0; i<iInputLength; i++)
		for (j=32; j<=127; j++)
			if (sInput[i] == j)
				iCount[j-32]++;

	//陣列計次初始化
	k = 0;

	//將各字元出現的次數及ASCII值 存入陣列Output
	for (i=1; i<1000; i++)
		for (j=0; j<96; j++)
			{
			if (i == iCount[j])
				{
    			iOutput[i][k] = j+32;
				k++;
				}
				
			}

	//輸出
	//第一組測資不換行 此後每組輸出前需換行
	if (bEndline)
		cout << endl;

	//依題意在同次數的字元需要由大至小輸出
	for (i=1; i<1000; i++)
		for (j=95; j>=0; j--)
			if (iOutput[i][j] != 0)
				cout << iOutput[i][j] << " " << i << endl;
	
	//當第一組測資結束後都必須輸出前換行
	bEndline = true;
	}
return 0;
}
