#include <stdio.h>
int win();
int draw();

char board[10]= {'0','1','2','3','4','5','6','7','8','9'};

void main_board();
int main(){
    int player = 1;
    int choice;
    int gamestatus = -1;
    char x_o;
    do{
        main_board();

        player = (player % 2) ? 1 : 2;
        x_o = (player ==1) ? 'X': 'O';

        printf("Player %d(%c) , Enter a number [1-9]: ", player, x_o );

        if(scanf("%d", &choice) != 1){
            printf("Invalid!! Please Enter a number: ");
            while(getchar() != '\n');
            continue;
        }
        if(choice >= 1 && choice <= 9 && board[choice] != 'X' && board[choice] !='O'){
            board[choice] = x_o;
        }
        else{
            printf("Invalid!, Try again! \n");
            continue;
        }

        if(win()) {
            gamestatus = 1;
        }
        else if(draw()){
            gamestatus = 0;
        }
        else{
            player ++;
        }
    } while (gamestatus == -1);

    main_board();

    if(gamestatus == 1)
        printf("Player %d wins! \n", (player%2) ? 1: 2);
    else
        printf("Draw!! :(");

    return 0;
    }
    void main_board(){
        printf("\n");
        printf(" %c | %c | %c \n", board[1], board[2], board[3]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", board[4], board[5], board[6]);
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", board[7], board[8], board[9]);
        printf("---+---+---\n");
    }
    int win(){
        if(board[1]==board[2] && board[2]==board[3]) return 1;
        if(board[4]==board[5] && board[5]==board[6]) return 1;
        if(board[7]==board[8] && board[8]==board[9]) return 1;

        if(board[1]==board[4] && board[4]==board[7]) return 1;
        if(board[2]==board[5] && board[5]==board[8]) return 1;
        if(board[3]==board[6] && board[6]==board[9]) return 1;

        if(board[1]==board[5] && board[5]==board[9]) return 1;
        if(board[3]==board[5] && board[5]==board[7]) return 1;

        return 0;
    }
    int draw(){
        for(int i=1 ; i<=9 ; i++){
            if(board[i] != 'X' && board[i] != 'O'){
                return 0 ;
            }
    }
    return 1;
    }
