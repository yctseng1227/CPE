/*==========================================
UVa10093 - An Easy Problem!
============================================
Completion Date: 105/03/19   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
string sInput;			//儲存輸入測資
int iInputLength;		//儲存輸入測資的長度
int i;				//迴圈變數
int j;				//迴圈變數
int iSum;			//儲存各位數相加之總和
bool bFound;			//判斷是否找到題目所求之進位

while (cin >> sInput)
	{
	//取得輸入測資之長度
	iInputLength = sInput.length();
	
	//初始化
	iSum = 0;
	bool bFound = true;
	
	//將每個字元依照62進位給予數值並加總
	for (i=0; i<iInputLength; i++)
		{
		if (sInput[i]>='0' && sInput[i]<='9')
			iSum += sInput[i]-'0';
		else if (sInput[i]>='A' && sInput[i]<='Z')
			iSum += sInput[i]-'A'+10;
		else if (sInput[i]>='a' && sInput[i]<='z')
			iSum += sInput[i]-'a'+36;
		}

	/*利用總和來判斷N進位 且能被N-1整除*/

	//當總和遇0時作為2進位輸出
	if (iSum == 0)
		{
		cout << "2" << endl;
		bFound = false;
		}

	//當總和為1-9則作為N+1進位輸出
	else if (iSum>=1 && iSum<=9)
		{
		cout << iSum+1 << endl;
		bFound = false;
		}

	//當總和不在以上範圍則從N-1判斷能否被整除
	//進而推論出N進位
	else
		for (i=61; i>=10; i--)
			if (iSum%i == 0)
				{
				cout << i+1 << endl;
				bFound = false;
				break;
				}
	
	//若無法從2-62進位中找到N值則依題意輸出
	if (bFound)
		cout << "such number is impossible!" << endl;
	}

return 0;
}
