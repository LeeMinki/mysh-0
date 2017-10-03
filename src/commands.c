#include <string.h>
#include <unistd.h>
#include "commands.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

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
	if(argc==2&&strcmp(argv[0],"cd")==0)
	{
		int result = access(argv[1], F_OK);
		int result2 = access(argv[1], R_OK);
		if(result == 0 && result2 == 0)
		{
			struct stat buf;
			stat(argv[1], &buf);
			if(S_ISDIR(buf.st_mode))
				return 1;
		}
	}	
	return 0;
}

int validate_pwd_argv(int argc, char** argv) {
	if(argc > 1 ||strcmp(argv[0],"pwd")!=0)
		return 0;
	return 1;
}
