#include "RainStreak.h"
#include "Random.h"
#include "Terminal.h"

void RainStreak::Step()
{
	x++;
	// Delete the tail MChar
	if (x > Length) {
		if (!MChars.empty()) {
			MChars.pop_front();
		} else {
			OutOfScreen = true;
		}
	}
	// Create a new MChar
	// FIXME: last row of the screen shouldn't be empty
	if (x < Terminal::getNumberOfRows()) {
		int UpdateRate = Random::Random(5, 7);
		int UpdateTimer = Random::Random(0, UpdateRate-1);

		MChars.push_back(MatrixChar(x, y, UpdateRate, UpdateTimer));
		MChars.back().Draw();
	}
	// Check if the tail MChar has entered the screen
	if (x >= Length) {
		FullyEnteredScreen = true;
	}
}

void RainStreak::Update()
{
	if (!OutOfScreen) {
		// Move the rain streak
		for (int i = 0; i < Speed; i++) {
			Step();
		}
		// Update all the MChars
		for (MatrixChar &mc : MChars) {
			mc.Update();
		}
	}
}