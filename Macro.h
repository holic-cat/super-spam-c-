#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>

class Macro
{
    std::vector<CHAR> keys;
    std::vector<DWORD> pause;
    bool loop = false;
    UINT stopKey = VK_NUMPAD5;

public:
    Macro(std::vector<CHAR> keys, std::vector<DWORD> pause, bool loop = false, UINT stopKey = VK_NUMPAD5);
    static void pressKey(CHAR keyParam);
    static void pressF1();
    static void pressF2();
    static void pressF3();
    static void pressF4();
    static void pressF5();
    static void pressF6();
    static void pressF7();
    static void pressF8();
    static void pressF9();
    static void delay(int del);
    static void leftClick();
    void run();
};