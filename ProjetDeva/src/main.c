#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BibliothequeMode.h"


/*------------------------------------------*//*Bibliotheque contenant les modes de jeux*//*----------------------------------------------*/
  
/*----------------------------------------------------------------------------------------*/
void Le_Mode_Moyen();
void Le_Mode_Facile();
void Le_Mode_Solo();
void Le_Mode_Duo();

/*------------------------------------------*//*Le programme principale*//*----------------------------------------------*/
int main(){

    int Menu;
    
    printf("=== Menu ===\n\n");
    printf("1. Mode Solo\n");
    printf("2. Pion Duo\n");
    scanf("%d", &Menu);
    
    printf("\n");
    
    switch (Menu)
    {
        case 1:
        system("cls");
        Le_Mode_Solo();
        break;
        case 2:
        system("cls");
        Le_Mode_Duo();
        break;
        default:
        printf("Vous n'avez pas rentre un nombre correct !\n");
        break;
    }
    
    printf("\n\n");
    return 0;
 
 }

/*------------------------------------------*//*Les differents menus*//*----------------------------------------------*/

void Le_Mode_Moyen(){
  int Menu;
   char Joueur1, Joueur2;
   printf("=== Choix des pions===\n\n");
   printf("1. Pion X\n");
   printf("2. Pion O\n");
   scanf("%d", &Menu);
   
   printf("\n");
   
   switch (Menu)
   {
         case 1:
            Joueur1='X';
            Joueur2='O';
            printf("Vous avez choisi les pions X !\n");
           Mode_Normale(Joueur1,Joueur2);
        break;
        case 2:
            Joueur1='O';
            Joueur2='X';
            printf("Vous avez choisi les pions O !\n");
           Mode_Normale(Joueur1,Joueur2);
        break;
      default:
         printf("Vous n'avez pas rentre un nombre correct !\n");
         break;
   }


 }

void Le_Mode_Facile(){
     
   int Menu;
   char Joueur1, Joueur2;
   printf("=== Choix des pions===\n\n");
   printf("1. Pion X\n");
   printf("2. Pion O\n");
   scanf("%d", &Menu);
   
   printf("\n");
   
   switch (Menu)
   {
         case 1:
            Joueur1='X';
            Joueur2='O';
            printf("Vous avez choisi les pions X !\n");
            system("cls");
            Mode_Facile(Joueur1,Joueur2);
        break;
        case 2:
            Joueur1='O';
            Joueur2='X';
            printf("Vous avez choisi les pions O !\n");
            system("cls");
            Mode_Facile(Joueur1,Joueur2);
        break;
      default:
         printf("Vous n'avez pas rentre un nombre correct !\n");
         break;
   }
   
 
}

void Le_Mode_Solo(){
   int Menu;
    printf("=== Mode Solo ===\n\n");
   printf("=== Choix de la  Difficulte ===\n\n");
   printf("1. Facile\n");
   printf("2. Moyen\n");
   scanf("%d", &Menu);
   
   printf("\n");
   
   switch (Menu)
   {
      case 1:
         printf("Mode Facile !\n");
         system("cls");
         Le_Mode_Facile();
         break;
      case 2:
         printf("Mode Moyen !\n");
         system("cls");
         Le_Mode_Moyen();
         break;
      default:
         printf("Vous n'avez pas rentre un nombre correct !\n");
         break;
   }
   
   printf("\n\n");


 }

 void Le_Mode_Duo(){
   int Menu;
    char Joueur1, Joueur2;
    printf("=== Mode Duo ===\n\n");
    printf("=== Menu ===\n\n");
    printf("1. Pion X\n");
    printf("2. Pion O\n");
    scanf("%d", &Menu);
    
    printf("\n");
    
    switch (Menu)
    {
        case 1:
         Joueur1='X';
         Joueur2='O';
         printf("Vous avez choisi les pions X !\n");
         system("cls");
         Partie_duo(Joueur1,Joueur2);
        break;
        case 2:
         Joueur1='O';
         Joueur2='X';
         printf("Vous avez choisi les pions O !\n");
         system("cls");
         Partie_duo(Joueur1,Joueur2);
        break;
        default:
        printf("Vous n'avez pas rentre un nombre correct !\n");
        break;
    }
    

 
 }
 