#include <string.h>
#include <unistd.h>
#include "commands.h"
#include <stdio.h>

int do_cd(int argc, char** argv) {
	if (!validate_cd_argv(argc, argv))
		return -1;

  	chdir(argv[1]);
	return 0;
}

int do_pwd(int argc, char** argv) {
	if (!validate_pwd_argv(argc, argv))
    		return -1;
	char str[8097];
	getcwd(str, 8096);
	printf("%s\n", str);
	return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if(argc!=2||strcmp(argv[0],"cd")!=0)
		return 0;
	return 1;
}

int validate_pwd_argv(int argc, char** argv) {
	if(argc > 1 ||strcmp(argv[0],"pwd")!=0)
		return 0;
	return 1;
}
