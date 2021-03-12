#include "utils.c"
/**************************************************************************
 * Project                : SSOOII Practice 1
 * 
 * 
 * Program Name           : demon.c
 * 
 * 
 * Author                 : Álvaro Cerdá
 * 
 * 
 * Date Created           : 12/03/2021
 * 
 * 
 * Description            : Performs a background backup every minute
 * 
 * 
 * End Proccess:          : ps aux 
 *                          kill -TERM pid
 * ************************************************************************/


/*************************** Process Management **************************/
void backup();


/*************************** Main Function **************************/
int main()
{   
    while(1){
        backup();
        sleep(60);
    }

    return EXIT_SUCCESS;
}


/*************************** Process Management **************************/
int checkFile()
{
    FILE *f;

    if(f = fopen(DIR_STUDENTS, "r")){
        fclose(f);
        return 1;
    }
    
    return 0;
}

void backup()
{
    char command[512];
    char dirs[128];

    if(checkFile()){
        snprintf(dirs, sizeof (dirs), "%s %s %s", DIR_STUDENTS, DIR_INCLUDES, DIR_SRC);
    }else{
        snprintf(dirs, sizeof (dirs), "%s %s", DIR_INCLUDES, DIR_SRC);
    }

    snprintf(command, sizeof(command), "cp -r -u --force --backup=numbered %s %s", dirs, DIR_BACKUP);
    system(command);
}