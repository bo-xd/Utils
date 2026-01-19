#ifndef SIMPLERSDL_H
#define SIMPLERSDL_H

#include <SDL3/SDL.h>
#include <stdbool.h>

extern SDL_Window *g_window;
extern SDL_Renderer *g_renderer;

int InitSimpleSDL(const char* title, int width, int height, SDL_WindowFlags flags);
void HandleEvents(bool *running); 
bool IsKeyDown(SDL_Scancode key);
void CleanupSDL();

#ifdef SIMPLERSDL_IMPL

SDL_Window *g_window = NULL;
SDL_Renderer *g_renderer = NULL;

int InitSimpleSDL(const char* title, int width, int height, SDL_WindowFlags flags) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return false;
  }

  if (SDL_CreateWindowAndRenderer(width, height, flags, &g_window, &g_renderer) != 0) {
    fprintf(stderr, "Window/Renderer Creation Error: %s\n", SDL_GetError());
    SDL_Quit();
    return false;
  }
  
  SDL_SetWindowTitle(g_window, title);

  return true;
}

void CleanupSDL() {
  SDL_DestroyRenderer(g_renderer);
  SDL_DestroyWindow(g_window);
  SDL_Quit();
}

void HandleEvents(bool *running) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      *running = false;
      CleanupSDL();
    }
  }
}

bool IsKeyDown(SDL_Scancode key) {
  const bool *state = SDL_GetKeyboardState(NULL);
  return state[key];
}

#endif
#endif
