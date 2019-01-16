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

//��������
//
int DMLock(Cdmsoft& dm, VARIANT x, VARIANT y, unsigned int delayTime);

//����vec�е����� obj
//
int DMLockVec(Cdmsoft& dm, vector<OverViewElement> &v, unsigned int delayTime);

//������� ����
//
int DMUnLock(Cdmsoft& dm, VARIANT x, VARIANT y, unsigned int delayTime);

//��ʼ��DM obj
//
Cdmsoft * DMInit(char * hwndname, char * dictname,char * mode = "windows");

//���б�Ȼ����� vec��
//
int DMFindListRetRow(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, vector<OverViewElement> &v, int x1, int y1, int x2, int y2, int offset);

//���б� ���ؼ���
//
int DMFindListCount(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int x1, int y1, int x2, int y2, int offset);

//���б� ��������ȫ��
//
int DMFindListLock(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS);

//���б��ҽ������
//
int DMFindListUnLock(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS);

//���б���Ĭ�Ϲ�����һ��
//
int DMFindListAttack(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int attackObj = 0);

//�󴬣����б� ����Ĭ�Ϲ�����һ��
//
int DMFindListAttackBig(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int  attackObj = 0);
//���б���Ĭ�ϻ��Ƶڶ���
//
int DMFindListRound(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int attackObj = 1);

//���б� ����Ĭ��������һ��
int DMFindListLockSingle(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias = CLICKBIAS, int attackObj = 0);

//����
//
int DMPressClk(Cdmsoft& dm, VARIANT x, VARIANT y, CString key, int delayTime);

//��obj ��໭һ�� ����
//
int DMDrawText(long hwnd, Cdmsoft &dm, long w, long h, vector<OverViewElement> &v, vector<long> &vHwnd);

//�ر� foorbar
//
int DMFoorBarClose(Cdmsoft &dm, vector<long> &vHwnd);

//����ɨ��  ��Ļ ���еķ��� Ѱ��ͼƬ
//
int DMFindPicRow(Cdmsoft &dm, VARIANT &x, VARIANT &y, char *pic_name, int offset, int x1 = 0, int y1 = 0, int x2 = 1920, int y2 = 1080);

//����ɨ��  ��Ļ ���еķ��� Ѱ��ͼƬ
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



