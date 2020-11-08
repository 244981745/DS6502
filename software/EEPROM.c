#include <windows.h>
#include <commctrl.h>
#include <Wchar.h> 
#include "Resource.h" 
#include "EEPROM.h"
#include "Common.c"
#include "GUI.c"


HANDLE	hEdit,hEdit0,hEdit1;
HANDLE	hVectorEdit,hVectorEdit1,hVectorEdit2;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	char	szClassName[]	=	"MainWClass";
	
	WNDCLASSEX	wndclass;
	wndclass.cbSize	=	sizeof(wndclass);	
	wndclass.style	=	CS_HREDRAW|CS_VREDRAW;
	wndclass.lpfnWndProc	=	WinProc;
	wndclass.cbClsExtra		=	NULL;
	wndclass.cbWndExtra		=	NULL;
	wndclass.hInstance		=	hInstance;
	wndclass.hIcon			=	LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor		=	LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground	=	(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName	=	NULL;
	wndclass.lpszClassName	=	szClassName;
	wndclass.hIconSm		=	NULL;
	
	RegisterClassEx(&wndclass);
	
	HWND	hwnd	=	CreateWindowEx(NULL,szClassName,TEXT("EEPROM ÉÕÂ¼Æ÷"),
						WS_BORDER|WS_CAPTION|WS_SYSMENU,	//´°¿Ú·ç¸ñ 
						CW_USEDEFAULT,CW_USEDEFAULT,600,600,	//x£¬y£¬w£¬h£¬ 
						NULL,NULL,hInstance,NULL);
	if(hwnd	==	NULL){
		MessageBox(NULL,L"Create Windows Faild ",L"ERROR",MB_OK);
		return -1;
	}
	
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	
	MSG msg;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	
	return msg.wParam;
}


LRESULT	CALLBACK WinProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	char szText[]="Main Windows Info"; 
	TCHAR	combo	=	0;

	OPENFILENAME ofn;
	static char szFile[256];
	static char szFileTitle[256];
	memset(&ofn,0,sizeof(ofn));
	ofn.lStructSize=sizeof(ofn);
	ofn.hwndOwner=hwnd;
	ofn.lpstrFilter="Picture File(*.txt,*.bin,*.txt)\0*.txt;*.bin;*.txt;\0\0";
	ofn.nFilterIndex=1;
	ofn.lpstrFile=szFile;
	ofn.nMaxFile=sizeof(szFile);
	ofn.lpstrFileTitle=szFileTitle;
	ofn.nMaxFileTitle=sizeof(szFileTitle);

	
	switch(message)
	{
		case WM_CREATE:
		{
			GUI(hwnd,lParam);
			return 0;
		}
		

		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case	IDM_FILE_QUIT:
					SendMessage(hwnd,WM_CLOSE,0,0);
					break;
					
				case	IDC_BUTTON_OPENHEX:
				case	IDM_FILE_OPEN:
					if(GetOpenFileName(&ofn))
					ShowHexText(hEdit,szFile);
					break;
					
				case	IDC_COMBOBOX_SERIAL:
					break;
					
				case	IDM_EDIT_CLEAR_RECV:
					SendMessage(hEdit0,WM_SETTEXT,0,(LPARAM)"");
					break;
					
				case	IDM_EDIT_CLEAR_HEX:
					SendMessage(hEdit,WM_SETTEXT,0,(LPARAM)"");
					break;
					
				case	IDC_BUTTON_OPENCOM:
					OpenCom(hwnd);
					break;
					
				default:
					DefWindowProc(hwnd,message,wParam,lParam);
					break;
			}
			return 0;
		}
		
		case WM_CLOSE:
		{
			DestroyWindow(hwnd);
			return 0;
		}
		
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}

