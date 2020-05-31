/*
This code has been compiled in Code::Blocks 16.01 IDE on Windows 10
Author:- Mishal Shah
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

typedef struct
{
	char symbol;
	char name[50];
}Player_Info;

void showRule(void);
void chooseSymbol(Player_Info* game_player1, Player_Info* game_player2);
int checkHorizontal(char game_board[]);
int checkVertical(char game_board[]);
int checkDiagonal(char game_board[]); 
int checkDraw(char game_board[]);
void showBoard(char game_board[], Player_Info game_player1, Player_Info game_player2);

int main(void)
{
    FILE *leaderboard;
    int current_player=1;
    char board_position[100];
    int game_state=0;
    char symbol;
    char menu_option[10];
    const int someoneWin =1;
    const int keepGoing = 0;
    const char* gotoGame ="1";
    const char* gotoLeaderBoard = "2";
    const char* quitGame = "3";
    const int player1_turn =1;
    const int player2_turn =2;
	
    Player_Info player1;
    Player_Info player2;
    char board_symbol[9]={'1','2','3','4','5','6','7','8','9'};

    leaderboard = fopen("leaderboard.txt","a+");
    fclose(leaderboard);
    system("color 09");
    showRule();

    printf("\n\nType 1 to start the game:-\nType 2 to view leader board:-\n");
    scanf("%s", menu_option);
    if(strcmp(menu_option , gotoGame) == 0)
    {
read:
	//menu_option =gotoGame ;
		leaderboard = fopen("leaderboard.txt","a+");
    	printf("\nEnter name of player1: ");
    	scanf("%s", player1.name);
    	fprintf(leaderboard, "\n%s",player1.name);
    	printf("Enter name of player2: ");
    	scanf("%s", player2.name);
    	fprintf(leaderboard, "\t%s", player2.name);
    	fclose(leaderboard);

    	if(strcmp(player1.name, player2.name))
    	{
	        chooseSymbol(&player1,&player2);
    	}
   	else
	{ 
        	printf("Enter names of different players!\n\n");
		goto read;	
	}
   	system("color fc");
   	showBoard(board_symbol, player1, player2);


    	while(game_state == keepGoing)
    	{
		if(current_player%2){
			current_player=player1_turn;
		}
		else{
			current_player=player2_turn;
		}
        
		if (current_player == player1_turn)
			printf("%s Type any digit from 1-9 to fill your response:- ", player1.name);
		else
			printf("%s Type any digit from 1-9 to fill your response:- ", player2.name);
		scanf("%s",board_position);
		if(current_player == player1_turn)
		{
			symbol=player1.symbol;
		}
		else
		{
			symbol=player2.symbol;
		}
		
		if (strcmp(board_position, "1") == 0  && board_symbol[0] == '1')
			board_symbol[0] = symbol;
		else if (strcmp(board_position,"2")==0 && board_symbol[1] == '2')
			board_symbol[1] = symbol;
		else if (strcmp(board_position, "3") == 0 && board_symbol[2] == '3')
			board_symbol[2] = symbol;
		else if (strcmp(board_position, "4") == 0 && board_symbol[3] == '4')
			board_symbol[3] = symbol;
		else if (strcmp(board_position, "5") == 0 && board_symbol[4] == '5')
			board_symbol[4] = symbol;
		else if (strcmp(board_position, "6") == 0 && board_symbol[5] == '6')
			board_symbol[5] = symbol;
		else if (strcmp(board_position, "7") == 0 && board_symbol[6] == '7')
			board_symbol[6] = symbol;
		else if (strcmp(board_position, "8") == 0 && board_symbol[7] == '8')
			board_symbol[7] = symbol;
		else if (strcmp(board_position, "9") == 0 && board_symbol[8] == '9')
			board_symbol[8] = symbol;
		else
		{
			printf("Wrong Selection\n");
			Sleep(1000);
			current_player--;
		}
		
		game_state = checkVertical(board_symbol);
		if (game_state )
		{
				current_player++;
				showBoard(board_symbol, player1, player2);
				break;
		}
		game_state = checkHorizontal(board_symbol);
		if (game_state )
		{
			current_player++;
			showBoard(board_symbol, player1, player2);
			break;
		}
		
		game_state = checkDiagonal(board_symbol);
		if (game_state )
		{
				current_player++;
				showBoard(board_symbol, player1, player2);
				break;
		}
		
		game_state=checkDraw(board_symbol);
		current_player++;
		showBoard(board_symbol, player1, player2);
	} 
 
	leaderboard = fopen("leaderboard.txt", "a+");
    	if(game_state==someoneWin)
    	{
        	if(current_player==2)
        	{
			printf("\n\nPlayer1 %s Wins!\n\n",player1.name);
			fprintf(leaderboard,"\t%s",player1.name);
        		getchar();
		}
        	else
        	{
			printf("\n\nPlayer2 %s Wins!\n\n",player2.name);
			fprintf(leaderboard,"\t%s",player2.name);
			getchar();
		}
		fclose(leaderboard);
	}
	else
	{
		printf("\n\nGame Draws!\n\n");
		fprintf(leaderboard,"\t%s","DRAW");
		getchar();
		fclose(leaderboard);
	}
    }

    else if (strcmp(menu_option, gotoLeaderBoard) == 0)
    {
		char cho[10];
		char c = '\0';
		int insert_error =1;
menu2:
	system("cls");
	printf("\n\n");
	printf("\tLEADERBOARD\n\n");
	printf("-------------------------\n");
	printf("Player1\t|Player2|Winner|\n");
	printf("-------------------------\n");
	
	leaderboard = fopen("leaderboard.txt", "r");

	while (c != EOF)
	{
		c = (char)(getc(leaderboard));
		printf("%c", c);
	}
	fclose(leaderboard);
	
	while(insert_error)
	{
		printf("\n\nPress 1 to start the game, Press 3 to quit game : ");
		scanf("%s", cho);
		if(strcmp(cho, gotoGame) == 0)
		{
			goto read;
		}
		else if(strcmp(cho, quitGame) == 0)
		{
			printf("\n\nBye~\n");
			break;
		}
		else
		{		
			printf("\nPress again!");
			getchar();
		}	 
	}
	
    }
    else 
    {
menu3:
	printf("잘못된 입력입니다!");
	printf("게임을 시작하려면 1을, 리더보드를 보려면 2를 입력하세요");
	scanf("%s", menu_option);
	if (strcmp(menu_option, gotoGame) == 0) 
	{
		goto read;
	}
	else if (strcmp(menu_option, gotoLeaderBoard) == 0) 
	{
		goto menu2;
	}
	else 
	{
		goto menu3;
	}
    }
}

int checkHorizontal(char game_board[])
{
	const int horizontal_complete =1;
	const int horizontal_fail = 0;
	if(game_board[0] == game_board[1] && game_board[1] == game_board[2])
		return horizontal_complete;
    	else if(game_board[3] == game_board[4] && game_board[4] == game_board[5])
        	return horizontal_complete;
    	else if(game_board[6] == game_board[7] && game_board[7] == game_board[8])
        	return horizontal_complete; 
    	else
        	return horizontal_fail;
}


int checkVertical(char game_board[])
{
	const int vertical_complete =1;
	const int vertical_fail = 0;
	
    	if(game_board[0] == game_board[3] && game_board[3] == game_board[6])
        	return vertical_complete;
    	else if(game_board[1] == game_board[4] && game_board[4] == game_board[7])
		return vertical_complete;
    	else if(game_board[2] == game_board[5] && game_board[5] == game_board[8])
		return vertical_complete;
   	else
		return vertical_fail;

} 

int checkDiagonal(char game_board[])
{
	const int diagonal_complete =1;
	const int diagonal_fail = 0;
    	if(game_board[0] == game_board[4] && game_board[4] == game_board[8])
        	return diagonal_complete ;
    	else if(game_board[2] == game_board[4] && game_board[4] == game_board[6])
        	return diagonal_complete;
    	else
        	return diagonal_fail;
}

int checkDraw(char game_board[])
{
	const int draw_complete = -1;
	const int draw_fail = 0;
	
    	if(game_board[0] != '1' && game_board[1] != '2' && game_board[2] != '3' && game_board[3] !='4' && game_board[4] != '5' && game_board[5] != '6' && game_board[6] != '7' && game_board[7] != '8' && game_board[8] != '9')
        	return draw_complete;
    	else
		return draw_fail;

}

void showBoard(char game_board[], Player_Info game_player1, Player_Info game_player2)
{
	system("cls");
    	printf("\tTic-Tac-Toe\n\n");

        printf("\n\n");
        printf("%s:- (%c)\n%s:-  (%c)\n\n\n",game_player1.name,game_player1.symbol,game_player2.name,game_player2.symbol);

        printf("  %c |  %c | %c\n", game_board[0], game_board[1], game_board[2]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("    |    |    \n");
        printf("  %c |  %c | %c\n", game_board[3], game_board[4], game_board[5]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("  %c |  %c | %c\n", game_board[6], game_board[7], game_board[8]);
        printf("    |    |    \n");
}

void showRule(void)
{
	char link[10];
	printf("\tTic-Tac-Toe\n\n");
	printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
	printf("Rules:-\n");
	printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
	printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
	printf("\n\nEnjoy the game! Be a Winner!\n\n");
	printf("For more clarifications press Y else type any other character:- ");
	scanf("%s", link);
	if (strcmp(link, "y") == 0 || strcmp(link, "Y") == 0)
	{
		system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
	}
}

void chooseSymbol(Player_Info* game_player1, Player_Info* game_player2)
{
    	char dec[10];
deci:
    	printf("\n\nPlayer1 %s choose the X or 0:", game_player1->name);
    	//dec = getchar();
    	scanf("%s", dec);
    
    	if(strcmp(dec, "X") == 0 || strcmp(dec, "x") == 0)
    	{
    		game_player1->symbol='X';
    		game_player2->symbol='0';
    	}
   	else if(strcmp(dec, "O") == 0 || strcmp(dec, "o") == 0)
    	{
    		game_player1->symbol='0';
        	game_player2->symbol='X';
    	}
    	else
    	{
    		printf("Please enter either X or O only \n\n");
        	goto deci;
    	}

}

