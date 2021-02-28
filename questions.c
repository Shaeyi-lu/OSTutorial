/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>'
#include "questions.h"

int num_questions = 12;
int counter;
int value = 0;
char category[MAX_LEN] = "category";
char answer[MAX_LEN];


// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    //Q1
	strcpy(questions[0].category, "programming");
	strcpy(questions[0].question, "In OOP, is a feature that allows a subclass or child class to provide a specific implementation of a method that is already provided by one of its super-classes or parent classes. ");
	strcpy(questions[0].answer, "method overriding");
	questions[0].value = 100;
	questions[0].answered = false;

	//Q2
	strcpy(questions[1].category, "programming");
	strcpy(questions[1].question, "JAVA is an _ _ programming language.");
	strcpy(questions[1].answer, "object oriented");
	questions[1].value = 200;
	questions[1].answered = false;

	//Q3
	strcpy(questions[2].category, "programming");
	strcpy(questions[2].question, "What is the type for integer variables in java?");
	strcpy(questions[2].answer, "int");
	questions[2].value = 300;
	questions[2].answered = false;

	//Q4
    strcpy(questions[0].category, "programming");
	strcpy(questions[0].question, "What is the output of this line? int age = 5 * 3; printf(\"%s\", age);");
	strcpy(questions[0].answer, "what is 15");
	questions[0].value = 400;
	questions[0].answered = false;
	

	//Q5
	strcpy(questions[4].category, "algorithms");
	strcpy(questions[4].question, "Which searching algorithm searches the array one at a time");
	strcpy(questions[4].answer, "linear search");
	questions[4].value = 100;
	questions[4].answered = false;

	//Q6
	strcpy(questions[5].category, "algorithms");
	strcpy(questions[5].question, "Which searching algorithm divides the array in half to find the target?");
	strcpy(questions[5].answer, "what is binary search");
	questions[5].value = 200;
	questions[5].answered = false;

	//Q7
	strcpy(questions[6].category, "algorithms");
	strcpy(questions[6].question, "Which sorting algorithm breaks the array into single digits and the sorts it while building the array back up?");
	strcpy(questions[6].answer, "merge sort");
	questions[6].value = 300;
	questions[6].answered = false;

	//Q8
	strcpy(questions[7].category, "algorithms");
	strcpy(questions[7].question, "Is this the worst case scenario for a linear search? (1,2,3,4,5,6,7  find 7)");
	strcpy(questions[7].answer, "yes");
	questions[7].value = 400;
	questions[7].answered = false;

    //Q9
    strcpy(questions[3].category, "databases");
	strcpy(questions[3].question, "RDBMS stands for");
	strcpy(questions[3].answer, "relational database management systems");
	questions[3].value = 100;
	questions[3].answered = false;

	//Q10
	strcpy(questions[8].category, "databases");
	strcpy(questions[8].question, "SQL stands for?");
	strcpy(questions[8].answer, "structured query language");
	questions[8].value = 200;
	questions[8].answered = false;

	//Q11
	strcpy(questions[9].category, "databases");
	strcpy(questions[9].question, "DBMS stands for?");
	strcpy(questions[9].answer, "database management system");
	questions[9].value = 300;
	questions[9].answered = false;

    //Q12
    strcpy(questions[10].category, "databases");
	strcpy(questions[10].question, "Is a key also a superkey?");
	strcpy(questions[10].answer, "what is no");
	questions[10].value = 400;
	questions[10].answered = false;

}

void player_choose_question(void){//asks players input for question
    

    printf("Choose a category and value: ");
    display_categories();//calls method to display questions available
    
	scanf("%s %d", category, &value);//reads player's input

    for(int j=0; j< num_questions; j++){
        if(category == questions[i].category && questions[i].value == value){
            questions[i].answered==true;//initializes the question chosen to be true
        }
    }

	display_question(category, value);//calls method to then display question picked

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("REMAINING QUESTIONS")
    for(int i =0; i< num_questions; i++ ){
        if(questions[i].answered == false){
            printf("%s | $%d\n", questions[i].category, questions[i].value);
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    if(already_answered() == false){//checks if question picked has already been answered or not

        for(int i = 0; i<num_questions; i++){
             if(category == questions[i].category && questions[i].value == value){
            printf(questions[i].question)//prints question chosen
             players_answer(i);//calls function to get player's answer
          
            }

        }

    }
   

	

}
bool players_answer(int num){//player answers question
    printf("What is your answer?");
    scanf("Answer: %s ", &answer);

    if(strcmp(answer, questions[num].answer)){ //validates players answer
        printf("correct answer");
        
        return true;
        
    }


}


/* Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
      
    return false;
}
*/

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for(int i =0; i< num_questions; i++ ){
        if(questions[i].answered == true){
            printf("question has already been answered, choose another question");

            display_categories();//calls display categories so player can recchoose a question
            return true;
        }
        else{
            return false;
        }
    }
    
    
}

bool all_questions_answered(void){//confirms is all questions have been answered
    for(int i=0; i<num_questions; i++){
        if(questions[i].answered == true){
            print("All questions have been answered");
            return true;
            
        }
        else{
            return false;
            break;

        }
    }
}
