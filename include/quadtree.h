#include <stdlib.h>
#include "square.h"
#include "bits.h"

typedef struct QuadTree
{
    Rectangle boundary;
    int pixel_value;   // Valor médio dos pixels na região
    int is_leaf;       // Flag para indicar se é folha
    struct QuadTree *northwest;
    struct QuadTree *northeast;
    struct QuadTree *southwest;
    struct QuadTree *southeast;
} QuadTree;

QuadTree *load_quadtree_bin(FILE *, int, int, int);

QuadTree *load_quadtree(const char *, int *);

void free_quadtree(QuadTree *);