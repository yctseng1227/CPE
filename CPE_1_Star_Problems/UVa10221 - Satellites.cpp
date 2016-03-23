/*==========================================
UVa10221 - Satellites
============================================
Completion Date: 105/01/22   by Geneyozakura
==========================================*/

//#define PI 3.1415926535	//原本使用的巨集
#define R 6440 			//定義地球半徑為6440 (km)

/* 事後了解有數學常數巨集可以使用
   而使用其中的圓周率常數為 M_PI */
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>		//使用sqrt,pow,cos
#include <iomanip>		//使用fixed,setprecision
using namespace std;

int main()
{
double dShift;			//儲存輸入的距離
double dAngle;			//儲存輸入的角度
double dRadians;		//儲存換算後的弧度
string sAngleMeasurement;	//儲存指定的角度度量衡
double dArcDistance;		//儲存弧線長度
double dChordDistance;		//儲存割線長度

while (cin >> dShift >> dAngle >> sAngleMeasurement)
	{
	//將角度(degrees)、角分(minutes)統一轉成弧度(Randians)以便三角函數的使用
	//PI (rad) = 180 (deg);  1 (deg) = 60 (min);
	if (sAngleMeasurement == "deg")
		dRadians = dAngle * (M_PI/180);
	if (sAngleMeasurement == "min")
		dRadians = dAngle * (M_PI/10800);

	//將圓周長依角度比例算出弧線長度
	dArcDistance = ( 2*(R+dShift)*M_PI ) * ( dRadians/(2*M_PI) );
	//利用餘弦定理算出割線長度
	dChordDistance = sqrt( 2*pow(R+dShift,2) * (1-cos(dRadians)) );
	
	//輸出
	//利用setprecision控制輸出位數 並且利用fixed修正成輸出小數點後的位數
	cout << fixed << setprecision(6) << dArcDistance << " ";
	cout << fixed << setprecision(6) << dChordDistance << endl;
	}

return 0;
}
