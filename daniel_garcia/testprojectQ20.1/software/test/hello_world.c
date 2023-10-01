/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "system.h"
int main()
{
	// Definir la dirección de memoria
	    char *direccion = (char *)NEW_SDRAM_CONTROLLER_0_BASE;

	    // Cadena que deseas escribir
	    char cadena[] = "Hola mundo";

	    // Copiar la cadena en la dirección de memoria byte por byte
	    int i;
	    for (i = 0; cadena[i] != '\0'; i++) {
	        direccion[i] = cadena[i];
	    }

	    // Asegurarse de agregar el carácter nulo al final para que sea una cadena válida
	    direccion[i] = '\0';

	    // Verificar que la cadena se haya escrito en la dirección de memoria

	    return 0;
}
