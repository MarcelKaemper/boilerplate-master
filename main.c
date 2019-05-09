#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void copyFile(char * name, char * filename);
void getDir(char * path);

int main(int argc, char ** argv){

	char * home = getenv("HOME");
	char * path = strcat(home, "/.bpm/boilerplates/");

	if((strcmp(argv[1],"help"))){
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

void getDir(char * pathPara){
	DIR *dp;
	struct dirent *ep;	

	char * dirName;
	char * subdirName;

	char * path = malloc(strlen(pathPara) + 1);
	strcpy(path, pathPara);

	dp = opendir(path);

	if(dp != NULL){
		while(ep = readdir(dp)){
			dirName = malloc((strlen(ep->d_name) + 1) * sizeof(char));
			strcpy(dirName, ep->d_name);
			
			if((strcmp(dirName, "..")) && (strcmp(dirName, "."))){
				printf("> %s\n", dirName);

				DIR *subdp;
				struct dirent *subep;

				subdp = opendir(strcat(path, dirName));

				if(subdp != NULL){
					while(subep = readdir(subdp)){
						subdirName = malloc((strlen(ep->d_name) + 1) * sizeof(char));
						strcpy(subdirName, subep->d_name);
						if((strcmp(subdirName, "..")) && (strcmp(subdirName, "."))){
							printf("%s\n", subep->d_name);	
						}
						free(subdirName);
					}
				}
				strcpy(path, pathPara);
				(void) closedir(subdp);
			}
			free(dirName);
		}
		(void) closedir(dp);
	}

	free(path);
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
