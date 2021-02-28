/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
int numPlayers = 4;
int scores[4];

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(struct player *players, int num_players){
    for(int j =0; j<num_players; j++){
        for(int i=0; i<num_players; i++){

         printf("Score of %s: %d\n", players[i].name,player[i].score);
        }
    }
   
};

int game_state;


/*
void mystrcpy(char *first, char *second) {
	int smallest = strlen(first);
	if (strlen(second) < smallest)
		smallest = strlen(second);
	int i;
	for (i=0; i < smallest; i++) first[i] = second[i];
	first[i] = 0;
}
*/


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player players[NUM_PLAYERS];
    
    char name[MAX_LENGTH];
    
    

    // EXAMPLE: player 1 is named Fred
	// players[0].name = "Fred";
    strcpy(players[0].name, "Fred");
    printf("%s\n", players[0].name);
    
    // Buffer for user input
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    

    // Prompt for players names
    printf("Enter name: ");
    scanf("%s", &name);
    
    // initialize each of the players in the array
    for(int i = 0; i<NUM_PLAYERS; i++){
      strcpy(players[i].name, name); //names of players
        players[i].score = 0; //assigns players earnings to 0
      
    }

    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
    while (game_state)
    {
        // EXAMPLE: This line gets a line of input from the user
        fgets(buffer, BUFFER_LEN, stdin);
        printf("[before]%s[after]", buffer);

		if (strcmp(buffer, "hello") == 0) printf(":)\n");
		if (strcmp(buffer, "world\n") == 0) printf(":)\n"); 

        

        // Execute the game until all questions are answered
        while(all_questions_answered() != true){

            for(int i=0; i<NUM_PLAYERS; i++){//allows each player a turn

            // Call functions from the questions and players source files

            //this function starts a sequence of other functions calling each other
            //so calling other functions is not needed
            player_choose_question(); //last thing returned is if player's answer is correct or not

                if(players_answer()== true){
                    update_score(players, num_players, players[i].name, score);//updates player's score

                }

            }


        }
        
        
        // Display the final results and exit
        show_results(struct player *players, int num_players);
    }
    return EXIT_SUCCESS;
}