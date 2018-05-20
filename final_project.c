/*
SIMPLE SNACK AND LADDER
KELOMPOK 19 :
	1. ARIAN DEWANTARA - 1606904705
	2. TRI WHAYU GUNTARA - 1606904693
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int board[100] =
{
	0, 22, 0, 0, 0, 12, 0, 0, 0, 0,
	0, 0, 0, 0, 0, -10, 0, 0, 0, 12,
	0, 0, 0, -19, 0, 0, 0, 56, 0, 0,
	10, 0, -15, 0, 17, 0, 12, 0, 0, 0,
	0, 0, 0, -15, 0, 0, -23, 0, 0, 0,
	0, 0, 0, 0, 0, 0, -17, 0, 0, 0,
	0, 0, 0, 6, 0, 17, 0, 0, 0, 0,
	20, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, -10, 0, 0, -6, 0, 0,
	0, 0, 0, 0, -20, 0, 0, 0, -21, 0
};

char icon[4] = {'X', '#', '+', '?'};

// Check if there's one player that in position of 100
// If there's 100, return true
bool finish(int player_position[], int n_player){
	for(int i=0; i<n_player; i++){
		if(player_position[i] == 100){
			printf("\n===========================================\n");
			printf("CONGRATULATIONS! PLAYER %d IS THE WINNER!", i+1);
			printf("\n===========================================\n");
			return true;
		}
	}
	return false;
}

// Print board. Players' position will be marked with special symbol
void print_board(int player_position[], int n_player){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			// Get current index of itteration
			int index;
			if(i%2 == 0) index = 100-(i*10+j);
			else index = 100-(i*10+(9-j));
			
			// Check for player position to print their corresponding symbol
			bool no_player=true;
			printf(" | ");

			for(int k=0; k<n_player; k++)
				if(index == player_position[k]) no_player = false;

			if(!no_player){
				for(int k=0; k<(4-n_player); k++) printf(" ");
				for(int k=0; k<n_player; k++){
					if(index == player_position[k]) printf("%c", icon[k]);
					else printf(" ");
				}
			}
			else printf("%*d", 4, index);
		}
		printf(" |\n");
	}
}

// Return random number between 1 and 6
int throw_dice(int randomer = 0){
	srand(time(NULL)+randomer);
	return (rand()%6)+1;
}

// Play the game
void play_game(int n_player){
	// Initilize player position at 0
	int player_position[n_player];
	for(int i=0; i<n_player; i++) player_position[i] = 0;
	
	printf("SIMPLE SNAKE AND LADDER\n");
	printf("===============================\n\n");
	print_board(player_position, n_player);		// Print starting board

	// Keep playing until there's player in position 100
	int current_player = 0;							// Current player indexing starts at 0
	while(!finish(player_position, n_player)){
		char randomer;
		printf("\n(Press ctrl+c to exit at anytime)\n");
		printf("\nPlayer %d turn (%c) [insert any character] : ", current_player+1, icon[current_player]);
		scanf("%c%*c", &randomer);							// "Randomer" to throw dice

		int temp_dice = throw_dice((int)randomer);
		player_position[current_player] += temp_dice;		// Move current player by throwing dice

		// Check if player's position surpasses 100
		if(player_position[current_player] > 100) player_position[current_player] = 100 - (player_position[current_player]%100);
		
		system("clear");
		printf("SIMPLE SNAKE AND LADDER\n");
		printf("===============================\n\n");
		printf("Dice result is %d.\n", temp_dice);
		printf("Players %d position change to %d.\n\n", current_player+1, player_position[current_player]);

		// Check for "stair" or "snake"
		if(board[player_position[current_player]] != 0){
			printf("There is a ladder or snake that move %d.\n", board[player_position[current_player]]);
			player_position[current_player] += board[player_position[current_player]];

			// Check if player's position surpasses 100, again
			if(player_position[current_player] > 100) player_position[current_player] = 100 - (player_position[current_player]%100);
			
			printf("Player %d position change to %d.\n\n", current_player+1, player_position[current_player]);
		}

		print_board(player_position, n_player);

		// Change player turn if the dice isn't 6
		if(temp_dice != 6) current_player = (current_player+1)%n_player;
		else printf("\nDice result is 6, you get one more chance to move.\n");
	}
}

int main(){
	// Asks for number of players
	int n_player;
	char w;
	
	system("clear");
	printf("SIMPLE SNAKE AND LADDER\n");
	printf("===============================\n");
	printf("Main Menu :\n");
	printf("[1] Start Game\n");
	printf("[2] How to Play\n");
	printf("[3] Get Help\n");
	printf("[4] Exit Game\n\n");
	printf("(Press ctrl+c to exit at anytime)\n\n");
	printf("Insert your command :"); scanf("%c%*c", &w);

	while(true){
		if (w == '1'){
			// Keep asking for input if didn't meet the constraint
			printf("Insert players (2 - 4): "); scanf("%d", &n_player);
			while(n_player != 2 && n_player != 3 && n_player != 4){
				printf("Only  (2-4) players allowed\n");
				printf("Insert players (2 - 4): "); scanf("%d", &n_player);
			}
			system("clear");

			// Play the game
			play_game(n_player);
			break;
		}
		
		else if (w == '2'){
			system("clear");
			printf("HOW TO PLAY :\n");
			printf("[1] Press start button\n");
			printf("[2] Insert how many players playing\n");
			printf("[3] Determine which player to go first\n");
			printf("[4] Move by type 1 character randomly on keyboard, the game will role the dice for you\n");
			printf("[5] Watch out for snake and ladder, snake means you go down, and ladder means you go up\n");
			printf("[6] Enjoy the game with your friends\n\n");

			printf("Main Menu :\n");
			printf("[1] Start Game\n");
			printf("[2] How to Play\n");
			printf("[3] Get Help\n");
			printf("[4] Exit Game\n");
			printf("(Press ctrl+c to exit at anytime)\n");
			printf("Insert your command :"); scanf("%c%*c", &w);
		}
		
		else if (w == '3') {
			system("clear");
			printf("HELP\n");
			printf("Please contact maintainer +6282115560642 for further help.\n\n");
			
			printf("Main Menu :\n");
			printf("[1] Start Game\n");
			printf("[2] How to Play\n");
			printf("[3] Get Help\n");
			printf("[4] Exit Game\n");
			printf("(Press ctrl+c to exit at anytime)\n");
			printf("Insert your command :"); scanf("%c%*c", &w);
		}
			
		else if (w == '4') {
			printf("Thanks for playing\n");
			break;
		}
		
		else{
			system("clear");
			printf("Command Invalid, please try again.\n");
			printf("SIMPLE SNAKE AND LADDER\n");
			printf("________________________\n");
			printf("Main Menu :\n");
			printf("[1] Start Game\n");
			printf("[2] How to Play\n");
			printf("[3] Get Help\n");
			printf("[4] Exit Game\n");
			printf("(Press ctrl+c to exit at anytime)\n");
			printf("Insert your command :"); scanf("%c%*c", &w);
		}
	}
	return 0;
}

/*
1. USER FRIENDLY (help or play,
	masukkan jumlah pemain jika leih dari 4 minta lagi,
	how to exit, print position of current player,
	if player ask for his position, print keluaran dadu dan posisinya setelah)
2. EDIT MAP
3. POSITION IF SURPASS 100 (EDIT FINISH() ALSO)
4. SCANF bermasalah
*/
