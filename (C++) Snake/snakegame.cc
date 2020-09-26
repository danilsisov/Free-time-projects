/******************************************************************************* 
 * 
 * 
DANIL SISOV
BANK RECORD
2K20
 * 
 *    
*******************************************************************************/

#include <cstdlib>
#include <ncurses.h>
using namespace std;


class game {
    public:
bool game_over;
const int width = 20;
const int height = 20;
int x, y, FruitX, FruitY, score;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

// can have up to 100 tail sections
int TailX[100], TailY[100];
int nTail = 0;

void Setup();
void Draw();
void Input();
void Logic();
void more();
void again();

};

void game::Setup(){
    curs_set(0);
    clear();
    initscr();
    noecho();
    cbreak();

    game_over = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    FruitX = (rand() % width) + 1;
    FruitY = (rand() % height) + 1;
    score = 0;
}

void game::Draw() {

    clear();

    for (int i = 0; i < width + 2; i++)
        mvprintw(0, i, "-");

    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 | i == 21)
                mvprintw(i, j, "-");
            else if (j == 0 | j == 21)
                mvprintw(i, j, "|");
            else if (i == y && j == x)
                mvprintw(i, j, "O");
            else if (i == FruitY && j == FruitX)
                mvprintw(i, j, "+");
            else
                for (int k = 0; k < nTail; k++)
                {
                    if (TailX[k] == j && TailY[k] == i)
                        mvprintw(i, j, "o");
                }
        }
    }

    mvprintw(23, 0, "Your score is: ---> %d", score);

    refresh();
}

void game::Input()
{

    // what key changes mean for snake head
    keypad(stdscr, TRUE);
    halfdelay(1);

    int c = getch();

    switch (c)
    {
    case KEY_LEFT:
        dir = LEFT;
        break;
    case KEY_RIGHT:
        dir = RIGHT;
        break;
    case KEY_UP:
        dir = UP;
        break;
    case KEY_DOWN:
        dir = DOWN;
        break;
    // q key for exit
    case 99:
        game_over = true;
        break;
    }
}

void game::Logic()
{

    // tail
    int prevX = TailX[0];
    int prevY = TailY[0];
    int prev2X, prev2Y;
    TailX[0] = x;
    TailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = TailX[i];
        prev2Y = TailY[i];
        TailX[i] = prevX;
        TailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // move snake head from key changes
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // gameover if you hit the game border
    if (x > width || x < 1 || y < 1 || y > height)
        game_over = true;

    // when snake eats fruit
    if (x == FruitX && y == FruitY)
    {
        score++;
        FruitX = (rand() % width) + 1;
        FruitY = (rand() % height) + 1;
        nTail++;
    }

    // end if head hits tail
    for (int i = 0; i < nTail; i++)
        if (TailX[i] == x && TailY[i] == y)
        {
            return again();
        }
}
void game::more(){
    mvprintw(25, 0, "Your score is: ---> %d", score);
}
void game::again(){
    printw("Press 1 for again, press 2 for exit....... "); 
    int choose = getch();
    switch (choose)
    {
    case 1:
        return Setup();
    case 2:
        game_over = true;
    default:
        break;
    }
}

int main()
{   
    game game;
    game.more();
    game.Setup();

    while (!game.game_over)
    {  
        game.Draw();
        game.Input();
        game.Logic();
        game.more();
    }   

    getch();
    endwin();

    return 0;
}



//g++ snakegame.cc -o game -lncurses./snakegame
//
