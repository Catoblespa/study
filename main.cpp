#include "GameWindow.h"
int main() {
	while (1) {
		GameWindow game;
		game.gameRestart();
		delete (&game);
		if (game.playstate == false)
			return 0;
	}
}