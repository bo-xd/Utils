#ifndef SIMPLYSDL_H
#define SIMPLYSDL_H

#include <SDL3/SDL.h>
#include <stdlib.h>

typedef struct WindowCTX {
  SDL_Window *g_window;
  SDL_Renderer *g_renderer;
  SDL_Event event;
} WindowCTX;

static WindowCTX ctx;

static int InitWindow(const char* title, int width, int height, SDL_WindowFlags flags) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    fprintf(stderr, "SDL_Init error: %s\n", SDL_GetError());
    return -1;
  }
  
  if (!SDL_CreateWindowAndRenderer(title, width, height, flags, &ctx.g_window, &ctx.g_renderer)) {
    fprintf(stderr, "Window/Renderer Creation Error: %s\n", SDL_GetError());
    return -1;
  }

  return 0;
}

static void CleanupSDL(void) {
  if (ctx.g_window) SDL_DestroyWindow(ctx.g_window);
  if (ctx.g_renderer) SDL_DestroyRenderer(ctx.g_renderer);
  SDL_Quit();
}

static bool CloseWindow(bool quit) {
  if (quit) {
    CleanupSDL();
    return false;
  }

  while (SDL_PollEvent(&ctx.event)) {
    if (ctx.event.type == SDL_EVENT_QUIT) {
      CleanupSDL();
      return false;
    }
  }

  SDL_SetRenderDrawColor(ctx.g_renderer, 0, 0, 0, 255);
  SDL_RenderClear(ctx.g_renderer);

  return true;
}

#endif
