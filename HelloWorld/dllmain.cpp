// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <stdio.h>
#include <Windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //MessageBox(0, L"inject success", L"xue", MB_OK);
        OutputDebugStringW(L"DLL_PROCESS_ATTACH.\n");
        printf("DLL_PROCESS_ATTACH\n");
    case DLL_THREAD_ATTACH:
        OutputDebugStringW(L"DLL_THREAD_ATTACH.\n");
        printf("DLL_THREAD_ATTACH\n");
    case DLL_THREAD_DETACH:
        OutputDebugStringW(L"DLL_THREAD_DETACH.\n");
        printf("DLL_THREAD_DETACH\n");
    case DLL_PROCESS_DETACH:
        OutputDebugStringW(L"DLL_PROCESS_DETACH.\n");
        printf("DLL_PROCESS_DETACH\n");
        break;
    }
    return TRUE;
}

