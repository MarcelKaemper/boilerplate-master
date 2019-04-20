#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(char * name, char * filename);

int main(int argc, char ** argv){

	char * home = getenv("HOME");

	// Building path from command line arguments
	copyFile(strcat(strcat(strcat(strcat(home,"/Documents/coding/projects/boilerplate-master/boilerplates/"),argv[2]),"/"),argv[3]), argv[1]);
		
	return 0;
}

void copyFile(char * name, char * filename){
	FILE *file = fopen(name, "r");
	FILE *newFile = fopen(strcat(strcat(getenv("PWD"),"/"),filename), "w");
	
	if (file != NULL){
		char line [128];
		while(fgets(line, sizeof line, file) != NULL){
			fputs(line, newFile); 
		}
		fclose(file);
		fclose(newFile);
	}
}
