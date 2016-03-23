/*==========================================
UVa10019 - Funny Encryption
============================================
Completion Date: 105/02/20   by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;				//儲存 輸入的測資個數
int iEncryptNumber;			//儲存 要加密的數字
int iTemp;				//暫存 要進行轉換用的數字
int iTempArray[4];			//暫存 要進行轉換用的陣列
int iDecCountOne;			//儲存 統計十進位轉二進位之"1"的個數
int iHexCountOne;			//儲存 統計十六進位轉二進位之"1"的個數
int iDigit;				//儲存 位數
int i;					//迴圈變數

cin >> iCase;
while (iCase--)
	{
	//初始化
	iDecCountOne = 0;
	iHexCountOne = 0;
	iDigit = 0;

	//輸入
	cin >> iEncryptNumber;

	/*計算加密數字(十進位制)轉成二進位後 "1"的個數*/
	iTemp = iEncryptNumber;
	while (iTemp)
		{
		if (iTemp%2 == 1)
			iDecCountOne++;
		iTemp /= 2;
		}

	/*計算加密數字(十六進位制)轉成二進位後 "1"的個數*/
	iTemp = iEncryptNumber;
	
	//先將各數字分別存入陣列中
	while (iTemp)
		{
		iTempArray[iDigit] = iTemp%10;
		iTemp /= 10;
		iDigit++;
		}

	//再將各數字轉換二進位時統計"1"的個數
	for (i=0; i<iDigit; i++)
		while (iTempArray[i])
			{
			if (iTempArray[i]%2 == 1)
				iHexCountOne++;
			iTempArray[i] /= 2;
			}

	//輸出
	cout << iDecCountOne << " " << iHexCountOne << endl;
	}

return 0;
}
