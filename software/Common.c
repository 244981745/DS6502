#include <windows.h>

#include "Common.h" 

void ShowHexText(HANDLE hEdit,LPWSTR sFilePath)
{
	const char hexMask[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',};

	char	buff[65536];
	char	HexBuff[24000]={0};
	char	szRead[20];
	DWORD	dwReadedSize;
	DWORD	dwFileSize	=	0;
	DWORD	dwFileSizeH	=	0;
	HANDLE	hFile;
	int		i,j=0;
	
	hFile	=	CreateFile(sFilePath,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,
							FILE_ATTRIBUTE_NORMAL,
							NULL);
	if(hFile	==	NULL)
	{
		MessageBox(hEdit,TEXT("打开文件失败"),TEXT("ERROR!"),MB_OK);
		return ;
	}

	dwFileSize	=	GetFileSize(hFile,&dwFileSizeH);
	
	
	if(dwFileSize > 65535| dwFileSizeH > 0)
	{
		MessageBox(hEdit,TEXT("程序文件超出CPU支持的最大地址，\r\n检查文件大小后再执行。"),TEXT("ERROR!"),MB_OK);
		return ;
	}
	ReadFile(hFile,buff,65535,&dwReadedSize,NULL);
	
	
	for(i = 0; i < dwReadedSize; i++)
	{
		HexBuff[j]		=	hexMask[	buff[i]>>4 &0xf	];
		HexBuff[j+1]	=	hexMask[	buff[i]>>0 &0xf	];
		HexBuff[j+2]	=	0x20;
		j	+= 3;
		if((i+1)%8 == 0)
		{
			if((i+1)%16 == 0)
			{
				HexBuff[j]		=	'\r';
				HexBuff[j+1]	=	'\n';
			}
			else
			{
				HexBuff[j]		=	0x20;
				HexBuff[j+1]	=	0x20;
			}
			j	+= 2;	
		}

	} 
	wsprintf(szRead,"读取文件大小%d",dwReadedSize);
	MessageBox(NULL,szRead,"tips",MB_OK);	
	SendMessage(hEdit,WM_SETTEXT,0,(LPARAM)HexBuff);
	
}

HANDLE	OpenCom(HANDLE fatherHandle)
{
	
	
} 
