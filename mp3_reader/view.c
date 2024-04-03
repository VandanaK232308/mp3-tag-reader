/*
NAME :
DATE :
DESCRIPTION :
SAMPLE INPUT :
SAMPLE OUTPUT :
 */

#include "mp3.h"

mp3tag_info tag;

void view_mp3(char **argv)
{
    FILE *fp;

    fp = fopen(argv[2], "rb");
    if(fp == NULL)
    {
	perror("fopen");
	exit(1);
    }

    //	printf("\n%ld",ftell(fp));

    version(fp);
    album(fp);
    title(fp);
    artist(fp);

    //fclose(fp);
}

void version(FILE *fp)
{

    char buffer[3]={'\0'};
    fseek(fp, +3, SEEK_SET);
    fread(buffer,2,1,fp);
    printf("%s", buffer);
    strcpy(buffer,tag.version);
    printf("Version_id : %s\n", tag.version);
}

void album(FILE *fp)
{
    char buffer[30] = {'\0'};
    fseek(fp, +30, SEEK_SET);

    fread(buffer,4,1,fp);
    if(strcmp(buffer, "TALB") == 0)
    {
	fseek(fp, +41, SEEK_SET);
	memset(buffer,'\0',30);
	fread(buffer,21,1,fp);
	strcpy(buffer,tag.album);
	printf("Album : %s\n", tag.album);
    }
}


void title(FILE *fp)
{
    char buffer[30] = {'\0'};
    fseek(fp, +62, SEEK_SET);

    fread(buffer,4,1,fp);
    if(strcmp(buffer, "TIT2") == 0)
    {
	fseek(fp, +73, SEEK_SET);
	memset(buffer,'\0',30);
	//printf("buffer content is %s", buffer);
	fread(buffer,15,1,fp);
	strcpy(buffer,tag.title);
	printf("Title : %s\n", tag.title);
    }
}

void artist(FILE *fp)
{
    char buffer[30] = {'\0'};
    fseek(fp, +88, SEEK_SET);

    fread(buffer,4,1,fp);
    if(strcmp(buffer, "TPE1") == 0)
    {
	fseek(fp, +99, SEEK_SET);
	memset(buffer,'\0',30);
	fread(buffer,13,1,fp);
	strcpy(buffer,tag.artist);
	printf("Artist : %s\n", tag.artist);
    }
}

void year(FILE *fp)
{
    char buffer[4] = {'\0'};
    fseek(fp, +88, SEEK_SET);

    fread(buffer,4,1,fp);
    if(strcmp(buffer, "TYER") == 0)
    {
	fseek(fp, +99, SEEK_SET);
	memset(buffer,'\0',4);
	fread(buffer,4,1,fp);
	strcpy(buffer,tag.year);
	printf("Year : %s\n", tag.year);
    }
}
