/****************************************************************/
/* A quick and dirty little program to close all active windows */
/* David J. Looney 27 May 1995                                  */
/* 75246.3364@compuserve.com   DJLOON@delphi.com                */
/* Use at your own risk.  The author assumes absolutely no      */
/* liability for suitability, performance, or security of your  */
/* data or system.  Public Domain.  Freeware.                   */
/****************************************************************/

#define INCL_WINWORKPLACE       /* Window Workplace Shell Functions */
#define INCL_WINWINDOWMGR       /* Window Manager Functions     */

#include <os2.h>
#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include <stdlib.h>

HWND   hwndNext;       /* current enumeration handle           */
HWND   hwndWPS;        /* WPS / Bottom Desktop Folder handle   */
HENUM  henum;          /* enumeration handle                   */
BOOL   fSuccess;       /* success indicator                    */
SHORT  sRetLen;        /* returned string length               */
LONG  lLength=1024L;   /* Length of pchBuffer */
PCH   pchBuffer;       /* Class name */
LONG  lRetLen;         /* Returned class name length */

main()
{
	pchBuffer=(PCH) malloc(lLength*sizeof(long));

	hwndWPS = WinQueryWindow(HWND_DESKTOP, QW_BOTTOM);
	henum = WinBeginEnumWindows(HWND_DESKTOP);
	while ((hwndNext = WinGetNextWindow(henum)) != NULLHANDLE) {
		lRetLen = WinQueryClassName(hwndNext, lLength, pchBuffer);
		if (hwndNext!=hwndWPS){
			if(strcmp((char*) pchBuffer, "wpFolder window")==0){
				WinSetFocus(HWND_DESKTOP,hwndNext);
				WinPostMsg(hwndNext,WM_CLOSE,NULL,NULL);
			}
		}
	}
	fSuccess = WinEndEnumWindows(henum);
	exit(fSuccess);
}




