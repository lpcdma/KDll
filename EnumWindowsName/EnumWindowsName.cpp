#include <windows.h>
#include <tchar.h>
#include <iostream>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    TCHAR className[256];
    DWORD processId;
    DWORD threadId;

    // 获取窗口类名
    if (GetClassName(hwnd, className, sizeof(className) / sizeof(TCHAR))) {
        // 获取窗口的进程 ID 和线程 ID
        threadId = GetWindowThreadProcessId(hwnd, &processId);

        // 打印窗口句柄、类名、进程 ID 和线程 ID
        std::wcout << L"HWND: " << hwnd
            << L", Class Name: " << className
            << L", Process ID: " << processId
            << L", Thread ID: " << threadId << std::endl;
    }
    return TRUE; // 继续枚举下一个窗口
}

DWORD target_process_id = 11912;
DWORD target_thread_id = 0;

BOOL CALLBACK EnumWindowsProc2(HWND hwnd, LPARAM lParam) {
    DWORD process_id;
    GetWindowThreadProcessId(hwnd, &process_id);
    if (process_id == target_process_id) {
        target_thread_id = GetWindowThreadProcessId(hwnd, NULL);
        return FALSE; // 找到目标进程，停止枚举
    }
    return TRUE; // 继续枚举
}

void GetThreadIdFromProcessId(DWORD process_id) {
    EnumWindows(EnumWindowsProc2, (LPARAM)&process_id);
    if (target_thread_id != 0) {
        printf("Found thread ID: %lu\n", target_thread_id);
    }
    else {
        printf("Thread ID not found.\n");
    }
}

int main() {
    // 枚举所有顶级窗口
    EnumWindows(EnumWindowsProc, 0);
    GetThreadIdFromProcessId(target_process_id);
    std::wcout << L"target_thread_id: " << target_thread_id << std::endl;
    return 0;
}