#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(char * name);

int main(int argc, char ** argv){

	char * home = getenv("HOME");
	copyFile(strcat(home,"/Documents/coding/projects/boilerplate-master/boilerplates/c/main"));
		
	return 0;
}

void copyFile(char * name){
	FILE *file = fopen(name, "r");
	FILE *newFile = fopen(strcat(getenv("PWD"),"/copy"), "w");
	
	if (file != NULL){
		char line [128]; /* or other suitable maximum line size */
		while(fgets(line, sizeof line, file) != NULL){
			fputs(line, newFile); /* write the line */
		}
		fclose(file);
		fclose(newFile);
	}else{
		perror(name); /* why didn't the file open? */
	}
}
