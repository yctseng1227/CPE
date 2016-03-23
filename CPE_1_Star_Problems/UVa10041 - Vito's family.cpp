/*==========================================
UVa10041 - Vito's family
============================================
Completion Date: 105/01/24	by Geneyozakura
==========================================*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int iCase;				//儲存輸入的測資個數
int iRelative;			//儲存輸入的親戚個數
int iStreet[500];		//儲存各親戚所居住的街道號碼
int iVitoHouse;			//儲存Vito理想中居住的街道號碼
int iMiniDistanceSum;	//儲存Vito與各親戚的距離總和
int i;					//迴圈變數
int j;					//迴圈變數
int k;					//迴圈變數

//輸入測資個數
cin >> iCase;

for (i=0; i<iCase; i++)
	{
	//初始化
	iMiniDistanceSum = 0;
	
	//輸入
	cin >> iRelative;
	for (j=0; j<iRelative; j++)
		cin >> iStreet[j];

	//利用泡泡排序法將各親戚居住的街道號碼由小至大排序
	for (j=0; j<iRelative; j++)
		for (k=0; k<iRelative; k++)
			if (iStreet[j] > iStreet[k])
				swap (iStreet[j], iStreet[k]);

	//取中位數作為Vito理想中居住的街道號碼
	if (iRelative%2 == 1)
		iVitoHouse = iStreet[ (iRelative/2) ];
	else
		iVitoHouse = ( iStreet[ (iRelative/2)-1 ] + iStreet[ (iRelative/2) ] ) / 2;
	
	//計算Vito與各親戚的距離總和
	for (j=0; j<iRelative; j++)
		iMiniDistanceSum += abs (iVitoHouse - iStreet[j]);

	//輸出
	cout << iMiniDistanceSum << endl;
	}

return 0;
}