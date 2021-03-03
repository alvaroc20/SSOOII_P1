#ifdef __UTILS_H__
#define __UTILS_H__

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define g_nSTUDENTS 15
#define g_MAXNOTE 10

#define pathPA "./exec/pa"
#define classPA "PA"

#define pathPB "./exec/pb"
#define classPB "PB"

#define pathPC "./exec/pc"
#define classPC "PC"

#define model_A "MODELOA.pdf"
#define model_B "MODELOB.pdf"
#define model_C "MODELOC.pdf"

#define P_READ 0
#define P_WRITE 1

#define DIR_STUDENTS "data/"
#define FILE_NAME "estudiantes.txt"
#define N_STUDENTS_DIR 50

enum ExamModel {A,B,C};

struct Estudiantes{
    char dni[9];
    char model;
    int note;
};

#endif