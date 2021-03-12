# SSOOII_P1
Práctica 1 de la asignatura SSOOII tratando llamadas al sistema y señales.  


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

