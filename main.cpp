
//Importing the inbuild libraries in CPP
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;;

//Function to show the current status of the gaming board

void display_board(){

    //Rander Game Board LAYOUT

    cout<<"Igralec 1 [X] - Igralec - 2 [O]"<<endl;
    cout<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<endl;
    cout<<"     |     |     "<<endl;
}

//Function to get the player input and update the board

void player_turn(){
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
        cout<<"pozicija je ze zapolnjena"<<endl;
        player_turn();
    }
    /* Ends */
    display_board();
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

//Program Main Method

int glasnost=100;
string resolucija="220x340";

void  nastavitve()
{
    cout<<"izbrali ste nastavitve, vase nastavitve so: "<<endl;
    cout<<"glasnost: "<<glasnost<<endl;
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

int main()
{

    char x;

    do {
        cout<<"izberi opcijo 1=igra, 2=rezultati prejsnjih iger, 3=nastavitve, 0=zakljucek "<<endl;
        cin >> x;

        if(x=='1') {
            while (gameover()) {
                display_board();
                player_turn();
                gameover();
            }
            if (turn == 'X' && draw == false) {
                cout << "igralec 1 je zmagal";
            } else if (turn == 'O' && draw == false) {
                cout << "igralec 2 je zmagal";
            } else {
                cout << "ni zmagovalca";
            }
        }
        else if(x=='2')
        {

        }

        else if(x=='3')
        {
            nastavitve();
        }

    }while(x!='0');
} 