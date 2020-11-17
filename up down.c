#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int user, number, trycount;
static int min=1;
static int max=100;

void setNumber();
void printHead();
void printHigher();
void printLower();
void printAnswer();

int main(void) {
  setNumber();
  printHead();
  while(1){
    trycount++;
    if(user>100||user<1){
      printf("잘못된 입력입니다.\n다시 입력해주세요. >");
      scanf("%d", &user);
    }
    else if(user>number){
      printHigher();
    }
    else if(user<number){
      printLower();
    }
    else{
      printAnswer();
      break;
    }
    if(trycount==4 && user==number){
      printAnswer();
    }
    else if (trycount==4 && user!=number){
      printf("ㅋ...정답은 %d!", number);
      break;
    }
  }


}
void setNumber(){
  srand(time(NULL));
  number=rand()%100+1;
}
void printHead(){
 printf("%d 에서 %d 까지의 하나의 정수가 결정되었습니다.\n이 정수를 맞추어 보세요? >", min, max);
  scanf("%d", &user);
}
void printLower(){
  min=user;
  printf("맞추어야 할 정수가 입력한 정수 %d 보다 큽니다.\n%d 에서 %d 사이의 정수를 다시 입력하세요. >", user, min, max);
  scanf("%d", &user);
}
void printHigher(){
  max=user;
  printf("맞추어야 할 정수가 입력한 정수 %d 보다 작습니다.\n%d에서 %d 사이의 정수를 다시 입력하세요. >", user, min, max);
  scanf("%d", &user);
}
void printAnswer(){
  printf("축하합니다! 정답은 %d 입니다.", user);
}
