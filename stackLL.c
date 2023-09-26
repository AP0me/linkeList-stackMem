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
void arrToLL(int arrSize, int sizeLL, struct NodeLL (*nodeArr)[sizeLL], int array[arrSize]){
  if(sizeLL>arrSize){
    for(int i=0; i<arrSize; i++){
      (*nodeArr)[i].data = array[i];
    }
  }
  else{ printf("Size of the Linked List is smaller than Size of the Array"); }
}
void fillNodeArr(int arrSize, struct NodeLL (*nodeArr)[arrSize]){
  for(int i = 0; i < arrSize; i++){
    (*nodeArr)[i].data = i+1;
    (*nodeArr)[i].next = NULL;
  }
}

int main(int argc, char** argv){
  int nodeArrSize = 10;
  struct NodeLL nodeArr[nodeArrSize];
  
  //Filled Linked List with (1,2,3...).
  fillNodeArr(nodeArrSize, &nodeArr);
  pushLL(&nodeArr[0], &nodeArr[1]);
  printLL(&nodeArr[0]);
  insertLL(&nodeArr[0], &nodeArr[2]);
  printLL(&nodeArr[0]);

  //Refilled Linked List with data in array.
  int arrayInt[] = {10,30,60};
  int arraySize = sizeof(arrayInt)/sizeof(int);
  arrToLL(arraySize, nodeArrSize, &nodeArr, arrayInt);
  pushLL(&nodeArr[0], &nodeArr[1]);
  printLL(&nodeArr[0]);
  insertLL(&nodeArr[0], &nodeArr[2]);
  printLL(&nodeArr[0]);
}
