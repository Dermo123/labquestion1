#include "mbed.h"
#include <cstdio>
/*
this program sets up an interrupt on a button connected to pin PC_13. When the button is pressed, the interrupt service routine btnFall sets a flag (int_trig). The main loop continuously checks this flag, and when it detects the button press (flag set to 1), it prints “btnFall \r\n” and resets the flag.


*/

InterruptIn bluebtn(PC_13);
volatile int int_trig = 0;


void bttnFall(){
    int_trig = 1;
}

// main() runs in its own thread in the OS
int main()
{
    bluebtn.fall(&bttnFall);

    // this is a program for lab 1 embedded systems module
    while (true) {
        if(int_trig == 1){
            int_trig = 0;
            printf("bttnFall \r\n");

        }
    }
}


