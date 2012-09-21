#include <SDL/SDL.h>

class Screen;

class Image
{
    friend class Screen;

public:
    Image(const char* apFileName);

private:
    SDL_Surface*    mpSurface;
    bool            mbValid;
};
