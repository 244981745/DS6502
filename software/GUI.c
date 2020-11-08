#include "GUI.h"


void GUI(HWND hwnd,LPARAM lParam)
{
	HANDLE	group[3],m_hBarWnd,hWndComboBox[5],hButton[10],hStatic[3];
	static HFONT hFont;  //逻辑字体
	int 	i;
/******** 
*	菜单 
*********/
	HMENU hMenubar;
    HMENU hMenu;
    HMENU hMenu0;

    hMenubar	=	CreateMenu();
    hMenu		=	CreateMenu();
    hMenu0		=	CreateMenu();

 
    AppendMenu(hMenu, MF_STRING, IDM_FILE_OPEN, TEXT("打开程序(&O)"));
    AppendMenu(hMenu, MF_STRING, IDM_FILE_SAVE, TEXT("保存程序(&S)"));
    AppendMenu(hMenu, MF_STRING, IDM_FILE_CLOSE, TEXT("关闭程序(&C)"));
    AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu, MF_STRING, IDM_FILE_QUIT, TEXT("退出(&Q)"));
    
    AppendMenu(hMenubar, MF_POPUP, (UINT_PTR) hMenu, TEXT("文件(&F)"));
    

    AppendMenu(hMenu0, MF_STRING, IDM_EDIT_CLEAR_RECV, TEXT("清空接收区"));
    AppendMenu(hMenu0, MF_STRING, IDM_EDIT_CLEAR_HEX, TEXT("清空程序区"));
    AppendMenu(hMenubar, MF_POPUP, (UINT_PTR) hMenu0, TEXT("查看(&V)"));
    
    SetMenu(hwnd, hMenubar);
    
	hFont = CreateFont(-13/*高*/, -7/*宽*/, 0, 0, 400 /*一般这个值设为400*/,
	            FALSE/*斜体?*/, FALSE/*下划线?*/, FALSE/*删除线?*/,DEFAULT_CHARSET,
	            OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
	            FF_DONTCARE, TEXT("courier new "));//courier new 

/******** 
*	分区 
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
*	串口和程序区 
*********/
	hButton[0]	=	CreateWindow(TEXT("button"),		//打开程序文件 
				TEXT("打开程序文件"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,\
				20,20,
				140,30,\
				hwnd,(HMENU)IDC_BUTTON_OPENHEX,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[0], WM_SETFONT, (WPARAM)hFont, NULL);
	
	hWndComboBox[0]	=	CreateWindow(TEXT("combobox"),TEXT("端口号"),	//选择端口号
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,60,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_SERIAL,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[0], WM_SETFONT, (WPARAM)hFont, NULL);
	
	for(i = 0; i < 20; i++)//添加列表 
	{
		SendMessage(hWndComboBox[0], CB_ADDSTRING, 0, (LPARAM)comName[i]);
	}
	SendMessage(hWndComboBox[0],CB_SETCURSEL, 1, 0);//设置默认值


				
	hWndComboBox[1]	=	CreateWindow(TEXT("combobox"),TEXT("类型"),	//选择EPROM类型 
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
	
	hWndComboBox[2]	=	CreateWindow(TEXT("combobox"),TEXT("波特率"),	//选择波特率 
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
	
	hWndComboBox[3]	=	CreateWindow(TEXT("combobox"),TEXT("校验位"),	//选择校验 
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,150,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_CHECK,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[3], WM_SETFONT, (WPARAM)hFont, NULL);
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"无校验");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"奇校验");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"偶校验");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"1校验");
	SendMessage(hWndComboBox[3], CB_ADDSTRING, 0, (LPARAM)"0校验");
	SendMessage(hWndComboBox[3],CB_SETCURSEL, 0, 0);
	
	hWndComboBox[4]	=	CreateWindow(TEXT("combobox"),TEXT("停止位"),	//选择停止位 
				CBS_DROPDOWN|CBS_HASSTRINGS|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,
				20,180,
				142,400,
				hwnd,(HMENU)IDC_COMBOBOX_STOP,
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hWndComboBox[4], WM_SETFONT, (WPARAM)hFont, NULL);
	SendMessage(hWndComboBox[4], CB_ADDSTRING, 0, (LPARAM)"1位");
	SendMessage(hWndComboBox[4], CB_ADDSTRING, 0, (LPARAM)"1.5位");
	SendMessage(hWndComboBox[4], CB_ADDSTRING, 0, (LPARAM)"2位");
	SendMessage(hWndComboBox[4],CB_SETCURSEL, 0, 0);
	
	hButton[1]	=	CreateWindow(TEXT("button"),	//打开端口
				TEXT("打开串口"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,\
				20,220,
				65,30,\
				hwnd,(HMENU)IDC_BUTTON_OPENCOM,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[1], WM_SETFONT, (WPARAM)hFont, NULL);
	
	hButton[2]	=	CreateWindow(TEXT("button"),	//关闭端口
				TEXT("关闭串口"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED,\
				95,220,
				65,30,\
				hwnd,(HMENU)IDC_BUTTON_CLOSECOM,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[2], WM_SETFONT, (WPARAM)hFont, NULL);
	
	//NMI	中 
	hStatic[0]	=	CreateWindow(
                TEXT("static"), //静态文本框的类名
                TEXT("NMI(0xFFFA)"),  //控件的文本
                WS_CHILD | WS_VISIBLE | WS_BORDER| SS_CENTER | SS_CENTERIMAGE ,
               	12,280,
               	95,20,
                hwnd,  //父窗口句柄
                (HMENU)1,  //为控件指定一个唯一标识符
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

	//RESET	高 
	hStatic[1]	=	CreateWindow(
                TEXT("static"), //静态文本框的类名
                TEXT("RESET(0xFFFC)"),  //控件的文本
                WS_CHILD | WS_VISIBLE | WS_BORDER| SS_CENTER | SS_CENTERIMAGE ,
               	12,305,
               	95,20,
                hwnd,  //父窗口句柄
                (HMENU)1,  //为控件指定一个唯一标识符
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
	
	//IRQ	低 
	hStatic[2]	=	CreateWindow(
                TEXT("static"), //静态文本框的类名
                TEXT("RESET(0xFFFC)"),  //控件的文本
                WS_CHILD | WS_VISIBLE | WS_BORDER| SS_CENTER | SS_CENTERIMAGE ,
               	12,330,
               	95,20,
                hwnd,  //父窗口句柄
                (HMENU)1,  //为控件指定一个唯一标识符
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
				TEXT("使用修改地址"),\
				WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX|WS_BORDER,\
				30,360,
				120,24,\
				hwnd,(HMENU)IDC_BUTTON_TEST,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[6], WM_SETFONT, (WPARAM)hFont, NULL);
/******** 
*	程序查看区 
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
*	交互区 
*********/			
	hButton[3]	=	CreateWindow(TEXT("button"),\
				TEXT("下载"),\
				WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|WS_DISABLED,\
				20,420,
				100,24,\
				hwnd,(HMENU)IDC_BUTTON_DOWNLOAD,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
	SendMessage(hButton[3], WM_SETFONT, (WPARAM)hFont, NULL);

	hButton[4]	=	CreateWindow(TEXT("button"),\
				TEXT("回传"),\
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
 
	SendMessage(m_hBarWnd, PBM_SETRANGE, 0, MAKELPARAM(0, 1000)); //设置进度条的范围
	//SendMessage(hwnd, PBS_MARQUEE, 1, 0); //设置PBS_MARQUEE 是滚动效果
	SendMessage(m_hBarWnd, PBM_SETPOS, 0, (LPARAM)0);   //设置进度
//	SendMessage(m_hBarWnd, PBM_GETRANGE, TRUE, (LPARAM)&range);  //获取进度条的范围

/******** 
*	交互信息区 
*********/	
	hEdit0	=	CreateWindow(TEXT("edit"),\
				TEXT("测试"),\
				WS_CHILD|WS_VISIBLE|WS_BORDER|WS_VSCROLL|ES_READONLY|ES_MULTILINE,\
				130,420,
				445,85,\
				hwnd,(HMENU)IDC_EDIT_RWV,\
				((LPCREATESTRUCT)lParam)->hInstance,\
				NULL);
    SendMessage(hEdit0, WM_SETFONT, (WPARAM)hFont, NULL);
}
