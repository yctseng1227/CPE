/*==========================================
UVa10242 - Fourth Point!! 
============================================
Completion Date: 105/02/17	by Geneyozakura
==========================================*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
float fCoordinateX[4];		//儲存輸入的X座標
float fCoordinateY[4];		//儲存輸入的Y座標
float fFourthPointX;		//儲存第四點的座標
float fFourthPointY;		//儲存第四點的座標

while (cin >> fCoordinateX[0] >> fCoordinateY[0] >> fCoordinateX[1] >> fCoordinateY[1]
 		   >> fCoordinateX[2] >> fCoordinateY[2] >> fCoordinateX[3] >> fCoordinateY[3])
	{
	/* 由於輸入的四個座標為平行四邊形中兩鄰邊之頂點
	   因此必定會有兩個重複的座標 在此預設的兩個相同座標為陣列[1],[2]
	   而以下四個if皆為調整座標數值以便進行運算                       */
	if (fCoordinateX[1] == fCoordinateX[0] && fCoordinateY[1] == fCoordinateY[0])
		{
		swap(fCoordinateX[0], fCoordinateX[2]);
		swap(fCoordinateY[0], fCoordinateY[2]);
		}
	if (fCoordinateX[2] == fCoordinateX[0] && fCoordinateY[2] == fCoordinateY[0])
		{
		swap(fCoordinateX[0], fCoordinateX[1]);
		swap(fCoordinateY[0], fCoordinateY[1]);
		}
	if (fCoordinateX[1] == fCoordinateX[3] && fCoordinateY[1] == fCoordinateY[3])
		{
		swap(fCoordinateX[3], fCoordinateX[2]);
		swap(fCoordinateY[3], fCoordinateY[2]);
		}
	if (fCoordinateX[0] == fCoordinateX[3] && fCoordinateY[0] == fCoordinateY[3])
		{
		swap(fCoordinateX[0], fCoordinateX[1]);
		swap(fCoordinateY[0], fCoordinateY[1]);
		swap(fCoordinateX[3], fCoordinateX[2]);
		swap(fCoordinateY[3], fCoordinateY[2]);
		}
	
	/* 由平行四邊形的性質可以推導出:
	   平行四邊形ABCD中對角座標A+C = B+D */
	fFourthPointX = fCoordinateX[0] + fCoordinateX[3] - fCoordinateX[1];
	fFourthPointY = fCoordinateY[0] + fCoordinateY[3] - fCoordinateY[1];
	
	
	cout << fixed << setprecision(3) << fFourthPointX << " " << fFourthPointY << endl;
	}

return 0;
}