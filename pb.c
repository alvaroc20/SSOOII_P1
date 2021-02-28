#include "utils.c"

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

char *modelExam(char model){

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


void copyExams(struct Estudiantes *Student_list){

    int i = 0;
    char *exam;
    char command[512];

    for(i=0; i < n_STUDENTS; i++){
        exam = modelExam(Student_list[i].model);
        snprintf(command, sizeof (command), "/bin/cp %s %s", exam, Student_list[i].dni);
        system(command);
    }
}

/*************************** Main Function **************************/

int main(){
    install_signal_handler();


    struct Estudiantes *Student_list;
    Student_list = (struct Estudiantes*) malloc(n_STUDENTS * sizeof(struct Estudiantes));
    Student_list = readEstudiantes(Student_list);

    copyExams(Student_list);

    printf("[PB %d]: terminates.\n", getpid());
    return EXIT_SUCCESS;
}