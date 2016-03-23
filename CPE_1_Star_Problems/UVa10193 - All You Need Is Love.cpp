/*==========================================
UVa10193 - All You Need Is Love
============================================
Completion Date: 105/01/26   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
int iCase;			//儲存輸入的測資個數
string sBinString1;		//儲存輸入的第一條二進位字串
string sBinString2;		//儲存輸入的第二條二進位字串
int iBinString1Length;		//儲存第一條二進位字串的長度
int iBinString2Length;		//儲存第二條二進位字串的長度
int iDecNumber1;		//儲存第一條二進位字串轉換後的十進位整數
int iDecNumber2;		//儲存第二條二進位字串轉換後的十進位整數
int i;				//迴圈變數, 測資編號
int j;				//迴圈變數
bool bLove;			//判斷是否需要愛(!?)

cin >> iCase;
for (i=1; i<=iCase; i++)
	{
	//輸入
	cin >> sBinString1 >> sBinString2;

	//初始化
	bLove = true;
	iDecNumber1 = 0;
	iDecNumber2 = 0;

	//取得兩條字串的長度
	iBinString1Length = sBinString1.length();
	iBinString2Length = sBinString2.length();

	//將兩條字串分別轉成十進位整數
	for (j=0; j<iBinString1Length; j++)
		iDecNumber1 += ( (sBinString1[j]-48) * pow(2,iBinString1Length-1-j) );
	for (j=0; j<iBinString2Length; j++)
		iDecNumber2 += ( (sBinString2[j]-48) * pow(2,iBinString2Length-1-j) );

	//利用輾轉相除法得出最大公因數
	while (1)
		{
		if (iDecNumber1 > iDecNumber2)
			swap (iDecNumber1, iDecNumber2);

		iDecNumber2 %= iDecNumber1;
		if (iDecNumber2 == 0)
			{
			//若最大公因數為1(質因數) 則不需要愛!
			if (iDecNumber1 == 1)
				{
				bLove = false;
				break;
				}
			else
				break;
			}

		}

	//輸出
	if (bLove)
		cout << "Pair #" << i << ": All you need is love!" << endl;
	else
		cout << "Pair #" << i << ": Love is not all you need!" << endl;
	}

return 0;
}
