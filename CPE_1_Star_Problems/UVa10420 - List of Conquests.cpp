/*==========================================
UVa10420 - List of Conquests
============================================
Completion Date: 105/02/23   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
int iCase;			//儲存測資個數
char cCountry[2000][10];	//儲存國家名
string sName;			//儲存人名
int iCount;			//儲存國家出現次數
int i;				//迴圈變數
int j;				//迴圈變數

//依題意輸入
cin >> iCase;
for (i=0; i<iCase; i++)
	{
	cin >> cCountry[i];
	getline (cin, sName);
	}

//將國家以其第一個字母做排序
for (i=0; i<iCase; i++)
	for (j=i+1; j<iCase; j++)
		if (cCountry[i][0] > cCountry[j][0])
			swap (cCountry[i], cCountry[j]);

//依題意輸出
for (i=0; i<iCase; i++)
	{
	//初始化
	iCount = 0;

	cout << cCountry[i] << " ";
	
	//若國家有重複則計次+1 反之跳出迴圈
	for (j=i; j<iCase; j++)
		{
		if (cCountry[i][0] != cCountry[j][0])
			break;
		iCount++;
		}
		
	cout << iCount << endl;

	//當迴圈進行到j時國家不重複 故i值須減1以便繼續進行
	i = j-1;
	}

return 0;
}
