// todo: figure how to use sdl main function
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_Window * window = SDL_CreateWindow("SDL2_ttf Playground", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    TTF_Font *font = TTF_OpenFont("NotoColorEmoji.ttf", 72);
    SDL_Color color = { 255, 255, 255, 255 };
    SDL_Surface *text = TTF_RenderUTF8_Blended(font, "😄", color);
    SDL_BlitSurface(text, NULL, surface, NULL);

    SDL_bool running = SDL_TRUE;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = SDL_FALSE;
                    break;
            }
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(16);
    }

    return 0;
}