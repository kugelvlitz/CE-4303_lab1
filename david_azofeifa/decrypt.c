#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Función para aplicar la operación de exponenciación modular (a^b mod n)
uint16_t mod_pow(uint16_t a, uint16_t b, uint16_t n) {
    uint16_t result = 1;
    a = a % n;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % n;
        }
        a = (a * a) % n;
        b = b / 2;
    }
    return result;
}

int decifrar() {
    FILE *input_file = fopen("encrypted.txt", "r");
    if (input_file == NULL) {
        perror("Error al abrir el archivo de entrada");
        return 1;
    }

    FILE *output_file = fopen("decrypted.txt", "w");
    if (output_file == NULL) {
        perror("Error al abrir el archivo de salida");
        fclose(input_file);
        return 1;
    }

    FILE *keys_file = fopen("rsa_keys.txt", "r");
    if (keys_file == NULL) {
        perror("Error al abrir el archivo de claves");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    // Leer las claves RSA desde el archivo
    char d_hex[5], n_hex[5];
    fscanf(keys_file, "%s,%s", d_hex, n_hex);
    uint16_t d = strtol(d_hex, NULL, 16);
    uint16_t n = strtol(n_hex, NULL, 16);

    // Padding
    if (strlen(d_hex) < 4) {
        d |= 1 << 15;  // Asegura que d tenga 16 bits
    }

    // Leer dimensiones de la imagen
    int width, height;
    fscanf(input_file, "%d,%d", &width, &height);
    fprintf(output_file, "%d,%d\n", width, height);

    // Leer y descifrar los valores de píxeles
    uint16_t encrypted_pixel;
    while (fscanf(input_file, "%hu,", &encrypted_pixel) != EOF) {
        // Descifrar el valor del píxel
        uint16_t decrypted_pixel = mod_pow(encrypted_pixel, d, n);
        fprintf(output_file, "%hu,", decrypted_pixel);
    }

    // Cerrar los archivos
    fclose(input_file);
    fclose(output_file);
    fclose(keys_file);

    return 0;
}
