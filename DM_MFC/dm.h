#pragma once
#include "stdafx.h"

#include <string>
#include <vector>
using namespace std;


#define DM_DEBUG_BIAS_X		60
#define DM_DEBUG_BIAS_Y		-20 
#define CTRLPRESSTIME		300
#define CLICKBIAS			30
//#define DM_DEBUG
//#define DM_DEBUG_BIAS_Y 10 
struct OverViewElement {
	VARIANT x;
	VARIANT y;
	string name;
	unsigned int type;
};






//UINT DMRegister(char * DMDir);

Cdmsoft * DMInstan();

int DMFindList(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, vector<OverViewElement> &v);

//锁定单个
//
int DMLock(Cdmsoft& dm, VARIANT x, VARIANT y, unsigned int delayTime);

//锁定vec中的所有 obj
//
int DMLockVec(Cdmsoft& dm, vector<OverViewElement> &v, unsigned int delayTime);

//解除锁定 单个
//
int DMUnLock(Cdmsoft& dm, VARIANT x, VARIANT y, unsigned int delayTime);

//初始化DM obj
//
Cdmsoft * DMInit(char * hwndname, char * dictname,char * mode = "windows");

//找列表然后放入 vec中
//
int DMFindListRetRow(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, vector<OverViewElement> &v, int x1, int y1, int x2, int y2, int offset);

//找列表 返回计数
//
int DMFindListCount(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int x1, int y1, int x2, int y2, int offset);

//找列表 并且锁定全部
//
int DMFindListLock(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS);

//找列表并且解除锁定
//
int DMFindListUnLock(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS);

//找列表并且默认攻击第一个
//
int DMFindListAttack(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int attackObj = 0);

//大船！找列表 并且默认攻击第一个
//
int DMFindListAttackBig(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int  attackObj = 0);
//找列表并且默认环绕第二个
//
int DMFindListRound(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int attackObj = 1);

//找列表 并且默认锁定第一个
int DMFindListLockSingle(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int attackObj = 0);

//单击
//
int DMPressClk(Cdmsoft& dm, VARIANT x, VARIANT y, CString key, int delayTime);

//在obj 左侧画一个 方块
//
int DMDrawText(long hwnd, Cdmsoft &dm, long w, long h, vector<OverViewElement> &v, vector<long> &vHwnd);

//关闭 foorbar
//
int DMFoorBarClose(Cdmsoft &dm, vector<long> &vHwnd);

//横向扫描  屏幕 从列的方向 寻找图片
//
int DMFindPicRow(Cdmsoft &dm, VARIANT &x, VARIANT &y, char *pic_name, int offset, int x1 = 0, int y1 = 0, int x2 = 1920, int y2 = 1080);

//竖向扫描  屏幕 从列的方向 寻找图片
//
int DMFindPicCol(Cdmsoft &dm, VARIANT &x, VARIANT &y, char *pic_name, int offset, int x1 = 0, int y1 = 0, int x2 = 1920, int y2 = 1080);
class CDm
{
public:
	CDm()
	{
		pDm = DMInstan();
	}
	~CDm()
	{
		delete pDm;
	}

	Cdmsoft * GetInstance()
	{
		return pDm;
	}

	long GetHandle(const char * handleName)
	{
		return pDm->FindWindow("", handleName);;
	}




private:
	Cdmsoft* pDm;
};



