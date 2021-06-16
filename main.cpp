// todo: figure how to use sdl main function
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <hb.h>
#include <cstdio>

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_Window * window = SDL_CreateWindow("SDL2_ttf Playground", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    TTF_Font *font = TTF_OpenFont("DejaVuSans.ttf", 72);
    SDL_Color color = { 255, 255, 255, 255 };
    TTF_SetScript(HB_SCRIPT_ARABIC);
    TTF_SetDirection(HB_DIRECTION_RTL);

    const char * textstr = "هنا مثال حيث يمكنك الكتابة من اليسار";
    int w;
    TTF_SizeUTF8(font,textstr,&w, nullptr);
    printf("%d\n", w);

    SDL_Surface *text = TTF_RenderUTF8_Blended(font, textstr, color);
    printf("%d\n", text->w);
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