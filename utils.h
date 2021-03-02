#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define FILE_NAME "estudiantes.txt"
#define g_nSTUDENTS 15
#define g_MAXNOTE 10

#define pathPA "./pa"
#define classPA "PA"

#define pathPB "./pb"
#define classPB "PB"

#define pathPC "./pc"
#define classPC "PC"

#define model_A "MODELOA.pdf"
#define model_B "MODELOB.pdf"
#define model_C "MODELOC.pdf"

#define P_READ 0
#define P_WRITE 1

enum ExamModel {A,B,C};

struct Estudiantes{
    char dni[9];
    char model;
    int note;
};