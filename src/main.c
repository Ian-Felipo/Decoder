#include "..\include\image.h"

int main()
{
    int image_dimension;
    // Abrir o arquivo quadtree binário
    QuadTree *qt = load_quadtree("outputneo.dat", &image_dimension);
    printf("A dimensão da imagem é: %d\n", image_dimension);
    if (qt == NULL)
    {
        return 1;
    }

    // Criar uma imagem
    int size = image_dimension;
    int **image = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        image[i] = (int *)malloc(size * sizeof(int));
    }

    // Preencher a imagem a partir da quadtree
    fill_image(qt, image);

    // Salvar a imagem PGM
    save_pgm_p5("teste_out.pgm", image, size, size);

    // Liberar memória
    for (int i = 0; i < size; i++)
    {
        free(image[i]);
    }
    free(image);
    free_quadtree(qt);

    return 0;
}