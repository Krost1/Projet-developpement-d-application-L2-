#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
/*---------------------------------------------*//*Structures utilisées*//*------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
#define Max 10
typedef char Tableau[Max][Max];
typedef struct {
    int nbBas;
    int nbHaut;
    int score;
    int scoreordinateur;
}nombre;
typedef struct{
    int x;
    int y;
}Position;
typedef struct{
    char teamHaut;
    char teamBas;
    Position initial;
}Pion;

/*---------------------------------------------*//*Fonction utilisées*//*------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------*//*Initialisation du plateau et du damier*//*---------------------------*/
void tab(Tableau T){

    for (int i = 0; i <Max ; ++i) {
        for (int j = 0; j <Max; ++j) {
            T[i][j]='-';
        }
    }
}
void afficher(Tableau T){
    printf("|_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_|\n",0,1,2,3,4,5,6,7,8,9);
    for (int i = 0; i <Max ; ++i) {
        for (int j = 0; j <Max; ++j) {
            printf("| %c |",T[i][j]);
        }
        printf("|_%d_|",i);
        printf("\n");
    }
}
void dam(Tableau T,Pion *position){

    for (int i = 0; i <4; i+=2)
    {
        for (int j = 1; j <=Max; j+=2)
        {
            T[i][j]=position->teamHaut;
        }
    }
    for (int i = 1; i <4; i+=2)
    {
        for (int j = 0; j <Max; j+=2)
        {
            T[i][j]=position->teamHaut;
        }
    }
    for (int i = 6; i <Max; i+=2)
    {
        for (int j = 1; j <Max; j+=2)
        {
            T[i][j]=position->teamBas;
        }
    }
    for (int i = 7; i <=Max; i+=2)
    {
        for (int j = 0; j <Max; j+=2)
        {
            T[i][j]=position->teamBas;
        }
    }


}

/*---------------------------*//*Initialisation des déplacements des pions en bas du damier (Joueur 1)*//*---------------------------*/
int pion_droite_teamBas(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamBas&&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamHaut && T[position->initial.x-1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y+1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}
int pion_en_arrier_droite_teamBas(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamBas &&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamHaut && T[position->initial.x+1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y+1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");

        return 0;
    }
    return 1;
}
int pion_gauche_teamBas(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamBas&&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y-1]!=position->teamHaut && T[position->initial.x-1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y-1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}
int pion_en_arrier_gauche_teamBas(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamBas &&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y-1]!=position->teamHaut && T[position->initial.x+1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y-1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}

/*---------------------------*//*Initialisation des déplacements des pions en haut du damier (Joueur 2)*//*---------------------------*/
int pion_droite_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamHaut && T[position->initial.x+1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y+1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");

        return 0;
    }
    return 1;
}
int pion_en_arrier_droite_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut&&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamHaut && T[position->initial.x-1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y+1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}
int pion_gauche_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y-1]!=position->teamHaut && T[position->initial.x+1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y-1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}
int pion_en_arrier_gauche_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut&&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y-1]!=position->teamHaut && T[position->initial.x-1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y-1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}


/*---------------------------*//*Initialisation suppresion de pion*//*---------------------------*/
void suppr_pion_teamBas(Tableau T, Pion *position,nombre *nbr){
    if (T[position->initial.x-1][position->initial.y-1]==position->teamHaut && T[position->initial.x-2][position->initial.y-2]=='-'){
        T[position->initial.x-1][position->initial.y-1]='-';
        nbr->nbHaut=nbr->nbHaut-1;
        nbr->score=nbr->score+50;
    }

    if (T[position->initial.x-1][position->initial.y+1]==position->teamHaut && T[position->initial.x-2][position->initial.y+2]=='-'){
        T[position->initial.x-1][position->initial.y+1]='-';
        nbr->nbHaut=nbr->nbHaut-1;
        nbr->score=nbr->score+50;
    }
}

void suppr_pion_teamHaut(Tableau T,Pion *position,nombre *nbr){
    if (T[position->initial.x+1][position->initial.y+1]==position->teamBas && T[position->initial.x+2][position->initial.y+2]=='-'){
        nbr->nbBas=nbr->nbBas-1;
        nbr->score=nbr->score+50;
    }
    if (T[position->initial.x+1][position->initial.y-1]==position->teamBas && T[position->initial.x+2][position->initial.y-2]=='-'){

        T[position->initial.x+1][position->initial.y-1]='-';
        nbr->nbBas=nbr->nbBas-1;
        nbr->score=nbr->score+50;
    }
}


/*---------------------------*//*Choix déplacement*//*---------------------------*/
void deplace_joueur1(Tableau T, Pion *position,nombre *nbr){
    int Menu;
    printf("Veuillez saisir les coordonnee (Joueurs 1):\n");
    scanf("%d",&position->initial.x);
    scanf("%d",&position->initial.y);
    printf("=== Choix du deplacement ===\n\n");
    printf("1. Gauche\n");
    printf("2. Droite\n");
    printf("3. En arrirer a Gauche\n");
    printf("4. En arrirer a Droite\n");
    scanf("%d", &Menu);

    printf("\n");

    switch (Menu)
    {
        case 1:
            suppr_pion_teamBas(T,position,nbr);
            if (pion_gauche_teamBas(T,position)==0){
                deplace_joueur1(T,position,nbr);
            }
            break;
        case 2:
            suppr_pion_teamBas(T,position,nbr);
            if (pion_droite_teamBas(T,position)==0){
               deplace_joueur1(T,position,nbr);
            }
            suppr_pion_teamBas(T,position,nbr);
            break;
        case 3:
            suppr_pion_teamBas(T,position,nbr);
            if (pion_en_arrier_gauche_teamBas(T,position)==0){
                deplace_joueur1(T,position,nbr);
            }
            break;
        case 4:
            suppr_pion_teamBas(T,position,nbr);
            if (pion_en_arrier_droite_teamBas(T,position)==0){
                deplace_joueur1(T,position,nbr);
            }
            break;
        default:
            printf("Vous n'avez pas rentre un nombre correct !\n");
           deplace_joueur1(T,position,nbr);
            break;
    }

    printf("\n\n");
}

void deplac_ordi(Pion*position){
    position->initial.x=rand() % 9;
    position->initial.y=rand() % 9;
}
void deplac_joueur2(Tableau T, Pion *position,nombre *nbr){
    srand(time(NULL));
    position->initial.x=rand() % 9;
    position->initial.y=rand() % 9;
    printf("=== Choix du deplacement ===\n\n");
    int z;
    z = rand()%4;
    if (z==1){
        printf("Gauche");
        suppr_pion_teamHaut(T,position,nbr);
        while (pion_gauche_teamHaut(T,position)==0){
            deplac_ordi(position);
        }
    }
    if (z==2){
        printf("Droite");
        suppr_pion_teamHaut(T,position,nbr);
        while (pion_droite_teamHaut(T,position)==0){
            deplac_joueur2(T,position,nbr);
        }
    }
    if (z==3){
        printf("En arriere a Gauche");
        suppr_pion_teamHaut(T,position,nbr);
        while (pion_en_arrier_gauche_teamHaut(T,position)==0){
            deplac_joueur2(T,position,nbr);
        }
    }
    if (z==4){
        printf("En arriere a Droite");
        suppr_pion_teamHaut(T,position,nbr);
        while (pion_en_arrier_droite_teamHaut(T,position)==0){
            deplac_joueur2(T,position,nbr);
        }
    }

    printf("\n\n");
}


/*---------------------------*//*Score*//*---------------------------*/
void Score3(){
    nombre *score = NULL;
    FILE *fichier = NULL;
 
    fichier = fopen("Score.txt", "w");

    if (fichier != NULL && score != NULL )
    {
        fprintf(fichier,"=== Partie  === \n\n "); 
        fprintf(fichier,"pseudo    |    score\n");
        fprintf(fichier,"Joueur    |    %d\n", score->score);
        fprintf(fichier,"ordinateur |    %d\n", score->scoreordinateur);
        fclose(fichier);
    }
}
void affiche_score3(){
    FILE* fichier = NULL;
    int caractereActuel = 0;
 
    fichier = fopen("test.txt", "r");
 
    if (fichier != NULL)
    {
      
        do
        {
            caractereActuel = fgetc(fichier); 
            printf("%c", caractereActuel);
        } while (caractereActuel != EOF); 
 
        fclose(fichier);
    }
 
}

/*---------------------------------------------*//*Fonction Principale*//*------------------------------------------------------------*/




void  Mode_Normale(char Joueur1, char Joueur2){
    int compteur =240;
    Tableau T;
    nombre *nbr;
    Pion *position;
    printf("Vous avez %d tours pour battre l'ordinateur\n",compteur);
    position = (Pion*)malloc(sizeof(Pion));
    if (position!=NULL)
    {   position->teamBas=Joueur1;
        position->teamHaut=Joueur2;
        nbr=(nombre*)malloc(sizeof (nombre));
        if (nbr!=0){
            nbr->nbHaut=20;
            nbr->nbBas=20;
            tab(T);
            dam(T,position);
            while (compteur!=0||nbr->nbBas!=0 || nbr->nbHaut!=0){
                afficher(T);
                deplace_joueur1(T,position,nbr);
                deplac_joueur2(T,position,nbr);
                printf("\n");
                compteur=compteur-1;
                printf("Il vous reste %d tours\n",compteur);
                  system("cls");
            }
            Score3();
        }free(nbr);
    }
    free(position);
    affiche_score3();
}
