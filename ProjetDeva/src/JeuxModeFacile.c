#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void tableau(Tableau T){

    for (int i = 0; i <Max ; ++i) {
        for (int j = 0; j <Max; ++j) {
            T[i][j]='-';
        }
    }
}
void affichage(Tableau T){
    printf("|_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_||_%d_|\n",0,1,2,3,4,5,6,7,8,9);
    for (int i = 0; i <Max ; ++i) {
        for (int j = 0; j <Max; ++j) {
            printf("| %c |",T[i][j]);
        }
        printf("|_%d_|",i);
        printf("\n");
    }
}
void damier(Tableau T,Pion *position){

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
int pion_a_droite_teamBas(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamBas&&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamHaut && T[position->initial.x-1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y+1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}
int pion_en_arrier_a_droite_teamBas(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamBas &&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamHaut && T[position->initial.x+1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y+1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");

        return 0;
    }
    return 1;
}
int pion_a_gauche_teamBas(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamBas&&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y-1]!=position->teamHaut && T[position->initial.x-1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y-1]=position->teamBas;
    } else{
        printf("Deplacement impossible\n");
        return 0;
    }
    return 1;
}
int pion_en_arrier_a_gauche_teamBas(Tableau T, Pion *position){
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
int pion_a_droite_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y+1]!=position->teamHaut && T[position->initial.x+1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y+1]=position->teamHaut;
    } else{
        
        return 0;
    }
    return 1;
}
int pion_en_arrier_a_droite_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut&&position->initial.y+1<Max&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y+1]!=position->teamHaut && T[position->initial.x-1][position->initial.y+1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y+1]=position->teamHaut;
    } else{
        
        return 0;
    }
    return 1;
}
int pion_a_gauche_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut &&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x+1][position->initial.y-1]!=position->teamHaut && T[position->initial.x+1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x+1][position->initial.y-1]=position->teamHaut;
    } else{
        
        return 0;
    }
    return 1;
}
int pion_en_arrier_a_gauche_teamHaut(Tableau T, Pion *position){
    if (T[position->initial.x][position->initial.y]==position->teamHaut&&position->initial.y-1>=0&&T[position->initial.x][position->initial.y]!='-' && T[position->initial.x-1][position->initial.y-1]!=position->teamHaut && T[position->initial.x-1][position->initial.y-1]!=position->teamBas){
        T[position->initial.x][position->initial.y]='-';
        T[position->initial.x-1][position->initial.y-1]=position->teamHaut;
    } else{
        
        return 0;
    }
    return 1;
}


/*---------------------------*//*Initialisation suppresion de pion*//*---------------------------*/
void suppression_pion_teamBas(Tableau T, Pion *position,nombre *nbr){
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

void suppression_pion_teamHaut(Tableau T,Pion *position,nombre *nbr){
    if (T[position->initial.x+1][position->initial.y+1]==position->teamBas && T[position->initial.x+2][position->initial.y+2]=='-'){
        nbr->nbBas=nbr->nbBas-1;
        nbr->score=nbr->scoreordinateur+50;
    }
    if (T[position->initial.x+1][position->initial.y-1]==position->teamBas && T[position->initial.x+2][position->initial.y-2]=='-'){

        T[position->initial.x+1][position->initial.y-1]='-';
        nbr->nbBas=nbr->nbBas-1;
        nbr->score=nbr->scoreordinateur+50;
    }
}

/*---------------------------*//*Score*//*---------------------------*/
void Score2(){
    nombre *score = NULL ;
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
void affiche_score2(){
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


/*---------------------------*//*Choix déplacement*//*---------------------------*/
void deplamcement_joueur1(Tableau T, Pion *position,nombre *nbr){
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
            suppression_pion_teamBas(T,position,nbr);
            if (pion_a_gauche_teamBas(T,position)==0){
                deplamcement_joueur1(T,position,nbr);
            }
            break;
        case 2:
            suppression_pion_teamBas(T,position,nbr);
            if (pion_a_droite_teamBas(T,position)==0){
               deplamcement_joueur1(T,position,nbr);
            }
            suppression_pion_teamBas(T,position,nbr);
            break;
        case 3:
            suppression_pion_teamBas(T,position,nbr);
            if (pion_en_arrier_a_gauche_teamBas(T,position)==0){
                deplamcement_joueur1(T,position,nbr);
            }
            break;
        case 4:
            suppression_pion_teamBas(T,position,nbr);
            if (pion_en_arrier_a_droite_teamBas(T,position)==0){
                deplamcement_joueur1(T,position,nbr);
            }
            break;
        default:
            printf("Vous n'avez pas rentre un nombre correct !\n");
           deplamcement_joueur1(T,position,nbr);
            break;
    }

    printf("\n\n");
}

void deplacement_ordi(Pion*position){
    position->initial.x=rand() % 9;
    position->initial.y=rand() % 9;
}
void deplamcement_joueur2(Tableau T, Pion *position,nombre *nbr){
    srand(time(NULL));
    position->initial.x=rand() % 9;
    position->initial.y=rand() % 9;
    printf("=== Choix du deplacement ===\n\n");
    int z;
    z = rand()%4;
    if (z==1){
        printf("Gauche");
        suppression_pion_teamHaut(T,position,nbr);
        while (pion_a_gauche_teamHaut(T,position)==0){
            deplacement_ordi(position);
        }
    }
    if (z==2){
        printf("Droite");
        suppression_pion_teamHaut(T,position,nbr);
        while (pion_a_droite_teamHaut(T,position)==0){
            deplamcement_joueur2(T,position,nbr);
        }
    }
    if (z==3){
        printf("En arriere a Gauche");
        suppression_pion_teamHaut(T,position,nbr);
        while (pion_en_arrier_a_gauche_teamHaut(T,position)==0){
            deplamcement_joueur2(T,position,nbr);
        }
    }
    if (z==4){
        printf("En arriere a Droite");
        suppression_pion_teamHaut(T,position,nbr);
        while (pion_en_arrier_a_droite_teamHaut(T,position)==0){
            deplamcement_joueur2(T,position,nbr);
        }
    }

    printf("\n\n");
}


/*---------------------------------------------*//*Fonction Principale*//*------------------------------------------------------------*/



void Mode_Facile(char Joueur1, char Joueur2){
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
            tableau(T);
            damier(T,position);
            while (nbr->nbBas!=0 || nbr->nbHaut!=0){
                affichage(T);
                deplamcement_joueur1(T,position,nbr);
                deplamcement_joueur2(T,position,nbr);
                   system("cls");
            }
           Score2();
        }free(nbr);
    }
    free(position);
    affiche_score2();
}
