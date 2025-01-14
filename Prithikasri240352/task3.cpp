//R.Prithikasri CODSOFT Task3:Tic-Tac-Toe game

#include<iostream>
using namespace std;
char board[3][3]={{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
char current_marker;
int current_player;
void drawBoard()
{
    cout<<" 0 1 2\n";
    for(int i=0;i<3;i++)
    {
        cout<<i<<" ";
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j];
            if(j<2)
            cout<<" |";
        }
        cout<<"\n";
    if(i<2)
    cout<<"--------\n";
    }

}
bool placeMarker(int row, int col)
{
    if(board[row][col] !=' ')
    {
        return false;
    }
    board[row][col]=current_marker;
    return true;
}
int checkWin()
{
for(int i=0;i<3;i++)
{
    if((board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] !=' ') || (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i] !=' ')){
        return current_player;
    }
}
 if((board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0] !=' ') || (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2] !=' ')){
        return current_player;
    }
    return 0;
}void swapPlayerAndMarker() {
    if(current_marker == 'x') current_marker = 'o';
    else current_marker = 'x';

    if(current_player == 1) current_player = 2;
    else current_player = 1;
}

void game() {
    cout << "Player 1, choose your marker (x/o): ";
    char marker_p1;
    cin >> marker_p1;
    current_player = 1;
    current_marker = marker_p1;

    drawBoard();
    int player_won = 0;

    for(int i = 0; i < 9; i++) {
        cout << "It's player " << current_player << "'s turn. Enter row and column: ";
        int row, col;
        cin >> row >> col;

        if(row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "That position is out of bounds! Try again.\n";
            i--;
            continue;
        }

        if(!placeMarker(row, col)) {
            cout << "That position is already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();
        player_won = checkWin();

        if(player_won == 1) {
            cout << "Player 1 wins! Congratulations!\n";
            break;
        } else if(player_won == 2) {
            cout << "Player 2 wins! Congratulations!\n";
            break;
        }
        swapPlayerAndMarker();
    }
    if(player_won==0)
    {
        cout<<"It's a tie!\n";
    }
}
int main()
{
    game();
    return 0;
}
