![preview.gif](https://raw.github.com/AlxHnr/robo_bug/master/preview.gif)

Use the arrow keys or wasd to move around.

This game has its own simple tile engine with basic collision detection.
Maps are [hardcoded](https://github.com/AlxHnr/robo_bug/blob/master/forest.c).
I failed to implement a fighting system with skills and couldn't get the
screen splitting right. (See the preview below with the black bar removed).

![preview-without-black-bar.gif](https://raw.github.com/AlxHnr/robo_bug/master/preview-without-black-bar.gif)

## Building

This program requires the development files of the following libraries:

* SDL (_not_ SDL2)
* SDL\_image
* SDL\_ttf

Build and run the game using only one thread: `make -j1 run`.
