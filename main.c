#include <stdio.h>
#include "fonctions.h"
#include "structures.h"

void afficherInfoBloc (Block b){
	Transaction t = b->transactionList;
	printf("Index: %d\n", b->index);
	printf("Previous hash: %s\n", b->previousHash);
	printf("Transaction list:\n");
	for(int i = 0; i < b->nbTransaction; i++){
		printf("   %d) %s\n", i, t->trans);
		t = t->next;
	}
	printf("\nHash root: %s\n", b->hashRoot);
	printf("Hash block: %s\n", b->hashBlock);
	printf("Nonce: %d\n", b->nonce);
}

int main (void) {
	Blockchain blockchain;
	Block block;
	int difficulty;
	int choix;
	int taille;
	int maxTrans;
	int indice1;
	int indice2;
	printf("Choix du mode de création:\n");
	printf(" 1) Création d'une nouvelle blockchain\n");
	printf(" 2) Chargement depuis un fichier Json --bloqué--\n");
	while (choix != 1 || choix != 2){
		scanf("%d", &choix);
	}
	if (choix == 1){
		printf("Choisissez la difficulté du minage: ");
		scanf("%d", &difficulty);
		blockchain = initBlockchain(difficulty);

		printf("Veuillez saisir un nombre de blocs: ");
		scanf("%d", &taille);

		printf("Veuillez saisir un maximum de transactions: ");
		scanf("%d", &maxTrans);
		printf("Création de la blockchain...");
		for(int i = 0; i < taille; i++){
			addBlock(blockchain, maxTrans);
		}
		printf("Blockchain générée");
	}
	if (choix == 2){
		return 1;
	}

	choix = -1;
	while (choix != 0){
		printf("Choisissez une action:\n");
		printf(" 0) Quitter\n");
		printf(" 1) afficher la blockchain\n");
		printf(" 2) Supprimer une transaction\n");
		printf(" 3) Supprimer un bloc\n");
		printf(" 4) Verif1...?\n");
		printf(" 5) Verif2...?\n");
		scanf("%d", &choix);
		if (choix == 1){
			block = blockchain->genesis->next;
			printf("Taille de la blockchain:");
			while (block != NULL){
				afficherInfoBloc (block);
			}
		}

		else if (choix == 2){
			printf("Indice du bloc: ");
			scanf("%d", &indice1);
			printf("Indice de la transaction: ");
			scanf("%d", &indice2);
			cheaterTrans (blockchain, indice1, indice2);
		}

		else if (choix == 3){
			printf("Indice du bloc: ");
			scanf("%d", &indice1);
			cheaterBlock (blockchain, indice1);
		}
	}
	return 0;
}