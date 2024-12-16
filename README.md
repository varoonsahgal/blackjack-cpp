# ♠️ Blackjack (C++)
Demo:

<img alt="Blackjack Demo" style="display: block; margin-left: auto; margin-right: auto; width: fit-content;" src="data/demo.gif" />


## 🔧 Setup

### Cloning
You should have [Git](https://git-scm.com/) installed and use the following commands in your terminal in your preferred directory
```sh
$ git clone https://github.com/varoonsahgal/blackjack-cpp
$ cd Blackjack_CPP
```
else you can download a [ZIP](https://github.com/ineshbose/Blackjack_CPP/archive/master.zip).

### Building / Compiling
There are four options available ordered by recommendation. You should compile the program in the `build` directory.
```sh
$ cd build
```

#### CMake
```sh
$ cmake ..          # generates build configuration (Makefile)
$ cmake --build .   # or `make` to build the executable
$ ./blackjack       # viola!
```

#### Meson
```sh
$ meson ..          # generates build configuration (ninja)
$ ninja             # builds the executable
$ ./blackjack       # viola!
```

#### Make
```sh
$ cd ..             # if you are in the build directory
$ make              # builds executable based on Makefile
$ ./blackjack       # viola!
```

#### g++
```sh
$ cd ..             # if you are in the build directory
$ g++ src/blackjack.cpp src/card.cpp src/dealer.cpp src/deck.cpp src/game.cpp src/human.cpp src/player.cpp src/print.cpp src/statistics.cpp -o blackjack
$ ./blackjack       # viola!
```

