#include <snes.h>

extern char tilfont, palfont;

#define PLAYER_SYMBOL "@"

int main(void)
{
    u16 pad;
    u16 playerX = 15;
    u16 playerY = 13;
    u16 oldX;
    u16 oldY;
    u8 gameStarted = 0;

    consoleSetTextMapPtr(0x6800);
    consoleSetTextGfxPtr(0x3000);
    consoleSetTextOffset(0x0100);
    consoleInitText(0, 16 * 2, &tilfont, &palfont);

    bgSetGfxPtr(0, 0x2000);
    bgSetMapPtr(0, 0x6800, SC_32x32);

    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);

    consoleDrawText(8, 7, "THE LEGEND OF");
    consoleDrawText(10, 10, "ASTERION");
    consoleDrawText(9, 14, "VERSION 0.0.3");
    consoleDrawText(10, 18, "PRESS START");

    setScreenOn();

    while (1)
    {
        WaitForVBlank();

        if (!gameStarted)
        {
            if (padsDown(0) & KEY_START)
            {
                gameStarted = 1;

                consoleDrawText(8, 7, "             ");
                consoleDrawText(10, 10, "        ");
                consoleDrawText(9, 14, "             ");
                consoleDrawText(10, 18, "           ");

                consoleDrawText(5, 3, "CIDADE DA ESPERANCA");
                consoleDrawText(3, 5, "USE O DIRECIONAL PARA ANDAR");
                consoleDrawText(playerX, playerY, PLAYER_SYMBOL);
            }
        }
        else
        {
            pad = padsCurrent(0);

            oldX = playerX;
            oldY = playerY;

            if ((pad & KEY_LEFT) && playerX > 1)
            {
                playerX--;
            }
            else if ((pad & KEY_RIGHT) && playerX < 30)
            {
                playerX++;
            }

            if ((pad & KEY_UP) && playerY > 7)
            {
                playerY--;
            }
            else if ((pad & KEY_DOWN) && playerY < 26)
            {
                playerY++;
            }

            if (oldX != playerX || oldY != playerY)
            {
                consoleDrawText(oldX, oldY, " ");
                consoleDrawText(playerX, playerY, PLAYER_SYMBOL);
            }
        }
    }

    return 0;
}