
// DM_MFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DM_MFC.h"
#include "DM_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



void getFolderDayFile(CString pathStr, CStringArray& arrStrFile)
{
	CString myDataPath, fdPath;   //设置路径变量
	myDataPath = pathStr + "\\*.*"; //文件夹路径
	CString strTmp;      //后缀名变量

	CFileFind find;		//例化CFileFind
	BOOL bf = find.FindFile(myDataPath);	//
	while (bf)
	{
		bf = find.FindNextFile();
		if (!find.IsDots())
		{
			fdPath = find.GetFilePath();
			if (find.IsDirectory())
			{
				//如果是文件夹，递归，继续往下找                        
				getFolderDayFile(fdPath, arrStrFile);
			}
			else
			{
				//如果是文件,判断是否是*.txt
				strTmp = fdPath.Right(4);  //取后缀名
				strTmp.MakeLower();		//字符串小写化
				if (strTmp == ".txt")
					arrStrFile.Add(fdPath.Right(fdPath.GetLength() - fdPath.ReverseFind('\\') - 1));
			}
		}
	}
	find.Close();
}

struct overViewElement{
	VARIANT x;
	VARIANT y;
	string name;
};
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDM_MFCDlg 对话框



CDM_MFCDlg::CDM_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DM_MFC_DIALOG, pParent)
	, handleName2(_T(""))
	, handleName3(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDM_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, handleName3);
	DDX_Control(pDX, IDC_COMBO_MODE, m_cbb_mode);
	DDX_Control(pDX, IDC_LIST_MSG, m_lsb_msg);
	DDX_Control(pDX, IDC_COMBO_MODE2, m_mode2);
	//DDX_Control(pDX, IDC_BUTTONCAPTURE, m_btn_capture);
	DDX_Control(pDX, IDC_BUTTON6, m_btn_screen);
	DDX_Control(pDX, IDC_COMBO_DICT, m_cbb_dict);
	DDX_Control(pDX, IDC_BUTTON8, m_btn_script01);
	DDX_Control(pDX, IDC_BUTTON_INIT, m_btn_init);
	DDX_Control(pDX, IDC_BUTTON19, m_btn_script3);
}

BEGIN_MESSAGE_MAP(CDM_MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &CDM_MFCDlg::OnBnClickedButtonTest)
	ON_BN_CLICKED(IDC_BUTTON_FINDPIC, &CDM_MFCDlg::OnBnClickedButtonFindpic)
	ON_BN_CLICKED(IDC_BUTTON_OCR, &CDM_MFCDlg::OnBnClickedButtonOcr)
	ON_BN_CLICKED(IDC_BUTTON4, &CDM_MFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_EXEC, &CDM_MFCDlg::OnBnClickedButtonExec)
	ON_BN_CLICKED(IDC_BUTTON_yichang, &CDM_MFCDlg::OnBnClickedButtonyichang)
	ON_BN_CLICKED(IDC_BUTTON7, &CDM_MFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDM_MFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON1, &CDM_MFCDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE, &CDM_MFCDlg::OnCbnSelchangeComboMode)
	ON_EN_CHANGE(IDC_EDIT1, &CDM_MFCDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CDM_MFCDlg::OnBnClickedButtonInit)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE2, &CDM_MFCDlg::OnCbnSelchangeComboMode2)
	//ON_BN_CLICKED(IDC_BUTTONCAPTURE, &CDM_MFCDlg::OnBnClickedButtoncapture)
	ON_BN_CLICKED(IDC_BUTTON5, &CDM_MFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDM_MFCDlg::OnBnClickedButton6)
	ON_CBN_SELCHANGE(IDC_COMBO_DICT, &CDM_MFCDlg::OnCbnSelchangeComboDict)
	ON_BN_CLICKED(IDC_BUTTON2, &CDM_MFCDlg::OnBnClickeLockSmallShip)
	ON_BN_CLICKED(IDC_BUTTON3, &CDM_MFCDlg::OnBnClickeFindScanPoint)
	ON_BN_CLICKED(IDC_BUTTON9, &CDM_MFCDlg::OnBnClickedUnLock)
	ON_BN_CLICKED(IDC_BUTTON10, &CDM_MFCDlg::OnBnClickeLockBigShip)
	ON_BN_CLICKED(IDC_BUTTON11, &CDM_MFCDlg::OnBnClickeAttFirSShip)
	ON_BN_CLICKED(IDC_BUTTON12, &CDM_MFCDlg::OnBnClickeRoundSecShip)
	ON_BN_CLICKED(IDC_BUTTON13, &CDM_MFCDlg::OnBnClickeAttFirBShip)
	ON_BN_CLICKED(IDC_BUTTON14, &CDM_MFCDlg::OnBnClickeRoundSecBShip)
	ON_BN_CLICKED(IDC_BUTTON15, &CDM_MFCDlg::OnBnClickeRoundFirBShip)
	ON_BN_CLICKED(IDC_BUTTON16, &CDM_MFCDlg::OnBnClickedButtoScript2)
	ON_BN_CLICKED(IDC_BUTTON17, &CDM_MFCDlg::StartShipNumDectThread)
	ON_BN_CLICKED(IDC_BUTTON18, &CDM_MFCDlg::OnBnClickeRoundFirShip)
	ON_BN_CLICKED(IDC_BUTTON19, &CDM_MFCDlg::SCRIPT3)
	ON_BN_CLICKED(IDC_BUTTON20, &CDM_MFCDlg::LockFirSShip)
	ON_BN_CLICKED(IDC_BUTTON21, &CDM_MFCDlg::LockFirBShip)
	ON_BN_CLICKED(IDC_BUTTON22, &CDM_MFCDlg::IFMissleEmpty)
	ON_BN_CLICKED(IDC_BUTTON23, &CDM_MFCDlg::CALLBACKALLDRON)
	ON_BN_CLICKED(IDC_BUTTON24, &CDM_MFCDlg::RELEASEALLDRON)
	ON_BN_CLICKED(IDC_BUTTON25, &CDM_MFCDlg::StartWrapDtectThread)
END_MESSAGE_MAP()


// CDM_MFCDlg 消息处理程序

BOOL CDM_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);

	InitializeControls();




	STARTFLAG = false;





	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDM_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDM_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDM_MFCDlg::OnQueryDragIcon()
{

	return static_cast<HCURSOR>(m_hIcon);
}



void CDM_MFCDlg::OnBnClickedButtonTest()
{
	// TODO: 在此添加控件通知处理程序代码

	//使用大漠对象完成工作，比如让鼠标移至坐标(100,100)处
	//dm.MoveTo(100, 100);

	//Dm.GetInstance()->MoveTo(100, 100);
	//long hwnd = Dm.GetInstance()->FindWindow("", "EVE");
	long hwnd = Dm.GetHandle("EVE");
	Sleep(200);
	cout << hwnd << endl;
	Dm.GetInstance()->BindWindow(hwnd, "dx2", "windows", "windows", 0);
	Sleep(200);

	//Dm.GetInstance()->KeyPress(27);

}


void CDM_MFCDlg::CheckRun()
{
	if (m_pdm == NULL)
	{
		m_btn_screen.EnableWindow(false);
		m_btn_script01.EnableWindow(false);
		
	}
	else {
		m_btn_screen.EnableWindow(true);
		m_btn_script01.EnableWindow(true);
	}
	if (m_ShipNumCountThreadEnable == true && m_script3Enable == true)
	{
		m_btn_init.EnableWindow(false);
		m_btn_script3.SetWindowTextA("关闭脚本3");
	}
	else 
	{
		m_btn_init.EnableWindow(true);
		m_btn_script3.SetWindowTextA("开启脚本3");
	}

}

void CDM_MFCDlg::OnBnClickedButtonFindpic()
{


	Cdmsoft * pdm = DMInit("画图", "EVE2.txt","normal");


	// TODO: 在此添加控件通知处理程序代码
	VARIANT x, y;
	pdm->FindPic(0, 0, 1920, 1080, "huwei.bmp", "000000", 0.85, 0, &x, &y);
	cout << "X: " << x.intVal << "Y: " << y.intVal << endl;
	pdm->MoveTo(x.intVal, y.intVal);
	//Sleep(200);
	//Dm.GetInstance()->LeftClick();
	//Dm.GetInstance()->MoveTo(100, 100);



}


void CDM_MFCDlg::OnBnClickedButtonOcr()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Dm.GetInstance()->SetDict(0, "EVE.txt"))
		cout << "TEXT FAILED" << endl;
	string str = Dm.GetInstance()->Ocr(0, 0, 1920, 1080, "c3c3c3-606060", 0.85);

	cout << str << endl;
}


void CDM_MFCDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void CDM_MFCDlg::OnBnClickedButtonExec()
{
	// TODO: 在此添加控件通知处理程序代码
	Cdmsoft *pDm =  DMInstan();

	//找窗口
	long hwnd = pDm->FindWindow("","EVE");

	Sleep(200);
	cout << hwnd << endl; 
	//绑定
	pDm->BindWindow(hwnd, "dx2", "windows", "windows", 0); //windows
	Sleep(200);
	//设置路径
	char path[] = "I:\\C_C++\\DM\\DM_MFC\\source";
	pDm->SetPath(path);
	if (!pDm->SetDict(0, "EVE.txt"))
		cout << "TEXT FAILED" << endl;
	else
		cout << "LOAD TXT OK" << endl;

	VARIANT x, y;
	int state = 0; //0 :未知 1：空间站内 2：空间站外

	///////////////////////
	//int y__ = 178;
	//while (pDm->FindStr(1489, y__, 1920, 1080, "凡晶石标志", "c3c3c3-606060", 0.85, &x, &y) != -1)
	//{
	//	pDm->CreateFoobarRect(hwnd, x.intVal, y.intVal, 200, 16);
	//	y__ = y.intVal + 16;
	//	cout << x.intVal << " " << y.intVal << " "  << endl;
	//}
	//cout << "遍历完成" << endl;

	///////////////////////////////////////////TEST/////////////////////////
	while(1)
	{
		if (pDm->FindStr(1438, 136, 1897, 414, "总览|距离|名字|类型", "c3c3c3-606060", 0.85, &x, &y) != -1)
		{
			cout << "不在空间站内" << endl;
			GetDlgItem(IDC_STATIC)->SetWindowText("不在空间站内");
			state = 2;

			//已经不再空间站内
			//找总览
			int timeOut = 10;
			bool overViewFindFlag = false;
			while (timeOut-- > 0 && overViewFindFlag == false)
			{
				if (pDm->FindStr(0, 0, 1920, 1080, "总览", "c3c3c3-606060", 0.85, &x, &y) != -1)
				{
					//找到总览了
					//
					overViewFindFlag = true;
				}
			}
			if (overViewFindFlag == false)
			{
				cout << " ERROR 找不到总览！" << endl;
				return ;
			}
			else 
			{
				//找到总览了 遍历总览！
				cout << "总览找到了" <<x.intVal<<" "<<y.intVal<< endl;

				VARIANT x_overvirw = x;
				VARIANT y_overvirw = y;

				VARIANT x_tmp = x;
				VARIANT y_tmp = y;
				//从总览的地方开始 遍历所有小行星带
				int tmp_y = y_overvirw.intVal;
				//所有可用小行星带
				vector<overViewElement> vecOverviewElement;
				int i = 0;
				while (pDm->FindStr(x_overvirw.intVal, tmp_y, 1920, 1080, "小行星带", "c3c3c3-606060", 0.85, &x, &y) != -1)
				{
					overViewElement element;
					element.x = x;
					element.y = y;
					char name[256];
					sprintf(name, "小行星带_%d", i++);
					element.name = name;
					vecOverviewElement.push_back(element);
					tmp_y = y.intVal + 16;
					cout << x.intVal << " " << y.intVal << " " << element.name << endl;
				}
				cout << "遍历完成" << endl;
				//遍历完成

				//向小行星带 跃迁！
				int time = 1000;
				cout << "移动鼠标！" << endl;
				pDm->MoveTo(vecOverviewElement[0].x.intVal + 10, vecOverviewElement[0].y.intVal + 4);
				Sleep(time);
				cout << "按键按下！" << endl;
				pDm->KeyDownChar("s");
				Sleep(time);
				cout << "鼠标点击！" << endl;
				pDm->LeftClick();
				Sleep(1000);
				pDm->LeftClick();
				Sleep(time);
				cout << "按键释放！" << endl;
				pDm->KeyUpChar("s");

				//等待跃迁流程结束
				while (pDm->FindStr(590, 601, 1312, 832, "目的地", "c3c3c3-606060", 0.85, &x, &y) == -1)
				{
					cout << "等待跃迁引擎启动" << endl;
				}
				cout << "跃迁引擎已经启动" << endl;
				while (pDm->FindStr(590, 601, 1312, 832, "目的地", "c3c3c3-606060", 0.85, &x, &y) != -1)
				{
					cout << "等待跃迁引擎关闭" << endl;
				}

				cout << "跃迁引擎已经关闭" << endl;

				//已经到达小行星带
				//遍历总览找凡晶石
				tmp_y = y_overvirw.intVal;
				//所有可用小行星带
				//vector<overViewElement> vecOverviewElement;
				vecOverviewElement.clear();
				i = 0;
				tmp_y = 200;
				//x_overvirw.intVal
				while (pDm->FindStr(1400, tmp_y, 1920, 1080, "凡晶石|凡晶石标志", "c3c3c3-606060", 0.85, &x, &y) != -1)
				                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       {
					overViewElement element;
					element.x = x;
					element.y = y;
					char name[256];
					sprintf(name, "凡晶石标志_%d", i++);
					element.name = name;
					vecOverviewElement.push_back(element);
					tmp_y = y.intVal + 16;
					cout << x.intVal << " " << y.intVal << " " << element.name << endl;
				}
				cout << "遍历完成" << endl;

				//检测是否找到了凡晶石
				if (vecOverviewElement.size() == 0)
				{
					cout << "没有找到凡晶石" << endl;
					return;
				}

				//接近凡晶石
				pDm->KeyDownChar("q");
				Sleep(200);
				pDm->MoveTo(vecOverviewElement[0].x.intVal + 20, vecOverviewElement[0].y.intVal + 3);
				Sleep(200);
				pDm->LeftClick();
				pDm->KeyUpChar("q");
				//判断是否接近成功
				Sleep(15000);
				int LockNum = 3;
				i = 0;
				for (; i < LockNum; i++)
				{
					pDm->KeyDown(17);
					Sleep(200);
					pDm->MoveTo(vecOverviewElement[i].x.intVal+20, vecOverviewElement[i].y.intVal+3);
					Sleep(200);
					pDm->LeftClick();
				}
				pDm->KeyUp(17);


				//锁定三个




				cout << "done" << endl;
				while (1);


			}


		}
		else if (pDm->FindStr(1438, 136, 1897, 414, "离站|空间站服务", "c3c3c3-606060", 0.85, &x, &y) != -1)
		{
			cout << "在空间站内" << endl;
			GetDlgItem(IDC_STATIC)->SetWindowText("在空间站内");
			state = 1;

			//出站
			pDm->MoveTo(x.intVal, y.intVal-20);
			Sleep(200);
			pDm->LeftClick();
			Sleep(200);

			//等待离站
			while (pDm->FindStr(1438, 136, 1897, 414, "总览|距离|名字|类型", "c3c3c3-606060", 0.85, &x, &y) == -1)
			{
				Sleep(1000);
				cout << "等待出站" << endl;
			}

		}
		else 
		{
			cout << "状态不确定" <<pDm->Ocr(1438, 136, 1897, 414,"c3c3c3-606060",0.85) << endl;
		}
		Sleep(200);
	}



}


void CDM_MFCDlg::OnBnClickedButtonyichang()
{
	// TODO: 在此添加控件通知处理程序代码
	Cdmsoft * pdm = DMInit("EVE", "EVE2.txt");

	vector<OverViewElement> BigShipVec;
	VARIANT BigShip_x, BigShip_y;
	vector<OverViewElement> SmallShipVec;
	VARIANT SmallShip_x, SmallShip_y;

	VARIANT x, y, tmp_x, tmp_y;
	BigShip_x.intVal = 1000;
	BigShip_y.intVal = 200;
	SmallShip_x.intVal = 1000;
	SmallShip_y.intVal = 200;
	STARTFLAG = true;
	cout << "开始执行" << endl;
	int times = 0;

	while (STARTFLAG)
	{
		//检测
		system("cls");
		int i = DMFindList(*pdm, BigShip_x, BigShip_y, "科波斯", BigShipVec);
		cout << i << endl;
		i = DMFindList(*pdm, SmallShip_x, SmallShip_y, "科波姆|科必伊|科帕提斯", SmallShipVec);
		cout << i << endl;

		//if (BigShipVec.size() != 0)
		//{
		//	BigShip_x = BigShipVec[0].x;
		//	BigShip_y = BigShipVec[0].y;
		//}
		//if (SmallShipVec.size() != 0)
		//{
		//	SmallShip_x = SmallShipVec[0].x;
		//	SmallShip_y = SmallShipVec[0].y;
		//}

		//检测完成
		//锁定小船
		if (times == 109 || SmallShipVec.size() < 3)
		{
			times = 0;
		}
		if (SmallShipVec.size() != 0 && times%10 == 0)
		{
			DMLockVec(*pdm, SmallShipVec, 200);
		}
		if (SmallShipVec.size() <3 &&  times%10 == 0)
		{
			DMLockVec(*pdm, BigShipVec, 200);
		}


		if (SmallShipVec.size() != 0)
		{
			pdm->MoveTo(SmallShipVec[0].x.intVal, SmallShipVec[0].y.intVal + 4);
			Sleep(200);
			pdm->LeftClick();
			Sleep(200);
			pdm->KeyPress(112);
		}



		int smallshipsize = SmallShipVec.size();
		int bigshipsize = BigShipVec.size();


	}



}


void CDM_MFCDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码


}


void CDM_MFCDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码

	vector<OverViewElement> BigShipVec;
	VARIANT BigShip_x, BigShip_y;
	vector<OverViewElement> SmallShipVec;
	VARIANT SmallShip_x, SmallShip_y;
	vector<long> SmallShipBarVec;
	vector<long> BigShipBarVec;

	BigShipVec.reserve(20);
	SmallShipVec.reserve(20);

	int curBigShipNum = 0;
	int pastBigShipNum = 0;
	int curSmallShipNum = 0;
	int pastSmallShipNum = 0;

	bool ifAttack = false;
	bool BigShipLocked = false;

	int target = 0;		//0: 无目标 1：小船 2：大船


	VARIANT x, y, tmp_x, tmp_y;
	if (m_pdm->FindStrFast(0, 0, 1920, 1080, "名字", "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "名字已经定位");
		tmp_x = x;
		tmp_y = y;
		m_scanPoint_x = x;
		m_scanPoint_y = y;
	}
	while (1)
	{
		cout << "----------------------------------------------------------------------" << endl;
		//int i = DMFindList(*pdm, tmp_x, tmp_y, "科波姆|科必伊|科帕提斯", SmallShipVec);

		//扫描小船数量
		curSmallShipNum = DMFindListRetRow(*m_pdm, tmp_x, tmp_y, "科波姆|科必伊|科帕提斯", SmallShipVec, \
			tmp_x.intVal - 10, tmp_y.intVal, tmp_x.intVal + 145, 1080, 16);
		
		cout << "小船数量：" << curSmallShipNum <<endl;

		curBigShipNum  = DMFindListRetRow(*m_pdm, tmp_x, tmp_y, "科波斯", BigShipVec, \
			tmp_x.intVal - 10, tmp_y.intVal, tmp_x.intVal + 145, 1080, 16);

		cout << "大船数量：" << curBigShipNum << endl;
		cout << "大船VEC数量：" << BigShipVec.size() << endl;
		cout << "小船VEC数量：" << SmallShipVec.size() << endl;

		DMDrawText(m_CurHwnd, *m_pdm, 8, 12, SmallShipVec, SmallShipBarVec);
		DMDrawText(m_CurHwnd, *m_pdm, 20, 12, BigShipVec, BigShipBarVec);
		//如果刚刚开始 curSmallShipNum ！= 0 且 pastSmallShipNum == 0
		//if (pastSmallShipNum == 0 && curSmallShipNum != 0)
		//{
		//	cout << "出现了新的小船 或者 刚刚开始 锁定所有小船：" << curSmallShipNum << endl;
		//	DMLockVec(*m_pdm, SmallShipVec,500);	//锁定所有小船
		//	cout << "延时2s" << endl;
		//	Sleep(2000);							//延时2s开始操作
		//}

		if ( (ifAttack == true) && (curSmallShipNum == pastSmallShipNum) && (curBigShipNum == pastBigShipNum))
		{
			cout << ">>>正在开火 等待船数量减小" << endl;
			SmallShipVec.clear();
			BigShipVec.clear();
			continue;
		}

		//--------小船增加----------
		if (pastSmallShipNum < curSmallShipNum)
		{
			cout << ">>>过去小船数量小于现在小船数量 出现了新的船" << endl;
			cout << "锁定所有小船 " << endl;
			DMLockVec(*m_pdm, SmallShipVec, 200);	//锁定所有小船
			BigShipLocked = false;
		}
		//--------小船数量小于2----------
		if (curSmallShipNum <= 2 )//如果小船数量小于2
		{
			cout << ">>>小船数量小于等于2了"<< endl;
			if (curBigShipNum > 0 && BigShipLocked == false)
			{
				cout << "大船数量也不 等于0 则 锁定所有大船!!!w" << endl;
				DMLockVec(*m_pdm, BigShipVec, 200);//锁定所有大船
				BigShipLocked = true;
				//cout << "延时2s" << endl;
				//Sleep(2000);
			}
		}
		//--------小船数量减小----------
		if(curSmallShipNum < pastSmallShipNum && curSmallShipNum != 0)//小船的数量减少了！ 就是被打掉了
		{
			cout << ">>>小船数量减少了！并且存在小船" << endl;

			ifAttack = false;		//简单的 认为延时后 武器冷却完毕

			cout << "环绕第一个小船" << endl;
			DMPressClk(*m_pdm, SmallShipVec[0].x, SmallShipVec[0].y, "w", 200);		//环绕第一个

			cout << "延时2s 等待武器冷却！" << endl;
			Sleep(2000);		//!!!延时5秒 等待武器冷却！

			cout << "按下F1" << endl;
			m_pdm->KeyPress(112);	//按下F1进行进攻		然后攻击

			target = 1;				//目标为小船

			ifAttack = true;		//简单的认为	按下就开火 后续会进行图像识别检测

			if (curSmallShipNum >= 2)
			{
				cout << "小船数量足够 环绕第二个" << endl;
				DMPressClk(*m_pdm, SmallShipVec[1].x, SmallShipVec[1].y, "w", 500);		//环绕第二个
			}
			else
			{
				//如果小船只有一艘 那就环绕大船第一艘
				if (curBigShipNum > 0)
				{
					cout << "小船数量不足 且大船存在 环绕第一个大船" << endl;
					DMPressClk(*m_pdm, BigShipVec[0].x, BigShipVec[0].y, "w", 200);		//环绕第二个
				}
			}
		}
		//--------小船存在 但是没有攻击----------
		if ((ifAttack == false) && (curSmallShipNum != 0))		//如果不在开火 且小船存在
		{
			cout << ">>>如果不在开火且小船存在 则环绕第一个小船" << endl;
			DMPressClk(*m_pdm,SmallShipVec[0].x, SmallShipVec[0].y, "w", 200);		//环绕
			//Sleep(500);
			//DMPressClk(*m_pdm, SmallShipVec[0].x, SmallShipVec[0].y, "w", 500);

			cout << "开火F1" << endl;
			//if(ifAttack == false)
				m_pdm->KeyPress(112);	//按下F1进行进攻
			Sleep(200);
			ifAttack = true;		//简单的认为	按下就开火 后续会进行图像识别检测

			if (curSmallShipNum >= 2)		//如果小船 有两个以上 那么久环绕下一个
			{
				cout << "小船数量足够 环绕第二个" << endl;
				DMPressClk(*m_pdm, SmallShipVec[1].x, SmallShipVec[1].y, "w", 200);		//环绕第二个
			}
			else
			{	
				//如果小船只有一艘 那就环绕大船第一艘
				if (curBigShipNum > 0)
				{
					cout << "小船数量不足 且大船存在 环绕第一个大船" << endl;
					DMPressClk(*m_pdm, BigShipVec[0].x, BigShipVec[0].y, "w", 200);		//环绕第二个
				}
			}
		}
		//--------小船数量为0 或者大船数量减少了----------
		if ( (curBigShipNum != 0)&&(curBigShipNum < pastBigShipNum) || ( (curSmallShipNum == 0)&&(curSmallShipNum < pastSmallShipNum)))//大船的数量减少了！ 就是被打掉了
		{
			cout << ">>>大船数量减少 或者小船不存在的第一波 开始转火" << endl;
			Sleep(2000);		//!!!延时5秒 等待武器冷却！

			cout << "环绕第一个大船" << endl;
			DMPressClk(*m_pdm, BigShipVec[0].x, BigShipVec[0].y, "w", 500);		//环绕第一个

			Sleep(500);
			cout << "开火" << endl;
			m_pdm->KeyPress(112);	//按下F1进行进攻		然后攻击

			Sleep(500);

			m_pdm->KeyPress(114);	//启动导弹

			target = 2;				//目标为大船

			ifAttack = true;		//简单的认为	按下就开火 后续会进行图像识别检测

			if (BigShipVec.size() >= 2)
			{
				cout << "延时五秒" << endl;
				Sleep(5000);		//延时5秒后再绕下一条船
				cout << "大船数量足够 环绕第二辆" << endl;
				DMPressClk(*m_pdm, BigShipVec[1].x, BigShipVec[1].y, "w", 500);		//环绕第二个
			}
			//后续完善

		}

		if (curBigShipNum == 0 && curSmallShipNum == 0)
		{
			cout << "当前无目标" << endl;
			ifAttack = false;
			target = 0;
		}
		m_pdm->MoveTo(200+ curSmallShipNum, 300+ curBigShipNum);

		pastBigShipNum = curBigShipNum;
		pastSmallShipNum = curSmallShipNum;
		SmallShipVec.clear();
		BigShipVec.clear();

		DMFoorBarClose(*m_pdm, SmallShipBarVec);
		DMFoorBarClose(*m_pdm, BigShipBarVec);
		cout << "----------------------------------------------------------------------" << endl;
	}

}

//int CDM_MFCDlg::ListScanFun(Cdmsoft *pdm, vector<OverViewElement> &v, 
//							char * location,bool &enableFlag ,char * findStr,
//							int x_end = 1920, int y_end = 1080,
//							char * color = "c3c3c3-606060",double sim = 0.85)
//{
//	// TODO: 在此添加控件通知处理程序代码
//
//	VARIANT x, y, tmp_x, tmp_y;
//	if (pdm->FindStrFast(0, 0, x_end, y_end, location, color, 0.85, &x, &y) != -1)
//	{
//		cout << "location Finded" << endl;
//		tmp_x = x;
//		tmp_y = y;
//	}
//	else
//	{
//		return -1;
//	}
//	while (enableFlag)
//	{
//		v.clear();
//		//int i = DMFindList(*pdm, tmp_x, tmp_y, "科波姆|科必伊|科帕提斯", SmallShipVec);
//		int i = DMFindListRetRow(*pdm, tmp_x, tmp_y, findStr, v,
//								tmp_x.intVal - 10, tmp_y.intVal, tmp_x.intVal + 145, y_end, 16);
//		
//	}
//
//}


void CDM_MFCDlg::OnBnClickedButton1()
{
	m_pdm->KeyDown(16);

}


void CDM_MFCDlg::OnCbnSelchangeComboMode()
{
	// TODO: 在此添加控件通知处理程序代码
	int choice = m_cbb_mode.GetCurSel();
	
		switch (choice)
		{
		case 0:
			m_mode = "normal";	break;
		case 1:
			m_mode = "dx";		break;
		case 2:
			m_mode = "dx2";		break;
		case 3:
			m_mode = "gdi";		break;
		default:
			m_mode = "dx2";		break;
		}	
	
	//m_cbb_mode.GetWindowTextA(m_mode);
	m_lsb_msg.AddString("Mode choice: " + m_mode);
}

void CDM_MFCDlg::OnCbnSelchangeComboMode2()
{
	// TODO: 在此添加控件通知处理程序代码
	int sel = m_mode2.GetCurSel();
	switch (sel)
	{
	case 0: m_mode2_cstr = "normal";		break;
	case 1: m_mode2_cstr = "windows";		break;
	case 2: m_mode2_cstr = "dx";			break;
	case 3: m_mode2_cstr = "dx2";			break;
	case 4: m_mode2_cstr = "windows3";		break;
	default: m_mode2_cstr = "windows";		break;
	}

	m_lsb_msg.AddString("Mode2 choice: " + m_mode2_cstr);
}

void CDM_MFCDlg::InitializeControls(void)
{

	CString mode[] = { "normal","dx","dx2","gdi" };
	int num = sizeof(mode) / sizeof(CString);
	for (int i = 0; i < num; i++)
	{
		m_cbb_mode.InsertString(i, mode[i]);
	}
	m_cbb_mode.SetCurSel(2);
	OnCbnSelchangeComboMode();

	CString mode2[] = { "normal","windows","dx","dx2","windows3"};
	num = sizeof(mode2) / sizeof(CString);
	for (int i = 0; i < num; i++)
	{
		m_mode2.InsertString(i, mode2[i]);
	}
	m_mode2.SetCurSel(1);
	OnCbnSelchangeComboMode2();

	CStringArray cstra;
	getFolderDayFile("..\\source", cstra);

	for (int i = 0; i < cstra.GetSize(); i++)
	{
		m_cbb_dict.InsertString(i, cstra[i]);
	}
	m_cbb_dict.SetCurSel(1);
	OnCbnSelchangeComboDict();

	handleName3 = "OBRS";
	UpdateData(FALSE);
	m_lsb_msg.AddString("Handle Name: " + handleName3);

	//m_dictNmae = "EVE2.txt";

	m_pdm = NULL;

	CheckRun();
	//m_cbb_mode.inser
}




void CDM_MFCDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CDM_MFCDlg::OnBnClickedButtonInit()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm == NULL)
	{
		//Cdmsoft *pDm = ;
		m_pdm = DMInstan();
		m_pdmCounter = DMInstan();
		if (m_pdm == NULL || m_pdmCounter == NULL)
		{
			m_lsb_msg.AddString("NEW 大漠对象失败");
			return;
		}
	}
		
	//
	long hwnd = m_pdm->FindWindow("", handleName3.GetBuffer(0)); //
	long hwnd2 = m_pdmCounter->FindWindow("", handleName3.GetBuffer(0));
	if (hwnd == 0 || hwnd2 == 0)
	{
		m_lsb_msg.AddString("没有找到对应窗口！");
		return;
	}
	else
	{
		CString cstr;
		cstr.Format("对应窗口已找到: %d", hwnd);
		m_CurHwnd = hwnd;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), cstr);
	}
		
	Sleep(200);
	//绑定
	char *mode = "windows";
	//if (0 == (m_pdm->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0))
	//		|| 0 == (m_pdmCounter->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0)))
	if (0 == (m_pdm->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0))
		|| 0 == (m_pdmCounter->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0)))
	{
		m_lsb_msg.AddString("绑定窗口失败！");
		return;
	}
	Sleep(200);

	char path[] = "..\\source";
	if (m_pdm->SetPath(path) == 0 || m_pdmCounter->SetPath(path) == 0)
	{
		m_lsb_msg.AddString("路径设置失败！");
		return;
	}

	if (!m_pdm->SetDict(0, m_dictNmae) || !m_pdmCounter->SetDict(0, m_dictNmae))
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "载入字库失败");
		return ;
	}
	else
	{ 
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "载入字库成功");
	}
		



	CheckRun();
}





void CDM_MFCDlg::OnBnClickedButtoncapture()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm->Capture(0, 0, 1920, 1080, "capture.bmp") == 0)
		m_lsb_msg.AddString("截图失败");
	else
		m_lsb_msg.AddString("截图成功");
}


void CDM_MFCDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_lsb_msg.ResetContent();
}


void CDM_MFCDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm->Capture(0, 0, 1920, 1080, "capture.bmp") == 0)
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(),"截图失败");
	else
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "截图成功");
}


void CDM_MFCDlg::OnCbnSelchangeComboDict()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString cstr;
	m_cbb_dict.GetWindowTextA(m_dictNmae);
	m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "选择字典：" + m_dictNmae);
}


void CDM_MFCDlg::OnBnClickeLockSmallShip()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//锁定所有小船
	DMFindListLock(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波姆|科必伊|科帕提斯", 100, 
					m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);

}


void CDM_MFCDlg::OnBnClickeFindScanPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm == NULL )
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "DM没有初始化");
		return;
	}
	VARIANT x, y, tmp_x, tmp_y;
	if (m_pdm->FindStrFast(0, 0, 1920, 1080, "名字", "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		cout << ">>>查找起始点 已经重定位" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "名字已经定位 扫描起始点已定位");
		tmp_x = x;
		tmp_y = y;
		m_scanPoint_x = x;
		m_scanPoint_y = y;
		
	}

}


void CDM_MFCDlg::OnBnClickedUnLock()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm == NULL)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//锁定所有小船
	DMFindListUnLock(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波姆|科必伊|科帕提斯", 200,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);	// TODO: 在此添加控件通知处理程序代码

}


void CDM_MFCDlg::OnBnClickeLockBigShip()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//锁定所有小船
	DMFindListLock(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波斯|黑暗", 120,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeAttFirSShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//攻击第一个小船
	DMFindListAttack(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波姆|科必伊|科帕提斯", 80,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeRoundSecShip()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//环绕第二个小船
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波姆|科必伊|科帕提斯", 80, 
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeAttFirBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//攻击第一个大船
	DMFindListAttackBig(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波斯|黑暗", 80,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeRoundSecBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//环绕第二个大船
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波斯|黑暗", 80,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeRoundFirBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//环绕第一个大船
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波斯|黑暗", 100,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16,70,0);
}


void CDM_MFCDlg::OnBnClickedButtoScript2()
{
	// TODO: 在此添加控件通知处理程序代码
	int curBigShipNum = 0;
	int pastBigShipNum = 0;
	int curSmallShipNum = 0;
	int pastSmallShipNum = 0;

	bool ifAttack = false;
	bool BigShipLocked = false;
	bool SmallShipLocked = false;
	int target = 0;		//0: 无目标 1：小船 2：大船

	//初始化 总览扫描起点
	//
	this->OnBnClickeFindScanPoint();

	//开启 船数量检测线程
	//
	if(m_ShipNumCountThreadEnable == false)
		this->StartShipNumDectThread();

	Sleep(5000);
	while (1)
	{
		//获取当前船只数量
		//
		curBigShipNum = m_curBShipNum;
		curSmallShipNum = m_curSShipNum;


		if ((ifAttack == true) && (curSmallShipNum == pastSmallShipNum) && (curBigShipNum == pastBigShipNum))
		{
			//cout << "w" << endl;
			//system("clr");
			continue;
		}

		//--------小船增加----------
		if (pastSmallShipNum < curSmallShipNum)
		{
			cout << ">>>过去小船数量小于现在小船数量 出现了新的船" << endl;
			cout << "环绕第一个小船" << endl;
			this->OnBnClickeRoundFirShip();
			cout << "延时 3秒" << endl;
			Sleep(3000);
			cout << "锁定所有小船 " << endl;
			this->OnBnClickeLockSmallShip();	//锁定所有小船

			cout << "延时 7 s等待所有小船 被锁定 " << endl;
			Sleep(7000);

			SmallShipLocked = true;
			BigShipLocked = false;
		}

		//--------小船数量减小----------
		if (curSmallShipNum < pastSmallShipNum && curSmallShipNum != 0)//小船的数量减少了！ 就是被打掉了
		{
			cout << ">>>小船数量减小了" << endl;
			cout << "环绕第一艘小船" << endl;

			this->OnBnClickeRoundFirShip();
			BigShipLocked = false;
			ifAttack = false;		//简单的 认为延时后 武器冷却完毕

			cout << ">>>延时 7s 等待武器冷却" << endl;
			Sleep(7000);
			cout << "攻击第一个小船" << endl;
			this->OnBnClickeAttFirSShip();

			this->OnBnClickeRoundFirShip();

			target = 1;				//目标为小船

			ifAttack = true;		//简单的认为	按下就开火 后续会进行图像识别检测

			//if (curSmallShipNum >= 2)
			//{
			//	cout << "小船数量足够 环绕第二个" << endl;
			//	this->OnBnClickeRoundSecShip();	//环绕第二艘小船
			//}
			//else
			//{
			//	//如果小船只有一艘 那就环绕大船第一艘
			//	if (curBigShipNum > 0)
			//	{
			//		cout << "小船数量不足 且大船存在 环绕第一个大船" << endl;
			//		this->OnBnClickeRoundFirBShip();	//环绕第一艘大船
			//	}
			//}
		}

		//--------小船数量小于2----------
		if (curSmallShipNum <= 2)//如果小船数量小于2
		{
			
			if ((curBigShipNum > 0) && (BigShipLocked == false))
			{
				cout << ">>>小船数量小于等于2了" << endl;
				cout << "大船数量也不 等于0 则 锁定所有大船!!!w" << endl;

				this->OnBnClickeLockBigShip();
				BigShipLocked = true;
				//cout << "延时2s" << endl;
				//Sleep(2000);
			}
		}

		//--------小船存在 但是没有攻击----------
		//if ((ifAttack == false) && (curSmallShipNum != 0))		//如果不在开火 且小船存在
		if ((curSmallShipNum != 0))
		{
			cout << ">>>如果不在开火且小船存在 则环绕第一个小船" << endl;
			cout << "环绕第一艘小船" << endl;

			this->OnBnClickeRoundFirShip();
			this->OnBnClickeAttFirSShip();
			ifAttack = true;		//简单的认为	按下就开火 后续会进行图像识别检测

			//if (curSmallShipNum >= 2)
			//{
			//	cout << "小船数量足够 环绕第二个" << endl;
			//	this->OnBnClickeRoundSecShip();	//环绕第二艘小船
			//}
			//else
			//{
			//	//如果小船只有一艘 那就环绕大船第一艘
			//	if (curBigShipNum > 0)
			//	{
			//		cout << "小船数量不足 且大船存在 环绕第一个大船" << endl;
			//		this->OnBnClickeRoundFirBShip();	//环绕第一艘大船
			//	}
			//}
		}

		//--------小船数量为0 或者大船数量减少了----------
		if ((curBigShipNum != 0) && (curBigShipNum < pastBigShipNum) || ((curSmallShipNum == 0) && (curSmallShipNum < pastSmallShipNum)) ||(curBigShipNum != 0 && ifAttack == false ) )//大船的数量减少了！ 就是被打掉了
		{
			cout << ">>>大船数量减少 或者小船不存在的第一波 开始转火延时5秒 等待武器冷却！" << endl;

			ifAttack = false;
			cout << "环绕第一艘大船" << endl;
			this->OnBnClickeRoundFirBShip();
			cout << "延时 7s" << endl;
			Sleep(7000);		//!!!延时5秒 等待武器冷却！

			//攻击第一艘大船
			this->OnBnClickeAttFirBShip();

			ifAttack = true;		//简单的认为	按下就开火 后续会进行图像识别检测

			//if (curBigShipNum >= 2)
			//{
			//	this->OnBnClickeRoundSecBShip();
			//}
			////后续完善

		}

		if (curBigShipNum == 0 && curSmallShipNum == 0)
		{
			cout << ">>>当前无目标" << endl;
			ifAttack = false;
			target = 0;
		}
		//m_pdm->MoveTo(200 + curSmallShipNum, 300 + curBigShipNum);




		pastBigShipNum = curBigShipNum;
		pastSmallShipNum = curSmallShipNum;
		//cout << "----------------------------------------------------------------------" << endl;
	}
}


//当前船数量计数线程
//
UINT ShipCoutThread(LPVOID pParam)
{
	CDM_MFCDlg * pThis = (CDM_MFCDlg *)pParam;
	int pastSmallShipNum = 0;
	int pastBigShipNum = 0;
	int curSmallShipNum = 0;
	int curBigShipNum = 0;
	int changeFlag = 0;
	int changNum = 2;		//改变两次以上 就更新值
	while (pThis->m_ShipNumCountThreadEnable)
	{
		curSmallShipNum = DMFindListCount(*pThis->m_pdmCounter, pThis->m_scanPoint_x, pThis->m_scanPoint_y,"科波姆|科必伊|科帕",
			pThis->m_scanPoint_x.intVal - 10, pThis->m_scanPoint_y.intVal, pThis->m_scanPoint_x.intVal + 145, 1080, 16);

		curBigShipNum = DMFindListCount(*pThis->m_pdmCounter, pThis->m_scanPoint_x, pThis->m_scanPoint_y, "科波斯|黑暗",
			pThis->m_scanPoint_x.intVal - 10, pThis->m_scanPoint_y.intVal, pThis->m_scanPoint_x.intVal + 145, 1080, 16);

		if (pastSmallShipNum != curSmallShipNum)
		{
			changeFlag++;
			if (changeFlag >= changNum)
			{
				pastSmallShipNum = curSmallShipNum;
				pThis->m_curSShipNum = curSmallShipNum;
				changeFlag = 0;
				cout << "//---------------小船数量改变 数量为 :" << pThis->m_curSShipNum << endl;
			}
		}
		if (pastBigShipNum != curBigShipNum)
		{
			changeFlag++;
			if (changeFlag >= changNum)
			{
				pastBigShipNum = curBigShipNum;
				pThis->m_curBShipNum = curBigShipNum;
				changeFlag = 0;
				cout << "//---------------大船数量改变 数量为:" << pThis->m_curBShipNum << endl;
			}
		}
		//Sleep(50);
	}
	cout << "船数量计数线程已退出" << endl;
	return 0;
}

void CDM_MFCDlg::StartShipNumDectThread()
{
	if (m_ShipNumCountThreadEnable == false)
	{
		cout << "开始船数量计数线程" << endl;
		m_ShipNumCountThreadEnable = true;
		AfxBeginThread(ShipCoutThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

	}
	else
	{
		m_ShipNumCountThreadEnable = false;
		cout << "船数量计数线程已开启 关闭其" << endl;
	}
}


void CDM_MFCDlg::OnBnClickeRoundFirShip()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		cout << "ERROR! dm未初始化 或者 搜寻点为0" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//环绕第二个小船
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波姆|科必伊|科帕提斯", 150,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16,70,0);
}


UINT SCRIPT3THREAD(LPVOID pParam)
{
	// TODO: 在此添加控件通知处理程序代码
	int curBigShipNum = 0;
	int pastBigShipNum = 0;
	int curSmallShipNum = 0;
	int pastSmallShipNum = 0;
	int LockDelayTime = 7000;

	bool ifAttack = false;
	bool BigShipLocked = false;
	bool SmallShipLocked = false;
	int target = 0;		//0: 无目标 1：小船 2：大船
	bool ifMissleEmpty = false;
	bool onFire = false;
	int reLoadFlag = 0;

	long BShipAttOutTime = 8;
	long SShipAttOutTime = 8;
	CTime BShipStartAttackTimer;
	long BShipAttackTime;
	//初始化 时间 防止发生异常
	BShipStartAttackTimer = CTime::GetCurrentTime();
	BShipAttackTime = BShipStartAttackTimer.GetTime();
	CTime SShipStartAttackTimer;
	long SShipAttackTime;
	//初始化 时间 防止发生异常
	SShipStartAttackTimer = CTime::GetCurrentTime();
	SShipAttackTime = SShipStartAttackTimer.GetTime();
	//
	CTime noTargetTimer;
	long noTargetTime;
	bool noTargetTimerEnable = false;
	noTargetTimer = CTime::GetCurrentTime();
	noTargetTime = noTargetTimer.GetTime();

	CTime ReLoadTimer;
	long ReLoadTime = 70;
	long noTargetOutTime = 10;

	long BShipRoundSecTime = 8;
	long SShipRoundSecTime = 3;

	CTime Curtimer;
	long curTime;
	VARIANT attack_x, attack_y;
	//BShipStartAttackTime = CTime::GetCurrentTime();             //获取当前时间日期
	//BShipTimer
	//long nTSeconds = m_time.GetTime();
	


	//初始化 总览扫描起点
	//
	CDM_MFCDlg * pThis = (CDM_MFCDlg *)pParam;
	cout << "脚本3已经启动" << endl;
	Sleep(2000);
	while (pThis->m_script3Enable)
	{
		//获取当前船只数量
		//
		curBigShipNum = pThis->m_curBShipNum;
		curSmallShipNum = pThis->m_curSShipNum;
		
		//----------------环绕判断----------------
		//
		//if ((curBigShipNum != 0) || (0 != curSmallShipNum))
		//{
		//	if (onFire == false)
		//	{
		//		cout << ">>> <环绕判断> NOT ON FIRE!" << endl;
		//		if (0 != curSmallShipNum)
		//		{
		//			cout << "<环绕> 第1 <小艘>" << endl;
		//			pThis->OnBnClickeRoundFirShip();
		//		}
		//		else if (0 != curBigShipNum)
		//		{
		//			cout << "<环绕> 第1 <大艘>" << endl;
		//			pThis->OnBnClickeRoundFirBShip();
		//		}
		//	}
		//}

		//-----------------------无目标判断-----------------
		if (0 != curSmallShipNum || 0 != curBigShipNum)
		{
			noTargetTimerEnable = false;
		}
		if (0 == curSmallShipNum && 0 == curBigShipNum && false == noTargetTimerEnable)
		{
			//cout << ">>>当前无目标" << endl;
			//cout << "召回所有舰载机" << endl;
			//pThis->CALLBACKALLDRON();
			//Sleep(800);
			//pThis->m_pdm->KeyPress(113);
			//Sleep(10 * 1000);
			noTargetTimer = CTime::GetCurrentTime();
			noTargetTime = noTargetTimer.GetTime();
			noTargetTimerEnable = true;
			cout << "当前无目标 开启无目标计时" << endl;
			cout << endl;
		}
		if (true == noTargetTimerEnable)
		{
			Curtimer = CTime::GetCurrentTime();
			curTime = Curtimer.GetTime();
			cout << "无目标检测时间： " << curTime - noTargetTime <<endl;
			cout << endl;
			if (curTime - noTargetTime >= noTargetOutTime)
			{
				cout << "当前无目标！" << endl;
				cout << "收回所有无人机！" << endl;
				pThis->CALLBACKALLDRON();
				Sleep(800);
				pThis->m_pdm->KeyPress(113);
				Sleep(3000);
				cout << "退出线程！" << endl;
				
				pThis->m_script3Enable = false;
				pThis->m_WrapDetectThreadEnable = false;
				pThis->m_ShipNumCountThreadEnable = false;

				pThis->m_lsb_msg.AddString(">>>关闭舰船数量检测线程");
				pThis->m_lsb_msg.AddString(">>>关闭跃迁检测线程");
				pThis->m_lsb_msg.AddString(">>>关闭脚本");
				cout << endl;
				pThis->CheckRun();
				return 0;
			}
			Sleep(1000);
		}

		//-------------------------舰载机 就绪 判断------------------
		//在有目标的时候才会判断
		if ((onFire == false) && (0 != curSmallShipNum || 0 != curBigShipNum))
		{
			if (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "DroneReady.bmp", "202020", 0.8, 0, &attack_x, &attack_y) != -1)
			{
				cout << "检测到无人机就绪 且存在敌人" << endl;
				cout << "释放所有铁JJ" << endl;
				cout << endl;
				pThis->RELEASEALLDRON();
				Sleep(1500);
				pThis->m_pdm->KeyPress(113);
			}
		}


		//---------------------跃迁检测---------------------------
		if (pThis->m_IfWrapON == true)
		{
			cout << "-------------------ON WRAP！--------------" << endl;
			while (pThis->m_IfWrapON == true)
			{
				cout << "-------------------ON WRAP！--------------" << endl;
				Sleep(4000);
			}
			cout << "按下F4 启动感应增强脚本" << endl;
			pThis->m_pdm->KeyPress(115);
		}


		//船的数量发生改变时 则重新扫描所有船数量2次 防止遗漏小船
		//如果船只增加 
		//
		if(curSmallShipNum > pastSmallShipNum)
		{
			SmallShipLocked = false;
			//船的数量增加 先环绕两次 再刷新 数量 以防 后续错误判断
			for (int i = 0; i < 2; i++)
			{
				pThis->OnBnClickeRoundFirShip();
				Sleep(400);
			}
			curSmallShipNum = pThis->m_curSShipNum;
			curBigShipNum = pThis->m_curBShipNum;
		}
		if (curBigShipNum > pastBigShipNum)
		{
			BigShipLocked = false;
			//船的数量增加 先环绕两次 再刷新 数量 以防 后续错误判断
			//for (int i = 0; i < 2; i++)
			//{
			//	pThis->OnBnClickeRoundFirBShip();
			//	Sleep(400);
			//}
			//curSmallShipNum = pThis->m_curSShipNum;
			//curBigShipNum = pThis->m_curBShipNum;

		}
		if (curSmallShipNum < pastSmallShipNum)
		{
			pThis->OnBnClickeRoundFirShip();
			ifAttack = false;
		}
		if (curBigShipNum < pastBigShipNum)
		{
			cout << "<大船>减少 延时0秒" << endl;
			cout << endl;
			pThis->OnBnClickeRoundFirBShip();
			ifAttack = false;
			//reLoadFlag = 0;
			//Sleep(2000);
		}

		

		//----------攻击判断-----------------
		//
		if ((curSmallShipNum != 0) && (onFire == false))
		{
			cout << "<攻击判断>" << endl;
			cout << ">>>小船不为0 并且不在 开火" << endl;
			cout << "环绕第一艘小船" << endl;
			cout << endl;
			pThis->OnBnClickeRoundFirShip();
			ifAttack = true;

			/*
			Sleep(200);
			cout << "锁定第一艘小船" << endl;
			pThis->LockFirSShip();
			*/
			/*
			Sleep(200);
			cout << "攻击第一艘小船" << endl;
			pThis->OnBnClickeAttFirSShip();
			//定时器启动
			Sleep(100);
			pThis->OnBnClickeAttFirSShip();
			cout << "延时1秒" << endl;
			Sleep(1000);*/  //攻击行为交付给 图像检测系统完成
		}
		if ((curSmallShipNum == 0) && (curBigShipNum != 0) &&(ifAttack == false) && (onFire == false))
		{
			cout << "<攻击判断>" << endl;
			cout << ">>>小船为0,大船不为0，并且不在开火" << endl;
			cout << "环绕第一艘大船" << endl;
			cout << endl;
			pThis->OnBnClickeRoundFirBShip();
			ifAttack = true;

			/*			Sleep(200);
			cout << "锁定第一艘大船" << endl;
			pThis->LockFirBShip();
			*/
			/*			
			Sleep(200);
			cout << "攻击第一艘大船" << endl;
			pThis->OnBnClickeAttFirBShip();
			ifAttack = true;
			*/
			//攻击行为交付给 图像检测系统完成


			//Sleep(200);
			//pThis->OnBnClickeAttFirBShip();
			//cout << "延时2秒" << endl;
			//Sleep(2000);
		}

		//---------------------图像检测攻击判定----------------------
		if ((0 != curBigShipNum) || (0 != curSmallShipNum) && (ifAttack == true))
		{
			if ( (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "F1_3.bmp", "202020", 0.95, 0, &attack_x, &attack_y) == -1) ) //"F1_2.bmp"
			{
				cout << "<图像检测攻击判断>" << endl;
				cout << "/---------NOT ON FIRE!------------/" << endl;
				onFire = false;
				if (curSmallShipNum != 0)
				{
					//如果是由于打掉了一艘船导致的攻击失效则 
					//if (pThis->m_curSShipNum < curSmallShipNum)
					//{
					//	cout << "//----------小船 由于 攻击减少 环绕第一艘小船" << endl;
					//	pThis->OnBnClickeRoundFirShip();
					//	continue;
					//}
					cout << ">>>小船不为0" << endl;
					cout << "环绕第一艘小船" << endl;
					pThis->OnBnClickeRoundFirShip();
					Sleep(100);
					cout << "锁定第一艘小船" << endl;
					pThis->LockFirSShip();
					Sleep(100);
					cout << "攻击第一艘小船" << endl;
					cout << endl;
					pThis->OnBnClickeAttFirSShip();
					//开启小船攻击计时
					SShipStartAttackTimer = CTime::GetCurrentTime();
					SShipAttackTime = SShipStartAttackTimer.GetTime();
					Sleep(800);
				}
				else if (curBigShipNum != 0)
				{
					//如果是由于打掉了一艘船导致的攻击失效则 
					//if (pThis->m_curBShipNum < curBigShipNum)
					//{
					//	cout << "//----------大船 由于 攻击减少 环绕第一艘大船" << endl;
					//	pThis->OnBnClickeRoundFirBShip();
					//	continue;
					//}
					cout << "环绕第一艘大船" << endl;
					pThis->OnBnClickeRoundFirBShip();
					Sleep(100);
					if (pThis->m_curSShipNum != 0)
					{
						cout << "当前小船不为0 回滚！" << endl;
						continue;
					}
					cout << "锁定第一艘大船" << endl;
					pThis->LockFirBShip();
					Sleep(100);
					cout << "攻击第一艘大船" << endl;
					cout << endl;
					pThis->OnBnClickeAttFirBShip();
					Sleep(600);
					//开启大船攻击计时
					BShipStartAttackTimer = CTime::GetCurrentTime();
					BShipAttackTime = BShipStartAttackTimer.GetTime();
				}
			}
			else
			{
				onFire = true;
			}
		}

		//----------锁定判断-----------------
		//
		if ((curSmallShipNum != 0) && (SmallShipLocked == false))
		{
			cout << "<锁定判断>" << endl;
			//cout << ">>>锁定所有小船" << endl;
			cout << "环绕第一艘小船" << endl;
			pThis->OnBnClickeRoundFirShip();
			Sleep(200);
			cout << ">>>锁定所有小船" << endl;
			pThis->OnBnClickeLockSmallShip();
			cout << "延时2秒" << endl;
			cout << endl;
			Sleep(2000);
			SmallShipLocked = true;
			cout << endl;
		}

		if ((curSmallShipNum <= 3) && (BigShipLocked == false) && (curBigShipNum != 0))
		{
			cout << "<锁定判断>" << endl;
			cout << ">>>锁定所有大船" << endl;
			cout << endl;
			pThis->OnBnClickeLockBigShip();
			BigShipLocked = true;
			cout << endl;
		}

		//------------大船攻击计时判断--------------
		if ((curSmallShipNum == 0) && (ifAttack == true) && (curBigShipNum != 0))
		{
			Curtimer = CTime::GetCurrentTime();
			long ctime = Curtimer.GetTime();
			long passtime;
			passtime = (ctime - BShipAttackTime);
			//获取时间
			//等待消灭大船
			cout << "pass time: " << passtime << endl;;
			Sleep(500);
			//system("cls");
#ifdef ROUND_TEST
			if ((passtime == BShipRoundSecTime))
			{
				cout << "//================！！！环绕判定！！！" << endl;
				cout << "环绕第二艘大船！" << endl;

				pThis->OnBnClickeRoundSecBShip();
			}
#endif
			if ((passtime >= BShipAttOutTime) )
			{
				
				cout << "大船攻击超时 启动导弹" << endl;
				cout << endl;
				pThis->m_pdm->KeyPress(114);
				Sleep(800);
			}
			/*	
			VARIANT x_pic, y_pic;
			if (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "missleEmpty.bmp", "202020", 0.95, 0, &x_pic, &x_pic) != -1) //"F1_2.bmp"
			{
				ifMissleEmpty = true;
				cout << "/---------MISSSLE EMPTY------------/" << endl;
			}
			if (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "F1_2.bmp", "202020", 0.95, 0, &x_pic, &x_pic) != -1) //"F1_2.bmp"
			{
				//ifMissleEmpty = true;
				cout << "/---------NOT ON FIRE!------------/" << endl;
			}
			*/
		}
		//------------小船攻击计时判断--------------
		if ((curSmallShipNum != 0) && (ifAttack == true) )
		{
			Curtimer = CTime::GetCurrentTime();
			long ctime = Curtimer.GetTime();
			long passtime;
			passtime = (ctime - SShipAttackTime);
			//获取时间
			//等待消灭大船
			cout << "Small pass time: " << passtime << endl;;
			Sleep(400);
			//system("cls");
#ifdef ROUND_TEST
			if ((passtime == SShipRoundSecTime))
			{
				cout << "//================！！！环绕判定！！！" << endl;
				if (curSmallShipNum >= 2)
				{
					cout << "环绕第二艘小船！" << endl;
					pThis->OnBnClickeRoundSecShip();
				}
				else
				{
					cout << "环绕第1艘大船！" << endl;
					pThis->OnBnClickeRoundFirBShip();
				}
			}
#endif
			if ((passtime >= SShipAttOutTime))
			{
				cout << "小船攻击超时 " << endl;
				Sleep(100);
				cout << "锁定第一艘小船" << endl;
				pThis->LockFirSShip();
				Sleep(100);
				cout << "攻击第一艘小船" << endl;
				cout << endl;
				pThis->OnBnClickeAttFirSShip();
				Sleep(100);
			}
			/*
			VARIANT x_pic, y_pic;
			if (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "missleEmpty.bmp", "202020", 0.95, 0, &x_pic, &x_pic) != -1) //"F1_2.bmp"
			{
			ifMissleEmpty = true;
			cout << "/---------MISSSLE EMPTY------------/" << endl;
			}
			if (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "F1_2.bmp", "202020", 0.95, 0, &x_pic, &x_pic) != -1) //"F1_2.bmp"
			{
			//ifMissleEmpty = true;
			cout << "/---------NOT ON FIRE!------------/" << endl;
			}
			*/
		}
		//----------------导弹数量检测-----------------------
		//
		if (DMFindPicRow(*pThis->m_pdm, attack_x, attack_y, "missleEmpty.bmp", 20, 0, 0, 1920, 1080) >= 2)
		{
			cout << "------------------MISSLE EMPTY-----------------" << endl;
			if ((0 == curSmallShipNum))
			{
				cout << "没有小船！" << endl;
				cout << "召回所有铁骑！" << endl;
				pThis->CALLBACKALLDRON();
				Sleep(800);
				pThis->m_pdm->KeyPress(113);

				//暂时不做判断
				cout << "延时！" << endl;
				int time;
				for (time = 0; time < ReLoadTime; time++)
				{
					Sleep(1000);
					cout << "Waiting: " <<time<<endl;
				}
				//Sleep(100*1000);
				cout << "释放所有铁骑！" << endl;
				cout << endl;
				pThis->RELEASEALLDRON();
				Sleep(2000);
				pThis->m_pdm->KeyPress(113);
			}
			//Sleep();
		}
		


		//计数
		pastBigShipNum = curBigShipNum;
		pastSmallShipNum = curSmallShipNum;
	}
	cout << "脚本3已退出" << endl;
	cout << endl;
	return 0;
}

void CDM_MFCDlg::SCRIPT3()
{
	if (m_pdm == NULL)
	{
		//m_lsb_msg.AddString("!!!DM对象未创建！");
		m_lsb_msg.AddString("初始化");
		//return;
		this->OnBnClickedButtonInit();
	}
	if(m_script3Enable == false)
	{
		this->OnBnClickeFindScanPoint();

		//开启 船数量检测线程
		//
		m_lsb_msg.AddString(">>>开启舰船数量检测线程");
		m_lsb_msg.AddString(">>>开启跃迁检测线程");
		m_lsb_msg.AddString(">>>开启脚本");
		if (m_ShipNumCountThreadEnable == false)
			this->StartShipNumDectThread();
		//if (m_WrapDetectThreadEnable == false)
			//this->StartWrapDtectThread();

		//Sleep(2000);
		m_script3Enable = true;
		AfxBeginThread(SCRIPT3THREAD, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
		
	}
	else 
	{
		m_script3Enable = false;
		m_WrapDetectThreadEnable = false;
		m_ShipNumCountThreadEnable = false;
		
		m_lsb_msg.AddString(">>>关闭舰船数量检测线程");
		m_lsb_msg.AddString(">>>关闭跃迁检测线程");
		m_lsb_msg.AddString(">>>关闭脚本");
	}
	CheckRun();

}


void CDM_MFCDlg::LockFirSShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		cout << "ERROR! dm未初始化 或者 搜寻点为0" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//锁定第一个小船
	DMFindListLockSingle(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波姆|科必伊|科帕提斯", 100,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16, 70, 0);
}



void CDM_MFCDlg::LockFirBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		cout << "ERROR! dm未初始化 或者 搜寻点为0" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dm未初始化");
		return;
	}
	//int ret = 0;

	//锁定第一个大船
	DMFindListLockSingle(*m_pdm, m_scanPoint_x, m_scanPoint_y, "科波斯|黑暗", 100,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16, 70, 0);
}


void CDM_MFCDlg::IFMissleEmpty()
{
	// TODO: 在此添加控件通知处理程序代码
	VARIANT x_pic, y_pic;
	if (m_pdm->FindPic(0, 0, 1920, 1080, "missleEmpty.bmp", "202020", 0.95, 0, &x_pic, &y_pic) != -1) //"F1_2.bmp"
	{
		m_lsb_msg.AddString("导弹为空");
		cout << "/---------MISSSLE EMPTY------------/" << endl;
		
	}
	else 
	{
		m_lsb_msg.AddString("导弹不为空");
	}
}



void CDM_MFCDlg::CALLBACKALLDRON()
{
	int delaytime = 200;
	cout << "召回所有舰载机" << endl;
	m_pdm->KeyPressChar("m");
	Sleep(delaytime);
	m_pdm->KeyPressChar("m");
	Sleep(delaytime);
	m_pdm->KeyPressChar("l");
	Sleep(delaytime);
	m_pdm->KeyPressChar("l");
}


void CDM_MFCDlg::RELEASEALLDRON()
{
	int delaytime = 200;
	cout << "召回所有舰载机" << endl;
	m_pdm->KeyPressChar("m");
	Sleep(delaytime);
	m_pdm->KeyPressChar("m");
	Sleep(delaytime);
	m_pdm->KeyPressChar("p");
	Sleep(delaytime);
	m_pdm->KeyPressChar("p");
}

UINT WrapDetectThread(LPVOID pParam)
{
	CDM_MFCDlg * pThis = (CDM_MFCDlg *)pParam;
	int wrapOnFlag = 0;
	int wrapOnFlagNum = 2;
	VARIANT x, y;
	while (pThis->m_WrapDetectThreadEnable)
	{
		if (pThis->m_pdm->FindStrFast(0, 0, 1920, 1080, "跃迁", "c3c3c3-606060", 0.75, &x, &y) != -1)
		{
			wrapOnFlag++;
			//pThis->m_IfWrapON = true;
		}
		else
		{
			pThis->m_IfWrapON = false;
			//cout << "-----------------WRAP OFF-----------------" << endl;
		}
		if (wrapOnFlag >= wrapOnFlagNum)
		{
			pThis->m_IfWrapON = true;
			//cout << "-----------------WRAP ON-----------------" << endl;
			wrapOnFlag = 0;
		}
	}
	return 0;
}

void CDM_MFCDlg::StartWrapDtectThread()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_WrapDetectThreadEnable == false)
	{
		cout << "跃迁检测线程开启" << endl;
		m_WrapDetectThreadEnable = true;
		AfxBeginThread(WrapDetectThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

	}
	else
	{
		m_WrapDetectThreadEnable = false;
		cout << "跃迁检测线程关闭" << endl;
	}
}
