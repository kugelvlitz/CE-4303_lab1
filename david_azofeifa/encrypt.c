#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Función para calcular la potencia modular (OldP^d % n)
uint16_t mod_pow(uint16_t base, uint16_t exponent, uint16_t modulus) {
    uint16_t result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int encrypt() {
    FILE *clave_privada = fopen("private_key.txt", "r");
    FILE *datos_pixels = fopen("pixels.txt", "r");
    FILE *datos_cifrados = fopen("encrypted.txt", "w");

    if (clave_privada == NULL || datos_pixels == NULL || datos_cifrados == NULL) {
        perror("Error al abrir archivos");
        return 1;
    }

    // Leer las claves privadas (d y n)
    uint16_t d, n;
    fscanf(clave_privada, "%hx %hx", &d, &n);

    uint16_t ancho, alto;
    fscanf(datos_pixels, "%hx,%hx", &ancho, &alto);

    // Cifrar y guardar los datos de píxeles
    uint16_t pixel;
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (fscanf(datos_pixels, "%hx,", &pixel) == 1) {
                uint16_t pixel_cifrado = mod_pow(pixel, d, n);
                fprintf(datos_cifrados, "%hx,", pixel_cifrado);
            } else {
                // error
                fprintf(datos_cifrados, "?,");
            }
        }
        fprintf(datos_cifrados, "\n");
    }

    fclose(clave_privada);
    fclose(datos_pixels);
    fclose(datos_cifrados);

    return 0;
}
