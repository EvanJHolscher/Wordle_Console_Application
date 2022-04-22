#include <stdbool.h>
#include <time.h>
int* check_guess(char* guess, char* answer){

  //Funciton takes O(n^2) time
  int* verifier;
  verifier = malloc(5);
  //"apple" "treat"
  for (int i = 0; i < 5; i++){            
    for (int j = 0; j < 5; j++){  
      if (guess[i] == answer[i]) {verifier[i] = 1; break;}
      else if (guess[i] == answer[j]){           
        verifier[i] = -1;  
        break;
      }
      else verifier[i] = 0;
    }                  
  }
  return verifier;
}

void hint(const char* letters,int* correct){
  int index = randInRange(0, 4);  //randomly pick a number (index) 0-5
  bool flag = false;
  while (!flag){
    if (correct[index] == 0){
      flag = true;
      printf("One of the letters is: %c \n", letters[index]);
    }
    else {
      index = randInRange(0, 4);
    }
  }
  
}
