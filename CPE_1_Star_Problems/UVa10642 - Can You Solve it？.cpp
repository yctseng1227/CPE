/*==========================================
UVa10642 - Can You Solve it?
============================================
Completion Date: 105/02/15   by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
int iCase;			//儲存測資個數
int iCoordinate[4];		//儲存兩個座標位置
int iCount;			//儲存兩座標之間的座標數量
int i;				//迴圈變數
int j;				//迴圈變數
int iNumber;			//儲存測資編號
int iCoordinateBeginSum;	//儲存起始點座標總和
int iCoordinateEndSum;		//儲存終末點座標總和

//輸入測資個數
cin >> iCase;
for (iNumber=1; iNumber<=iCase; iNumber++)
	{
	//初始化
	iCount = 0;

	//輸入兩個座標
	for (i=0; i<4; i++)
		cin >> iCoordinate[i];
	
	//儲存起始點座標(X1,Y1)總和
	iCoordinateBeginSum = iCoordinate[0] + iCoordinate[1];
	//儲存終末點座標(X2,Y2)總和
	iCoordinateEndSum = iCoordinate[2] + iCoordinate[3];
	
	/*將輸入兩座標之間的座標數量分三部分計算:*/
	
	//1.起始點座標(X1,Y1)同一斜排的座標數量
	for (i=iCoordinateBeginSum-iCoordinate[1]; i<=iCoordinateBeginSum; i++)
		iCount++;

	//2.起始點座標(X1,Y1) 與 終末點座標(X2,Y2) 為準的兩條斜排之間的座標數量
	for (i=iCoordinateBeginSum+1; i<=iCoordinateEndSum-1; i++)
		for (j=0; j<=i; j++)
			iCount++;

	//3.終末點座標(X2,Y2)同一斜排的座標數量
	for (i=iCoordinateEndSum-iCoordinate[3]; i>0; i--)
		iCount++; 
	
	//輸出
	cout << "Case " << iNumber << ": " << iCount << endl;
	}

return 0;
}
