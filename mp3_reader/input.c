/*
NAME :
DATE :
DESCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
 */

#include "mp3.h"
#include "edit.h"

int validate_inputs(char **argv)
{
    FILE *fp;
    char mp3[4] = "ID3";
    int i;
    int arguments = 0;

    for ( i = 0; argv[i]; i++ )
    {
	arguments++;
    }

    if (arguments == 1)
    {
	printf("ERROR: ./a.out : INVALID ARGUMENTS\n");
	printf("USAGE :\n");
	printf("To view please pass like: ./a.out -v mp3filename.\n");
	printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c mp3filename\n");
    return ERROR;
	}

    if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "-e") == 0))
    {
	if ((fp = fopen(argv[2], "rb")) == NULL)
	{
	    perror("fopen");
	    printf("Unable to open Source File\n");
	    return ERROR;
	}
	
	if(strcmp(argv[1],"-v") == 0)
	{
		if(arguments < 3 || arguments > 4)
		{
			printf("INSUFFICIENT ARGUEMENTS\nUSAGE : ./mp3_tag_reader -v <.mp3 file>\n");
		return ERROR;
		}
	}

	if(strcmp(argv[1],"-e") == 0)
	{
		if(arguments < 4 || arguments > 5)
		{
          printf("INSUFFICIENT ARGUEMENTS\nUSAGE : ./mp3_tag_reader -e <.mp3 file> <modifier> <tag>");
		return ERROR;
		}
	}
    }

    if(strcmp(argv[1], "-h") == 0)
    {
	printf("Help menu for Mp3 Tag Reader and Editor:\n\nFor viewing the tags- ./mp3_tag_reader -v <.mp3 file>\n\nFor editing the tags- ./mp3_tag_reader -e <.mp3 file> <modifier> <tag>\n\nModifier  Function\n  -t   Modifies Title tag\n  -T   Modifies Track tag\n  -a   Modifies Artist tag\n  -A   Modifies Album tag\n  -y   Modifies Year tag\n  -c   Modifies Comment tag\n  -g   Modifies Genre tag\n");
	return SUCCESS;
    }


    if ( (argv[2] != "-t") && (argv[2] != "-a") && (argv[2] != "-A") && (argv[2] != "-y") && (argv[2] != "-m") && (argv[2] != "-c") )
    {
	printf("Please pass tag arguments which you want to edit\n");
	printf("eg: ./a.out -e -t/-a/-A/-y/-m/-c mp3filename\n");
    }

    if (strcmp(strstr(argv[3], "."), ".mp3") != 0)
    {
	printf("The file name should be of .mp3\n");
    }
}
