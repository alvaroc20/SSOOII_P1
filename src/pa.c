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
void createDirStudent();


/*************************** Main Function **************************/

int main() {
  install_signal_handler();

  struct Estudiantes *p_student_list;
  p_student_list = (struct Estudiantes*) malloc(nSTUDENTS * sizeof(struct Estudiantes));
  p_student_list = readEstudiantes(p_student_list);

  createDirStudent(p_student_list);
  createDirectories(p_student_list);

  printf("[PA %d]: terminates.\n", getpid());

  return EXIT_SUCCESS;
}



/*************************** Process Management **************************/

/*Creates the data/ directory where all data generated during the programme is stored*/
void createDirStudent()
{
  struct stat st;

   if (stat(DIR_STUDENTS, &st) == -1)
   {
      mkdir(DIR_STUDENTS, 0755);
   }
}

/*Create a subdirectory for each student*/
int createDirectories(struct Estudiantes *p_student_list)
{
  char dir[N_STUDENTS_DIR];
  struct stat st;
  int i;

  for(i=0; i < nSTUDENTS; i++){
      strcpy(dir, DIR_STUDENTS);
      strcat(dir,p_student_list[i].dni);
    if (stat(dir, &st) == -1)
   {
      mkdir(dir, 0755);
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


