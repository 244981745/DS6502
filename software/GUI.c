#include "GUI.h"


void GUI(HWND hwnd,LPARAM lParam)
{
	HANDLE	group[3],m_hBarWnd,hWndComboBox[5],hButton[10],hStatic[3];
	static HFONT hFont;  //�߼�����
	int 	i;
/******** 
*	�˵� 
*********/
	HMENU hMenubar;
    HMENU hMenu;
    HMENU hMenu0;

    hMenubar	=	CreateMenu();
    hMenu		=	CreateMenu();
    hMenu0		=	CreateMenu();

 
    AppendMenu(hMenu, MF_STRING, IDM_FILE_OPEN, TEXT("�򿪳���(&O)"));
    AppendMenu(hMenu, MF_STRING, IDM_FILE_SAVE, TEXT("�������(&S)"));
    AppendMenu(hMenu, MF_STRING, IDM_FILE_CLOSE, TEXT("�رճ���(&C)"));
    AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu, MF_STRING, IDM_FILE_QUIT, TEXT("�˳�(&Q)"));
    
    AppendMenu(hMenubar, MF_POPUP, (UINT_PTR) hMenu, TEXT("�ļ�(&F)"));
    

    AppendMenu(hMenu0, MF_STRING, IDM_EDIT_CLEAR_RECV, TEXT("��ս�����"));
    AppendMenu(hMenu0, MF_STRING, IDM_EDIT_CLEAR_HEX, TEXT("��ճ�����"));
    AppendMenu(hMenubar, MF_POPUP, (UINT_PTR) hMenu0, TEXT("�鿴(&V)"));
    
    SetMenu(hwnd, hMenubar);
    
	hFont = CreateFont(-13/*��*/, -7/*��*/, 0, 0, 400 /*һ�����ֵ��Ϊ400*/,
	            FALSE/*б��?*/, FALSE/*�»���?*/, FALSE/*ɾ����?*/,DEFAULT_CHARSET,
	            OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
	            FF_DONTCARE, TEXT("courier new "));//courier new 

/******** 
*	���� 
*********/
	group[0]	=	CreateWindow(TEXT("button"),\
				TEXT(""),\
				WS_CHILD|WS_VISIBLE|BS_GROUPBOX,\
				10,0,
				160,400,\
				hwnd,(HMENU)IDC_GROUP_LEFT,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	group[1]	=	CreateWindow(TEXT("button"),\
				TEXT(""),\
				WS_CHILD|WS_VISIBLE|BS_GROUPBOX,\
				10,260,
				160,140,\
				hwnd,(HMENU)IDC_GROUP_LEFT_1,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(group[1], WM_SETFONT, (WPARAM)hFont, NULL);
				
	group[2]	=	CreateWindow(TEXT("button"),\
				TEXT(""),\
				WS_CHILD|WS_VISIBLE|BS_GROUPBOX,\
				10,400,
				575,145,\
				hwnd,(HMENU)IDC_GROUP_BOTTON,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
/******** 
*	���ںͳ����� 
*********/
	hButton[0]	=	CreateWindow(TEXT("button"),		//�򿪳����ļ� 
				TEXT("�򿪳����ļ�"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,\
				20,20,
				140,30,\
				hwnd,(HMENU)IDC_BUTTON_OPENHEX,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[0], WM_SETFONT, (WPARAM)hFont, NULL);
	
	hWndComboBox[0]	=	CreateWindow(TEXT("combobox"),TEXT("�˿ں�"),	//ѡ��˿ں�
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,60,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_SERIAL,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[0], WM_SETFONT, (WPARAM)hFont, NULL);
	
	for(i = 0; i < 20; i++)//����б� 
	{
		SendMessage(hWndComboBox[0], CB_ADDSTRING, 0, (LPARAM)comName[i]);
	}
	SendMessage(hWndComboBox[0],CB_SETCURSEL, 1, 0);//����Ĭ��ֵ


				
	hWndComboBox[1]	=	CreateWindow(TEXT("combobox"),TEXT("����"),	//ѡ��EPROM���� 
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,90,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_EEPROM,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[1], WM_SETFONT, (WPARAM)hFont, NULL);
	SendMessage(hWndComboBox[1], CB_ADDSTRING, 0, (LPARAM)"AT28C256");
	SendMessage(hWndComboBox[1], CB_ADDSTRING, 0, (LPARAM)"AT28C64");
	SendMessage(hWndComboBox[1],CB_SETCURSEL, 0, 0);
	
	hWndComboBox[2]	=	CreateWindow(TEXT("combobox"),TEXT("������"),	//ѡ������ 
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,120,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_BAUD,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[2], WM_SETFONT, (WPARAM)hFont, NULL);
	SendMessage(hWndComboBox[2], CB_ADDSTRING, 0, (LPARAM)"115200");
	SendMessage(hWndComboBox[2], CB_ADDSTRING, 0, (LPARAM)"57600");
	SendMessage(hWndComboBox[2], CB_ADDSTRING, 0, (LPARAM)"38400");
	SendMessage(hWndComboBox[2], CB_ADDSTRING, 0, (LPARAM)"19200");
	SendMessage(hWndComboBox[2], CB_ADDSTRING, 0, (LPARAM)"14400");
	SendMessage(hWndComboBox[2], CB_ADDSTRING, 0, (LPARAM)"9600");
	SendMessage(hWndComboBox[2], CB_ADDSTRING, 0, (LPARAM)"7200");
	SendMessage(hWndComboBox[2], CB_SETCURSEL, 0, 0);
	
	hWndComboBox[3]	=	CreateWindow(TEXT("combobox"),TEXT("У��λ"),	//ѡ��У�� 
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,150,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_CHECK,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[3], WM_SETFONT, (WPARAM)hFont, NULL);
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"��У��");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"��У��");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"żУ��");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"1У��");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"0У��");
	SendMessage(hWndComboBox[3],CB_SETCURSEL, 0, 0);
	
	hWndComboBox[4]	=	CreateWindow(TEXT("combobox"),TEXT("ֹͣλ"),	//ѡ��ֹͣλ 
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,180,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_STOP,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[4], WM_SETFONT, (WPARAM)hFont, NULL);
	SendMessage(hWndComboBox[4], CB_ADDSTRING, 0, (LPARAM)"1λ");
	SendMessage(hWndComboBox[4], CB_ADDSTRING, 0, (LPARAM)"1.5λ");
	SendMessage(hWndComboBox[4], CB_ADDSTRING, 0, (LPARAM)"2λ");
	SendMessage(hWndComboBox[4],CB_SETCURSEL, 0, 0);
	
	hButton[1]	=	CreateWindow(TEXT("button"),	//�򿪶˿�
				TEXT("�򿪴���"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,\
				20,220,
				65,30,\
				hwnd,(HMENU)IDC_BUTTON_OPENCOM,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[1], WM_SETFONT, (WPARAM)hFont, NULL);
	
	hButton[2]	=	CreateWindow(TEXT("button"),	//�رն˿�
				TEXT("�رմ���"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED,\
				95,220,
				65,30,\
				hwnd,(HMENU)IDC_BUTTON_CLOSECOM,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[2], WM_SETFONT, (WPARAM)hFont, NULL);
	
	//NMI	�� 
	hStatic[0]	=	CreateWindow(
                TEXT("static"), //��̬�ı��������
                TEXT("NMI(0xFFFA)"),  //�ؼ����ı�
                WS_CHILD | WS_VISIBLE | WS_BORDER| SS_CENTER | SS_CENTERIMAGE ,
               	12,280,
               	95,20,
                hwnd,  //�����ھ��
                (HMENU)1,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
	SendMessage(hStatic[0], WM_SETFONT, (WPARAM)hFont, NULL);
	
	hVectorEdit	=	CreateWindow(TEXT("edit"),\
				TEXT("FFFA"),\
				WS_CHILD|WS_VISIBLE|WS_BORDER| BS_FLAT,\
				110,280,
				55,20,\
				hwnd,(HMENU)IDC_EDIT_VECTOR0,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hVectorEdit, WM_SETFONT, (WPARAM)hFont, NULL);

	//RESET	�� 
	hStatic[1]	=	CreateWindow(
                TEXT("static"), //��̬�ı��������
                TEXT("RESET(0xFFFC)"),  //�ؼ����ı�
                WS_CHILD | WS_VISIBLE | WS_BORDER| SS_CENTER | SS_CENTERIMAGE ,
               	12,305,
               	95,20,
                hwnd,  //�����ھ��
                (HMENU)1,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
	SendMessage(hStatic[1], WM_SETFONT, (WPARAM)hFont, NULL);

	hVectorEdit1	=	CreateWindow(TEXT("edit"),\
				TEXT("0000"),\
				WS_CHILD|WS_VISIBLE|WS_BORDER,\
				110,305,
				55,20,\
				hwnd,(HMENU)IDC_EDIT_VECTOR1,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);	
	SendMessage(hVectorEdit1, WM_SETFONT, (WPARAM)hFont, NULL);	
	
	//IRQ	�� 
	hStatic[2]	=	CreateWindow(
                TEXT("static"), //��̬�ı��������
                TEXT("RESET(0xFFFC)"),  //�ؼ����ı�
                WS_CHILD | WS_VISIBLE | WS_BORDER| SS_CENTER | SS_CENTERIMAGE ,
               	12,330,
               	95,20,
                hwnd,  //�����ھ��
                (HMENU)1,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��
                ((LPCREATESTRUCT)lParam)->hInstance,
                NULL);
	SendMessage(hStatic[2], WM_SETFONT, (WPARAM)hFont, NULL);
	
	hVectorEdit2	=	CreateWindow(TEXT("edit"),\
				TEXT("0000"),\
				WS_CHILD|WS_VISIBLE|WS_BORDER,\
				110,330,
				55,20,\
				hwnd,(HMENU)IDC_EDIT_VECTOR1,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hVectorEdit2, WM_SETFONT, (WPARAM)hFont, NULL);	
	
	hButton[6]	=	CreateWindow(TEXT("button"),\
				TEXT("ʹ���޸ĵ�ַ"),\
				WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX|WS_BORDER,\
				30,360,
				120,24,\
				hwnd,(HMENU)IDC_BUTTON_TEST,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[6], WM_SETFONT, (WPARAM)hFont, NULL);
/******** 
*	����鿴�� 
*********/ 
	hEdit	=	CreateWindow(TEXT("edit"),\
				TEXT(""),\
				WS_CHILD|WS_VISIBLE|WS_BORDER|WS_VSCROLL|ES_READONLY|ES_MULTILINE,\
				175,8,
				410,390,\
				hwnd,(HMENU)IDC_EDIT_VIEW,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, NULL);
/******** 
*	������ 
*********/			
	hButton[3]	=	CreateWindow(TEXT("button"),\
				TEXT("����"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED,\
				20,420,
				100,24,\
				hwnd,(HMENU)IDC_BUTTON_DOWNLOAD,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[3], WM_SETFONT, (WPARAM)hFont, NULL);

	hButton[4]	=	CreateWindow(TEXT("button"),\
				TEXT("�ش�"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED,\
				20,450,
				100,24,\
				hwnd,(HMENU)IDC_BUTTON_UPDATA,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[4], WM_SETFONT, (WPARAM)hFont, NULL);
	
	hButton[5]	=	CreateWindow(TEXT("button"),\
				TEXT(""),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED,\
				20,480,
				100,24,\
				hwnd,(HMENU)IDC_BUTTON_TEST,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[5], WM_SETFONT, (WPARAM)hFont, NULL);
	
	m_hBarWnd =	CreateWindowEx(0, PROGRESS_CLASS, (LPTSTR) NULL, 
                            WS_CHILD | WS_VISIBLE, 
							20, 520, 
                            555, 15, 
                            hwnd, (HMENU)IDC_SCROLL_RWT,
							 ((LPCREATESTRUCT)lParam)->hInstance, NULL);
 
	SendMessage(m_hBarWnd, PBM_SETRANGE, 0, MAKELPARAM(0, 1000)); //���ý������ķ�Χ
	//SendMessage(hwnd, PBS_MARQUEE, 1, 0); //����PBS_MARQUEE �ǹ���Ч��
	SendMessage(m_hBarWnd, PBM_SETPOS, 0, (LPARAM)0);   //���ý���
//	SendMessage(m_hBarWnd, PBM_GETRANGE, TRUE, (LPARAM)&range);  //��ȡ�������ķ�Χ

/******** 
*	������Ϣ�� 
*********/	
	hEdit0	=	CreateWindow(TEXT("edit"),\
				TEXT("����"),\
				WS_CHILD|WS_VISIBLE|WS_BORDER|WS_VSCROLL|ES_READONLY|ES_MULTILINE,\
				130,420,
				445,85,\
				hwnd,(HMENU)IDC_EDIT_RWV,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
    SendMessage(hEdit0, WM_SETFONT, (WPARAM)hFont, NULL);
}
