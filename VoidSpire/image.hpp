#ifndef IMAGE_H
#define IMAGE_H

void showMessages();

char* stand1R[6] = { "01r.bmp" };
char* stand1L[6] = { "01l.bmp" };

char *run1R[RUN_FRAME_NO][6]{
	{ "run1\\1.bmp" },
	{ "run1\\2.bmp" },
	{ "run1\\3.bmp" },
	{ "run1\\4.bmp" },
	{ "run1\\5.bmp" },
	{ "run1\\6.bmp" },
	{ "run1\\7.bmp" },
	{ "run1\\8.bmp" },
	{ "run1\\9.bmp" },
	{ "run1\\10.bmp" },
	{ "run1\\11.bmp" },
	{ "run1\\12.bmp" },
};

char *run1L[RUN_FRAME_NO][6]{
	{ "run1B\\1.bmp" },
	{ "run1B\\2.bmp" },
	{ "run1B\\3.bmp" },
	{ "run1B\\4.bmp" },
	{ "run1B\\5.bmp" },
	{ "run1B\\6.bmp" },
	{ "run1B\\7.bmp" },
	{ "run1B\\8.bmp" },
	{ "run1B\\9.bmp" },
	{ "run1B\\10.bmp" },
	{ "run1B\\11.bmp" },
	{ "run1B\\12.bmp" },
};

char *jumpR[JUMP_FRAME_NO][6] = {
	{ "jumpR\\1.bmp" },
	{ "jumpR\\2.bmp" },
	{ "jumpR\\3.bmp" },
	{ "jumpR\\4.bmp" },
	{ "jumpR\\5.bmp" },
	{ "jumpR\\6.bmp" },
	{ "jumpR\\7.bmp" },
	{ "jumpR\\8.bmp" }
};

char *jumpL[JUMP_FRAME_NO][6] = {
	{ "jumpL\\1.bmp" },
	{ "jumpL\\2.bmp" },
	{ "jumpL\\3.bmp" },
	{ "jumpL\\4.bmp" },
	{ "jumpL\\5.bmp" },
	{ "jumpL\\6.bmp" },
	{ "jumpL\\7.bmp" },
	{ "jumpL\\8.bmp" }
};



char* standR[6] = { "0r.bmp" };
char* standL[6] = { "0l.bmp" };
char *runR[RUN_FRAME_NO][6]{
	{ "run\\1.bmp" },
	{ "run\\2.bmp" },
	{ "run\\3.bmp" },
	{ "run\\4.bmp" },
	{ "run\\5.bmp" },
	{ "run\\6.bmp" },
	{ "run\\7.bmp" },
	{ "run\\8.bmp" },
	{ "run\\9.bmp" },
	{ "run\\10.bmp" },
	{ "run\\11.bmp" },
	{ "run\\12.bmp" },
};

char *runL[RUN_FRAME_NO][6]{
	{ "runB\\1.bmp" },
	{ "runB\\2.bmp" },
	{ "runB\\3.bmp" },
	{ "runB\\4.bmp" },
	{ "runB\\5.bmp" },
	{ "runB\\6.bmp" },
	{ "runB\\7.bmp" },
	{ "runB\\8.bmp" },
	{ "runB\\9.bmp" },
	{ "runB\\10.bmp" },
	{ "runB\\11.bmp" },
	{ "runB\\12.bmp" },
};

char *attack1[12][6] = {
	{ "attack1\\1.bmp" },
	{ "attack1\\2.bmp" },
	{ "attack1\\3.bmp" },
	{ "attack1\\4.bmp" },
	{ "attack1\\5.bmp" },
	{ "attack1\\6.bmp" },
	{ "attack1\\7.bmp" },
	{ "attack1\\8.bmp" },
	{ "attack1\\9.bmp" },
	{ "attack1\\10.bmp" },
	{ "attack1\\11.bmp" },
	{ "attack1\\12.bmp" }
};

char *attack2[15][6] = {
	{ "attack2\\1.bmp" },
	{ "attack2\\2.bmp" },
	{ "attack2\\3.bmp" },
	{ "attack2\\4.bmp" },
	{ "attack2\\5.bmp" },
	{ "attack2\\6.bmp" },
	{ "attack2\\7.bmp" },
	{ "attack2\\8.bmp" },
	{ "attack2\\9.bmp" },
	{ "attack2\\10.bmp" },
	{ "attack2\\11.bmp" },
	{ "attack2\\12.bmp" },
	{ "attack2\\13.bmp" },
	{ "attack2\\14.bmp" },
	{ "attack2\\15.bmp" }
};

char *attack3[16][6] = {
	{ "attack3\\1.bmp" },
	{ "attack3\\2.bmp" },
	{ "attack3\\3.bmp" },
	{ "attack3\\4.bmp" },
	{ "attack3\\5.bmp" },
	{ "attack3\\6.bmp" },
	{ "attack3\\7.bmp" },
	{ "attack3\\8.bmp" },
	{ "attack3\\9.bmp" },
	{ "attack3\\10.bmp" },
	{ "attack3\\11.bmp" },
	{ "attack3\\12.bmp" },
	{ "attack3\\13.bmp" },
	{ "attack3\\14.bmp" },
	{ "attack3\\15.bmp" },
	{ "attack3\\16.bmp" }
};

char *attack4[15][6] = {
	{ "attack4\\1.bmp" },
	{ "attack4\\2.bmp" },
	{ "attack4\\3.bmp" },
	{ "attack4\\4.bmp" },
	{ "attack4\\5.bmp" },
	{ "attack4\\6.bmp" },
	{ "attack4\\7.bmp" },
	{ "attack4\\8.bmp" },
	{ "attack4\\9.bmp" },
	{ "attack4\\10.bmp" },
	{ "attack4\\11.bmp" },
	{ "attack4\\12.bmp" },
	{ "attack4\\13.bmp" },
	{ "attack4\\14.bmp" },
	{ "attack4\\15.bmp" }
};

char *attack2Effect[7][6] = {
	{ "ice\\1.bmp" },
	{ "ice\\2.bmp" },
	{ "ice\\3.bmp" },
	{ "ice\\4.bmp" },
	{ "ice\\5.bmp" },
	{ "ice\\6.bmp" },
	{ "ice\\7.bmp" }
};

char *attack3Effect[8][6] = {
	{ "water\\1.bmp" },
	{ "water\\2.bmp" },
	{ "water\\3.bmp" },
	{ "water\\4.bmp" },
	{ "water\\5.bmp" },
	{ "water\\6.bmp" },
	{ "water\\7.bmp" },
	{ "water\\8.bmp" }
};

char *attack4Effect[9][6] = {
	{ "heal\\1.bmp" },
	{ "heal\\2.bmp" },
	{ "heal\\3.bmp" },
	{ "heal\\4.bmp" },
	{ "heal\\5.bmp" },
	{ "heal\\6.bmp" },
	{ "heal\\7.bmp" },
	{ "heal\\8.bmp" },
	{ "heal\\9.bmp" }
};

void pictureShow(){
	if (gamePage == 0){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, homepage);
		if (isQuitting){
			if (quitScreen == 1){
				iShowImage(524, 125, 452, 350, quitY);
			}
			else if (quitScreen == 2){
				iShowImage(524, 125, 452, 350, quitN);
			}
			else {
				iShowImage(524, 125, 452, 350, quit);
			}
		}
	}
	else if (gamePage == 1){
		if (isMapOn){
			
			iShowImage(0, 0, 1500, 600, mapBack);
			if (mapScreen == 1){
				iShowImage(58, 24, 1383, 532, mapW);
			}
			else if (mapScreen == 2){
				iShowImage(58, 24, 1383, 532, mapSp);
			}
			else if (mapScreen == 3){
				iShowImage(58, 24, 1383, 532, mapSu);
			}
			else if (mapScreen == 4){
				iShowImage(58, 24, 1383, 532, mapA);
			}
			else {
				iShowImage(58, 24, 1383, 532, mapMain);
			}
			iShowImage(mouseX, mouseY, 10, 15, cursor);
			showMessages();
		}
		else if (!isMapOn){
			if (gameLevel != 0 || puzzleLevel != 0 || battleLevel != 0){
				if (isPaused){
					if (pauseScreen == 0){
						iShowImage(490, 5, 500, 590, pause);
					}
					else if (pauseScreen == 1){
						iShowImage(490, 5, 500, 590, resume);
					}
					else if (pauseScreen == 2){
						iShowImage(490, 5, 500, 590, map);
					}
					else if (pauseScreen == 3){
						iShowImage(490, 5, 500, 590, settings);
					}
					else if (pauseScreen == 4){
						iShowImage(490, 5, 500, 590, mainmenu);
					}
					iShowImage(mouseX, mouseY, 10, 15, cursor);
				}
			}
		}

	}

	else if (gamePage == 2){
		if (currentPage == 0 && !isBookOpening) {
			iShowImage(365, 0, 770, 560, book[0]);
		}
		else {
			iShowImage(365, 0, 770, 560, book[displayFrame]);
		}
	}
	else if (gamePage == 3){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, settingPage);
		if (volumeHovering){
			if (volumeOn){
				iShowImage(365, 345, 80, 80, option[0]);
				iShowImage(200, 350, 150, 70, option[2]);
			}
			else{
				iShowImage(365, 345, 80, 80, option[1]);
				iShowImage(200, 350, 150, 70, option[3]);
			}
		}
		else{
			if (volumeOn){
				iShowImage(370, 350, 70, 70, option[0]);
				iShowImage(200, 350, 150, 70, option[2]);
			}
			else{
				iShowImage(370, 350, 70, 70, option[1]);
				iShowImage(200, 350, 150, 70, option[3]);
			}
		}
		if (instructionsHovering){
			iShowImage(195, 245, 160, 80, option[4]);
		}
		else{
			iShowImage(200, 250, 150, 70, option[4]);
		}
		if (gameLogHovering){
			iShowImage(195, 145, 160, 80, option[5]);
		}
		else {
			iShowImage(200, 150, 150, 70, option[5]);
		}
		if (instructionOn && iPage == 0){
			iShowImage(550, 130, 320, 380, instructions[0]);
		}
		else if (instructionOn && iPage == 1){
			iShowImage(550, 130, 320, 380, instructions[1]);
		}
		else if (gameLogOn) {
			showGameLog();
		}
	}
}



#endif