/*
Nathaniel Francis S. Filoteo
GDENG03 X22
HO -- Physics ECS
*/

#include"AppWindow.h"

int main() {
	AppWindow game;

	if (game.initialize()) {
		while (game.isRunning()) {
			game.broadcast();
		}
	}

	return 0;
}