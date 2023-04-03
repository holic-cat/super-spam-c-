#include <iostream>
#include <Windows.h>
#include <vector>
#include "Macro.h"


int main() {
    
    std::cout << R"(

Holic
     
)" << '\n';

    std::cout << "Demo: HOLD F1 to automatically press F1 and left mouse click...";

    // If you press Numpad 0 it quits the program
    while (!GetKeyState(VK_NUMPAD0)) {

        Sleep(40);

        // We are getting the f1 key state
        SHORT f1ToggleState = GetKeyState(VK_F1);

        // Checking if f1 was pressed
        bool f1Pressed = (f1ToggleState & 0x0800) ? true : false;

        // Loop amount
        int loop = 1;
        
        if (f1Pressed) {


            for (int i = 0; i < loop; i++) {

                std::cout << "Pressing F1\n";

                Macro::pressF1();
                //Macro::pressF2();
                //Macro::pressKey('c');
                Macro::delay(100);
            }
            
            std::cout << "Mouse left click successfull\n";

            Macro::delay(100);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Macro::delay(100);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

            //Macro::leftClick();
        }
    }
    return 0;
    
}
