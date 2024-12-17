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

```sh
$ cd ..             # if you are in the build directory
$ make              # builds executable based on Makefile
$ ./blackjack       # voila!
```

#### g++ compiler:
```sh
$ cd ..             # if you are in the build directory
$ g++ src/blackjack.cpp src/card.cpp src/dealer.cpp src/deck.cpp src/game.cpp src/human.cpp src/player.cpp src/print.cpp src/statistics.cpp -o blackjack
$ ./blackjack       # voila!
```

