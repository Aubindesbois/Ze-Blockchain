#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "stdbool.h"
#include "structures.h"

Blockchain initBlockchain (int difficulty);

void addBlock (Blockchain blockchain, int maxTrans);

Block genAleaBlock (int difficulty, int maxTrans, int index, char* previousHash);

void genAleaTrans (Block block, int maxTrans);

char* merkleRoot (Transaction transactionList);

void mine (int difficulty, Block block);

char* createHash(Block block);

void cheaterBlock (Blockchain blockchain, int index);

void cheaterTrans (Blockchain blockchain, int index, int numTrans);

bool verif1 (Blockchain blockchain);

bool verif2 (Blockchain blockchain);

#include "cheater.c"

#endif