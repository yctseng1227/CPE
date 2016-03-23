/*==========================================
UVa10071 - Back to High School Physics
============================================
Completion Date: 104/10/23   by Geneyozakura
==========================================*/
#include <iostream>
using namespace std;
int main()
{
//宣告變數
int iTime;              //儲存時間 
int iVelocity;          //儲存速度 
int iDisplacement;      //儲存位移 

//用while執行多組資料 輸入速度及時間 
while (cin >> iVelocity >> iTime)
    {
    //依題意計算位移=2*時間*速度 
    iDisplacement = 2 * iTime * iVelocity;
    
    //輸出位移 
    cout << iDisplacement << endl;    
    }

return 0;
}
