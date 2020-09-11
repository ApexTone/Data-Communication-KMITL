#include <Windows.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>

HANDLE hComm;
char comPortName[] = "\\\\.\\COM11"; // change this accordingly
BOOL status;
DWORD dwEventMask;
DWORD noBytesRead;

char SerialBuffer[256];
int iSend = 0;
BOOL frameNumber = 0;

struct Frame //must edit to fit my frame implementation
{
    unsigned char isData : 1;
    unsigned char framNo : 1;
    unsigned char isAck : 1;
    unsigned char isEnd : 1;
    unsigned char size : 4;
    char data[15];
};

void setup_serial()
{
    hComm = CreateFile(comPortName,                  // Name of the Port to be Opened
                       GENERIC_READ | GENERIC_WRITE, // Read/Write Access
                       0,                            // No Sharing, ports cant be shared
                       NULL,                         // No Security
                       OPEN_EXISTING,                // Open existing port only
                       0,                            // Non Overlapped I/O
                       NULL);
    if (hComm == INVALID_HANDLE_VALUE)
    {
        printf("Can't open port");
    }
    else
    {
        printf("Open the port");
    }

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
}

int main()
{
    return 0;
}