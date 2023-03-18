
//Importing the inbuild libraries in CPP
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;;
string player1="";
string player2="";
int player1Score = 0;
int player2Score = 0;

HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

//Function to show the current status of the gaming board
void display_board() {
    cout << " \n";
    cout << "    ----------------\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "   " << " | ";
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); // Set color to red
                cout << board[i][j];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Set color back to default
            }
            else if (board[i][j] == 'O')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); // Set color to blue
                cout << board[i][j];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Set color back to default
            }
            else
            {
                cout << board[i][j];
            }
            cout << "  | ";
        }
        cout << "\n    ----------------\n";
    }
}

//Function to get the player input and update the board
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        bool rowWin = true;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'O') {
                rowWin = false;
                break;
            }
        }
        if (rowWin) {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        bool colWin = true;
        for (int i = 0; i < 3; i++) {
            if (board[i][j] != 'O') {
                colWin = false;
                break;
            }
        }
        if (colWin) {
            return true;
        }
    }
    // Check diagonal 1
    bool diag1Win = true;
    for (int i = 0; i < 3; i++) {
        if (board[i][i] != 'X') {
            diag1Win = false;
            break;
        }
    }
    if (diag1Win) {
        return true;
    }

    // Check diagonal 2
    bool diag2Win = true;
    for (int i = 0; i < 3; i++) {
        if (board[i][3 - 1 - i] != 'O') {
            diag2Win = false;
            break;
        }
    }
    if (diag2Win) {
        return true;
    }

    return false;

}
// Function to check if the AI can win
/*
bool checkAndMove(char board[][3], char symbol) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] != 'X' && board[i][2] != 'O') ||
            (board[i][0] == symbol && board[i][2] == symbol && board[i][1] != 'X' && board[i][1] != 'O') ||
            (board[i][1] == symbol && board[i][2] == symbol && board[i][0] != 'X' && board[i][0] != 'O')) {
            board[i][board[i][0] == symbol ? 2 : (board[i][1] == symbol ? 0 : 1)] = symbol;
            return true;
        }
        if ((board[0][i] == symbol && board[1][i] == symbol && board[2][i] != 'X' && board[2][i] != 'O') ||
            (board[0][i] == symbol && board[2][i] == symbol && board[1][i] != 'X' && board[1][i] != 'O') ||
            (board[1][i] == symbol && board[2][i] == symbol && board[0][i] != 'X' && board[0][i] != 'O')) {
            board[board[0][i] == symbol ? 2 : (board[1][i] == symbol ? 0 : 1)][i] = symbol;
            return true;
        }
    }
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] != 'X' && board[2][2] != 'O') ||
        (board[0][0] == symbol && board[2][2] == symbol && board[1][1] != 'X' && board[1][1] != 'O') ||
        (board[1][1] == symbol && board[2][2] == symbol && board[0][0] != 'X' && board[0][0] != 'O')) {
        board[board[0][0] == symbol ? 2 : (board[1][1] == symbol ? 0 : 1)][board[0][0] == symbol ? 2 : (board[1][1] == symbol ? 0 : 1)] = symbol;
        return true;
    }
    if ((board[0][2] == symbol && board[1][1] == symbol && board[2][0] != 'X' && board[2][0] != 'O') ||
        (board[0][2] == symbol && board[2][0] == symbol && board[1][1] != 'X' && board[1][1] != 'O') ||
        (board[1][1] == symbol && board[2][0] == symbol && board[0][2] != 'X' && board[0][2] != 'O')) {
        board[board[0][2] == symbol ? 2 : (board[1][1] == symbol ? 0 : 1)][board[0][2] == symbol ? 0 : (board[1][1] == symbol ? 2 : 1)] = symbol;
        return true;
    }
    return false;
}*/
bool checkAndMove(char board[][3], char symbol) {}



/*//Function to allow AI to make a move
void ai_turn() {}*/


/*
char checkwincondition(char board[]) {
    // Check rows
    if (board[0] == board[1] && board[1] == board[2])
        return board[0];
    if (board[3] == board[4] && board[4] == board[5])
        return board[3];
    if (board[6] == board[7] && board[7] == board[8])
        return board[6];

    // Check columns
    if (board[0] == board[3] && board[3] == board[6])
        return board[0];
    if (board[1] == board[4] && board[4] == board[7])
        return board[1];
    if (board[2] == board[5] && board[5] == board[8])
        return board[2];

    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8])
        return board[0];
    if (board[2] == board[4] && board[4] == board[6])
        return board[2];

    // Check if the board is full
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ')
            return ' ';
    }
}
*/

void player_turn(){

    if(turn == 'X'){
        cout<<"Navrsti je "<<player1<<" [X]: ";
        cin >> choice;
    }

    else if(turn == 'O'){
        srand(time(NULL));

        if(checkWin()){
            player2Score++;
        }
        else {
            choice= rand()%9+1;
        }
        cout<<"Navrsti je "<<player2<<" [X]: "<<choice;
        /*if(checkAndMove(board,'X')){
            player2Score++;
        }
        else{
            choice=rand()%9+1;
        }*/
    }

    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Nelegalana pozicija"<<endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied


        board[row][column] = 'X';

        SetConsoleTextAttribute(color, 0);
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied

        board[row][column] = 'O';

        turn = 'X';
    }else {
        //if input position already filled
        cout<<"pozicija je ze zapolnjena"<<endl;
        player_turn();
    }

    /* Ends */
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

void player_turn2(){
    if(turn == 'X'){

        cout<<"Navrsti je igralec 1: ";
    }
    else if(turn == 'O'){

        cout<<"navrsti je igralec 2: ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Nelegalana pozicija"<<endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        SetConsoleTextAttribute(color, 5);
        cout<<"pozicija je ze zapolnjena"<<endl;
        player_turn2();
    }
    /* Ends */
    display_board();
}

//Program Main Method

int glasnost=100;
string resolucija="220x340";

void  nastavitve()
{
    cout<<"izbrali ste nastavitve, vase nastavitve so: "<<endl;
    SetConsoleTextAttribute(color, 5);
    cout<<"glasnost: "<<glasnost<<SetConsoleTextAttribute(color, 5)<<endl;
    cout<<"rezolucija: "<<resolucija<<endl;

    int x;

    do {
        cout<<"ce zelite spremeniti glasnost pritisnite 1, ce zelite spremeniti rezolucijo pritisnite 2, ce zelite zapustiti nastavitve pritisnite 0"<<endl;
        cin>>x;


        if(x==1)
        {
            cout<<"nastavite novo glasnost: ";
            do{
                cin>>glasnost;
            }while(glasnost>100);
            cout<<"glasnost: "<<glasnost<<endl;
        }
        else if(x==2)
        {
            cout<<"nastavi novo rezolucijo: ";
            cin>>resolucija;
            cout<<"rezolucija: "<<resolucija<<endl;
        }

    }while(x!=0);


}
void resetBoard() {
    char st = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = st++;
        }
    }
}
void showPlayerScore() {
    SetConsoleTextAttribute(color, 0);
    cout << "Rezultati" << endl;
    SetConsoleTextAttribute(color, 0);
    cout << "----------------" << endl;
    cout <<SetConsoleTextAttribute(color, 5)<<player1 << "      " << player2 << endl;
    cout << player1Score << "        " << player2Score << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(color, 5);
    if (player1Score > player2Score)
    cout << "Trenutno vodi " << player1<<endl;
    else
        cout << "Trenutno vodi " << player2<<endl;
}

int main()
{

    char x;
    SetConsoleTextAttribute(color, 5);
    do {
        cout<<"izberi opcijo 1=igra proti racunalniku, 2=igra s samim sabo 3=rezultati prejsnjih iger, 4=nastavitve, 0=zakljucek "<<endl;
        cin >> x;


        if(x=='1') {
            //doloèanje kateri igralec bo zaèel/ime igralcev
            if (player1 == "" && player2 == "") {
                SetConsoleTextAttribute(color, 5);
                cout << "Ime igralca 1: " << endl;
                cin >> player1;
                cout << "Ime igralca 2: " << endl;
                cin >> player2;
            }
            while (gameover()) {
                display_board();
                gameover();
                player_turn();
            }
            if (turn == 'X' && draw == false) {
                cout << "zmagal je: "<<player2<<endl;
                    player2Score++;
                resetBoard();
            } else if (turn == 'O' && draw == false) {
                cout << "zmagal je: "<<player1<<endl;
                    player1Score++;
                resetBoard();

            } else {
                cout << "ni zmagovalca";
                resetBoard();
            }
        }
        if(x=='2') {
            //doloèanje kateri igralec bo zaèel/ime igralcev
            if (player1 == "" && player2 == "") {
                SetConsoleTextAttribute(color, 5);
                cout << "Ime igralca 1: " << endl;
                cin >> player1;
                cout << "Ime igralca 2: " << endl;
                cin >> player2;
            }
            while (gameover()) {
                display_board();
                gameover();
                player_turn2();
            }
            if (turn == 'X' && draw == false) {
                cout << "zmagal je: "<<player2<<endl;
                player2Score++;
                resetBoard();
            } else if (turn == 'O' && draw == false) {
                cout << "zmagal je: "<<player1<<endl;
                player1Score++;
                resetBoard();

            } else {
                cout << "ni zmagovalca";
                resetBoard();
            }
        }
        else if(x=='3')
        {
            showPlayerScore();
        }

        else if(x=='4')
        {
            nastavitve();
        }

    }while(x!='0');

} 