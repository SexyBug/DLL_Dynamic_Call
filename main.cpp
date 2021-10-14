#include <iostream>
#include <windows.h>
#include <tchar.h>

// 定义一种名为lpMyAdd的函数指针，此函数以两个int为参数，返回值为void
typedef void (*HELLO)();

int main() {
    // DLL句柄
    HINSTANCE hModule;
    // 函数指针
    HELLO hello;
    // 加载DLL,注意是以exe所在目录为当前目录，写dll的相对路径,也可写绝对路径,注意路径分隔符格式
    //hModule = LoadLibrary(_T("..\\lib\\libuntitled.dll"));
    hModule = LoadLibrary(_T("libuntitled.dll"));
    if (hModule != NULL) {
        // 传入DLL句柄，获得MyAdd函数的地址，然后强转为lpMyAdd类型
        hello = (HELLO) GetProcAddress(hModule, "hello");
        //或者使用如下写法
        //void (*hello)() = reinterpret_cast<void (*)()>(GetProcAddress(hModule, "hello"));
        if (hello != NULL) {
            hello();
        }
        else {
            std::cout << "cannot find func" << std::endl;
        }
        // 释放
        FreeLibrary(hModule);
    }
    else {
        std::cout << "cannot load dll" <<std::endl;
    }

    return 0;
}
