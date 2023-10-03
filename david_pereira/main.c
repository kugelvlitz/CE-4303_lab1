#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stb-master/stb_image.h"
#include "stb-master/stb_image_write.h"

// Define el tamaño del filtro Laplaciano
#define FILTER_SIZE 3

// Función para aplicar el filtro Laplaciano a una imagen dada
void applyLaplacianFilter(uint8_t* inputImage, uint8_t* outputImage, int width, int height) {
    int kernel[FILTER_SIZE][FILTER_SIZE] = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    };

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int sum = 0;
            for (int i = 0; i < FILTER_SIZE; i++) {
                for (int j = 0; j < FILTER_SIZE; j++) {
                    int pixelValue = inputImage[((y + i - 1) * width + (x + j - 1)) * 3];
                    sum += kernel[i][j] * pixelValue;
                }
            }
            sum = (sum < 0) ? 0 : ((sum > 255) ? 255 : sum); // Asegurar que los valores estén en el rango [0, 255]
            outputImage[(y * width + x) * 3] = (uint8_t)sum;
            outputImage[(y * width + x) * 3 + 1] = (uint8_t)sum;
            outputImage[(y * width + x) * 3 + 2] = (uint8_t)sum;
        }
    }
}

int main() {
    // Cargar la imagen original
    int width, height, channels;
    uint8_t* inputImage = stbi_load("input_image.jpg", &width, &height, &channels, 0);
    if (!inputImage) {
        printf("No se pudo cargar la imagen.\n");
        return 1;
    }

    // Crear una imagen de salida del mismo tamaño
    uint8_t* outputImage = (uint8_t*)malloc(width * height * channels);

    // Aplicar el filtro Laplaciano
    applyLaplacianFilter(inputImage, outputImage, width, height);

    // Guardar la imagen procesada
    stbi_write_jpg("output_image.jpg", width, height, channels, outputImage, 0);

    // Liberar memoria
    stbi_image_free(inputImage);
    free(outputImage);

    printf("Proceso completado. Imagen procesada guardada como 'output.png'\n");

    return 0;
}
