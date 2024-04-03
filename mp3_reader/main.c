/*
NAME :
DATE :
DESCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
 */

#include <stdio.h>
#include "mp3.h"
#include <string.h>
#include "edit.h"

int main(int argc, char *argv[])
{
    int status;
    status = validate_inputs(argv);

    if (status == ERROR)
    {
	return 0;
    }

    if(strcmp(argv[1], "-e") == 0)
    {
	if (status != ERROR)
	{
	    printf("--------------SELECTED EDIT DETAILS_________________\n");
	    edit_mp3(argv);
	    printf("mp3 is editted successfully.\n");
	    return 0;
	}
    }

    if (strcmp(argv[1], "-v") == 0)
    {
	if (status != ERROR)
	{
	    printf("--------------SELECTED VIEW DETAILS_________________\n");
	    view_mp3(argv);
	    printf("mp3 is viewed successfully.\n");
	    return 0;
	}
    }


    /*if ( (argv[2] != "-t") || (argv[2] != "-a") || (argv[2] != "-A") || (argv[2] != "-y") || (argv[2] != "-m") || (argv[2] != "-c") )
    {
	printf("Please pass tag arguments which you want to edit\n");
	printf("eg: ./a.out -e -t/-a/-A/-y/-m/-c mp3filename\n");
    }

    if (strcmp(strstr(argv[3], "."), ".mp3") != 0) 
    {
	printf("The file name should be of .mp3\n");     
    }*/



}
