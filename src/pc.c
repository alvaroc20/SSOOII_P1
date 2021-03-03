#include "utils.c"
/**************************************************************************
 * Project                : SSOOII Practice 1
 * 
 * 
 * Program Name           : pc.c
 * 
 * 
 * Author                 : Álvaro Cerdá
 * 
 * 
 * Date Created           : 28/02/2021
 * 
 * 
 * Description            : 1) Perform the arithmetic mean of the tests 
 *                             already performed and send it via a pipeline to the manager.
 *                          2) Create a .txt file stating the grade you need 
 *                             to obtain a 5 average with the two tests.
 * ************************************************************************/



/*************************** Process Management **************************/
void signal_handler(int sig);
void install_signal_handler();
void sendByPipe(int fd, int av_score);
int averageScore(struct Estudiantes *p_student_list);
void putNoteInDir(char *dni, int note);
void gradebook(struct Estudiantes *p_student_list);
void check(char *argv[], int *fd);



/*************************** Main Function **************************/
int main(int argc, char *argv[]){
    int av_score;
    int fd;

    install_signal_handler();
    check(argv, &fd);

    struct Estudiantes *p_student_list;
    p_student_list = (struct Estudiantes*) malloc(g_nSTUDENTS * sizeof(struct Estudiantes));
    p_student_list = readEstudiantes(p_student_list);

    av_score = averageScore(p_student_list);
    sendByPipe(fd, av_score);
    gradebook(p_student_list);

    printf("[PC %d]: terminates.\n", getpid());
    return EXIT_SUCCESS;
}

/*************************** Process Management **************************/

void signal_handler(int sig)
{
   printf("[PC %d]: terminated (SIGINT).\n", getpid());
   exit(EXIT_SUCCESS);
}


void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "[PC %d]: Error installing handler: %s.\n", 
	     getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
    }
}

void sendByPipe(int fd, int av_score)
{
    
    char buffer[5];

    sprintf(buffer, "%d", av_score);
    if(write(fd, buffer, sizeof(buffer)) == -1){
        printf("Pipe writing error\n");
    }
}

int averageScore(struct Estudiantes *p_student_list)
{
    int i;
    int av_score = 0;

    for(i=0; i < g_nSTUDENTS; i++){
        av_score += p_student_list[i].note;
    }

    av_score /= g_nSTUDENTS;

    return av_score;
}

void putNoteInDir(char *dni, int note)
{
    FILE *f;
    
    char text[] = "La nota que debes obtener en este nuevo examen para superar la prueba es ";
    char dir[N_STUDENTS_DIR];

    sprintf(text, "%s%i", text, note);
    strcpy(dir, DIR_STUDENTS);
    strcat(dir, dni);
    strcat(dir, "/note.txt");
    
    f = fopen(dir, "wb");
    fputs(text, f);

    fclose(f);
}

void gradebook(struct Estudiantes *p_student_list)
{
    int neededNote, i;

    for(i=0; i < g_nSTUDENTS; i++){
        neededNote = g_MAXNOTE - p_student_list[i].note;
        putNoteInDir(p_student_list[i].dni, neededNote);
    }
}

void check(char *argv[], int *fd){
    *fd = atoi(argv[1]) ;
}

