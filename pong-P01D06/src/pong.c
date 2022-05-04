#include <stdio.h>

int main() {
    int BX = 40, BY = 13, XST = 0, YST = 0, XSP = 3, YSP = -1;
    int M_XSP = 0, M_YSP = 0;
    int y1 = 15, y2 = 12;
    int SP_Y = 0, P1S = 0, P2S = 0;
    char key;
    char FIELD[25][80] = {
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       ",
"                                       *                                       "
    };
    while (1) {
        // --- Iteration control ---- //
        scanf("%c", &key);
        if (key == 'q')
            break;
        SP_Y = 0;
        if (key == 'a' && y1 <= 21) {
            y1++;
            SP_Y = 1;
        }
        if (key == 'z' && y1 >= 1) {
            y1--;
            SP_Y = -1;
        }
        if (key == 'k' && y2 <= 21) {
            y2++;
            SP_Y = 1;
        }
        if (key == 'm' && y2 >= 1) {
            y2--;
            SP_Y = -1;
        }
        if (P1S == 21) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCONGRATULATIONS PLAYER 1\n");
            break;
        }
        if (P2S == 21) {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCONGRATULATIONS PLAYER 2\n");
            break;
        }
        fflush(stdin);
        // ------------------------- //
        // ------ Racket draw ------ //
        for (int i = 0; i < 3; i++)
            FIELD[y1 + i][0] = '*';
        for (int i = 0; i < 3; i++)
            FIELD[y2 + i][78] = '*';
        // ------------------------- //
        // ------- Ball draw ------- // DO-NOT-TOUCH //
        if (XSP < 0)
            M_XSP = -XSP;
        else
            M_XSP = XSP;
        if (YSP < 0)
            M_YSP = -YSP;
        else
            M_YSP = YSP;
        if (M_XSP > M_YSP) {
            if (YSP > 0)
                YSP = 1;
            else if (YSP < 0)
                YSP = -1;
            else
                YSP = 0;
            if (XST != 0) {
                if (XSP > 0)
                    BX++;
                else
                    BX--;
                XST--;
            } else {
                BY+=YSP;
                if (XSP < 0)
                    XST += (0 - XSP);
                else
                    XST += XSP;
            }
        } else if (M_XSP < M_YSP) {
            if (XSP > 0)
                XSP = 1;
            else if (XSP < 0)
                XSP = -1;
            else
                XSP = 0;
            if (YST != 0) {
                if (YSP > 0)
                    BY++;
                else
                    BY--;
                YST--;
            } else {
                BX+=XSP;
                if (YSP < 0)
                    YST += (0 - YSP);
                else
                    YST += YSP;
            }
        } else if (M_YSP == M_XSP) {
            if (XST != 0) {
                if (XSP < 0)
                    BX--;
                else
                    BX++;
            } else {
                XST++;
            }
            if (YST != 0) {
                if (YSP < 0)
                    BY--;
                else
                    BY++;

            } else {
                YST++;
            }
        }
        FIELD[BY][BX] = '*';
        // ------------------------- //
        // -------- Hit reg -------- //
        if (BX == 77) {
            if (BY <= y2 + 3 && BY >= y2) {
                if (XSP - SP_Y != 0)
                    XSP = -(XSP - SP_Y);
                else
                    XSP = -SP_Y;
                if (SP_Y != 0)
                    YSP = SP_Y;
                XST = 0;
                BX--;
            } else {
                BY = 13; BX = 40;
                XSP = -XSP;
                P1S++;
            }
        }
        if (BX == 1) {
            if (BY <= y1 + 3 && BY >= y1) {
                if (XSP - SP_Y != 0)
                    XSP = -(XSP - SP_Y);
                else
                    XSP = -SP_Y;
                if (SP_Y != 0)
                    YSP = SP_Y;
                XST = 0;
                BX++;
            } else {
                BY = 13; BX = 40;
                XSP = -XSP;
                P2S++;
            }
        }
        if (BY == 24) {
            YSP = -YSP;
            YST = 0;
            BY--;
        }
        if (BY == 0) {
            YSP = -YSP;
            YST = 0;
            BY++;
        }
        // ------------------------- //
        // ------- Field draw ------ //
        printf("\nPLAYER 1:%d PLAYER 2:%d\n", P1S, P2S);
        for (int i = 24; i >= 0; i--)
            printf("%s\n", FIELD[i]);
        // ------------------------- //
        // ------ Field clear ------ //
        key = ' ';
        for (int i = 24; i >= 0; i--) {
            for (int j = 78; j >= 0; j--)
                if (j != 39)
                    FIELD[i][j] = ' ';
                else
                    FIELD[i][j] = '*';
        }
        // ------------------------- //
    }
    return 0;
}
