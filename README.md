# Debug [![Build Status](https://travis-ci.org/aquafox/debuggame.svg)](https://travis-ci.org/aquafox/debuggame)
RPG game with deck building mechanics!

## Technical Overview
Used this [tutorial](http://gamedevelopment.tutsplus.com/articles/how-to-build-a-jrpg-a-primer-for-game-developers--gamedev-6676) to do the game state stack explained in it. (class IGameState)

###Maps
Maps are made using [Tiled](http://www.mapeditor.org/). Support for tmx is being coded, [tmxparser](https://github.com/andrewrk/tmxparser) is the library being used. Support for encrypted tmx files too.


## Dependencies
### Local Dependencies
These are external projects hosted within this git.
- [Ness-Engine](http://ness-engine.com) (Folder: src/NessEngine/)
- [tmxparser](https://github.com/andrewrk/tmxparser) (Folder: src/Entity/tmxparser/)

### External Dependencies
These are required to compile but not hosted in this git.
- [SDL2](http://libsdl.org)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)
- [TinyXML2](http://www.grinninglizard.com/tinyxml2/)
- Uses smart pointers (shared_ptr) from C++11 standard.

