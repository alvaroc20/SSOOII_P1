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
 * Description            : Completely deletes the directory containing 
 *                          the data generated from students
 * ************************************************************************/



/*************************** Process Management **************************/
void signal_handler(int sig);
void install_signal_handler();
void removeAll();


/*************************** Main Function **************************/

int main() 
{
  install_signal_handler();

  removeAll();
  printf("[PD %d]: terminates.\n", getpid());

  return EXIT_SUCCESS;
}



/*************************** Process Management **************************/
void signal_handler(int sig)
{
   printf("[PD %d]: terminated (SIGINT).\n", getpid());
   exit(EXIT_SUCCESS);
}


void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "[PD %d]: Error installing handler: %s.\n", 
	     getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
    }
}


void removeAll()
{
  char command[30];

  snprintf(command, sizeof (command), "rm -r %s", DIR_STUDENTS);
  system(command);
}