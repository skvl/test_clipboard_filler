#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include <Windows.h>


std::string GetRandomClipboardData()
{
    const size_t MIN_LENGTH = 10;
    const size_t MAX_LENGTH = 30;
    auto length = MIN_LENGTH + rand() % (MAX_LENGTH - MIN_LENGTH);
    char buffer[MAX_LENGTH] = {0};
    for (size_t i = 0; i < MAX_LENGTH; ++i)
        buffer[i] = 0x21 + rand() % (0x7e - 0x21 + 1);

    return std::string(buffer);
}

void FillClipboard()
{
    auto str = GetRandomClipboardData();
    std::cout << str << std::endl;
    int nMemSize = str.size() + 1;// need terminating zero
    HANDLE hData = GlobalAlloc(GHND,nMemSize);
    LPSTR lpData = (LPSTR)GlobalLock(hData);
    lstrcpyn(lpData, str.data(), nMemSize);
    GlobalUnlock(hData);
    if(OpenClipboard(NULL))
    {
        EmptyClipboard();
        SetClipboardData(CF_TEXT,hData);
        CloseClipboard();
    }
}

int main()
{
    std::srand(std::time(nullptr));
    FillClipboard();
    return 0;
}
