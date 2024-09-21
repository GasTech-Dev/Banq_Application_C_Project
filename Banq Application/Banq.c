#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "account.h"

int main() {
	char question;
	printf("Avez vous un compte ? 0/N\n");
	scanf(" %c", &question);
	printf("%c\n", question);
	if (question == 'n' || question == 'N') {//'d' désigne 1 seul charactère alors que "d" désigne string
		printf("Donne successivement ton non\n ton email\n ton password\n puis l'argent disponible\n");
		char name[100];
		char surname[100];
		char nb_cb[100];
		char password[100];
		scanf("%s", &name);
		scanf("%s", &surname);
		scanf("%s", &nb_cb);
		scanf("%s", &password);
		create_account(&name, &surname, &nb_cb, &password);
	}
	else {
		char name[100];
		char password[100];
		char id[100];
		scanf("%s", &name);
		scanf("%s", &password);
		scanf("%s", &id);
		int connect = 0;
		connexion(&name, &password, &id, &connect);
		if (connect == 1) {
			printf("Conncter");
		}
	}
	
	return 0;
}