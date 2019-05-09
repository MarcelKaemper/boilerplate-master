#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void copyFile(char * name, char * filename);
void getDir(char * path);

int main(int argc, char ** argv){

	char * home = getenv("HOME");
	char * path = strcat(home, "/.bpm/boilerplates/");

	if(strcmp(argv[1],"help")){
		// Building path from command line arguments
		copyFile(strcat(strcat(strcat(strcat(home,"/.bpm/boilerplates/"),argv[2]),"/"),argv[3]), argv[1]);
	}else{
		getDir(path);
		FILE *file = fopen(strcat(home, "/.bpm/help"), "r");
		
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

void getDir(char * path){
	DIR *dp;
	struct dirent *ep;	

	dp = opendir(path);

	if(dp != NULL){
		while(ep = readdir(dp)){
			puts(ep->d_name)	;
		}
		(void) closedir(dp);
	}
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
