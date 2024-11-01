#include <iostream>
#include <string_view>
#include <Windows.h>
#include <TlHelp32.h>
#include <memory>
#include <cstdint>
#include <vector>
#include "injector.hpp"
#include "xor.h"
#include "skStr.h"

int main()
{
	std::cout << skCrypt("\n\nStart your game");
	Sleep(3000);

    //pysen("KDll",L"HelloWorld.dll");
	pysen_pid(2132, L"HelloWorld.dll");

    system("pause");
    return 0;
}

