#include "Macro.h"
#include <windows.h>

Macro::Macro(std::vector<CHAR> keys, std::vector<DWORD> pause, bool loop, UINT stopKey) {
    this->keys = keys;
    this->pause = pause;
    this->loop = loop;
    this->stopKey = stopKey;
}

void Macro::pressKey(CHAR keyParam) {
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan(keyParam);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF1()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x70), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF2()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x71), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF3()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x72), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF4()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x73), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF5()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x74), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF6()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x75), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF7()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x76), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF8()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x77), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::pressF9()
{
    UINT mappedkey;
    INPUT input = { 0 };
    mappedkey = MapVirtualKey(LOBYTE(0x78), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Macro::delay(int del)
{
    Sleep(del);
}

void Macro::run() 
{
    if (keys.size() != pause.size()) {      
        std::cout << "Amount of keys and breaks must be equal!" << std::endl;
        return;
    }
    for (int i = 0; i < keys.size(); ++i) {
        std::cout << " Ran " << " \n";
        pressKey(keys.at(i));
        Sleep(pause.at(i) * 1000 + 50); //always at least 50ms break time
    }
}

void Macro::leftClick()
{
    INPUT    Input = { 0 };
    // left down 
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));

    Sleep(300);

    // left up
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
}
