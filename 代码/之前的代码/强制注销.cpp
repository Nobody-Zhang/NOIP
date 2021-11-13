#include<stdio.h>
#include<windows.h>
int main(void)
{
HANDLE hToken;
TOKEN_PRIVILEGES tkp;
OSVERSIONINFO osvi;
osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
if (GetVersionEx(&osvi) == 0)
return false;
if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT)
{
    if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
        return false;
        LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
        tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
}
ExitWindowsEx(EWX_FORCE, 0);
}
