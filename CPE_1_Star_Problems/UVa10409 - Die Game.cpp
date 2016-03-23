/*==========================================
UVa10409 - Die Game
============================================
Completion Date: 105/02/18   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
int iCommandQuantity;		//儲存輸入指令的個數
string sDirection;		//儲存輸入的指令
int iTemp;			//儲存骰子中的數字
int i;				//迴圈變數

while (cin >> iCommandQuantity)
	{
	//陣列初始化
	//此陣列依照骰子各面的點數排列 ([0]為骰子頂部)
	int iDice[6] = {1,2,6,5,3,4};
	
	//若輸入0則結束程式
	if (iCommandQuantity == 0)
		break;

	//輸入測資前必須先吃下換行符號
	getline(cin,sDirection);

	//輸入指令進行 將各點數所對應的位置進行轉換
	for (i=0; i<iCommandQuantity; i++)
		{
		getline (cin,sDirection);

		if (sDirection[0] == 'n')
			{
			iTemp = iDice[3];
			iDice[3] = iDice[2];
			iDice[2] = iDice[1];
			iDice[1] = iDice[0];
			iDice[0] = iTemp;
			}
		if (sDirection[0] == 's')
			{
			iTemp = iDice[0];
			iDice[0] = iDice[1];
			iDice[1] = iDice[2];
			iDice[2] = iDice[3];
			iDice[3] = iTemp;
			}
		if (sDirection[0] == 'w')
			{
			iTemp = iDice[0];
			iDice[0] = iDice[5];
			iDice[5] = iDice[2];
			iDice[2] = iDice[4];
			iDice[4] = iTemp;
			}
		if (sDirection[0] == 'e')
			{
			iTemp = iDice[0];
			iDice[0] = iDice[4];
			iDice[4] = iDice[2];
			iDice[2] = iDice[5];
			iDice[5] = iTemp;
			}
		}

	//輸出
	cout << iDice[0] << endl;
	}

return 0;
}
