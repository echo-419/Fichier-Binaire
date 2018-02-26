#include <stdio.h>
#include <stdlib.h>
#define TAILLE 15

typedef struct ddn{

    int j;
    int m;
    int A;
                    }ddn;

typedef struct cid{

    int NumC;
    char* Nom;
    char* prenom;
    char sexe;
    ddn naissance;
    char* ville;
                        }cid;


void setcarte(cid carte,FILE * pFile);
void read_carte(FILE * pFile);


int main()
{
    int rep;
    cid carte;
    FILE * pFile;

    printf("BONJOUR\n");

    do{
        printf("Voulez-vous entrer une carte (1) ou voir les cartes (2) ? Entrer (0) pour quitter\n");
        scanf("%d",&rep);
        if (rep==1){
                setcarte(carte,pFile);

        }
        if (rep==2){
                    read_carte(pFile);

        }
        printf("\n");
        //system("cls");
    }while(rep!=0);




    return 0;
}


void setcarte(cid carte,FILE * pFile){

            printf("Entrer le numero de carte\n");
            scanf("%d",&carte.NumC);

            printf("Entrer le nom\n");
            carte.Nom=(char*)malloc(sizeof(char)*TAILLE);
            scanf("%s",carte.Nom);

            printf("Entrer le prenom\n");
            carte.prenom=(char*)malloc(sizeof(char)*TAILLE);
            scanf("%s",carte.prenom);

            printf("Entrer le sexe\n");
            scanf("%s",&carte.sexe);

            printf("Entrer le jour, puis le mois, puis l annee de naissance\n");
            scanf("%d",&carte.naissance.j);
            scanf("%d",&carte.naissance.m);
            scanf("%d",&carte.naissance.A);

            printf("Entrer la ville\n");
            carte.ville=(char*)malloc(sizeof(char)*TAILLE);
            scanf("%s",carte.ville);

            if (pFile == NULL){
                pFile = fopen ("carte_bin.txt","wb");
            }else{
                pFile = fopen ("carte_bin.txt","ab");
            }

            fwrite (&carte.NumC , sizeof(int), sizeof(carte.NumC), pFile);
            fwrite (&carte.Nom , sizeof(char), sizeof(carte.Nom), pFile);
            fwrite (&carte.prenom , sizeof(char), sizeof(carte.prenom), pFile);
            fwrite (&carte.sexe , sizeof(char), sizeof(carte.sexe), pFile);
            fwrite (&carte.naissance.j , sizeof(int), sizeof(carte.naissance.j), pFile);
            fwrite (&carte.naissance.m , sizeof(int), sizeof(carte.naissance.m), pFile);
            fwrite (&carte.naissance.A , sizeof(int), sizeof(carte.naissance.A), pFile);
            fwrite (&carte.ville , sizeof(char), sizeof(carte.ville), pFile);

            fclose (pFile);

            printf("%d,%s,%s,%c,%d/%d/%d,%s",carte.NumC,carte.Nom,carte.prenom,carte.sexe,carte.naissance.j,carte.naissance.m,carte.naissance.A,carte.ville);

            free(carte.prenom);
            free(carte.ville);
            free(carte.Nom);
}

void read_carte(FILE * pFile){

    cid*carte=malloc(sizeof(cid));
    long lSize;
    char * buffer;
    size_t result;
    int i;

    pFile = fopen ( "carte_bin.txt" , "rb" );
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);

    buffer=(char*)malloc(sizeof(cid)*lSize);


    result=fread (buffer,1,lSize,pFile);
    printf("%d\n",result);

    if (result!=0){
        for(i=0;i<=result;i++){
        printf("%",buffer[i]);
        }
    }


    fclose(pFile);
    free (buffer);
    free (carte);

}
