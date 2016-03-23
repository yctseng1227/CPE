/*==========================================
UVa10189 - Minesweeper 
============================================
Completion Date: 105/01/23	by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iColumn;			//儲存輸入的直行數
int iLine;				//儲存輸入的橫列數
char cField[100][100];	//儲存範圍內的字元
char cCount[100][100];  //儲存範圍內輸出的格式
int iNumber;            //儲存測資編號
int i;					//迴圈變數
int j;					//迴圈變數
bool bEndline;			//判斷是否需要換行

//初始化
iNumber = 0;
bEndline = 0;

while (cin >> iColumn >> iLine)
	{
	//初始化
	for (i=0; i<iColumn; i++)
		for (j=0; j<iLine; j++)
			cCount[i][j] = '0';

	//輸入
	for (i=0; i<iColumn; i++)
		for (j=0; j<iLine; j++)
			cin >> cField[i][j];

	//若輸入的行列皆為0則結束
	if ( (iColumn==0) && (iLine==0) )
		break;

	//判斷周圍出現'*'的次數
	for (i=0; i<iColumn; i++)
		for (j=0; j<iLine; j++)
			{
			//若該位置為'*' 則輸出也為'*'
			if (cField[i][j] == '*')
				cCount[i][j] = '*';

			//判斷周圍八格出現'*'的次數
			else
				{
				if (cField[i+1][j] == '*')
					cCount[i][j]++;
				if (cField[i-1][j] == '*')
					cCount[i][j]++;
				if (cField[i][j+1] == '*')
					cCount[i][j]++;
				if (cField[i][j-1] == '*')
					cCount[i][j]++;
				
				if (cField[i+1][j+1] == '*')
					cCount[i][j]++;
				if (cField[i+1][j-1] == '*')
					cCount[i][j]++;
				if (cField[i-1][j+1] == '*')
					cCount[i][j]++;
				if (cField[i-1][j-1] == '*')
					cCount[i][j]++;
				}
			}

	//輸出
	//第一組測資不換行 此後每組輸出前需換行
	if (bEndline)
		cout << endl;
		
	cout << "Field #" << ++iNumber << ":" << endl;
	for (i=0; i<iColumn; i++)
		{
		for (j=0; j<iLine; j++)
			cout << cCount[i][j];
		cout << endl;
		}

	//當第一組測資結束後都必須輸出前換行
	bEndline = true;
	}
return 0;
}