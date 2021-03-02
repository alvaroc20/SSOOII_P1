#include "utils.c"

/**************************************************************************
 * Project                : SSOOII Practice 1
 * 
 * 
 * Program Name           : pa.c
 * 
 * 
 * Author                 : Álvaro Cerdá
 * 
 * 
 * Date Created           : 17/02/2021
 * 
 * 
 * Description            : Create a subdirectory for each student with 
 *                          the student's DNI as name.
 * ************************************************************************/


/*************************** Process Management **************************/
int createDirectories(struct Estudiantes *p_student_list);
void signal_handler(int sig);
void install_signal_handler();


/*************************** Main Function **************************/

int main() {
  install_signal_handler();

  struct Estudiantes *p_student_list;
  p_student_list = (struct Estudiantes*) malloc(g_nSTUDENTS * sizeof(struct Estudiantes));
  p_student_list = readEstudiantes(p_student_list);

  createDirectories(p_student_list);

  printf("[PA %d]: terminates.\n", getpid());

  return EXIT_SUCCESS;
}



/*************************** Process Management **************************/
/*Creation of directories according to the DNIs we obtain from the file.*/
int createDirectories(struct Estudiantes *p_student_list)
{
  char buffer[1024];
  struct stat st;
  int i;

  for(i=0; i < g_nSTUDENTS; i++){
    if (stat(p_student_list[i].dni, &st) == -1)
   {
      mkdir(p_student_list[i].dni, 0755);
   }
  }
  return EXIT_SUCCESS;
}

void signal_handler(int sig)
{
   printf("[PA %d]: terminated (SIGINT).\n", getpid());
   exit(EXIT_SUCCESS);
}


void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "[PA %d]: Error installing handler: %s.\n", 
	     getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
    }
}


