// win_console.cpp — Windows console font implementation
// windows.h is isolated here so it never pollutes other headers
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "win_console.h"

void setBengaliFont() {
    CONSOLE_FONT_INFOEX cfi = {};
    cfi.cbSize       = sizeof(cfi);
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily   = FF_DONTCARE;
    cfi.FontWeight   = FW_NORMAL;
    wcscpy_s(cfi.FaceName, LF_FACESIZE, L"SolaimanLipi");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    SetCurrentConsoleFontEx(GetStdHandle(STD_ERROR_HANDLE),  FALSE, &cfi);
}
