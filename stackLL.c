#include <stdio.h>

struct NodeLL{
  int data;
  struct NodeLL* next;
};

void pushLL(struct NodeLL* current, struct NodeLL* next){
  current->next = next;
}
void printLL(struct NodeLL* firstNodeLL){
  struct NodeLL* current = firstNodeLL;
  printf("[");
  for(int i=0; current!=NULL; i++){
    printf("%d, ", (*current).data);
    current = current->next;
  }
  printf("]\n");
}
void insertLL(struct NodeLL* beforeNodeLL, struct NodeLL* insertNodeLL){
  struct NodeLL* afterNodeLL = beforeNodeLL->next;
  beforeNodeLL->next = insertNodeLL;
  insertNodeLL->next = afterNodeLL;
}
void arrToLL(int arrSize, struct NodeLL (*nodeArr)[arrSize], int array[arrSize]){
  
}
void fillNodeArr(int arrSize, struct NodeLL (*nodeArr)[arrSize]){
  for(int i = 0; i < arrSize; i++){
    (*nodeArr)[i].data = i+1;
    (*nodeArr)[i].next = NULL;
  }
}

int main(int argc, char** argv){
  int nodeArrSize = 10; struct NodeLL nodeArr[nodeArrSize];
  fillNodeArr(nodeArrSize, &nodeArr);

  struct NodeLL* firstNodeLL  = &nodeArr[0];
  struct NodeLL* secondNodeLL = &nodeArr[1];
  struct NodeLL* thirdNodeLL  = &nodeArr[2];
  pushLL(firstNodeLL, secondNodeLL);
  printLL(firstNodeLL);
  insertLL(firstNodeLL, thirdNodeLL);
  printLL(firstNodeLL);
}
