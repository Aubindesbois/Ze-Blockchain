#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

void addBlock (Blockchain blockchain, int maxTrans){
  // appel de genAleaBlock (int difficulty, int maxTrans, int index, char* previousHash);
  Block newBlock = genAleaBlock( blockchain->difficulty, maxTrans, (blockchain->genesis->index)+1, blockchain->genesis->previous->hashBlock);
  
  //met a jour la blockchain avec le nouveau block 
  
  newBlock -> previous = blockchain->genesis->previous;
  newBlock -> next = blockchain->genesis ;
  blockchain->genesis->previous->next = newBlock;
  blockchain->genesis->previous = newBlock;
  
  (blockchain->size)++;
  
}
