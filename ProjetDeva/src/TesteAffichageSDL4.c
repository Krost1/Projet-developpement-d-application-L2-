// Cours en ligne 
/* La commande pour la SDL 
gcc src/TesteAffichageSDL4.c -o bin/test -I include -L lib -lmingw32 -lSDL2main -lSDL2*/

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
// SDL_WaitEvent

/*
    Pour les rendus 
    SDL_RENDERER_SOFWARE = depuis le logiciel (procésseur/par défaut)
    SDL_RENDERER_ACCELERATES = accéleration matériel (carte graphique)
    SDL_RENDERER_PRESENTVSYNC = synchronisation vertical
    SDL_RENDERER_TARGETTEXTURE = texture en particulier
*/

void SDL_ExitWithError(const char *message);

int main(int argc,char **argv)
{
    SDL_Window *window =NULL;
    SDL_Renderer *renderer =NULL;

    // Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) !=0)
    {
        SDL_ExitWithError("Initialisation SDL");
    }
    // Création d'une fenetre + rendu
    if (SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0){
         SDL_ExitWithError("Impossible de creer la fenetre et le rendu");
    }
    
    /*------------------------------------------------------------------*/
    SDL_bool program_launched = SDL_TRUE;

    while (program_launched)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
          switch (event.type)
          {
              /*
                SDL_BUTTON_LEFT
                SDL_BUTTON_MIDDLE
                SDL_BUTTON_RIGHT
              */
    //event.window.data1 event.window.data2
              case SDL_WINDOWEVENT:
              if (event.window.event==SDL_WINDOWEVENT_LEAVE)

              {
                  printf("La souris est sorti de la fenetre\n");
              }
              
                break;

            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;
          
            default:
                break;
          }
        }
        

    }
    
    /*------------------------------------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message){
    SDL_Log("ERReur : %s > %s\n",message,SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}