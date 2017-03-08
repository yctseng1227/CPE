/*=======================================
UVa10226 - Hardwood Species
=========================================
Completion Date: 105/06/04
=======================================*/
#include <iostream>
#include <string>
#include <iomanip>
#include <map>	//STL
using namespace std;
int main()
{
int iCase;					// 儲存輸入的測資個數
string sTreeName;			// 儲存輸入的樹種名稱
int iTotal;					// 儲存樹木的數量總和
bool bEndLine = false;		// 判斷是否需要換行
map<string, int> mapTree;	  // 建立樹種和數量的對應表


cin >> iCase;

// 跳過空格
cin >> ws;
while (iCase--)
	{
	// 總和初始化
	iTotal = 0;
	
	// 第一組測資以外輸出前需進行換行
	if (bEndLine)
		cout << endl;
	
	// 對應表的內容初始化
	mapTree.clear();

	// 輸入(純空白符號不計)
	// 同時計算樹種出現次數 及 樹木總和
	while ( getline(cin, sTreeName) && sTreeName != ""  )
		{
		mapTree[sTreeName]++;
		iTotal++;
		}

	// 依題意進行輸出
	// 宣告疊代器變數 以便遍訪map的內容
	map<string, int>::iterator i;
	for(i=mapTree.begin(); i!=mapTree.end(); i++)
        cout << (*i).first << " " << fixed << setprecision(4) << ( (*i).second*100.0 ) / iTotal << endl;

	bEndLine = true;
	}
	
return 0;
}