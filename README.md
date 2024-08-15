# Bubbles
Written in C++, this program generates renders circles within a window. Keyboard inputs change the direction of the circles, as well as close the program, and the keystrokes are printed to the terminal.

## Organization
The entire program is within one source file. Future versions of Bubbles will work towards an Entity Component System (ECS). This will enable entities to maintain their characteristics separate from rendering and entity coordinate computation.

#### Dependencies
Bubbles uses SFML [Simple and Fast Multimedia Library](https://github.com/SFML/SFML) as a window system to manage events and render graphics. 

### C++ Standard
Both Bubbles and SFML implement features from the C++17 standard.

#### Font
The font for this program is [Ohyou](https://www.dafont.com/ohyou.font) by Khurasan Studio.
