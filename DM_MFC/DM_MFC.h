
// DM_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDM_MFCApp: 
// �йش����ʵ�֣������ DM_MFC.cpp
//

class CDM_MFCApp : public CWinApp
{
public:
	CDM_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDM_MFCApp theApp;