#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "account.h"
#include "cJSON.h"
#include <string.h> 
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

int connexion(char *na, char *mdp, char *id, int *connect) {
	// open the file 
	char filename[100];
	sprintf(filename, "%s.json", na);
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Error: Unable to open the file.\n");
		return 1;
	}

	// read the file contents into a string 
	char buffer[1024];
	int len = fread(buffer, 1, sizeof(buffer), fp);
	fclose(fp);

	// parse the JSON data 
	cJSON* json = cJSON_Parse(buffer);
	if (json == NULL) {
		const char* error_ptr = cJSON_GetErrorPtr();
		if (error_ptr != NULL) {
			printf("Error: %s\n", error_ptr);
		}
		cJSON_Delete(json);
		return 1;
	}

	// access the JSON data 
	cJSON* password = cJSON_GetObjectItemCaseSensitive(json, "password");
	cJSON* argent = cJSON_GetObjectItemCaseSensitive(json, "argent");
	if (cJSON_IsString(password) && (password->valuestring != NULL)) {
		printf("Argent disponible: %s\n", password->valuestring);
		printf("%s\n", mdp);
		if (strcmp(mdp, password->valuestring) == 0) {//strcmp permet de comparer 2 chaine de charactère
			printf("ICI\n");
			*connect = 1;
		}
	}

	// delete the JSON object 
	cJSON_Delete(json);
	return 0;
}