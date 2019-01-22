
// DM_MFCDlg.cpp : ʵ���ļ�
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
	CString myDataPath, fdPath;   //����·������
	myDataPath = pathStr + "\\*.*"; //�ļ���·��
	CString strTmp;      //��׺������

	CFileFind find;		//����CFileFind
	BOOL bf = find.FindFile(myDataPath);	//
	while (bf)
	{
		bf = find.FindNextFile();
		if (!find.IsDots())
		{
			fdPath = find.GetFilePath();
			if (find.IsDirectory())
			{
				//������ļ��У��ݹ飬����������                        
				getFolderDayFile(fdPath, arrStrFile);
			}
			else
			{
				//������ļ�,�ж��Ƿ���*.txt
				strTmp = fdPath.Right(4);  //ȡ��׺��
				strTmp.MakeLower();		//�ַ���Сд��
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDM_MFCDlg �Ի���



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


// CDM_MFCDlg ��Ϣ�������

BOOL CDM_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);

	InitializeControls();




	STARTFLAG = false;





	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDM_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDM_MFCDlg::OnQueryDragIcon()
{

	return static_cast<HCURSOR>(m_hIcon);
}



void CDM_MFCDlg::OnBnClickedButtonTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//ʹ�ô�Į������ɹ����������������������(100,100)��
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
		m_btn_script3.SetWindowTextA("�رսű�3");
	}
	else 
	{
		m_btn_init.EnableWindow(true);
		m_btn_script3.SetWindowTextA("�����ű�3");
	}

}

void CDM_MFCDlg::OnBnClickedButtonFindpic()
{


	Cdmsoft * pdm = DMInit("��ͼ", "EVE2.txt","normal");


	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!Dm.GetInstance()->SetDict(0, "EVE.txt"))
		cout << "TEXT FAILED" << endl;
	string str = Dm.GetInstance()->Ocr(0, 0, 1920, 1080, "c3c3c3-606060", 0.85);

	cout << str << endl;
}


void CDM_MFCDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void CDM_MFCDlg::OnBnClickedButtonExec()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Cdmsoft *pDm =  DMInstan();

	//�Ҵ���
	long hwnd = pDm->FindWindow("","EVE");

	Sleep(200);
	cout << hwnd << endl; 
	//��
	pDm->BindWindow(hwnd, "dx2", "windows", "windows", 0); //windows
	Sleep(200);
	//����·��
	char path[] = "I:\\C_C++\\DM\\DM_MFC\\source";
	pDm->SetPath(path);
	if (!pDm->SetDict(0, "EVE.txt"))
		cout << "TEXT FAILED" << endl;
	else
		cout << "LOAD TXT OK" << endl;

	VARIANT x, y;
	int state = 0; //0 :δ֪ 1���ռ�վ�� 2���ռ�վ��

	///////////////////////
	//int y__ = 178;
	//while (pDm->FindStr(1489, y__, 1920, 1080, "����ʯ��־", "c3c3c3-606060", 0.85, &x, &y) != -1)
	//{
	//	pDm->CreateFoobarRect(hwnd, x.intVal, y.intVal, 200, 16);
	//	y__ = y.intVal + 16;
	//	cout << x.intVal << " " << y.intVal << " "  << endl;
	//}
	//cout << "�������" << endl;

	///////////////////////////////////////////TEST/////////////////////////
	while(1)
	{
		if (pDm->FindStr(1438, 136, 1897, 414, "����|����|����|����", "c3c3c3-606060", 0.85, &x, &y) != -1)
		{
			cout << "���ڿռ�վ��" << endl;
			GetDlgItem(IDC_STATIC)->SetWindowText("���ڿռ�վ��");
			state = 2;

			//�Ѿ����ٿռ�վ��
			//������
			int timeOut = 10;
			bool overViewFindFlag = false;
			while (timeOut-- > 0 && overViewFindFlag == false)
			{
				if (pDm->FindStr(0, 0, 1920, 1080, "����", "c3c3c3-606060", 0.85, &x, &y) != -1)
				{
					//�ҵ�������
					//
					overViewFindFlag = true;
				}
			}
			if (overViewFindFlag == false)
			{
				cout << " ERROR �Ҳ���������" << endl;
				return ;
			}
			else 
			{
				//�ҵ������� ����������
				cout << "�����ҵ���" <<x.intVal<<" "<<y.intVal<< endl;

				VARIANT x_overvirw = x;
				VARIANT y_overvirw = y;

				VARIANT x_tmp = x;
				VARIANT y_tmp = y;
				//�������ĵط���ʼ ��������С���Ǵ�
				int tmp_y = y_overvirw.intVal;
				//���п���С���Ǵ�
				vector<overViewElement> vecOverviewElement;
				int i = 0;
				while (pDm->FindStr(x_overvirw.intVal, tmp_y, 1920, 1080, "С���Ǵ�", "c3c3c3-606060", 0.85, &x, &y) != -1)
				{
					overViewElement element;
					element.x = x;
					element.y = y;
					char name[256];
					sprintf(name, "С���Ǵ�_%d", i++);
					element.name = name;
					vecOverviewElement.push_back(element);
					tmp_y = y.intVal + 16;
					cout << x.intVal << " " << y.intVal << " " << element.name << endl;
				}
				cout << "�������" << endl;
				//�������

				//��С���Ǵ� ԾǨ��
				int time = 1000;
				cout << "�ƶ���꣡" << endl;
				pDm->MoveTo(vecOverviewElement[0].x.intVal + 10, vecOverviewElement[0].y.intVal + 4);
				Sleep(time);
				cout << "�������£�" << endl;
				pDm->KeyDownChar("s");
				Sleep(time);
				cout << "�������" << endl;
				pDm->LeftClick();
				Sleep(1000);
				pDm->LeftClick();
				Sleep(time);
				cout << "�����ͷţ�" << endl;
				pDm->KeyUpChar("s");

				//�ȴ�ԾǨ���̽���
				while (pDm->FindStr(590, 601, 1312, 832, "Ŀ�ĵ�", "c3c3c3-606060", 0.85, &x, &y) == -1)
				{
					cout << "�ȴ�ԾǨ��������" << endl;
				}
				cout << "ԾǨ�����Ѿ�����" << endl;
				while (pDm->FindStr(590, 601, 1312, 832, "Ŀ�ĵ�", "c3c3c3-606060", 0.85, &x, &y) != -1)
				{
					cout << "�ȴ�ԾǨ����ر�" << endl;
				}

				cout << "ԾǨ�����Ѿ��ر�" << endl;

				//�Ѿ�����С���Ǵ�
				//���������ҷ���ʯ
				tmp_y = y_overvirw.intVal;
				//���п���С���Ǵ�
				//vector<overViewElement> vecOverviewElement;
				vecOverviewElement.clear();
				i = 0;
				tmp_y = 200;
				//x_overvirw.intVal
				while (pDm->FindStr(1400, tmp_y, 1920, 1080, "����ʯ|����ʯ��־", "c3c3c3-606060", 0.85, &x, &y) != -1)
				                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       {
					overViewElement element;
					element.x = x;
					element.y = y;
					char name[256];
					sprintf(name, "����ʯ��־_%d", i++);
					element.name = name;
					vecOverviewElement.push_back(element);
					tmp_y = y.intVal + 16;
					cout << x.intVal << " " << y.intVal << " " << element.name << endl;
				}
				cout << "�������" << endl;

				//����Ƿ��ҵ��˷���ʯ
				if (vecOverviewElement.size() == 0)
				{
					cout << "û���ҵ�����ʯ" << endl;
					return;
				}

				//�ӽ�����ʯ
				pDm->KeyDownChar("q");
				Sleep(200);
				pDm->MoveTo(vecOverviewElement[0].x.intVal + 20, vecOverviewElement[0].y.intVal + 3);
				Sleep(200);
				pDm->LeftClick();
				pDm->KeyUpChar("q");
				//�ж��Ƿ�ӽ��ɹ�
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


				//��������




				cout << "done" << endl;
				while (1);


			}


		}
		else if (pDm->FindStr(1438, 136, 1897, 414, "��վ|�ռ�վ����", "c3c3c3-606060", 0.85, &x, &y) != -1)
		{
			cout << "�ڿռ�վ��" << endl;
			GetDlgItem(IDC_STATIC)->SetWindowText("�ڿռ�վ��");
			state = 1;

			//��վ
			pDm->MoveTo(x.intVal, y.intVal-20);
			Sleep(200);
			pDm->LeftClick();
			Sleep(200);

			//�ȴ���վ
			while (pDm->FindStr(1438, 136, 1897, 414, "����|����|����|����", "c3c3c3-606060", 0.85, &x, &y) == -1)
			{
				Sleep(1000);
				cout << "�ȴ���վ" << endl;
			}

		}
		else 
		{
			cout << "״̬��ȷ��" <<pDm->Ocr(1438, 136, 1897, 414,"c3c3c3-606060",0.85) << endl;
		}
		Sleep(200);
	}



}


void CDM_MFCDlg::OnBnClickedButtonyichang()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	cout << "��ʼִ��" << endl;
	int times = 0;

	while (STARTFLAG)
	{
		//���
		system("cls");
		int i = DMFindList(*pdm, BigShip_x, BigShip_y, "�Ʋ�˹", BigShipVec);
		cout << i << endl;
		i = DMFindList(*pdm, SmallShip_x, SmallShip_y, "�Ʋ�ķ|�Ʊ���|������˹", SmallShipVec);
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

		//������
		//����С��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������


}


void CDM_MFCDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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

	int target = 0;		//0: ��Ŀ�� 1��С�� 2����


	VARIANT x, y, tmp_x, tmp_y;
	if (m_pdm->FindStrFast(0, 0, 1920, 1080, "����", "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "�����Ѿ���λ");
		tmp_x = x;
		tmp_y = y;
		m_scanPoint_x = x;
		m_scanPoint_y = y;
	}
	while (1)
	{
		cout << "----------------------------------------------------------------------" << endl;
		//int i = DMFindList(*pdm, tmp_x, tmp_y, "�Ʋ�ķ|�Ʊ���|������˹", SmallShipVec);

		//ɨ��С������
		curSmallShipNum = DMFindListRetRow(*m_pdm, tmp_x, tmp_y, "�Ʋ�ķ|�Ʊ���|������˹", SmallShipVec, \
			tmp_x.intVal - 10, tmp_y.intVal, tmp_x.intVal + 145, 1080, 16);
		
		cout << "С��������" << curSmallShipNum <<endl;

		curBigShipNum  = DMFindListRetRow(*m_pdm, tmp_x, tmp_y, "�Ʋ�˹", BigShipVec, \
			tmp_x.intVal - 10, tmp_y.intVal, tmp_x.intVal + 145, 1080, 16);

		cout << "��������" << curBigShipNum << endl;
		cout << "��VEC������" << BigShipVec.size() << endl;
		cout << "С��VEC������" << SmallShipVec.size() << endl;

		DMDrawText(m_CurHwnd, *m_pdm, 8, 12, SmallShipVec, SmallShipBarVec);
		DMDrawText(m_CurHwnd, *m_pdm, 20, 12, BigShipVec, BigShipBarVec);
		//����ոտ�ʼ curSmallShipNum ��= 0 �� pastSmallShipNum == 0
		//if (pastSmallShipNum == 0 && curSmallShipNum != 0)
		//{
		//	cout << "�������µ�С�� ���� �ոտ�ʼ ��������С����" << curSmallShipNum << endl;
		//	DMLockVec(*m_pdm, SmallShipVec,500);	//��������С��
		//	cout << "��ʱ2s" << endl;
		//	Sleep(2000);							//��ʱ2s��ʼ����
		//}

		if ( (ifAttack == true) && (curSmallShipNum == pastSmallShipNum) && (curBigShipNum == pastBigShipNum))
		{
			cout << ">>>���ڿ��� �ȴ���������С" << endl;
			SmallShipVec.clear();
			BigShipVec.clear();
			continue;
		}

		//--------С������----------
		if (pastSmallShipNum < curSmallShipNum)
		{
			cout << ">>>��ȥС������С������С������ �������µĴ�" << endl;
			cout << "��������С�� " << endl;
			DMLockVec(*m_pdm, SmallShipVec, 200);	//��������С��
			BigShipLocked = false;
		}
		//--------С������С��2----------
		if (curSmallShipNum <= 2 )//���С������С��2
		{
			cout << ">>>С������С�ڵ���2��"<< endl;
			if (curBigShipNum > 0 && BigShipLocked == false)
			{
				cout << "������Ҳ�� ����0 �� �������д�!!!w" << endl;
				DMLockVec(*m_pdm, BigShipVec, 200);//�������д�
				BigShipLocked = true;
				//cout << "��ʱ2s" << endl;
				//Sleep(2000);
			}
		}
		//--------С��������С----------
		if(curSmallShipNum < pastSmallShipNum && curSmallShipNum != 0)//С�������������ˣ� ���Ǳ������
		{
			cout << ">>>С�����������ˣ����Ҵ���С��" << endl;

			ifAttack = false;		//�򵥵� ��Ϊ��ʱ�� ������ȴ���

			cout << "���Ƶ�һ��С��" << endl;
			DMPressClk(*m_pdm, SmallShipVec[0].x, SmallShipVec[0].y, "w", 200);		//���Ƶ�һ��

			cout << "��ʱ2s �ȴ�������ȴ��" << endl;
			Sleep(2000);		//!!!��ʱ5�� �ȴ�������ȴ��

			cout << "����F1" << endl;
			m_pdm->KeyPress(112);	//����F1���н���		Ȼ�󹥻�

			target = 1;				//Ŀ��ΪС��

			ifAttack = true;		//�򵥵���Ϊ	���¾Ϳ��� ���������ͼ��ʶ����

			if (curSmallShipNum >= 2)
			{
				cout << "С�������㹻 ���Ƶڶ���" << endl;
				DMPressClk(*m_pdm, SmallShipVec[1].x, SmallShipVec[1].y, "w", 500);		//���Ƶڶ���
			}
			else
			{
				//���С��ֻ��һ�� �Ǿͻ��ƴ󴬵�һ��
				if (curBigShipNum > 0)
				{
					cout << "С���������� �Ҵ󴬴��� ���Ƶ�һ����" << endl;
					DMPressClk(*m_pdm, BigShipVec[0].x, BigShipVec[0].y, "w", 200);		//���Ƶڶ���
				}
			}
		}
		//--------С������ ����û�й���----------
		if ((ifAttack == false) && (curSmallShipNum != 0))		//������ڿ��� ��С������
		{
			cout << ">>>������ڿ�����С������ ���Ƶ�һ��С��" << endl;
			DMPressClk(*m_pdm,SmallShipVec[0].x, SmallShipVec[0].y, "w", 200);		//����
			//Sleep(500);
			//DMPressClk(*m_pdm, SmallShipVec[0].x, SmallShipVec[0].y, "w", 500);

			cout << "����F1" << endl;
			//if(ifAttack == false)
				m_pdm->KeyPress(112);	//����F1���н���
			Sleep(200);
			ifAttack = true;		//�򵥵���Ϊ	���¾Ϳ��� ���������ͼ��ʶ����

			if (curSmallShipNum >= 2)		//���С�� ���������� ��ô�û�����һ��
			{
				cout << "С�������㹻 ���Ƶڶ���" << endl;
				DMPressClk(*m_pdm, SmallShipVec[1].x, SmallShipVec[1].y, "w", 200);		//���Ƶڶ���
			}
			else
			{	
				//���С��ֻ��һ�� �Ǿͻ��ƴ󴬵�һ��
				if (curBigShipNum > 0)
				{
					cout << "С���������� �Ҵ󴬴��� ���Ƶ�һ����" << endl;
					DMPressClk(*m_pdm, BigShipVec[0].x, BigShipVec[0].y, "w", 200);		//���Ƶڶ���
				}
			}
		}
		//--------С������Ϊ0 ���ߴ�����������----------
		if ( (curBigShipNum != 0)&&(curBigShipNum < pastBigShipNum) || ( (curSmallShipNum == 0)&&(curSmallShipNum < pastSmallShipNum)))//�󴬵����������ˣ� ���Ǳ������
		{
			cout << ">>>���������� ����С�������ڵĵ�һ�� ��ʼת��" << endl;
			Sleep(2000);		//!!!��ʱ5�� �ȴ�������ȴ��

			cout << "���Ƶ�һ����" << endl;
			DMPressClk(*m_pdm, BigShipVec[0].x, BigShipVec[0].y, "w", 500);		//���Ƶ�һ��

			Sleep(500);
			cout << "����" << endl;
			m_pdm->KeyPress(112);	//����F1���н���		Ȼ�󹥻�

			Sleep(500);

			m_pdm->KeyPress(114);	//��������

			target = 2;				//Ŀ��Ϊ��

			ifAttack = true;		//�򵥵���Ϊ	���¾Ϳ��� ���������ͼ��ʶ����

			if (BigShipVec.size() >= 2)
			{
				cout << "��ʱ����" << endl;
				Sleep(5000);		//��ʱ5���������һ����
				cout << "�������㹻 ���Ƶڶ���" << endl;
				DMPressClk(*m_pdm, BigShipVec[1].x, BigShipVec[1].y, "w", 500);		//���Ƶڶ���
			}
			//��������

		}

		if (curBigShipNum == 0 && curSmallShipNum == 0)
		{
			cout << "��ǰ��Ŀ��" << endl;
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
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
//		//int i = DMFindList(*pdm, tmp_x, tmp_y, "�Ʋ�ķ|�Ʊ���|������˹", SmallShipVec);
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
}


void CDM_MFCDlg::OnBnClickedButtonInit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm == NULL)
	{
		//Cdmsoft *pDm = ;
		m_pdm = DMInstan();
		m_pdmCounter = DMInstan();
		if (m_pdm == NULL || m_pdmCounter == NULL)
		{
			m_lsb_msg.AddString("NEW ��Į����ʧ��");
			return;
		}
	}
		
	//
	long hwnd = m_pdm->FindWindow("", handleName3.GetBuffer(0)); //
	long hwnd2 = m_pdmCounter->FindWindow("", handleName3.GetBuffer(0));
	if (hwnd == 0 || hwnd2 == 0)
	{
		m_lsb_msg.AddString("û���ҵ���Ӧ���ڣ�");
		return;
	}
	else
	{
		CString cstr;
		cstr.Format("��Ӧ�������ҵ�: %d", hwnd);
		m_CurHwnd = hwnd;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), cstr);
	}
		
	Sleep(200);
	//��
	char *mode = "windows";
	//if (0 == (m_pdm->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0))
	//		|| 0 == (m_pdmCounter->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0)))
	if (0 == (m_pdm->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0))
		|| 0 == (m_pdmCounter->BindWindow(hwnd, m_mode.GetBuffer(0), m_mode2_cstr.GetBuffer(0), m_mode2_cstr.GetBuffer(0), 0)))
	{
		m_lsb_msg.AddString("�󶨴���ʧ�ܣ�");
		return;
	}
	Sleep(200);

	char path[] = "..\\source";
	if (m_pdm->SetPath(path) == 0 || m_pdmCounter->SetPath(path) == 0)
	{
		m_lsb_msg.AddString("·������ʧ�ܣ�");
		return;
	}

	if (!m_pdm->SetDict(0, m_dictNmae) || !m_pdmCounter->SetDict(0, m_dictNmae))
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "�����ֿ�ʧ��");
		return ;
	}
	else
	{ 
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "�����ֿ�ɹ�");
	}
		



	CheckRun();
}





void CDM_MFCDlg::OnBnClickedButtoncapture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm->Capture(0, 0, 1920, 1080, "capture.bmp") == 0)
		m_lsb_msg.AddString("��ͼʧ��");
	else
		m_lsb_msg.AddString("��ͼ�ɹ�");
}


void CDM_MFCDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_lsb_msg.ResetContent();
}


void CDM_MFCDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm->Capture(0, 0, 1920, 1080, "capture.bmp") == 0)
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(),"��ͼʧ��");
	else
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "��ͼ�ɹ�");
}


void CDM_MFCDlg::OnCbnSelchangeComboDict()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CString cstr;
	m_cbb_dict.GetWindowTextA(m_dictNmae);
	m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "ѡ���ֵ䣺" + m_dictNmae);
}


void CDM_MFCDlg::OnBnClickeLockSmallShip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//��������С��
	DMFindListLock(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�ķ|�Ʊ���|������˹", 100, 
					m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);

}


void CDM_MFCDlg::OnBnClickeFindScanPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm == NULL )
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "DMû�г�ʼ��");
		return;
	}
	VARIANT x, y, tmp_x, tmp_y;
	if (m_pdm->FindStrFast(0, 0, 1920, 1080, "����", "c3c3c3-606060", 0.85, &x, &y) != -1)
	{
		cout << ">>>������ʼ�� �Ѿ��ض�λ" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "�����Ѿ���λ ɨ����ʼ���Ѷ�λ");
		tmp_x = x;
		tmp_y = y;
		m_scanPoint_x = x;
		m_scanPoint_y = y;
		
	}

}


void CDM_MFCDlg::OnBnClickedUnLock()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm == NULL)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//��������С��
	DMFindListUnLock(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�ķ|�Ʊ���|������˹", 200,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);	// TODO: �ڴ���ӿؼ�֪ͨ����������

}


void CDM_MFCDlg::OnBnClickeLockBigShip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//��������С��
	DMFindListLock(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�˹|�ڰ�", 120,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeAttFirSShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//������һ��С��
	DMFindListAttack(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�ķ|�Ʊ���|������˹", 80,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeRoundSecShip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//���Ƶڶ���С��
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�ķ|�Ʊ���|������˹", 80, 
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeAttFirBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//������һ����
	DMFindListAttackBig(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�˹|�ڰ�", 80,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeRoundSecBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//���Ƶڶ�����
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�˹|�ڰ�", 80,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16);
}


void CDM_MFCDlg::OnBnClickeRoundFirBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//���Ƶ�һ����
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�˹|�ڰ�", 100,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16,70,0);
}


void CDM_MFCDlg::OnBnClickedButtoScript2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int curBigShipNum = 0;
	int pastBigShipNum = 0;
	int curSmallShipNum = 0;
	int pastSmallShipNum = 0;

	bool ifAttack = false;
	bool BigShipLocked = false;
	bool SmallShipLocked = false;
	int target = 0;		//0: ��Ŀ�� 1��С�� 2����

	//��ʼ�� ����ɨ�����
	//
	this->OnBnClickeFindScanPoint();

	//���� ����������߳�
	//
	if(m_ShipNumCountThreadEnable == false)
		this->StartShipNumDectThread();

	Sleep(5000);
	while (1)
	{
		//��ȡ��ǰ��ֻ����
		//
		curBigShipNum = m_curBShipNum;
		curSmallShipNum = m_curSShipNum;


		if ((ifAttack == true) && (curSmallShipNum == pastSmallShipNum) && (curBigShipNum == pastBigShipNum))
		{
			//cout << "w" << endl;
			//system("clr");
			continue;
		}

		//--------С������----------
		if (pastSmallShipNum < curSmallShipNum)
		{
			cout << ">>>��ȥС������С������С������ �������µĴ�" << endl;
			cout << "���Ƶ�һ��С��" << endl;
			this->OnBnClickeRoundFirShip();
			cout << "��ʱ 3��" << endl;
			Sleep(3000);
			cout << "��������С�� " << endl;
			this->OnBnClickeLockSmallShip();	//��������С��

			cout << "��ʱ 7 s�ȴ�����С�� ������ " << endl;
			Sleep(7000);

			SmallShipLocked = true;
			BigShipLocked = false;
		}

		//--------С��������С----------
		if (curSmallShipNum < pastSmallShipNum && curSmallShipNum != 0)//С�������������ˣ� ���Ǳ������
		{
			cout << ">>>С��������С��" << endl;
			cout << "���Ƶ�һ��С��" << endl;

			this->OnBnClickeRoundFirShip();
			BigShipLocked = false;
			ifAttack = false;		//�򵥵� ��Ϊ��ʱ�� ������ȴ���

			cout << ">>>��ʱ 7s �ȴ�������ȴ" << endl;
			Sleep(7000);
			cout << "������һ��С��" << endl;
			this->OnBnClickeAttFirSShip();

			this->OnBnClickeRoundFirShip();

			target = 1;				//Ŀ��ΪС��

			ifAttack = true;		//�򵥵���Ϊ	���¾Ϳ��� ���������ͼ��ʶ����

			//if (curSmallShipNum >= 2)
			//{
			//	cout << "С�������㹻 ���Ƶڶ���" << endl;
			//	this->OnBnClickeRoundSecShip();	//���Ƶڶ���С��
			//}
			//else
			//{
			//	//���С��ֻ��һ�� �Ǿͻ��ƴ󴬵�һ��
			//	if (curBigShipNum > 0)
			//	{
			//		cout << "С���������� �Ҵ󴬴��� ���Ƶ�һ����" << endl;
			//		this->OnBnClickeRoundFirBShip();	//���Ƶ�һ�Ҵ�
			//	}
			//}
		}

		//--------С������С��2----------
		if (curSmallShipNum <= 2)//���С������С��2
		{
			
			if ((curBigShipNum > 0) && (BigShipLocked == false))
			{
				cout << ">>>С������С�ڵ���2��" << endl;
				cout << "������Ҳ�� ����0 �� �������д�!!!w" << endl;

				this->OnBnClickeLockBigShip();
				BigShipLocked = true;
				//cout << "��ʱ2s" << endl;
				//Sleep(2000);
			}
		}

		//--------С������ ����û�й���----------
		//if ((ifAttack == false) && (curSmallShipNum != 0))		//������ڿ��� ��С������
		if ((curSmallShipNum != 0))
		{
			cout << ">>>������ڿ�����С������ ���Ƶ�һ��С��" << endl;
			cout << "���Ƶ�һ��С��" << endl;

			this->OnBnClickeRoundFirShip();
			this->OnBnClickeAttFirSShip();
			ifAttack = true;		//�򵥵���Ϊ	���¾Ϳ��� ���������ͼ��ʶ����

			//if (curSmallShipNum >= 2)
			//{
			//	cout << "С�������㹻 ���Ƶڶ���" << endl;
			//	this->OnBnClickeRoundSecShip();	//���Ƶڶ���С��
			//}
			//else
			//{
			//	//���С��ֻ��һ�� �Ǿͻ��ƴ󴬵�һ��
			//	if (curBigShipNum > 0)
			//	{
			//		cout << "С���������� �Ҵ󴬴��� ���Ƶ�һ����" << endl;
			//		this->OnBnClickeRoundFirBShip();	//���Ƶ�һ�Ҵ�
			//	}
			//}
		}

		//--------С������Ϊ0 ���ߴ�����������----------
		if ((curBigShipNum != 0) && (curBigShipNum < pastBigShipNum) || ((curSmallShipNum == 0) && (curSmallShipNum < pastSmallShipNum)) ||(curBigShipNum != 0 && ifAttack == false ) )//�󴬵����������ˣ� ���Ǳ������
		{
			cout << ">>>���������� ����С�������ڵĵ�һ�� ��ʼת����ʱ5�� �ȴ�������ȴ��" << endl;

			ifAttack = false;
			cout << "���Ƶ�һ�Ҵ�" << endl;
			this->OnBnClickeRoundFirBShip();
			cout << "��ʱ 7s" << endl;
			Sleep(7000);		//!!!��ʱ5�� �ȴ�������ȴ��

			//������һ�Ҵ�
			this->OnBnClickeAttFirBShip();

			ifAttack = true;		//�򵥵���Ϊ	���¾Ϳ��� ���������ͼ��ʶ����

			//if (curBigShipNum >= 2)
			//{
			//	this->OnBnClickeRoundSecBShip();
			//}
			////��������

		}

		if (curBigShipNum == 0 && curSmallShipNum == 0)
		{
			cout << ">>>��ǰ��Ŀ��" << endl;
			ifAttack = false;
			target = 0;
		}
		//m_pdm->MoveTo(200 + curSmallShipNum, 300 + curBigShipNum);




		pastBigShipNum = curBigShipNum;
		pastSmallShipNum = curSmallShipNum;
		//cout << "----------------------------------------------------------------------" << endl;
	}
}


//��ǰ�����������߳�
//
UINT ShipCoutThread(LPVOID pParam)
{
	CDM_MFCDlg * pThis = (CDM_MFCDlg *)pParam;
	int pastSmallShipNum = 0;
	int pastBigShipNum = 0;
	int curSmallShipNum = 0;
	int curBigShipNum = 0;
	int changeFlag = 0;
	int changNum = 2;		//�ı��������� �͸���ֵ
	while (pThis->m_ShipNumCountThreadEnable)
	{
		curSmallShipNum = DMFindListCount(*pThis->m_pdmCounter, pThis->m_scanPoint_x, pThis->m_scanPoint_y,"�Ʋ�ķ|�Ʊ���|����",
			pThis->m_scanPoint_x.intVal - 10, pThis->m_scanPoint_y.intVal, pThis->m_scanPoint_x.intVal + 145, 1080, 16);

		curBigShipNum = DMFindListCount(*pThis->m_pdmCounter, pThis->m_scanPoint_x, pThis->m_scanPoint_y, "�Ʋ�˹|�ڰ�",
			pThis->m_scanPoint_x.intVal - 10, pThis->m_scanPoint_y.intVal, pThis->m_scanPoint_x.intVal + 145, 1080, 16);

		if (pastSmallShipNum != curSmallShipNum)
		{
			changeFlag++;
			if (changeFlag >= changNum)
			{
				pastSmallShipNum = curSmallShipNum;
				pThis->m_curSShipNum = curSmallShipNum;
				changeFlag = 0;
				cout << "//---------------С�������ı� ����Ϊ :" << pThis->m_curSShipNum << endl;
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
				cout << "//---------------�������ı� ����Ϊ:" << pThis->m_curBShipNum << endl;
			}
		}
		//Sleep(50);
	}
	cout << "�����������߳����˳�" << endl;
	return 0;
}

void CDM_MFCDlg::StartShipNumDectThread()
{
	if (m_ShipNumCountThreadEnable == false)
	{
		cout << "��ʼ�����������߳�" << endl;
		m_ShipNumCountThreadEnable = true;
		AfxBeginThread(ShipCoutThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

	}
	else
	{
		m_ShipNumCountThreadEnable = false;
		cout << "�����������߳��ѿ��� �ر���" << endl;
	}
}


void CDM_MFCDlg::OnBnClickeRoundFirShip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		cout << "ERROR! dmδ��ʼ�� ���� ��Ѱ��Ϊ0" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//���Ƶڶ���С��
	DMFindListRound(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�ķ|�Ʊ���|������˹", 150,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16,70,0);
}


UINT SCRIPT3THREAD(LPVOID pParam)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int curBigShipNum = 0;
	int pastBigShipNum = 0;
	int curSmallShipNum = 0;
	int pastSmallShipNum = 0;
	int LockDelayTime = 7000;

	bool ifAttack = false;
	bool BigShipLocked = false;
	bool SmallShipLocked = false;
	int target = 0;		//0: ��Ŀ�� 1��С�� 2����
	bool ifMissleEmpty = false;
	bool onFire = false;
	int reLoadFlag = 0;

	long BShipAttOutTime = 8;
	long SShipAttOutTime = 8;
	CTime BShipStartAttackTimer;
	long BShipAttackTime;
	//��ʼ�� ʱ�� ��ֹ�����쳣
	BShipStartAttackTimer = CTime::GetCurrentTime();
	BShipAttackTime = BShipStartAttackTimer.GetTime();
	CTime SShipStartAttackTimer;
	long SShipAttackTime;
	//��ʼ�� ʱ�� ��ֹ�����쳣
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
	//BShipStartAttackTime = CTime::GetCurrentTime();             //��ȡ��ǰʱ������
	//BShipTimer
	//long nTSeconds = m_time.GetTime();
	


	//��ʼ�� ����ɨ�����
	//
	CDM_MFCDlg * pThis = (CDM_MFCDlg *)pParam;
	cout << "�ű�3�Ѿ�����" << endl;
	Sleep(2000);
	while (pThis->m_script3Enable)
	{
		//��ȡ��ǰ��ֻ����
		//
		curBigShipNum = pThis->m_curBShipNum;
		curSmallShipNum = pThis->m_curSShipNum;
		
		//----------------�����ж�----------------
		//
		//if ((curBigShipNum != 0) || (0 != curSmallShipNum))
		//{
		//	if (onFire == false)
		//	{
		//		cout << ">>> <�����ж�> NOT ON FIRE!" << endl;
		//		if (0 != curSmallShipNum)
		//		{
		//			cout << "<����> ��1 <С��>" << endl;
		//			pThis->OnBnClickeRoundFirShip();
		//		}
		//		else if (0 != curBigShipNum)
		//		{
		//			cout << "<����> ��1 <����>" << endl;
		//			pThis->OnBnClickeRoundFirBShip();
		//		}
		//	}
		//}

		//-----------------------��Ŀ���ж�-----------------
		if (0 != curSmallShipNum || 0 != curBigShipNum)
		{
			noTargetTimerEnable = false;
		}
		if (0 == curSmallShipNum && 0 == curBigShipNum && false == noTargetTimerEnable)
		{
			//cout << ">>>��ǰ��Ŀ��" << endl;
			//cout << "�ٻ����н��ػ�" << endl;
			//pThis->CALLBACKALLDRON();
			//Sleep(800);
			//pThis->m_pdm->KeyPress(113);
			//Sleep(10 * 1000);
			noTargetTimer = CTime::GetCurrentTime();
			noTargetTime = noTargetTimer.GetTime();
			noTargetTimerEnable = true;
			cout << "��ǰ��Ŀ�� ������Ŀ���ʱ" << endl;
			cout << endl;
		}
		if (true == noTargetTimerEnable)
		{
			Curtimer = CTime::GetCurrentTime();
			curTime = Curtimer.GetTime();
			cout << "��Ŀ����ʱ�䣺 " << curTime - noTargetTime <<endl;
			cout << endl;
			if (curTime - noTargetTime >= noTargetOutTime)
			{
				cout << "��ǰ��Ŀ�꣡" << endl;
				cout << "�ջ��������˻���" << endl;
				pThis->CALLBACKALLDRON();
				Sleep(800);
				pThis->m_pdm->KeyPress(113);
				Sleep(3000);
				cout << "�˳��̣߳�" << endl;
				
				pThis->m_script3Enable = false;
				pThis->m_WrapDetectThreadEnable = false;
				pThis->m_ShipNumCountThreadEnable = false;

				pThis->m_lsb_msg.AddString(">>>�رս�����������߳�");
				pThis->m_lsb_msg.AddString(">>>�ر�ԾǨ����߳�");
				pThis->m_lsb_msg.AddString(">>>�رսű�");
				cout << endl;
				pThis->CheckRun();
				return 0;
			}
			Sleep(1000);
		}

		//-------------------------���ػ� ���� �ж�------------------
		//����Ŀ���ʱ��Ż��ж�
		if ((onFire == false) && (0 != curSmallShipNum || 0 != curBigShipNum))
		{
			if (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "DroneReady.bmp", "202020", 0.8, 0, &attack_x, &attack_y) != -1)
			{
				cout << "��⵽���˻����� �Ҵ��ڵ���" << endl;
				cout << "�ͷ�������JJ" << endl;
				cout << endl;
				pThis->RELEASEALLDRON();
				Sleep(1500);
				pThis->m_pdm->KeyPress(113);
			}
		}


		//---------------------ԾǨ���---------------------------
		if (pThis->m_IfWrapON == true)
		{
			cout << "-------------------ON WRAP��--------------" << endl;
			while (pThis->m_IfWrapON == true)
			{
				cout << "-------------------ON WRAP��--------------" << endl;
				Sleep(4000);
			}
			cout << "����F4 ������Ӧ��ǿ�ű�" << endl;
			pThis->m_pdm->KeyPress(115);
		}


		//�������������ı�ʱ ������ɨ�����д�����2�� ��ֹ��©С��
		//�����ֻ���� 
		//
		if(curSmallShipNum > pastSmallShipNum)
		{
			SmallShipLocked = false;
			//������������ �Ȼ������� ��ˢ�� ���� �Է� ���������ж�
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
			//������������ �Ȼ������� ��ˢ�� ���� �Է� ���������ж�
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
			cout << "<��>���� ��ʱ0��" << endl;
			cout << endl;
			pThis->OnBnClickeRoundFirBShip();
			ifAttack = false;
			//reLoadFlag = 0;
			//Sleep(2000);
		}

		

		//----------�����ж�-----------------
		//
		if ((curSmallShipNum != 0) && (onFire == false))
		{
			cout << "<�����ж�>" << endl;
			cout << ">>>С����Ϊ0 ���Ҳ��� ����" << endl;
			cout << "���Ƶ�һ��С��" << endl;
			cout << endl;
			pThis->OnBnClickeRoundFirShip();
			ifAttack = true;

			/*
			Sleep(200);
			cout << "������һ��С��" << endl;
			pThis->LockFirSShip();
			*/
			/*
			Sleep(200);
			cout << "������һ��С��" << endl;
			pThis->OnBnClickeAttFirSShip();
			//��ʱ������
			Sleep(100);
			pThis->OnBnClickeAttFirSShip();
			cout << "��ʱ1��" << endl;
			Sleep(1000);*/  //������Ϊ������ ͼ����ϵͳ���
		}
		if ((curSmallShipNum == 0) && (curBigShipNum != 0) &&(ifAttack == false) && (onFire == false))
		{
			cout << "<�����ж�>" << endl;
			cout << ">>>С��Ϊ0,�󴬲�Ϊ0�����Ҳ��ڿ���" << endl;
			cout << "���Ƶ�һ�Ҵ�" << endl;
			cout << endl;
			pThis->OnBnClickeRoundFirBShip();
			ifAttack = true;

			/*			Sleep(200);
			cout << "������һ�Ҵ�" << endl;
			pThis->LockFirBShip();
			*/
			/*			
			Sleep(200);
			cout << "������һ�Ҵ�" << endl;
			pThis->OnBnClickeAttFirBShip();
			ifAttack = true;
			*/
			//������Ϊ������ ͼ����ϵͳ���


			//Sleep(200);
			//pThis->OnBnClickeAttFirBShip();
			//cout << "��ʱ2��" << endl;
			//Sleep(2000);
		}

		//---------------------ͼ���⹥���ж�----------------------
		if ((0 != curBigShipNum) || (0 != curSmallShipNum) && (ifAttack == true))
		{
			if ( (pThis->m_pdm->FindPic(0, 0, 1920, 1080, "F1_3.bmp", "202020", 0.95, 0, &attack_x, &attack_y) == -1) ) //"F1_2.bmp"
			{
				cout << "<ͼ���⹥���ж�>" << endl;
				cout << "/---------NOT ON FIRE!------------/" << endl;
				onFire = false;
				if (curSmallShipNum != 0)
				{
					//��������ڴ����һ�Ҵ����µĹ���ʧЧ�� 
					//if (pThis->m_curSShipNum < curSmallShipNum)
					//{
					//	cout << "//----------С�� ���� �������� ���Ƶ�һ��С��" << endl;
					//	pThis->OnBnClickeRoundFirShip();
					//	continue;
					//}
					cout << ">>>С����Ϊ0" << endl;
					cout << "���Ƶ�һ��С��" << endl;
					pThis->OnBnClickeRoundFirShip();
					Sleep(100);
					cout << "������һ��С��" << endl;
					pThis->LockFirSShip();
					Sleep(100);
					cout << "������һ��С��" << endl;
					cout << endl;
					pThis->OnBnClickeAttFirSShip();
					//����С��������ʱ
					SShipStartAttackTimer = CTime::GetCurrentTime();
					SShipAttackTime = SShipStartAttackTimer.GetTime();
					Sleep(800);
				}
				else if (curBigShipNum != 0)
				{
					//��������ڴ����һ�Ҵ����µĹ���ʧЧ�� 
					//if (pThis->m_curBShipNum < curBigShipNum)
					//{
					//	cout << "//----------�� ���� �������� ���Ƶ�һ�Ҵ�" << endl;
					//	pThis->OnBnClickeRoundFirBShip();
					//	continue;
					//}
					cout << "���Ƶ�һ�Ҵ�" << endl;
					pThis->OnBnClickeRoundFirBShip();
					Sleep(100);
					if (pThis->m_curSShipNum != 0)
					{
						cout << "��ǰС����Ϊ0 �ع���" << endl;
						continue;
					}
					cout << "������һ�Ҵ�" << endl;
					pThis->LockFirBShip();
					Sleep(100);
					cout << "������һ�Ҵ�" << endl;
					cout << endl;
					pThis->OnBnClickeAttFirBShip();
					Sleep(600);
					//�����󴬹�����ʱ
					BShipStartAttackTimer = CTime::GetCurrentTime();
					BShipAttackTime = BShipStartAttackTimer.GetTime();
				}
			}
			else
			{
				onFire = true;
			}
		}

		//----------�����ж�-----------------
		//
		if ((curSmallShipNum != 0) && (SmallShipLocked == false))
		{
			cout << "<�����ж�>" << endl;
			//cout << ">>>��������С��" << endl;
			cout << "���Ƶ�һ��С��" << endl;
			pThis->OnBnClickeRoundFirShip();
			Sleep(200);
			cout << ">>>��������С��" << endl;
			pThis->OnBnClickeLockSmallShip();
			cout << "��ʱ2��" << endl;
			cout << endl;
			Sleep(2000);
			SmallShipLocked = true;
			cout << endl;
		}

		if ((curSmallShipNum <= 3) && (BigShipLocked == false) && (curBigShipNum != 0))
		{
			cout << "<�����ж�>" << endl;
			cout << ">>>�������д�" << endl;
			cout << endl;
			pThis->OnBnClickeLockBigShip();
			BigShipLocked = true;
			cout << endl;
		}

		//------------�󴬹�����ʱ�ж�--------------
		if ((curSmallShipNum == 0) && (ifAttack == true) && (curBigShipNum != 0))
		{
			Curtimer = CTime::GetCurrentTime();
			long ctime = Curtimer.GetTime();
			long passtime;
			passtime = (ctime - BShipAttackTime);
			//��ȡʱ��
			//�ȴ������
			cout << "pass time: " << passtime << endl;;
			Sleep(500);
			//system("cls");
#ifdef ROUND_TEST
			if ((passtime == BShipRoundSecTime))
			{
				cout << "//================�����������ж�������" << endl;
				cout << "���Ƶڶ��Ҵ󴬣�" << endl;

				pThis->OnBnClickeRoundSecBShip();
			}
#endif
			if ((passtime >= BShipAttOutTime) )
			{
				
				cout << "�󴬹�����ʱ ��������" << endl;
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
		//------------С��������ʱ�ж�--------------
		if ((curSmallShipNum != 0) && (ifAttack == true) )
		{
			Curtimer = CTime::GetCurrentTime();
			long ctime = Curtimer.GetTime();
			long passtime;
			passtime = (ctime - SShipAttackTime);
			//��ȡʱ��
			//�ȴ������
			cout << "Small pass time: " << passtime << endl;;
			Sleep(400);
			//system("cls");
#ifdef ROUND_TEST
			if ((passtime == SShipRoundSecTime))
			{
				cout << "//================�����������ж�������" << endl;
				if (curSmallShipNum >= 2)
				{
					cout << "���Ƶڶ���С����" << endl;
					pThis->OnBnClickeRoundSecShip();
				}
				else
				{
					cout << "���Ƶ�1�Ҵ󴬣�" << endl;
					pThis->OnBnClickeRoundFirBShip();
				}
			}
#endif
			if ((passtime >= SShipAttOutTime))
			{
				cout << "С��������ʱ " << endl;
				Sleep(100);
				cout << "������һ��С��" << endl;
				pThis->LockFirSShip();
				Sleep(100);
				cout << "������һ��С��" << endl;
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
		//----------------�����������-----------------------
		//
		if (DMFindPicRow(*pThis->m_pdm, attack_x, attack_y, "missleEmpty.bmp", 20, 0, 0, 1920, 1080) >= 2)
		{
			cout << "------------------MISSLE EMPTY-----------------" << endl;
			if ((0 == curSmallShipNum))
			{
				cout << "û��С����" << endl;
				cout << "�ٻ��������" << endl;
				pThis->CALLBACKALLDRON();
				Sleep(800);
				pThis->m_pdm->KeyPress(113);

				//��ʱ�����ж�
				cout << "��ʱ��" << endl;
				int time;
				for (time = 0; time < ReLoadTime; time++)
				{
					Sleep(1000);
					cout << "Waiting: " <<time<<endl;
				}
				//Sleep(100*1000);
				cout << "�ͷ��������" << endl;
				cout << endl;
				pThis->RELEASEALLDRON();
				Sleep(2000);
				pThis->m_pdm->KeyPress(113);
			}
			//Sleep();
		}
		


		//����
		pastBigShipNum = curBigShipNum;
		pastSmallShipNum = curSmallShipNum;
	}
	cout << "�ű�3���˳�" << endl;
	cout << endl;
	return 0;
}

void CDM_MFCDlg::SCRIPT3()
{
	if (m_pdm == NULL)
	{
		//m_lsb_msg.AddString("!!!DM����δ������");
		m_lsb_msg.AddString("��ʼ��");
		//return;
		this->OnBnClickedButtonInit();
	}
	if(m_script3Enable == false)
	{
		this->OnBnClickeFindScanPoint();

		//���� ����������߳�
		//
		m_lsb_msg.AddString(">>>����������������߳�");
		m_lsb_msg.AddString(">>>����ԾǨ����߳�");
		m_lsb_msg.AddString(">>>�����ű�");
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
		
		m_lsb_msg.AddString(">>>�رս�����������߳�");
		m_lsb_msg.AddString(">>>�ر�ԾǨ����߳�");
		m_lsb_msg.AddString(">>>�رսű�");
	}
	CheckRun();

}


void CDM_MFCDlg::LockFirSShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		cout << "ERROR! dmδ��ʼ�� ���� ��Ѱ��Ϊ0" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//������һ��С��
	DMFindListLockSingle(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�ķ|�Ʊ���|������˹", 100,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16, 70, 0);
}



void CDM_MFCDlg::LockFirBShip()
{
	if (m_pdm == NULL || m_scanPoint_x.vt == VT_EMPTY || m_scanPoint_y.vt == VT_EMPTY)
	{
		cout << "ERROR! dmδ��ʼ�� ���� ��Ѱ��Ϊ0" << endl;
		m_lsb_msg.InsertString(m_lsb_msg.GetCount(), "dmδ��ʼ��");
		return;
	}
	//int ret = 0;

	//������һ����
	DMFindListLockSingle(*m_pdm, m_scanPoint_x, m_scanPoint_y, "�Ʋ�˹|�ڰ�", 100,
		m_scanPoint_x.intVal - 10, m_scanPoint_y.intVal, m_scanPoint_x.intVal + 145, 1080, 16, 70, 0);
}


void CDM_MFCDlg::IFMissleEmpty()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	VARIANT x_pic, y_pic;
	if (m_pdm->FindPic(0, 0, 1920, 1080, "missleEmpty.bmp", "202020", 0.95, 0, &x_pic, &y_pic) != -1) //"F1_2.bmp"
	{
		m_lsb_msg.AddString("����Ϊ��");
		cout << "/---------MISSSLE EMPTY------------/" << endl;
		
	}
	else 
	{
		m_lsb_msg.AddString("������Ϊ��");
	}
}



void CDM_MFCDlg::CALLBACKALLDRON()
{
	int delaytime = 200;
	cout << "�ٻ����н��ػ�" << endl;
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
	cout << "�ٻ����н��ػ�" << endl;
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
		if (pThis->m_pdm->FindStrFast(0, 0, 1920, 1080, "ԾǨ", "c3c3c3-606060", 0.75, &x, &y) != -1)
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_WrapDetectThreadEnable == false)
	{
		cout << "ԾǨ����߳̿���" << endl;
		m_WrapDetectThreadEnable = true;
		AfxBeginThread(WrapDetectThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

	}
	else
	{
		m_WrapDetectThreadEnable = false;
		cout << "ԾǨ����̹߳ر�" << endl;
	}
}
