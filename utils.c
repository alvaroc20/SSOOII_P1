#include "utils.h"

/* 
Apertura de fichero y lectura de los datos que contiene 
*/

struct Estudiantes* readEstudiantes(struct Estudiantes* p_student_list){
    FILE *f = fopen(FILE_NAME, "r");
    int i;


     if (f==NULL)
    {
        fprintf(stderr, "Error to open txt\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i < g_nSTUDENTS; i++)
    {
        if(fscanf(f, "%s %c %i\n", p_student_list[i].dni, &p_student_list[i].model, &p_student_list[i].note) == EOF)
        {
            exit(EXIT_FAILURE);
        }
    }

    fclose(f);
   
   return p_student_list;
}