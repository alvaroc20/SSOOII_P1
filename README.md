# SSOOII_P1
Práctica 1 de la asignatura SSOOII tratando llamadas al sistema y señales.  

## Manual de Usuario  
Para la compilación y posterior funcionamiento de la práctica he creado un Makefile.

**Crear directorios**  
Se requieren ciertos directorios para guardar los códigos objeto, los archivos ejecutables y el backup, que podremos generar mediante `make dirs`.

**Compilar**  
Para compilar todos los procesos podremos hace uso de `make all` (incluye dirs), donde compilará *manager, pa, pb, pc, pd, demon*. Si solo se desea compilar uno de ellos, entonces podremos hacer uso de `make opcion` donde *opcion* es uno de los nombres de los procesos citados en cursiva anteriormente.

**Ejecutar**  
Para ejecutar el programa, previamente deben estar compilados todos los procesos, solo ejecutaremos el proceso *manager* que se encargará de hacer llamadas a todos los procesos necesarios mediante `make run`. Al ejecutar este comando, también realiza la llamada al proceso demonio que trabajará en segundo plano y solo podremos "matar" desde el intérprete de comandos.

Para realizar esta última acción, podremos ver los procesos abiertos mediante `ps aux` donde veremos el PID de nuestro proceso demonio, y mediante `kill -TERM PID` donde *PID* es el PID visto anteriormente, podremos deshacernos de él.

**Limpieza de archivos**  
Para eliminar todos los archivos generados por el programa (data/), los archivos que se crean como ejecutable o objeto (exec/ y obj/) y el archivo log.txt haremos uso de `make clean`.

Por último, si queremos eliminar la carpeta donde se guardan los archivos de Backup, haremos uso de `make cleanBackup`.

## Versiones  
### v1.1  

**Utils**  
Creada estructura de un Estudiante con DNI, modelo de examen y nota.  
Definido el modelo de examen como A, B ó C mediante enumeración.  

**PA**   
Apertura y lectura del fichero "estudiantes.txt".  
Creados subdirectorios para cada uno de los estudiantes con DNI como id o nombre del subdirectorio correspondiente a cada uno de ellos.  
Instalado el manejador de señal.  

**Manager**  
Instalado el manejador de señal.  

### v1.2  

**Utils**  
Definida la ruta y clase PA.  

**Manager**  
Creado el proceso PA.  
Añadido fichero log.txt  


### v2.1  
**Utils**  
Añadidos los modelos PDFs.  

**PB**  
Instalado el manejador de señal.  
Copia los exámenes en el subdirectorio que corresponda al DNI del estudiante.  

**Manager**  
Creado el proceso PB y PC además de la espera.  

### v3.1  
**PC**  
Creado el PC por completo.   

**Manager**  
Creada la tubería necesaria para comunicarse con el proceso C.  

*Mejora de legibilidad en todos los procesos y manager*  

### v3.2  
Creación de carpetas src/ e include/ para la mejora de organización de los archivos creados, además de una carpeta data/ donde se almacenarán los datos que realizará el programa. Por último, se crean las carpetas exec/ y obj/. Con esta actualización queda todo de manera más organizada.  

Añado Makefile para automatizar la compilación y puesta en marcha del programa.  

**Utils**  
Añadido if-def

### v4.1  
**PD**  
Creado y finalizado el PD eliminando el directorio donde se almacenan los datos de los estudiantes (/data) por completo.  

### v5.1  
**Demon**  
Creado el proceso demonio que funcionará en segundo plano realizando copias en la carpeta backup de todos los archivos del programa (a excepción del fichero txt).  
Para ver todos los procesos podemos usar `ps aux`. Una vez veamos el PID al que corresponde el proceso demon, entonces podremos matar el proceso mediante `kill -TERM PID`.

### v5.2  
Correción de pequeños errores.