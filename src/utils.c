#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	*argv = (char**)malloc(sizeof(char*)*8096);
	int i = 0;
	char *str = (char*)malloc(sizeof(char)*8096);
	char *token = (char*)malloc(sizeof(char)*8096);
	strcpy(str, command);
	token = strtok(str, " \t\n");
	if(token==NULL)
	{	*(*argv+i) = (char*)malloc(sizeof(char)+2);
		strcpy(*(*argv+i), "");
		i++;
	}
			
	while(token != NULL)
	{
		*(*argv+i) = (char*)malloc(sizeof(char)*strlen(token));
		strcpy(*(*argv+i), token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	
	*argc = i;
	free(str);
	free(token);	
}
