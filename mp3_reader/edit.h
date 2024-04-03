#ifndef MP3_H
#define MP3_H
#define ERROR -1
#define SUCCESS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validate_inputs(char **argv);

typedef struct tag
{
    char version[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char content_type[30];
}mp3tag_info;

void edit_mp3(char **argv);

  void edit_content_type(FILE *fp, char **argv);
  void edit_album(FILE *fp, char **argv);
  void edit_artist(FILE *fp, char **argv);
  void edit_year(FILE *fp, char **argv);
  void edit_title(FILE *fp, char **argv);
#endif
