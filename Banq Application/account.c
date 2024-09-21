#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "account.h"
#include "cJSON.h"
int create_account(char *name, char *id, char *argentdsp, char *password) {
		// create a cJSON object 
	cJSON* json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "name", name);
	cJSON_AddStringToObject(json, "id", id);
	cJSON_AddStringToObject(json, "password",password);
	cJSON_AddStringToObject(json, "argent", argentdsp);
	char fileName[100];
	// convert the cJSON object to a JSON string 
	char* json_str = cJSON_Print(json);
	sprintf(fileName, "%s.json", name);
	// write the JSON string to a file 
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Error: Unable to open the file.\n");
		return 1;
	}
	
	fputs(json_str, fp);

	cJSON_Delete(json);
	return 0;
}
int connexion() {
	FILE* na = NULL;
	na = fopen("account.txt", "a+");
	int caracter = 0;
	do
	{
		caracter = fgetc(na);
		printf("%c", caracter);
	} while (caracter != EOF);
	return 0;
}
