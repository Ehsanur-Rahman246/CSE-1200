#ifndef LEVEL_H
#define LEVEL_H

float game1X = 0;
float game1X1 = 0;
float game1X2 = 0;
float game1X3 = 0;
float game1X4 = 0;

float game2X = 0;
float game2X1 = 0;
float game2X2 = 0;
float game2X3 = 0;
float game2X4 = 0;
float game2X5 = 0;

float gameWidth = SCREEN_WIDTH;


int levelOne[20];
int levelTwo[20];
void loadLevels(){
	levelOne[0] = iLoadImage("w1.png");
	levelOne[1] = iLoadImage("w2.png");
	levelOne[2] = iLoadImage("w3.png");
	levelOne[3] = iLoadImage("w4.png");
	levelOne[4] = iLoadImage("w5.png");

	levelTwo[0] = iLoadImage("sp1.png");
	levelTwo[1] = iLoadImage("sp2.png");
	levelTwo[2] = iLoadImage("sp3.png");
	levelTwo[3] = iLoadImage("sp4.png");
	levelTwo[4] = iLoadImage("sp5.png");
	levelTwo[5] = iLoadImage("sp6.png");

}

void levelOneShow(){
	if (gameLevel == 1 && !isMapOn){
		iShowImage(game1X4, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[4]);
		iShowImage(game1X4 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[4]);

		iShowImage(game1X3, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[3]);
		iShowImage(game1X3 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[3]);

		iShowImage(game1X2, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[2]);
		iShowImage(game1X2 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[2]);
		iShowImage(game1X2 + gameWidth + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[2]);

		iShowImage(game1X1, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[1]);
		iShowImage(game1X1 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[1]);
		iShowImage(game1X1 + gameWidth + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[1]);

		iShowImage(game1X, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[0]);
		iShowImage(game1X + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[0]);
		iShowImage(game1X + gameWidth + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[0]);
		iShowImage(game1X + gameWidth + gameWidth + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelOne[0]);

		if (isJumping){
			if (isFacingRight){
				iShowBMP2(character1X, characterY, *jumpR[jumpFrame], 0);
			}
			else if (!isFacingRight){
				iShowBMP2(character1X, characterY, *jumpL[jumpFrame], 0);
			}
		}
		else if (isRunning){
			if (isFacingRight){
				iShowBMP2(character1X, characterY, *run1R[runFrame], 0);
			}
			else if (!isFacingRight){
				iShowBMP2(character1X, characterY, *run1L[runFrame], 0);
			}
		}
		else {
			if (isFacingRight && !isJumping){
				iShowBMP2(character1X, characterY, *stand1R, 0);
			}
			else if (!isFacingRight && !isJumping){
				iShowBMP2(character1X, characterY, *stand1L, 0);
			}
		}
	}
}

void levelTwoShow(){
	if (gameLevel == 2 && !isMapOn){
		iShowImage(game2X5, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[5]);
		iShowImage(game2X5 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[5]);

		iShowImage(game2X4, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[4]);
		iShowImage(game2X4 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[4]);

		iShowImage(game2X3, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[3]);
		iShowImage(game2X3 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[3]);

		iShowImage(game2X2, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[2]);
		iShowImage(game2X2 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[2]);

		iShowImage(game2X1, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[1]);
		iShowImage(game2X1 + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[1]);
		iShowImage(game2X1 + gameWidth + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[1]);

		if (isJumping){
			if (isFacingRight){
				iShowBMP2(character2X, characterY, *jumpR[jumpFrame], 0);
			}
			else if (!isFacingRight){
				iShowBMP2(character2X, characterY, *jumpL[jumpFrame], 0);
			}
		}
		else if (isRunning){
			if (isFacingRight){
				iShowBMP2(character2X, characterY, *run1R[runFrame], 0);
			}
			else if (!isFacingRight){
				iShowBMP2(character2X, characterY, *run1L[runFrame], 0);
			}
		}
		else {
			if (isFacingRight && !isJumping){
				iShowBMP2(character2X, characterY, *stand1R, 0);
			}
			else if (!isFacingRight && !isJumping){
				iShowBMP2(character2X, characterY, *stand1L, 0);
			}
		}
		iShowImage(game2X, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[0]);
		iShowImage(game2X + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[0]);
		iShowImage(game2X + gameWidth + gameWidth, 0, SCREEN_WIDTH, SCREEN_HEIGHT, levelTwo[0]);
	}
}







#endif