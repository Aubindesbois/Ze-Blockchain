#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct s_Blockchain *Blockchain;
typedef struct s_Block *Block;
typedef struct s_Transaction *Transaction;

struct s_Blockchain{
    int difficulty;
    int size;
    Block genesis;
};

struct s_Block{
    int index;
    char* timestamp;
    char* previousHash;
    int nbTransaction;
    Transaction transactionList;
    char* hashRoot;
    char* hashBlock;
    int nonce;
    Block next;
    Block previous;
};

struct s_Transaction {
    char* trans;
    Transaction next;
};

#endif