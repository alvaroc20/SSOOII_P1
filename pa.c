#include "utils.c"

/* 
Creacion de directorios segun los DNIs que obtenemos del fichero
*/
int createDirectories(struct Estudiantes *Student_list){
  char buffer[1024];
  struct stat st;
  int i;

  for(i=0; i < n_STUDENTS; i++){
    if (stat(Student_list[i].dni, &st) == -1)
   {
      mkdir(Student_list[i].dni, 0755);
   }
  }
  return EXIT_SUCCESS;
}

void signal_handler(int sig)
{
   printf("[PA %d] terminated (SIGINT).\n", getpid());
   exit(EXIT_SUCCESS);
}


void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "[PA %d] Error installing handler: %s.\n", 
	     getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[]) {
  install_signal_handler();

  struct Estudiantes *Student_list;
  Student_list = (struct Estudiantes*) malloc(n_STUDENTS * sizeof(struct Estudiantes));
  Student_list = readEstudiantes(Student_list);

  createDirectories(Student_list);

  printf("[PA %d] terminates.\n", getpid());

  return EXIT_SUCCESS;
}