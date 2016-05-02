/*=======================================
UVa10209 - Is This Integration?
=========================================
Completion Date: 105/04/26
=======================================*/
#include <iostream>
#include <iomanip>
#define PI 2.0*acos(0.0) // 題目給予
using namespace std;
int main()
{
double dLength;				// 輸入之正方形邊長
double dStripedRegion;		// 題目中斜線的面積
double dDottedRegion;		// 題目中點點的面積
double dRestRegion;			// 題目中方格的面積
double dSquare;				// 整塊正方形面積
double dCircle;				// 以正方形邊長作為半徑之圓面積
double dSeed;				// 某塊為方便計算需求得的面積

while (cin >> dLength)
	{
	dSquare = dLength*dLength;
	dCircle = dLength*dLength*PI;
	dSeed = ( dCircle/6 - ( (sqrt(3)/4) * dLength*dLength ) );
	dRestRegion = 4 * ( ( dSquare-dCircle/4 ) - ( dCircle/4 - dCircle/6 - dSeed) );
	dDottedRegion = 4 * ( dSquare - dCircle/4 - dRestRegion/2 );
	dStripedRegion = dSquare - dRestRegion - dDottedRegion;
	cout << fixed << setprecision(3) << dStripedRegion << " "
		 << dDottedRegion << " " << dRestRegion << endl;
	}

return 0;
}