// 3x3 grid
//  Two-player input (X and O)
//  Check for win/draw
//  Display board every turn
#include <iostream>
using namespace std;

class Chess
{
private:
    char board[3][3];
    char currentplayer = 'X';

public:
    void initializeboard()
    {
        int pos = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // board[i][j] = ++pos; //this is wrong cuz pos is int and board is char 
                board[i][j] = (char)('1' + pos++); //bracket agadiko char na lekhe pani hunxa

            }
        }
    }
    void displayboard()
    {
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j];
                if (j < 2)
                {
                    cout << " | ";
                }
            }
            if (i < 2)
            {
                cout << endl;
                cout << "-------------" << endl;
            }
        }
    }
    bool makemove(int pos)
    {
        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Girl, that cell's taken. Try again."<<endl;
            return false;
        }
        board[row][col] = currentplayer;
        return true;
    }
    bool checkwin()
    {
        // horizontal rw vertical check gareko
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == currentplayer && board[i][1] == currentplayer && board[i][2] == currentplayer)
                return true;
            if (board[0][i] == currentplayer && board[1][i] == currentplayer && board[2][i] == currentplayer)
                return true;
        }

        // diagonal check haneko
        if (board[0][0] == currentplayer && board[1][1] == currentplayer && board[2][2] == currentplayer)
            return true;
        if (board[0][2] == currentplayer && board[1][1] == currentplayer && board[2][0] == currentplayer)
            return true;

        return false;
    }
    bool isDraw()
    {
        // sab cells bhariyo bhane draw
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }
    void switchPlayer()
    {
        currentplayer = (currentplayer == 'X') ? 'O' : 'X';
    }
    char getcurrentplayer()
    {
        return currentplayer;
    }
};

int main()
{
    Chess c;
    int move;

    c.initializeboard();
    while(true)
    {
        c.displayboard();
        cout<<endl;
        cout<<"Player "<<c.getcurrentplayer()<<", enter position (1-9): ";
        cin>>move;

        if(move<1 or move>9)
        {
            cout<<"Please enter a valid move."<<endl;
            continue; //tala na gyi pheri mathi janxa player enter position ma
        }

        if(!c.makemove(move))
        {
            continue; //already khelisakeko position ma halyo bhane pheri play enter move bhanxa
        }
        
        if(c.checkwin())
        {
            c.displayboard();
            cout << "Player " << c.getcurrentplayer() << " CONGRATULATIONS "<<endl;
            break;
        }

        if(c.isDraw())
        {
            c.displayboard();
            cout<<"Oops, it's a draw"<<endl;
            break;
        }

        c.switchPlayer();
    }
    

    return 0;
}