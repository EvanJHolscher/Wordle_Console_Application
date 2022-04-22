#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <curses.h>
#include "words.h"
#include "game.h"
#include "list.h"


int main(void) {
  srand(time(NULL)); // initialize random number seed. ONCE ONLY.
  
  struct node* guesses = NULL;
  char* answer = randomWord();
  char* guess = (char*)malloc(10);
  bool finish = false;
  int hint_counter = 0;
 
  
  printf("Try to guess the word in 6 tries.\nType \"hint\" to get a hint\n");
  printf("(_) = Letter not in Word\n");
  printf("{_} = Incorrect location of letter\n");
  printf("[_] = Correct location of letter\n");

  //Game Loop
  for (int j = 0; j < 6; j++){
    //Get guess
    bool next_scan = false;
    bool give_hint = false;
    printf("\nEnter guess #%d: ",j+1);
    scanf("%s", guess);
    bool first_guess = false;
    
    //Check if they want a hint
    if ((int)strcmp(guess,"hint") == 0){
       if(j == 0){
        printf("Try to make one guess first!\n");
         j --;
         first_guess = true;
      }
       else if (hint_counter >= 2) {
        printf("You may only have two hints\n");
        j--;
      }
      else{
        give_hint = true;
      }
    }
    //Check if guess is a new word
    else if (!isaWord(guess)){
      printf("Make sure the word is real!\n");
      next_scan = true;
    }
    else if (list_contains(guesses,guess)){
      printf("Please enter a new word!\n");
      next_scan = true;
    }
    //If it is a new word, check if correct
   
    guesses = list_insert(guesses,guess);
    int *test = check_guess(guess,answer);
    if (give_hint == true){
       hint(answer,test);
       hint_counter++;
       give_hint = false;
       next_scan = true;
    }
    else if (!first_guess){
      for (int i = 0; i < 5; i++){
     // printf("%d", test[i]);
      
      if (test[i] == 1){
        printf("[%c] ",guess[i]);
      }
      if (test[i] == 0){
        printf("(%c) ",guess[i]);
      }
      if (test[i] == -1){
        printf("{%c} ",guess[i]);
      }
      // if (test[i] == 1) color = green 
      // if (test[i] == -1) color = yellow 
      // if (test[i] == 0) color = grey
    }
    }
  
    for (int i = 0; i < 5; i++){
      if (test[i] != 1) {
        finish = false;
        break;
      }
      else finish = true;
    }
    if (finish) {
      printf("\nYou win!");
      break;
    }
    printf("\n");
    }
    
  
  printf ("\nThe answer was %s",answer);
  return 0;
  
}


