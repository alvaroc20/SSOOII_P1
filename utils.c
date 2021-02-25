#include "utils.h"

/* 
Apertura de fichero y lectura de los datos que contiene 
*/

struct Estudiantes* readEstudiantes(struct Estudiantes* Student_list){
    FILE *f = fopen(FILE_NAME, "r");
    int i;


     if (f==NULL)
    {
        fprintf(stderr, "Error to open txt\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i < n_STUDENTS; i++)
    {
        if(fscanf(f, "%s %c %i\n", Student_list[i].dni, &Student_list[i].model, &Student_list[i].note) == EOF)
        {
            exit(EXIT_FAILURE);
        }
    }

    fclose(f);
   
   return Student_list;
}