/*==========================================
UVa10056 - What is the Probability?
============================================
Completion Date: 105/02/16   by Geneyozakura
==========================================*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
int iCase;			//儲存測資個數
int iPlayerQuantity;		//儲存參加者的數量
float fDiceProbability;		//儲存遊戲設定的骰子機率
int iPlayerSerial;		//儲存指定的第N位玩家
float fWinProbability;		//儲存第N位玩家獲勝的機率
int i;				//迴圈變數

//輸入測資個數
cin >> iCase;
for (i=0; i<iCase; i++)
	{
	//輸入
	cin >> iPlayerQuantity >> fDiceProbability >> iPlayerSerial;
	
	//若設定的骰子機率為0 則獲勝機率也為0
	if (fDiceProbability == 0)
		fWinProbability = 0;
	//條件機率:獲勝的條件中第N位獲勝的機率
	else
		fWinProbability = ( fDiceProbability * pow( (1-fDiceProbability), (iPlayerSerial-1) )  )
						/ ( 1 - pow( (1-fDiceProbability), iPlayerQuantity ) );

	//輸出
	//利用setprecision控制輸出位數 並且利用fixed修正成輸出小數點後的位數
	cout << fixed << setprecision(4) << fWinProbability << endl;
	}

return 0;
}
