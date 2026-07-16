#include <snes.h>

extern char tilfont, palfont;

int main(void)
{
    consoleSetTextMapPtr(0x6800);
    consoleSetTextGfxPtr(0x3000);
    consoleSetTextOffset(0x0100);
    consoleInitText(0, 16 * 2, &tilfont, &palfont);

    bgSetGfxPtr(0, 0x2000);
    bgSetMapPtr(0, 0x6800, SC_32x32);

    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);

    consoleDrawText(8, 7,  "THE LEGEND OF");
    consoleDrawText(10, 10, "ASTERION");
    consoleDrawText(9, 14, "VERSION 0.0.2");
    consoleDrawText(10, 18, "PRESS START");

    setScreenOn();

    while (1)
    {
        WaitForVBlank();

        if (padsDown(0) & KEY_START)
        {
            consoleDrawText(8, 7,  "             ");
            consoleDrawText(10, 10, "        ");
            consoleDrawText(9, 14, "             ");
            consoleDrawText(10, 18, "           ");

            consoleDrawText(11, 10, "LOADING...");
            consoleDrawText(5, 14, "CIDADE DA ESPERANCA");
        }
    }

    return 0;
}