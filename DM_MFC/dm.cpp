#include "stdafx.h"
#include "dm.h"



UINT DMRegister(char * dir)
{
	//初始化大漠插件
	string DMDir(dir);
	string DMReg("regsvr32 ");
	DMReg = DMReg + " " + DMDir + " /s";

	return WinExec(DMReg.c_str(), SW_HIDE);
}


Cdmsoft * DMInstan()
{
	Cdmsoft *pDm = new Cdmsoft;
	::CoInitialize(NULL);		//初始化线程库
	CLSID clsid;
	HRESULT hr = CLSIDFromProgID(OLESTR("dm.dmsoft"), &clsid);	//获取句柄
	pDm->CreateDispatch(clsid);
	return pDm;
}


//int DMDectOverview(Cdmsoft *dm,VARIANT &x, VARIANT &y,double sim)
//{
//	dm->FindStr(1390, 95, 1864, 307, "总览", "c3c3c3-606060", 0.85,&x, &y);
//
//}



Cdmsoft * DMInit(char * hwndname,char * dictname, char * mode)
{
	Cdmsoft *pDm = DMInstan();

	//找窗口
	long hwnd = pDm->FindWindow("", hwndname);
	if(hwnd == 0)
		return (Cdmsoft *)-2;
	Sleep(200);
	cout << hwnd << endl;
	//绑定
	pDm->BindWindow(hwnd, "dx2", mode, mode, 0); //windows
	Sleep(200);
	//设置路径
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
	//所有可用小行星带
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
		//sprintf(name, "小行星带_%d", i++);
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
	//所有可用小行星带
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
	//所有可用小行星带
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
		cout << "锁定 "<<x.intVal << " " << y.intVal << " " << i << endl;
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
	//所有可用小行星带
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		x.intVal -= bias;
		cout << "解除锁定 " << x.intVal << " " << y.intVal << " " << i << endl;
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
	dm.MoveTo(x.intVal, y.intVal);		//移动
	Sleep(delayTime);
	dm.KeyDownChar(key);				//按下
	Sleep(delayTime);
	dm.LeftClick();						//鼠标左击
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
		long dmhwnd = dm.CreateFoobarRect(0, x- xBias, y- yBias, w, h); //先创建dm的foorbar
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
	//所有可用小行星带
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		

		//cout << "环绕第一个小船" << endl;
		//DMPressClk(dm, x, y, "w", delayTime);		//环绕第一个
		if(i == attackObj)
		{ 
			cout << "攻击 " << x.intVal << " " << y.intVal << "第 " << i <<" 个"<< endl;
#ifdef DM_DEBUG
			long foohandle = dm.CreateFoobarRect(0, x.intVal , y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif
			x.intVal -= bias; //向左偏移防止 发生 说明 挡住 其他的
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
	//所有可用小行星带
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{


		//cout << "环绕第一个小船" << endl;
		//DMPressClk(dm, x, y, "w", delayTime);		//环绕第一个
		if (i == attackObj)
		{
			cout << "攻击 " << x.intVal << " " << y.intVal << "第 " << i << " 个" << endl;
#ifdef DM_DEBUG
			long foohandle = dm.CreateFoobarRect(0, x.intVal, y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif
			x.intVal -= bias; //向左偏移防止 发生 说明 挡住 其他的
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
			cout << "环绕 " << x.intVal << " " << y.intVal << "第 " << i << " 个" << endl;
#ifdef DM_DEBUG
			long foohandle = dm.CreateFoobarRect(0, x.intVal, y.intVal - DM_DEBUG_BIAS_Y, 20, 16);
#endif
			x.intVal -= bias; //向左偏移防止 发生 说明 挡住 其他的
			//开始环绕
			
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
	//所有可用小行星带
	//vector<overViewElement> vecOverviewElement;
	int i = 0;
	while (dm.FindStrFast(x1, y1, x2, y2, FindString, "c3c3c3-606060", 0.85, &x, &y) != -1)
	{		
		y1 = y.intVal + offset;
		i++;
	}
	//cout << "计数一共： " << i << endl;
	return i;
}

int DMFindListLockSingle(Cdmsoft &dm, VARIANT x, VARIANT y, char *FindString, int delayTime, int x1, int y1, int x2, int y2, int offset, int bias, int attackObj)
{
	//int tmp_y = y_overvirw.intVal;
	//所有可用小行星带
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
			cout << "锁定 " << x.intVal << " " << y.intVal << " " << i << endl;
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
