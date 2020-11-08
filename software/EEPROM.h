#ifndef	_EEPROM_H
#define	_EEPROM_H

LRESULT	CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);
void AddMenus(HWND hwnd) ;
void AddButton(HWND hwnd,LPARAM lParam);

char *comName[]	={	"COM 1","COM 2","COM 3","COM 4","COM 5","COM 6","COM 7",
					"COM 8","COM 9","COM 10","COM 11","COM 12","COM 13","COM 14",
					"COM 15","COM 16","COM 17","COM 18","COM 19","COM 20"};

#endif
