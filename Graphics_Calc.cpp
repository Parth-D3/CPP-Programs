#include <iostream>
#include <stdio.h>
#include <string.h>
#include <graphics.h>
using namespace std;

double num1 = 0, num2 = 0, result;
char op = 'n';
string dispNum;
char *cArray = new char[20];
int len;
POINT pos;

void displayScreen();
void drawCalc();
void keyboardInp();
void generateNum(int);
void exitScreen();
void getResult();
inline void setData();
void onHit(int, int);
void mouseInp();
void onClick(int, int, int, int, int);

int main()
{
    displayScreen();
    exitScreen();
    getch();
    closegraph();

    cout << "Num1 = " << num1 << endl;
    ;
    cout << "Num2 = " << num2 << endl;
    cout << "Result = " << result << endl;
    delete cArray;
    return 0;
}

void displayScreen()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    outtextxy(100, 100, (char *)"-----> WELCOME TO CALCULATOR <-----");
    line(100, 110, 135, 110);
    outtextxy(100, 150, (char *)"Press 'k' for keyboard input");
    outtextxy(100, 200, (char *)"Press 'm' for keyboard input");
    outtextxy(100, 250, (char *)"Press any other key to exit");

    char choice = getch();
    drawCalc();

    switch (choice)
    {
    case 'k':
        keyboardInp();
        break;
    case 'K':
        keyboardInp();
        break;
    case 'm':
        mouseInp();
        break;
    case 'M':
        mouseInp();
        break;
    default:
        return;
    }
}

void drawCalc()
{

    cleardevice();
    setcolor(YELLOW);
    rectangle(100, 100, 300, 350);
    line(100, 150, 300, 150);
    line(100, 200, 300, 200);
    line(100, 250, 300, 250);
    line(100, 300, 300, 300);

    line(150, 150, 150, 350);
    line(200, 150, 200, 350);
    line(250, 150, 250, 350);
    line(300, 150, 300, 350);

    outtextxy(125, 275, (char *)"1");
    outtextxy(175, 275, (char *)"2");
    outtextxy(225, 275, (char *)"3");
    outtextxy(125, 225, (char *)"4");
    outtextxy(175, 225, (char *)"5");
    outtextxy(225, 225, (char *)"6");
    outtextxy(125, 175, (char *)"7");
    outtextxy(175, 175, (char *)"8");
    outtextxy(225, 175, (char *)"9");
    outtextxy(175, 325, (char *)"0");
    outtextxy(275, 175, (char *)"+");
    outtextxy(275, 225, (char *)"-");
    outtextxy(275, 275, (char *)"*");
    outtextxy(275, 325, (char *)"/");
    outtextxy(125, 325, (char *)"X");
    outtextxy(225, 325, (char *)"=");

    outtextxy(350, 380, (char *)"Press 'E' to exit");
}

void generateNum(int x)
{
    if (op == 'n')
        num1 = num1 * 10 + x;
    else
        num2 = num2 * 10 + x;
}

void keyboardInp()
{

    while (!kbhit())
    {
        setcolor(LIGHTGREEN);
        switch (getch())
        {
        case '0':
            generateNum(0);
            onHit(155, 315);
            break;
        case '1':
            generateNum(1);
            onHit(115, 255);
            break;
        case '2':
            generateNum(2);
            onHit(155, 255);
            break;
        case '3':
            generateNum(3);
            onHit(215, 255);
            break;
        case '4':
            generateNum(4);
            onHit(115, 215);
            break;
        case '5':
            generateNum(5);
            onHit(155, 215);
            break;
        case '6':
            generateNum(6);
            onHit(215, 215);
            break;
        case '7':
            generateNum(7);
            onHit(115, 155);
            break;
        case '8':
            generateNum(8);
            onHit(155, 155);
            break;
        case '9':
            generateNum(9);
            onHit(215, 155);
            break;
        case '+':
            op = '+';
            drawCalc();
            outtextxy(280, 120, (char *)"+");
            onHit(255, 155);
            break;
        case '-':
            op = '-';
            drawCalc();
            outtextxy(280, 120, (char *)"-");
            onHit(255, 215);
            break;
        case '*':
            op = '*';
            drawCalc();
            outtextxy(280, 120, (char *)"*");
            onHit(255, 255);
            break;
        case '/':
            op = '/';
            drawCalc();
            outtextxy(280, 120, (char *)"/");
            onHit(255, 315);
            break;
        case '=':
            drawCalc();
            outtextxy(280, 120, (char *)"=");
            getResult();
            setData();
            onHit(215, 315);

            op = '=';
            break;
        case 'e':
            return;
        case 'E':
            return;
        default:
            outtextxy(50, 50, (char *)"INVALID INPUT !!!");
            Sleep(100);
            break;
        } // end of switch
        
        if (op == 'n')
            dispNum = to_string(num1);
        else if (op == '=')
        {
            op = 'n';
            dispNum = to_string(result);
        }
        else
            dispNum = to_string(num2);

        strcpy(cArray, dispNum.c_str());
        outtextxy(120, 120, (char *)cArray);
    }
}

void exitScreen()
{
    cleardevice();
    setcolor(BLUE);
    outtextxy(250, 250, (char *)"!!! EXITTING THE PROGRAM !!!");
    outtextxy(250, 280, (char *)"Press Any Key to Exit");
}

inline void setData()
{
    num1 = num2 = 0;
}

void getResult()
{
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        result = num1;
        break;
    }
}

void onHit(int in_x, int in_y)
{
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(in_x, in_y, YELLOW);
    delay(300);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(in_x, in_y, YELLOW);
}

void onClick(int x1, int y1, int x2, int y2, int data)
{
    if ((pos.x > x1 && pos.x < x2) && (pos.y > y1 && pos.y < y2))
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            generateNum(data);
            onHit(x1 + 5, y1 + 5);
        }
    }
}

void mouseInp()
{
    while (1)
    {
        GetCursorPos(&pos);
        onClick(100, 150, 150, 200, 7);
        onClick(100, 200, 150, 250, 4);
        onClick(100, 250, 150, 300, 1);

        onClick(150, 150, 200, 200, 8);
        onClick(150, 200, 200, 250, 5);
        onClick(150, 250, 200, 300, 2);
        onClick(150, 300, 200, 350, 0);

        onClick(200, 150, 250, 200, 9);
        onClick(200, 200, 250, 250, 6);
        onClick(200, 250, 250, 300, 3);

        if ((pos.x > 250 && pos.x < 300) && (pos.y > 150 && pos.y < 200))
        {
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                op = '+';
                drawCalc();
                outtextxy(280, 120, (char *)"+");
                onHit(255, 155);
            }
        }

        if ((pos.x > 250 && pos.x < 300) && (pos.y > 200 && pos.y < 250))
        {
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                op = '-';
                drawCalc();
                outtextxy(280, 120, (char *)"-");
                onHit(255, 215);
            }
        }

        if ((pos.x > 250 && pos.x < 300) && (pos.y > 250 && pos.y < 300))
        {
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                op = '*';
                drawCalc();
                outtextxy(280, 120, (char *)"*");
                onHit(255, 255);
            }
        }

        if ((pos.x > 250 && pos.x < 300) && (pos.y > 300 && pos.y < 350))
        {
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                op = '/';
                drawCalc();
                outtextxy(280, 120, (char *)"/");
                onHit(255, 315);
            }
        }

        if ((pos.x > 200 && pos.x < 250) && (pos.y > 300 && pos.y < 350))
        {
            if (GetAsyncKeyState(VK_LBUTTON))
            {
                drawCalc();
                outtextxy(280, 120, (char *)"=");
                getResult();
                setData();
                onHit(215, 315);

                op = '=';
            }
        }

        if (op == '=')
        {
            op = 'n';
            dispNum = to_string(result);
            strcpy(cArray, dispNum.c_str());
            outtextxy(120, 120, (char *)cArray);
            
            delay(1500);
        }
        else if (op == 'n')
            dispNum = to_string(num1);
        else
            dispNum = to_string(num2);

        strcpy(cArray, dispNum.c_str());
        outtextxy(120, 120, (char *)cArray);
    }
}
