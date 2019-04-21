#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(char * name, char * filename);

int main(int argc, char ** argv){

	if(strcmp(argv[1],"help")){
		// Building path from command line arguments
		char * home = getenv("HOME");
		copyFile(strcat(strcat(strcat(strcat(home,"/.bpm/boilerplates/"),argv[2]),"/"),argv[3]), argv[1]);
	}else{
		FILE *file = fopen("help", "r");
		
		if (file != NULL){
			char line [128];
			while(fgets(line, sizeof line, file) != NULL){
				fputs(line, stdout); 
			}
			fclose(file);
		}
	}
		
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
