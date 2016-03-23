/*==========================================
UVA10908 - Largest Square
============================================
Completion Date: 105/02/18	by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;					//儲存測資個數
int iRow;					//儲存輸入的橫列數
int iColumn;				//儲存輸入的直行數
int iLine;					//儲存輸入位置RC的行數
char cCharacter[22][22];	//儲存輸入的字母
int iLocationR;				//儲存輸入的位置R
int iLocationC;				//儲存輸入的位置C
int i;						//迴圈變數					
int j;						//迴圈變數					
int h;						//迴圈變數					
int k;						//迴圈變數
int iSquareMaxLength;		//儲存矩形的最大長度
bool bLimitLength;			//判斷是否已經為最大長度極限

cin >> iCase;
while (iCase--)
	{
	//輸入
	cin >> iRow >> iColumn >> iLine;

	//在輸入字母前周圍一圈設定為'0'
	for (i=0; i<=iColumn+1; i++)
		{
		cCharacter[0][i] = '0';
		cCharacter[iRow+1][i] = '0';
		}
	for (i=0; i<=iRow+1; i++)
		{
		cCharacter[i][0] = '0';
		cCharacter[i][iColumn+1] = '0';
		}

	//依題意輸入字母
	for (i=1; i<=iRow; i++)
		for (j=1; j<=iColumn; j++)
			cin >> cCharacter[i][j];

	//依題意輸出
	cout << iRow << " " << iColumn << " " << iLine << endl;

	//輸出
	for (i=0; i<iLine; i++)
		{
		//初始化
		iSquareMaxLength = 1;
		j = 1;
		bLimitLength = false;

		//輸入指定位置
		cin >> iLocationR >> iLocationC;
		
		//由於四周多圍一圈0 因此指定的位置必須加1
		iLocationR++;
		iLocationC++;

		//直到求出矩形的最大長度為止
		while (!bLimitLength)
			{
			//以(R,C)為中心 向周圍一圈進行字母比對
	  		for (k=iLocationR-j; k<=iLocationR+j; k++)
				for (h=iLocationC-j; h<=iLocationC+j; h++)
					if (cCharacter[iLocationR][iLocationC] != cCharacter[k][h])
						bLimitLength = true;

			//若取得矩形最大長度則輸出
			if (bLimitLength)
				cout << iSquareMaxLength << endl;
			//否則以(R,C)為中心向兩側長度+1 並且j+1擴大檢查範圍
			else
				{
				iSquareMaxLength += 2;
				j++;
				}
			}
		}
	}

return 0;
}