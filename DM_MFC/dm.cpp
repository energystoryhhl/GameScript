#include "stdafx.h"
#include "dm.h"



UINT DMRegister(char * dir)
{
	//��ʼ����Į���
	string DMDir(dir);
	string DMReg("regsvr32 ");
	DMReg = DMReg + " " + DMDir + " /s";

	return WinExec(DMReg.c_str(), SW_HIDE);
}


Cdmsoft * DMInstan()
{
	Cdmsoft *pDm = new Cdmsoft;
	::CoInitialize(NULL);		//��ʼ���߳̿�
	CLSID clsid;
	HRESULT hr = CLSIDFromProgID(OLESTR("dm.dmsoft"), &clsid);	//��ȡ���
	pDm->CreateDispatch(clsid);
	return pDm;
}


//int DMDectOverview(Cdmsoft *dm,VARIANT &x, VARIANT &y,double sim)
//{
//	dm->FindStr(1390, 95, 1864, 307, "����", "c3c3c3-606060", 0.85,&x, &y);
//
//}



Cdmsoft * DMInit(char * hwndname,char * dictname, char * mode)
{
	Cdmsoft *pDm = DMInstan();

	//�Ҵ���
	long hwnd = pDm->FindWindow("", hwndname);
	if(hwnd == 0)
		return (Cdmsoft *)-2;
	Sleep(200);
	cout << hwnd << endl;
	//��
	pDm->BindWindow(hwnd, "dx2", mode, mode, 0); //windows
	Sleep(200);
	//����·��
	char path[] = "F:\\CPP_PROJECT\\DM_MFC\\source";
	pDm->SetPath(path);
	if (!pDm->SetDict(0, dictname))
	{
		cout << "TEXT FAILED" << endl;
		return (Cdmsoft *)-1;
	}	
	else
		cout << "LOAD TXT OK" << endl;
	return pDm;
}


int DMFindList(Cdmsoft &dm, VARIANT x, VARIANT y,char *FindString,vector<OverViewElement> &v)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	int tmp_y = y.intVal;
	int tmp_x = x.intVal;
	OverViewElement element;
	while(dm.FindStr(x.intVal, tmp_y, 1920, 1080, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		element.x = x;
		element.y = y;
		//char name[256];
		//sprintf(name, "С���Ǵ�_%d", i++);
		//element.name = name;
		v.push_back(element);
		tmp_x = x.intVal - 100;
		tmp_y = y.intVal + 16;
		cout << x.intVal << " " << y.intVal << " "  << i<< endl;
		i++;
	}
	return i;
}

int DMFindListRetRow(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, vector<OverViewElement> &v,int x1,int y1,int x2,int y2,int offset)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;

	OverViewElement element;
	while(dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		element.x = x;
		element.y = y;
		v.push_back(element);
		//cout << x.intVal << " " << y.intVal << " " << i << endl;
		y1 = y.intVal + offset;
		i++;
	}
	return i;
}

int DMFindListLock(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime,int x1, int y1, int x2, int y2, int offset,int bias)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;

	//OverViewElement element;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		//element.x = x;
		//element.y = y;
		//v.push_back(element);
#ifdef DM_DEBUG
		long foohandle = dm.CreateFoobarRect(0, x.intVal - DM_DEBUG_BIAS_X, y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif
		//dm.KeyPress(17);
		//Sleep(500);
		x.intVal -= bias;
		cout << "���� "<<x.intVal << " " << y.intVal << " " << i << endl;
		DMLock(dm, x, y, delayTime);

#ifdef DM_DEBUG
		dm.FoobarClose(foohandle);
#endif

		y1 = y.intVal + offset;
		i++;
	}
	return i;
}

int DMFindListUnLock(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		x.intVal -= bias;
		cout << "������� " << x.intVal << " " << y.intVal << " " << i << endl;
		DMUnLock(dm, x, y, delayTime);
		y1 = y.intVal + offset;
		i++;
	}
	return i;
}




int DMLock(Cdmsoft& dm, VARIANT x, VARIANT y,unsigned int delayTime)
{
	dm.MoveTo(x.intVal, y.intVal);
	Sleep(delayTime);
	dm.KeyDown(17);
	Sleep(delayTime);
	dm.LeftClick();
	Sleep(delayTime);
	dm.KeyUp(17);
	return 0;
}

int DMUnLock(Cdmsoft& dm, VARIANT x, VARIANT y, unsigned int delayTime)
{
	dm.MoveTo(x.intVal, y.intVal);
	Sleep(delayTime);
	dm.KeyDown(17);
	Sleep(delayTime);
	dm.KeyDown(16);
	Sleep(delayTime);
	dm.LeftClick();
	Sleep(delayTime);
	dm.KeyUp(17);
	Sleep(delayTime);
	dm.KeyUp(16);
	return 0;
}

int DMLockVec(Cdmsoft& dm,vector<OverViewElement> &v,unsigned int delayTime)
{
	int i = 0;
	for ( i = 0; i < v.size(); i++)
	{
		DMLock(dm, v[i].x, v[i].y, delayTime);
	}
	return i;
}


int DMPressClk(Cdmsoft& dm, VARIANT x, VARIANT y,CString key,int delayTime)
{
	dm.MoveTo(x.intVal, y.intVal);		//�ƶ�
	Sleep(delayTime);
	dm.KeyDownChar(key);				//����
	Sleep(delayTime);
	dm.LeftClick();						//������
	Sleep(delayTime);
	dm.KeyUpChar(key);
	return 0;
}

int DMDrawText(long hwnd,Cdmsoft &dm ,long w,long h,vector<OverViewElement> &v,vector<long> &vHwnd)
{
	int i = 0;
	int xBias = 55;
	int yBias = 8;
	for (i = 0; i < v.size(); i++)
	{
		long x = v[i].x.lVal;
		long y = v[i].y.lVal;
		long dmhwnd = dm.CreateFoobarRect(0, x- xBias, y- yBias, w, h); //�ȴ���dm��foorbar
		vHwnd.push_back(dmhwnd);
		//dm.FoobarDrawText(dmhwnd, 20, 0, w, h, str, "ff0000", 1);//draw text
	}
	return i;
}

int DMFoorBarClose(Cdmsoft &dm, vector<long> &vHwnd)
{
	int i = 0;
	for (i = 0; i < vHwnd.size(); i++)
	{
		dm.FoobarClose(vHwnd[i]);
	}
	return i;
}




int DMFindListAttack(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias,int attackObj)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		

		//cout << "���Ƶ�һ��С��" << endl;
		//DMPressClk(dm, x, y, "w", delayTime);		//���Ƶ�һ��
		if(i == attackObj)
		{ 
			cout << "���� " << x.intVal << " " << y.intVal << "�� " << i <<" ��"<< endl;
#ifdef DM_DEBUG
			long foohandle = dm.CreateFoobarRect(0, x.intVal , y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif
			x.intVal -= bias; //����ƫ�Ʒ�ֹ ���� ˵�� ��ס ������
			dm.MoveTo(x.intVal, y.intVal);
			Sleep(delayTime);
			dm.LeftClick();
			Sleep(delayTime);
			dm.KeyPress(112);

#ifdef DM_DEBUG
			dm.FoobarClose(foohandle);
#endif
			break;
		}
		y1 = y.intVal + offset;
		i++;
	}
	return i;
}

int DMFindListAttackBig(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias, int attackObj)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{


		//cout << "���Ƶ�һ��С��" << endl;
		//DMPressClk(dm, x, y, "w", delayTime);		//���Ƶ�һ��
		if (i == attackObj)
		{
			cout << "���� " << x.intVal << " " << y.intVal << "�� " << i << " ��" << endl;
#ifdef DM_DEBUG
			long foohandle = dm.CreateFoobarRect(0, x.intVal, y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif
			x.intVal -= bias; //����ƫ�Ʒ�ֹ ���� ˵�� ��ס ������
			dm.MoveTo(x.intVal, y.intVal);
			Sleep(delayTime);
			dm.LeftClick();
			Sleep(delayTime);
			dm.KeyPress(112);
			Sleep(delayTime);
			dm.KeyPress(114);

#ifdef DM_DEBUG
			dm.FoobarClose(foohandle);
#endif
			break;
		}
		y1 = y.intVal + offset;
		i++;
	}
	return i;
}

int DMFindListRound(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias, int attackObj)
{
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		if (i == attackObj)
		{
			cout << "���� " << x.intVal << " " << y.intVal << "�� " << i << " ��" << endl;
#ifdef DM_DEBUG
			long foohandle = dm.CreateFoobarRect(0, x.intVal, y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif
			x.intVal -= bias; //����ƫ�Ʒ�ֹ ���� ˵�� ��ס ������
			//��ʼ����
			
			dm.KeyDownChar("w");
			Sleep(delayTime);
			dm.MoveTo(x.intVal, y.intVal);
			Sleep(delayTime);
			dm.LeftClick();
			Sleep(delayTime);
			dm.KeyUpChar("w");

#ifdef DM_DEBUG
			dm.FoobarClose(foohandle);
#endif
			break;
		}
		y1 = y.intVal + offset;
		i++;
	}
	return i;
}

int DMFindListCount(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int x1, int y1, int x2, int y2, int offset)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{		
		y1 = y.intVal + offset;
		i++;
	}
	//cout << "����һ���� " << i << endl;
	return i;
}

int DMFindListLockSingle(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias, int attackObj)
{
	//int tmp_y = y_overvirw.intVal;
	//���п���С���Ǵ�
	//vector<overViewElement> vecOverviewElement;
	int i = 0;

	//OverViewElement element;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		//element.x = x;
		//element.y = y;
		//v.push_back(element);
#ifdef DM_DEBUG
		long foohandle = dm.CreateFoobarRect(0, x.intVal - DM_DEBUG_BIAS_X, y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif

		x.intVal -= bias;
		if (i == attackObj)
		{
			cout << "���� " << x.intVal << " " << y.intVal << " " << i << endl;
			DMLock(dm, x, y, delayTime);
#ifdef DM_DEBUG
			dm.FoobarClose(foohandle);
#endif
			break;
		}



		y1 = y.intVal + offset;
		i++;
	}
	return i;
}

//long FindPic(x1, y1, x2, y2, pic_name, delta_color,sim, dir,intX, intY)
int DMFindPicRow(Cdmsoft &dm, VARIANT &x, VARIANT &y, char *pic_name,  int offset ,int x1, int y1 , int x2 , int y2 )
{
	int i = 0;
	while (dm.FindPic(x1, y1, x2, y2, pic_name, "202020", 0.95, 0,&x, &y) != -1)
	{
		i++;
		
		x1 = x.intVal + offset;
		
	}
	return i;
}

int DMFindPicCol(Cdmsoft &dm, VARIANT &x, VARIANT &y, char *pic_name, int offset, int x1, int y1, int x2, int y2)
{
	int i = 0;
	while (dm.FindPic(x1, y1, x2, y2, pic_name, "202020", 0.95, 0, &x, &y) != -1)
	{
		i++;

		y1 = y.intVal + offset;

	}
	return i;
}
