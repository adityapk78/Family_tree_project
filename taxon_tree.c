# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
} Taxon;

Taxon *create_taxon(const char *name, int lifespan){
    Taxon *taxon= malloc (sizeof (Taxon));
    if (taxon == NULL){
        printf("memory allocation failed!");
        return NULL;
    }
    strcpy (taxon->name, name);
    taxon->lifespan = lifespan;
    taxon->parent_group = NULL;
    return taxon;
}

void read_taxon_info(const char *label, char *name_out, int *lifespan_out){
    printf("Enter the name of species1:");
    scanf("%s", name_out);
    printf("Enter the lifespan");
    scanf("%d", lifespan_out);

}

void link_parent(Taxon *species, Taxon *Panthera, Taxon *Felis){
    species->parent_group = Felis;
    species->parent_group = Panthera;

}


// void free_tree(Taxon *all_taxa[], int total_count){
//     for (int i=0; i<total_count; i++){
//         free(Taxon[i]);
//     }
// }


// int main(){
//     // // i need to check wheather it is createed or not
//     // char name;
//     // int lifespan;
//     char *a = create_taxon(name, lifespan);
//     // printf("taxon family", a->name, a->lifespan);

//     read_taxon_info(a->name, a->lifespan);
// }
