
// DM_MFCDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CDM_MFCDlg 对话框
class CDM_MFCDlg : public CDialogEx
{
// 构造
public:
	CDM_MFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DM_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonTest();


protected:
	CDm Dm;
	bool STARTFLAG;
public:
	void CheckRun();
	afx_msg void OnBnClickedButtonFindpic();
	afx_msg void OnBnClickedButtonOcr();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButtonExec();
	afx_msg void OnBnClickedButtonyichang();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	//bool handleName;
	afx_msg void OnBnClickedButton1();
	CString handleName2;
	CString handleName3;
	CComboBox m_cbb_mode;
	afx_msg void OnCbnSelchangeComboMode();

	//--------------------------------	PUBLIC MEMBERS--------------------------
	//
	//
	//----------------------------------------------------------------------------
	void InitializeControls(void);
	//UINT ShipCoutThread(LPVOID pParam);


	//--------------------------------	PRIVATE MEMBERS--------------------------
	//
	//
	//----------------------------------------------------------------------------
private:
	CString m_mode;
	CString m_mode2_cstr;
	CString m_dictNmae;
	Cdmsoft * m_pdm;
	Cdmsoft * m_pdmCounter;
	long m_CurHwnd;
	VARIANT m_scanPoint_x;
	VARIANT m_scanPoint_y;
	vector<long> fooBarVec;
	int m_curSShipNum;
	int m_curBShipNum;
	bool m_ShipNumCountThreadEnable;
	bool m_script3Enable;
	bool m_WrapDetectThreadEnable;
	bool m_IfWrapON;
	int  m_voiceFlag;

	friend UINT VOICETHREAD(LPVOID pParam);
	friend UINT ShipCoutThread(LPVOID pParam);
	friend UINT SCRIPT3THREAD(LPVOID pParam);
	friend UINT WrapDetectThread(LPVOID pParam);

	//--------------------------------	CONTROL MEMBERS--------------------------
	//
	//
	//----------------------------------------------------------------------------
public:
	CListBox m_lsb_msg;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonInit();
	CComboBox m_mode2;
	afx_msg void OnCbnSelchangeComboMode2();
	CButton m_btn_capture;
	afx_msg void OnBnClickedButtoncapture();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CButton m_btn_screen;
	CComboBox m_cbb_dict;
	afx_msg void OnCbnSelchangeComboDict();

	CButton m_btn_script01;
	//锁定所有小船
	//
	afx_msg void OnBnClickeLockSmallShip();
	afx_msg void OnBnClickeFindScanPoint();
	afx_msg void OnBnClickedUnLock();
	afx_msg void OnBnClickeLockBigShip();
	afx_msg void OnBnClickeAttFirSShip();
	afx_msg void OnBnClickeRoundSecShip();
	afx_msg void OnBnClickeAttFirBShip();
	afx_msg void OnBnClickeRoundSecBShip();
	afx_msg void OnBnClickeRoundFirBShip();
	afx_msg void OnBnClickedButtoScript2();
	afx_msg void StartShipNumDectThread();
	afx_msg void OnBnClickeRoundFirShip();
	afx_msg void SCRIPT3();
	afx_msg void LockFirSShip();
	afx_msg void LockFirBShip();
	afx_msg void IFMissleEmpty();
	afx_msg void CALLBACKALLDRON();
	afx_msg void RELEASEALLDRON();
	CButton m_btn_init;
	CButton m_btn_script3;
	afx_msg void StartWrapDtectThread();
	afx_msg void NoTargetVoice();
};
