#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#define FILE_NAME "estudiantes.txt"
#define n_STUDENTS 15

#define pathPA "./pa"
#define classPA "PA"

enum ExamModel {A,B,C};

struct Estudiantes{
    char dni[9];
    char model;
    int note;
};