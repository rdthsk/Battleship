#include <ctime>
#include <windows.h>
#include <iostream>

using namespace std;

const int rows = 10;
const int col = 10;

int maxShips = 10;

int board[rows][col];

void ClearBoard()
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = 0;
        }
    }
}

void ShowBoard()
{
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void SetShips()
{
    int shipsPlaced = 0;
    
    while(shipsPlaced < maxShips)
    {
        
        int x = rand() % rows;
        int y = rand() % col;
        
        if (board[x][y] != 1)
        {
            shipsPlaced++;
            board[x][y] = 1;
        }
    }
    
}

bool Attack (int x, int y)
{
    if (board[x][y] == 1)
    {
        board[x][y] = 2;
        return true;
    }
    return false;
}

int main()
{
    ClearBoard();
    ShowBoard();
    cout << "-------------------" << endl;
    SetShips();
    ShowBoard();
    
    system("pause");
    return 0;
}

