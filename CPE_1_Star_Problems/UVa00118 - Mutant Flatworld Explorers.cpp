/*==========================================
UVa00118 - Mutant Flatworld Explorers
============================================
Completion Date: 105/03/08   by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
int iMapLength;					//儲存地圖的長度
int iMapWidth;					//儲存地圖的寬度
bool bBoundary[50][50];				//判斷會掉出地圖外的位置
int iPositionX;					//儲存機器人的X位置
int iPositionY;					//儲存機器人的Y位置
char cInitialOrientation;			//儲存機器人初始朝向的方位
string sCommand;				//儲存輸入的字串指令
int iCommandLength;				//儲存輸入字串指令的長度
char cOrientation[4] = {'N', 'W', 'S', 'E'};	//儲存四個方位的陣列
int iIndex;					//儲存進行轉向時的陣列索引
int i;						//迴圈變數
int j;						//迴圈變數
bool bOver;					//判斷機器人是否會掉出地圖外
int iWrongCommand;				//儲存錯誤的指令

//輸入預設的地圖範圍
cin >> iMapLength >> iMapWidth;

//輸入機器人的X,Y座標 以及面對方位
while (cin >> iPositionX >> iPositionY >> cInitialOrientation)
	{
	//初始化
	for (i=0; i<iMapLength; i++)
		for (j=0; j<iMapWidth; j++)
			bBoundary[i][j] = false;
	bOver = false;
	
	//輸入指令 並取得其長度
	cin >> sCommand;
	iCommandLength = sCommand.length();
	
	//確立起始面對方位的陣列索引 方便進行"轉向"
	for (i=0; i<4; i++)
		if (cOrientation[i] == cInitialOrientation)
			iIndex = i;
	
	//逐一使用每個指令
	//如同時遇到"關鍵點"與"錯誤指令"則忽略該指令	
	for (i=0; i<iCommandLength; i++)
		{
		switch (sCommand[i])
			{
			//Right: 每轉一次陣列索引將依序 3>2>1>0>3 循環表示轉向
			case 'R':
				--iIndex += 4;
				iIndex %= 4;
				break;

			//Left: 每轉一次陣列索引將依序 0>1>2>3>0 循環表示轉向
			case 'L':
				++iIndex %= 4;
				break;

			//Forward: 首先判斷前進方位 再判斷當前位置是否為關鍵點 
			//若為關鍵點則必須跳過錯誤指令 以避免機器人掉出地圖範圍外
			case 'F':
				if (cOrientation[iIndex] == 'N')
					{
					if (bBoundary[iPositionX][iPositionY] = true)
						if (iIndex == iWrongCommand)
							break;
					iPositionY++;
					}
				if (cOrientation[iIndex] == 'W')
					{
					if (bBoundary[iPositionX][iPositionY] = true)
						if (iIndex == iWrongCommand)
							break;
					iPositionX--;
					}
				if (cOrientation[iIndex] == 'E')
					{
					if (bBoundary[iPositionX][iPositionY] = true)
						if (iIndex == iWrongCommand)
							break;
					iPositionX++;
					}
				if (cOrientation[iIndex] == 'S')
					{
					if (bBoundary[iPositionX][iPositionY] = true)
						if (iIndex == iWrongCommand)
							break;
					iPositionY--;
					}
			}
		
		//當機器人所在位置為地圖之外
		//則將前一位置的布林轉為true 提示之後此地為關鍵點
		//同時也將會掉出地圖外的指令 設定為錯誤指令
		if (iPositionX > iMapLength)
			{
			bOver = true;
			bBoundary[--iPositionX][iPositionY] = true;
			iWrongCommand = iIndex;
			break;
			}
		if (iPositionY > iMapWidth)
			{
			bOver = true;
			bBoundary[iPositionX][--iPositionY] = true;
			iWrongCommand = iIndex;
			break;
			}
		}
	
	//輸出
	if (bOver)
		cout << iPositionX << " " << iPositionY << " " << cOrientation[iIndex] << " " << "LOST" << endl;
		
	else
		cout << iPositionX << " " << iPositionY << " " << cOrientation[iIndex] << endl;
	}

return 0;
}
