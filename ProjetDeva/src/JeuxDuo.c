#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------*//*Structures utilisées*//*------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------------------------------*/
#define Max 10
typedef char Tableau[Max][Max];
typedef struct {
    int nbBas;
    int nbHaut;
    int scoreJ1;
    int scoreJ2;
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
void initialisation_tableau(Tableau T){

    for (int i = 0; i <Max ; ++i) {
        for (int j = 0; j <Max; ++j) {
            T[i][j]='-';
        }
    }
}
void initialisation_affichage(Tableau T){
    printf("|_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_|\n",0,1,2,3,4,5,6,7,8,9);
    for (int i = 0; i <Max ; ++i) {
        for (int j = 0; j <Max; ++j) {
            printf("| %c |",T[i][j]);
        }
        printf("|_%d_|",i);
        printf("\n");
    }
}
void initialisation_damier(Tableau T,Pion *position){

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

/*---------------------------*//*Initialisation suppresion de pion*//*---------------------------*/
void initialisation_suppression_pion_teamBas(Tableau T, Pion *position,nombre *nbr){
    if (T[position->initial.x-1][position->initial.y-1]==position->teamHaut && T[position->initial.x-2][position->initial.y-2]=='-'){
        T[position->initial.x-1][position->initial.y-1]='-';
        nbr->nbHaut=nbr->nbHaut-1;
        nbr->scoreJ1=nbr->scoreJ1+50;
    }

    if (T[position->initial.x-1][position->initial.y+1]==position->teamHaut && T[position->initial.x-2][position->initial.y+2]=='-'){
        T[position->initial.x-1][position->initial.y+1]='-';
        nbr->nbHaut=nbr->nbHaut-1;
        nbr->scoreJ1=nbr->scoreJ1+50;
    }
}

void  initialisation_suppression_pion_teamHaut(Tableau T,Pion *position,nombre *nbr){
    if (T[position->initial.x+1][position->initial.y+1]==position->teamBas && T[position->initial.x+2][position->initial.y+2]=='-'){
        nbr->nbBas=nbr->nbBas-1;
        nbr->scoreJ2=nbr->scoreJ2+50;
    }
    if (T[position->initial.x+1][position->initial.y-1]==position->teamBas && T[position->initial.x+2][position->initial.y-2]=='-'){

        T[position->initial.x+1][position->initial.y-1]='-';
        nbr->nbBas=nbr->nbBas-1;
        nbr->scoreJ2=nbr->scoreJ2+50;
    }
}

/*---------------------------*//*Initialisation des déplacements des pions en bas du damier (Joueur 1)*//*---------------------------*/
int initialise_pion_a_droite_teamBas(Tableau T, Pion *position, nombre *nbr){
    if (T[position->initial.x][position->initial.y]==position->teamBas&&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamHaut && T[position->initial.x-2][position->initial.y+2]=='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamBas)
    {
        initialisation_suppression_pion_teamBas(T,position,nbr);
    }
    if (T[position->initial.x][position->initial.y]==position->teamBas&&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamHaut && T[position->initial.x-1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y+1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}

int initialise_pion_en_arrier_a_droite_teamBas(Tableau T, Pion *position){
    
    if (T[position->initial.x][position->initial.y]==position->teamBas &&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamHaut && T[position->initial.x+1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y+1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");

        return 0;
    }
    return 1;
}

int  initialise_pion_a_gauche_teamBas(Tableau T, Pion *position, nombre *nbr){
    if (T[position->initial.x][position->initial.y]==position->teamBas && position->initial.y-1>=0 && T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y-1]==position->teamHaut && T[position->initial.x-2][position->initial.y-2]=='-'&& T[position->initial.x-1][position->initial.y-1]!=position->teamBas)
    {
        initialisation_suppression_pion_teamBas(T,position,nbr);
    }
    if (T[position->initial.x][position->initial.y]==position->teamBas && position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y-1]!=position->teamHaut && T[position->initial.x-1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y-1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}

int  initialise_pion_en_arrier_a_gauche_teamBas(Tableau T, Pion *position){
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
int initialise_pion_a_droite_teamHaut(Tableau T, Pion *position, nombre *nbr){
     if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamHaut && T[position->initial.x+2][position->initial.y+2]=='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamBas)
    {
        initialisation_suppression_pion_teamHaut(T,position,nbr);
    }
    if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamHaut && T[position->initial.x+1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y+1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");

        return 0;
    }
    return 1;
}

int  initialise_pion_en_arrier_a_droite_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut&&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamHaut && T[position->initial.x-1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y+1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}

int initialise_pion_a_gauche_teamHaut(Tableau T, Pion *position, nombre *nbr){
      if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y-1]!=position->teamHaut && T[position->initial.x+2][position->initial.y-2]=='-' && T[position->initial.x+1][position->initial.y-1]!=position->teamBas)
    {
        initialisation_suppression_pion_teamHaut(T,position,nbr);
    }
    if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y-1]!=position->teamHaut && T[position->initial.x+1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y-1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}

int  initialise_pion_en_arrier_a_gauche_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut&&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y-1]!=position->teamHaut && T[position->initial.x-1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y-1]=position->teamHaut;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}


/*---------------------------*//*Choix déplacement*//*---------------------------*/
void choix_deplamcement_joueur1(Tableau T, Pion *position,nombre *nbr){
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
            if (initialise_pion_a_gauche_teamBas(T,position,nbr)==0){
                choix_deplamcement_joueur1(T,position,nbr);
            }
            break;
        case 2:
            initialisation_suppression_pion_teamBas(T,position,nbr);
            if (initialise_pion_a_droite_teamBas(T,position,nbr)==0){
                choix_deplamcement_joueur1(T,position,nbr);
            }
            initialisation_suppression_pion_teamBas(T,position,nbr);
            break;
        case 3:
            initialisation_suppression_pion_teamBas(T,position,nbr);
            if (initialise_pion_en_arrier_a_gauche_teamBas(T,position)==0){
                choix_deplamcement_joueur1(T,position,nbr);
            }
            break;
        case 4:
            initialisation_suppression_pion_teamBas(T,position,nbr);
            if (initialise_pion_en_arrier_a_droite_teamBas(T,position)==0){
                choix_deplamcement_joueur1(T,position,nbr);
            }
            break;
        default:
            printf("Vous n'avez pas rentre un nombre correct !\n");
            choix_deplamcement_joueur1(T,position,nbr);
            break;
    }
}
void choix_deplamcement_joueur2(Tableau T, Pion *position,nombre *nbr){
    int Menu;
    printf("Veuillez saisir les coordonnee (Joueurs 2) :\n");
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
            initialisation_suppression_pion_teamHaut(T,position,nbr);
            if (initialise_pion_a_gauche_teamHaut(T,position,nbr)==0){
                choix_deplamcement_joueur2(T,position,nbr);
            }
            break;
        case 2:
            initialisation_suppression_pion_teamHaut(T,position,nbr);
            if (initialise_pion_a_droite_teamHaut(T,position,nbr)==0){
                choix_deplamcement_joueur2(T,position,nbr);
            }
            break;
        case 3:
            initialisation_suppression_pion_teamHaut(T,position,nbr);
            if (initialise_pion_en_arrier_a_gauche_teamHaut(T,position)==0){
                choix_deplamcement_joueur2(T,position,nbr);
            }
            break;
        case 4:
            initialisation_suppression_pion_teamHaut(T,position,nbr);
            if (initialise_pion_en_arrier_a_droite_teamHaut(T,position)==0){
                choix_deplamcement_joueur2(T,position,nbr);
            }
            break;
        default:
            printf("Vous n'avez pas rentre un nombre correct !\n");
            break;
    }

    printf("\n\n");
}

/*---------------------------*//*Score*//*---------------------------*/
void Score(){
    nombre *score = NULL;
    FILE *fichier = NULL;
 
    fichier = fopen("Score.txt", "w");

    if (fichier != NULL && score != NULL )
    {
        fprintf(fichier,"=== Partie  === \n\n "); 
        fprintf(fichier,"pseudo    |    score\n");
        fprintf(fichier,"Joueur 1   |    %d\n", score->scoreJ1);
        fprintf(fichier,"Joueur 2   |    %d\n", score->scoreJ2);
        fclose(fichier);
    }
}
void affiche_score(){
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


void Partie_duo(char Joueur1, char Joueur2){
    Tableau T;
    nombre *nbr;
    Pion *position;
    position = (Pion*)malloc(sizeof(Pion));
    if (position!=NULL)
    {   position->teamBas=Joueur1;
        position->teamHaut=Joueur2;
        nbr=(nombre*)malloc(sizeof (nombre));
        if (nbr!=0){
            nbr->nbHaut=20;
            nbr->nbBas=20;
            initialisation_tableau(T);
            initialisation_damier(T,position);
            while (nbr->nbBas!=0 || nbr->nbHaut!=0){

                initialisation_affichage(T);
                choix_deplamcement_joueur1(T,position,nbr);
                system("cls");
                initialisation_affichage(T);
                choix_deplamcement_joueur2(T,position,nbr);
                system("cls");
            }
            Score();
            
        }free(nbr);
    }
    free(position);
    affiche_score();
}
