#include "utils.c"
/**************************************************************************
 * Project                : SSOOII Practice 1
 * 
 * 
 * Program Name           : pb.c
 * 
 * 
 * Author                 : Álvaro Cerdá
 * 
 * 
 * Date Created           : 27/02/2021
 * 
 * 
 * Description            : Extract the model of the student's exam and 
 *                          copy the .pdf model corresponding to each DNI.
 * ************************************************************************/


/*************************** Process Management **************************/
void signal_handler(int sig);
void install_signal_handler();
char *modelExam(char model);
void copyExams(struct Estudiantes *p_student_list);


/*************************** Main Function **************************/

int main(){
    install_signal_handler();


    struct Estudiantes *p_student_list;
    p_student_list = (struct Estudiantes*) malloc(nSTUDENTS * sizeof(struct Estudiantes));
    p_student_list = readEstudiantes(p_student_list);

    copyExams(p_student_list);

    printf("[PB %d]: terminates.\n", getpid());
    return EXIT_SUCCESS;
}

/*************************** Process Management **************************/

void signal_handler(int sig)
{
   printf("[PB %d]: terminated (SIGINT).\n", getpid());
   exit(EXIT_SUCCESS);
}


void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "[PB %d]: Error installing handler: %s.\n", 
	     getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
    }
}

char *modelExam(char model)
{

    char *exam;
    switch(model){
        case 'A':
            exam = model_A;
            break;
        case 'B':
            exam = model_B;
            break;
        case 'C':
            exam = model_C;
            break;
    }
    return exam;
}

/*Concatenates the DNI to the directory and copies the exam using command*/
void copyExams(struct Estudiantes *p_student_list)
{

    int i = 0;
    char *exam;
    char command[512];
    char dir[N_STUDENTS_DIR];

    for(i=0; i < nSTUDENTS; i++){
        exam = modelExam(p_student_list[i].model);

        strcpy(dir,DIR_STUDENTS);
        strcat(dir,p_student_list[i].dni);
        strcat(dir,"/");

        snprintf(command, sizeof (command), "/bin/cp %s %s", exam, dir);
        system(command);
    }
}

