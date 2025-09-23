#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "iGraphics.h"
#include "utils.hpp"
#include "MainMenu.hpp"
#include "Movement.hpp"
#include "image.hpp"
#include "level.hpp"
#include "obstacle.hpp"
#include "puzzle.hpp"
#include "battle.hpp"
#include "story.hpp"
#include "progress.hpp"
#include "save_system.hpp"
using namespace std;
string getCurrentPlayerName();
void setCurrentPlayerName(const string& name);
string getCurrentPlayerName() {
	return currentPlayerName;
}

void setCurrentPlayerName(const string& name) {
	currentPlayerName = name;
}
extern int getCurrentProgress();
extern void resetGameProgress();
extern void saveCurrentGame(const string& playerName);

void setCurrentPlayer(const string& playerName) {
	currentPlayerName = playerName;
}

void iDraw()
{
	iClear();

	if (isLoading) {
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, loadBack[loadingBgFrame]);
		iShowBMP2(1200, 450, "logo.bmp", 0);

		int barWidth = 400;
		int barHeight = 20;
		int barX = (SCREEN_WIDTH - barWidth) / 2;
		int barY = 100;

		iSetColor(50, 50, 50);
		iFilledRectangle(barX - 5, barY - 5, barWidth + 10, barHeight + 10);

		int progress = (loadingBarFrame * barWidth) / maxLoadingBarFrames;
		iSetColor(100, 200, 100);
		iFilledRectangle(barX, barY, progress, barHeight);
		iSetColor(0, 0, 0);
		char loadingText[50];
		sprintf_s(loadingText, "Loading... %d%%", (loadingBarFrame * 100) / maxLoadingBarFrames);
		iText(barX + barWidth / 2 - 50, barY + 40, loadingText, GLUT_BITMAP_HELVETICA_18);
		switch (loadTextIndex){
			case 0: iText(550, 60, "Go to the Options for the Instruction.", GLUT_BITMAP_HELVETICA_18);
				break;
			case 1: iText(550, 60, "A broken blade, a shattered world.", GLUT_BITMAP_HELVETICA_18);
				break;
			case 2: iText(550, 60, "Climb the silent peak, where snow buries a forgotten truth.", GLUT_BITMAP_HELVETICA_18);
				break;
			case 3: iText(550, 60, "In a perfect garden, a song must be remembered.", GLUT_BITMAP_HELVETICA_18);
				break;
			case 4: iText(550, 60, "The jungle burns, but the truth blazes brighter.", GLUT_BITMAP_HELVETICA_18);
				break;
			case 5: iText(550, 60, "A castle of memories and a mirrored truth.", GLUT_BITMAP_HELVETICA_18);
				break;
		}

		return;
	}

	playMusic();
	glutSetCursor(GLUT_CURSOR_NONE);
	levelOneShow();
	if (gameLevel == 1 && gamePage == 1 && !isMapOn){
		for (int i = 0; i < 15; i++){
			obstacleShow1(w[i]);
		}
	}
	showPuzzle1();
	if (puzzleLevel == 1 && gamePage == 1 && !isMapOn){
		for (int i = 0; i < 4; i++){
			showCrystal(crystals[i]);
		}
	}
	if (battleLevel == 1){
		showBattle1();
	}

	levelTwoShow();
	if (gameLevel == 2 && gamePage == 1 && !isMapOn){
		for (int i = 0; i < 8; i++){
			obstacleShow2(sp[i]);
		}
	}
	showPuzzle2();
	if (puzzleLevel == 2 && gamePage == 1 && !isMapOn){
		for (int i = 0; i < 6; i++){
			showFlower(flowers[i]);
		}
	}
	if (battleLevel == 2){
		showBattle2();
	}

	if (((puzzleLevel == 1 && !puzzle1Completed) || (puzzleLevel == 2 && !puzzle2Completed)) && gamePage == 1 && !isMapOn && !isPaused && !storyTelling){
		iShowImage(mouseX, mouseY, 40, 60, puzzleCursor);
	}
	
	showStory();
	pictureShow();
	if (gamePage == 0){
		for (int i = 0; i < 4; i++){
			buttonShow(b[i], i);
		}
		iShowImage(mouseX, mouseY, 10, 15, cursor);
	}
	if (gamePage == 3){
		iShowImage(mouseX, mouseY, 10, 15, cursor);
	}


	if (!isPaused && gameLevel == 1 && !level1Completed){
		if (isHit1()){
			health1--;
			updateHealth(health1, heart1);
			if (health1 <= 0) {
				game1Over = true;
			}
			else {
				character1X -= 70;
			}
		}
	}
	if (!isPaused && gameLevel == 2 && !level2Completed){
		if (isHit2()){
			health2--;
			updateHealth(health2, heart2);
			if (health2 <= 0) {
				game2Over = true;
			}
			else {
				character2X -= 70;
			}
		}
	}

	updateGameProgress();
	showSaveSystem();
}

void iMouseMove(int mx, int my)
{
	mouseX = mx;
	mouseY = my - 15;
	if (gamePage == 1 && puzzleLevel != 0 && !isPaused){
		mouseY = my - 60;
	}

}

void iPassiveMouseMove(int mx, int my)
{
	mouseX = mx;
	mouseY = my - 15;
	if (gamePage == 1 && puzzleLevel != 0 && !isPaused){
		mouseY = my - 60;
	}
	if (gamePage == 0){
		buttonHover(mx, my);
	}
	if ((gamePage == 1 || puzzleLevel != 0 || battleLevel != 0) && isPaused){
		pauseScreenHover(mx, my);
	}
	if (gamePage == 0 && isQuitting){
		quitScreenHover(mx, my);
	}
	if (gamePage == 1 && isMapOn){
		mapHover(mx, my);
	}
	if (gamePage == 3){
		optionScreenHover(mx, my);
	}
}

void iMouse(int button, int state, int mx, int my)
{
	mouseX = mx;
	mouseY = my - 15;
	if (gamePage == 1 && puzzleLevel != 0 && !isPaused){
		mouseY = my - 60;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mciSendString("play click from 0", NULL, 0, NULL);
		//main menu
		if (gamePage == 0){
			buttonClick(mx, my);
		}
		//paused
		if ((gamePage == 1 || puzzleLevel != 0 || battleLevel != 0) && isPaused){
			pauseScreenClick(mx, my);
		}
		//exit
		if (gamePage == 0 && isQuitting){
			quitScreenClick(mx, my);
		}
		//map
		if (gamePage == 1 && isMapOn){
			mapClick(mx, my);
		}
		//options
		if (gamePage == 3){
			optionScreenClick(mx, my);
		}
		//play puzzle
		if (puzzleLevel == 1 && gamePage == 1 && !isPaused && !isMapOn){
			placePuzzle(mx, my);
		}
		if (puzzleLevel == 2 && gamePage == 1 && !isPaused && !isMapOn){
			selectPuzzle(mx, my);
		}
	}


	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		buttonAction(mx, my);
	}
}

DWORD lastEnterTime = 0;

void iKeyboard(unsigned char key){

	if (saveSystemActive) {
		handleSaveInput(key);
		return;
	}

	if (key == '\r'){
		DWORD currentTime = GetTickCount();

		if (currentTime - lastEnterTime < 300) {
			return;
		}
		lastEnterTime = currentTime;

		if (storyTelling && blinkingText && storyFinised && !enterKeyProcessed){
			enterKeyProcessed = true;
			handleStoryComplete();
			return;
		}

		if (!storyTelling) {
			enterKeyProcessed = false;
		}

		if (!storyTelling && !battleOngoing && battleLevel == 0) {

			if (puzzle2Completed && puzzleLevel == 2 && !puzzle2StoryPlayed) {
				startStory(11);
				return;
			}

			if (puzzle1Completed && puzzleLevel == 1 && !puzzle1StoryPlayed) {
				startStory(4);
				return;
			}

			if (level2Completed && gameLevel == 2 && !level2StoryPlayed) {
				startStory(9);
				return;
			}

			if (level1Completed && gameLevel == 1 && !level1StoryPlayed) {
				startStory(2);
				return;
			}
		}

		if (!storyTelling && !battleOngoing && puzzleLevel != 0) {
			if (puzzleLevel == 1 && !puzzle1Completed) {
				if (tries1 > 0) {
					resetPuzzle1();
				}
				else {
					resetEntirePuzzle1();
				}
				return;
			}

			if (puzzleLevel == 2 && !puzzle2Completed) {
				if (tries2 > 0) {
					resetPuzzle2();
					puzzle2State = 1;
				}
				else {
					resetEntirePuzzle2();
					tunePlaybackIndex = 0;
					isPlayingTunes = true;
					puzzle2State = 0;
					lastTuneTime = GetTickCount();
				}
				return;
			}
		}
	}

	if (key == 'r' || key == 'R') {
		if ((battleLevel == 1 && battle1Over) || (battleLevel == 2 && battle2Over)) {
			restartGame();
		}
	}

	if ((battleLevel == 1 && battle1Over) || (battleLevel == 2 && battle2Over)) {
		return;
	}

	if (gamePage == 1 && !isPaused && !isMapOn && battleLevel != 0 && battleOngoing) {
		if (key == 'a' || key == 'A') {
			handleAttackInput();
		}
		if (key == ' ') {
			handleBlockInput();
		}

		if (!isAttacking && !isBlocking) {
			switch (key) {
			case '0':
				currentAttack = 0;
				break;
			case '1':
				if (!attack2Cooldown) {
					currentAttack = 1;
				}
				break;
			case '2':
				if (battleLevel == 2) {
					currentAttack = 2;
				}
				break;
			case '3':
				if (battleLevel == 2) {
					currentAttack = 3;
				}
				break;
			default:
				return;
			}
		}
	}
}


void iSpecialKeyboard(unsigned char key){
	//book animation
	if (gamePage == 2){
		if (key == GLUT_KEY_RIGHT){
			if (currentPage == 0 && !isBookOpening) {
				isBookOpening = true;
				animationStep = 1;
				iResumeTimer(pageAnimation);
			}
			else if (currentPage > 0 && currentPage < 6 && !isFlippingForward) {
				isFlippingForward = true;
				animationStep = 10;
				iResumeTimer(pageAnimation);
			}

		}

		else if (key == GLUT_KEY_LEFT){
			if (currentPage == 1 && !isBookClosing) {
				isBookClosing = true;
				animationStep = 3;
				iResumeTimer(pageAnimation);
			}
			else if (currentPage > 1 && !isFlippingBackward) {
				isFlippingBackward = true;
				animationStep = 16;
				iResumeTimer(pageAnimation);
			}
		}
	}
	if (gamePage == 3 && instructionOn){
		if (iPage == 0 && key == GLUT_KEY_RIGHT){
			iPage = 1;
		}
		else if (iPage == 1 && key == GLUT_KEY_LEFT){
			iPage = 0;
		}
	}
	if (gamePage == 3 && gameLogOn && totalGameLogPages > 1){
		if (key == GLUT_KEY_UP && gameLogPage > 0){
			gameLogPage--;
		}
		else if (key == GLUT_KEY_DOWN && gameLogPage < totalGameLogPages - 1){
			gameLogPage++;
		}
	}
}

bool escKeyHandled = false;

void fixedUpdate()
{
	//menu
	if (gamePage != 0 && !storyTelling){
		if (isKeyPressed(GLUT_KEY_ESC)){
			if (!escKeyHandled) {
				escKeyHandled = true;

				if (isMapOn){
					isMapOn = false;
					gamePage = 0;
					for (int i = 0; i < 4; i++){
						b[i].isHovering = false;
						b[i].isClicked = false;
					}

				}
				else if (gamePage == 1 && (gameLevel != 0 || puzzleLevel != 0 || battleLevel != 0)){
					isPaused = true;
					pauseScreen = 0;
					if (puzzleLevel == 2){
						iPauseTimer(obstacleAnimation);
					}

					if (battleLevel != 0) {
						iPauseTimer(bossAnimation);
						iPauseTimer(bossAttackTimer);
						iPauseTimer(attackAnimation);
						iPauseTimer(blockAnimation);
						iPauseTimer(attack2EffectTimer);
						iPauseTimer(attack3EffectTimer);
						iPauseTimer(attack4EffectTimer);
						iPauseTimer(freezeEffectTimer);
					}
				}
				else if (gamePage == 3){
					if (instructionOn){
						instructionOn = false;
					}
					else if (gameLogOn){
						gameLogOn = false;
					}
					else{
						if (previousGamePage == 1){
							gamePage = 1;

							if (puzzleLevel != 0 || battleLevel != 0 || gameLevel != 0) {
								isPaused = true;
								pauseScreen = 0;
								
								if (puzzleLevel == 2){
									iPauseTimer(obstacleAnimation);
								}
								if (battleLevel != 0) {
									iPauseTimer(bossAnimation);
									iPauseTimer(bossAttackTimer);
									iPauseTimer(attackAnimation);
									iPauseTimer(blockAnimation);
									iPauseTimer(attack2EffectTimer);
									iPauseTimer(attack3EffectTimer);
									iPauseTimer(attack4EffectTimer);
									iPauseTimer(freezeEffectTimer);
								}
							}
						}
						else if (previousGamePage == 0) {
							gamePage = 0;
							for (int i = 0; i < 4; i++){
								b[i].isHovering = false;
								b[i].isClicked = false;
							}
						}
						else {
							gamePage = 0;
							for (int i = 0; i < 4; i++){
								b[i].isHovering = false;
								b[i].isClicked = false;
							}
						}
					}
				}
				else {
					gamePage = 0;
					for (int i = 0; i < 4; i++){
						b[i].isHovering = false;
						b[i].isClicked = false;
					}
				}
			}
		}
		else {
			escKeyHandled = false;
		}
	}

	//obstacle level 1
	if (gameLevel == 1 && gamePage == 1 && !isMapOn){
		if (!isPaused && !game1Over && !level1Completed && !storyTelling){
			if (isKeyPressed(' ')){
				if (!isJumping){
					isJumping = true;
					jumpState = 1;
					iResumeTimer(jumpAnimation);
				}

			}
			else if (isSpecialKeyPressed(GLUT_KEY_RIGHT))
			{
				isFacingRight = true;

				if (character1X < SCREEN_WIDTH - 700){
					character1X += 1;

					if (game1X > -(gameWidth + gameWidth + gameWidth + gameWidth)){
						game1X -= 1;
						game1X1 -= 0.9;
						game1X2 -= 0.7;
						game1X3 -= 0.5;
						game1X4 -= 0.2;
						obstacle1X -= 1;
					}
				}

				else if (game1X > -(gameWidth + gameWidth + gameWidth + gameWidth))
				{
					game1X -= 2;
					game1X1 -= 0.9;
					game1X2 -= 0.7;
					game1X3 -= 0.5;
					game1X4 -= 0.2;
					obstacle1X -= 2;
				}

				if (!isRunning) {
					isRunning = true;
					iResumeTimer(runAnimation);
				}
			}

			else if (isSpecialKeyPressed(GLUT_KEY_LEFT))
			{
				isFacingRight = false;

				if (character1X > 300){
					character1X -= 1;

					if (game1X < 0){
						game1X += 1;
						game1X1 += 0.9;
						game1X2 += 0.7;
						game1X3 += 0.5;
						game1X4 += 0.2;
						obstacle1X += 1;
					}
				}

				else if (game1X < 0)
				{
					game1X += 2;
					game1X1 += 0.9;
					game1X2 += 0.7;
					game1X3 += 0.5;
					game1X4 += 0.2;
					obstacle1X += 2;
				}

				if (!isRunning) {
					isRunning = true;
					iResumeTimer(runAnimation);
				}
			}

			else if (!isKeyPressed(GLUT_KEY_LEFT) || !isKeyPressed(GLUT_KEY_RIGHT))
			{
				if (isRunning) {
					isRunning = false;
					runFrame = 0;
					iPauseTimer(runAnimation);
				}
			}
		}


		if (!game1Over && !level1Completed){
			if (game1X == -(gameWidth + gameWidth + gameWidth)){
				if (character1X == 800){
					level1Completed = true;
					isRunning = false;
					isJumping = false;
				}
			}
		}

		if (game1Over) {
			isRunning = false;
			isJumping = false;
			if (isKeyPressed('r')) {
				health1 = 3;
				game1Over = false;
				updateHealth(health1, heart1);

				character1X = 200;
				characterY = 80;
				obstacle1X = 0;

				game1X = 0;
				game1X1 = 0;
				game1X2 = 0;
				game1X3 = 0;
				game1X4 = 0;
				gameLevel = 1;
			}

		}
	}


	//obstacle level 2
	if (gameLevel == 2 && gamePage == 1 && !isMapOn){
		if (isPaused){
			iPauseTimer(obstacleAnimation);
		}
		if (!isPaused){
			iResumeTimer(obstacleAnimation);
		}

		if (!isPaused && !game2Over && !level2Completed && !storyTelling){
			if (isKeyPressed(' ')){
				if (!isJumping){
					isJumping = true;
					jumpState = 1;
					iResumeTimer(jumpAnimation);
				}

			}
			else if (isSpecialKeyPressed(GLUT_KEY_RIGHT))
			{
				isFacingRight = true;

				if (character2X < SCREEN_WIDTH - 700){
					character2X += 1;

					if (game2X > -(gameWidth + 800)){
						game2X -= 1;
						game2X1 -= 0.9;
						game2X2 -= 0.8;
						game2X3 -= 0.6;
						game2X4 -= 0.4;
						game2X5 -= 0.2;
						obstacle2X -= 1;
					}
				}

				else if (game2X > -(gameWidth + 800))
				{
					game2X -= 2;
					game2X1 -= 0.9;
					game2X2 -= 0.8;
					game2X3 -= 0.6;
					game2X4 -= 0.4;
					game2X5 -= 0.2;
					obstacle2X -= 2;
				}

				if (!isRunning) {
					isRunning = true;
					iResumeTimer(runAnimation);
				}
			}

			else if (isSpecialKeyPressed(GLUT_KEY_LEFT))
			{
				isFacingRight = false;

				if (character2X > 300){
					character2X -= 1;

					if (game2X < 0){
						game2X += 1;
						game2X1 += 0.9;
						game2X2 += 0.8;
						game2X3 += 0.6;
						game2X4 += 0.4;
						game2X5 += 0.2;
						obstacle2X += 1;
					}
				}
				else if (game2X < 0)
				{
					game2X += 2;
					game2X1 += 0.9;
					game2X2 += 0.8;
					game2X3 += 0.6;
					game2X4 += 0.4;
					game2X5 += 0.2;
					obstacle2X += 2;
				}

				if (!isRunning) {
					isRunning = true;
					iResumeTimer(runAnimation);
				}
			}

			else if (!isKeyPressed(GLUT_KEY_LEFT) || !isKeyPressed(GLUT_KEY_RIGHT))
			{
				if (isRunning) {
					isRunning = false;
					runFrame = 0;
					iPauseTimer(runAnimation);
				}
			}
		}


		if (!game2Over && !level2Completed){
			if (game2X == -(gameWidth + 800)){
				if (character2X == 800){
					iPauseTimer(obstacleAnimation);
					level2Completed = true;
					isRunning = false;
					isJumping = false;
				}
			}
		}

		if (game2Over) {
			isRunning = false;
			isJumping = false;
			iPauseTimer(obstacleAnimation);
			if (isKeyPressed('r')) {
				health2 = 3;
				game2Over = false;
				updateHealth(health2, heart2);

				character2X = 200;
				characterY = 80;
				obstacle2X = 0;

				game2X = 0;
				game2X1 = 0;
				game2X2 = 0;
				game2X3 = 0;
				game2X4 = 0;
				game2X5 = 0;
				gameLevel = 2;

				iResumeTimer(obstacleAnimation);
			}
		}
	}


	//puzzle 2 
	if (gamePage == 1 && puzzleLevel == 2 && !puzzle2Completed && !isPaused && !isMapOn){
		playPuzzleSound();
	}


	//battle 
	if (gamePage == 1 && battleLevel != 0){

		if (isPaused || isMapOn || gamePage != 1) {
			iPauseTimer(bossAnimation);
			iPauseTimer(bossAttackTimer);
			iPauseTimer(attackAnimation);
			iPauseTimer(blockAnimation);
			iPauseTimer(attack2EffectTimer);
			iPauseTimer(attack3EffectTimer);
			iPauseTimer(attack4EffectTimer);
			iPauseTimer(freezeEffectTimer);
			iPauseTimer(runAnimation);
			return;
		}
		else {
			if (battleOngoing) {
				iResumeTimer(bossAnimation);
				iResumeTimer(bossAttackTimer);
				iResumeTimer(attackAnimation);
				iResumeTimer(blockAnimation);
				iResumeTimer(attack2EffectTimer);
				iResumeTimer(attack3EffectTimer);
				iResumeTimer(attack4EffectTimer);
				iResumeTimer(freezeEffectTimer);
				iResumeTimer(runAnimation);
			}
		}

		if (gamePage != 0 && !battleOngoing || isPaused || isMapOn){
			return;
		}

		updateProjectile();

		if (isSpecialKeyPressed(GLUT_KEY_RIGHT)){
			isFacingRight = true;
			if (!isRunning && !isAttacking) {
				isRunning = true;
				iResumeTimer(runAnimation);
			}
			if (battleLevel == 1){
				if (battle1X <= SCREEN_WIDTH - 750){
					battle1X += 2;
				}
			}
			if (battleLevel == 2){
				if (battle2X <= SCREEN_WIDTH - 750){
					battle2X += 2;
				}
			}
		}
		else if (isSpecialKeyPressed(GLUT_KEY_LEFT)){
			isFacingRight = false;
			if (!isRunning && !isAttacking) {
				isRunning = true;
				iResumeTimer(runAnimation);
			}
			if (battleLevel == 1){
				if (battle1X > 200){
					battle1X -= 2;
				}
			}
			if (battleLevel == 2){
				if (battle2X > 200){
					battle2X -= 2;
				}
			}
		}
		else {
			if (isRunning) {
				isRunning = false;
				runFrame = 0;
				iPauseTimer(runAnimation);
			}
		}

		if (!isKeyPressed('a') && !isKeyPressed('A')) {
			attackKeyPressed = false;
		}
		if (!isKeyPressed(' ')){
			blockKeyPressed = false;
		}
	}


	static bool level1WasCompleted = false;
	static bool level2WasCompleted = false;
	static bool puzzle1WasCompleted = false;
	static bool puzzle2WasCompleted = false;
	static bool battle1WasCompleted = false;
	static bool battle2WasCompleted = false;

	if (level1Completed && !level1WasCompleted) {
		level1WasCompleted = true;
		if (!currentPlayerName.empty()) {
			saveGameData(currentPlayerName);
		}
	}

	if (level2Completed && !level2WasCompleted) {
		level2WasCompleted = true;
		if (!currentPlayerName.empty()) {
			saveGameData(currentPlayerName);
		}
	}

	if (puzzle1Completed && !puzzle1WasCompleted) {
		puzzle1WasCompleted = true;
		if (!currentPlayerName.empty()) {
			saveGameData(currentPlayerName);
		}
	}

	if (puzzle2Completed && !puzzle2WasCompleted) {
		puzzle2WasCompleted = true;
		if (!currentPlayerName.empty()) {
			saveGameData(currentPlayerName);
		}
	}

	if (battle1Completed && !battle1WasCompleted) {
		battle1WasCompleted = true;
		if (!currentPlayerName.empty()) {
			saveGameData(currentPlayerName);
		}
	}

	if (battle2Completed && !battle2WasCompleted) {
		battle2WasCompleted = true;
		if (!currentPlayerName.empty()) {
			saveGameData(currentPlayerName);
		}
	}

	static int lastGamePage = -1;
	if (gamePage == 0 && lastGamePage == 1 && !saveSystemActive) {
		if (!currentPlayerName.empty()) {
			saveGameData(currentPlayerName);
		}
	}
	lastGamePage = gamePage;
}


int main()
{
	mciSendString("open \"Audios//mouseclick1.mp3\" alias click", NULL, 0, NULL);
	mciSendString("open \"Audios//spirits-of-the-greenwood.mp3\" alias mmsong", NULL, 0, NULL);
	mciSendString("open \"Audios//ssvid.net--Crystal-Cavern-Original-Fantasy-Music.mp3\" alias puzzle", NULL, 0, NULL);
	mciSendString("open \"Audios//ssvid.net--Winter-Night.mp3\" alias battle1", NULL, 0, NULL);
	mciSendString("open \"Audios//ssvid.net--A-Swift-Breath-of-Spring-Clover-s-Battle-Theme-Original.mp3\" alias battle2", NULL, 0, NULL);
	mciSendString("open \"Audios//ssvid.net--Spring-Breeze-Blowing-Day.mp3\" alias spring", NULL, 0, NULL);

	mciSendString("open \"Audios//tune1.mp3\" alias 1", NULL, 0, NULL);
	mciSendString("open \"Audios//tune2.mp3\" alias 2", NULL, 0, NULL);
	mciSendString("open \"Audios//tune3.mp3\" alias 3", NULL, 0, NULL);
	mciSendString("open \"Audios//tune4.mp3\" alias 4", NULL, 0, NULL);
	mciSendString("open \"Audios//tune5.mp3\" alias 5", NULL, 0, NULL);
	mciSendString("open \"Audios//tune6.mp3\" alias 6", NULL, 0, NULL);

	srand(time(NULL));
	iInitialize(SCREEN_WIDTH, SCREEN_HEIGHT, "VoidSpire");
	loadingImg();
	loadingBgTimer = iSetTimer(100, updateLoadingBg);
    loadingBarTimer = iSetTimer(50, updateLoadingBar);
	loadTxt = iSetTimer(2000, generateIndex);

	storyAnimation = iSetTimer(100, storyAnimated);
	textAnimation = iSetTimer(30, updateText);
	runAnimation = iSetTimer(100, running);
	jumpAnimation = iSetTimer(20, jumping);
	pageAnimation = iSetTimer(100, bookFlip);
	obstacleAnimation = iSetTimer(1000, spObstacle);
	attackAnimation = iSetTimer(70, attack);
	bossAnimation = iSetTimer(100, bossMovement);
	bossAttackTimer = iSetTimer(3000, startBossAttack);
	blockAnimation = iSetTimer(100, blocked);
	attack2EffectTimer = iSetTimer(100, updateAttack2Effect);
	attack3EffectTimer = iSetTimer(100, updateAttack3Effect);
	attack4EffectTimer = iSetTimer(100, updateAttack4Effect);
	freezeEffectTimer = iSetTimer(100, updateFreezeTimer);
	msgAnimation = iSetTimer(2000, hideText);
	iPauseTimer(bossAnimation);
	iPauseTimer(pageAnimation);
	iPauseTimer(runAnimation);
	iPauseTimer(jumpAnimation);
	iPauseTimer(attackAnimation);
	iPauseTimer(blockAnimation);
	iPauseTimer(bossAttackTimer);
	iPauseTimer(attack2EffectTimer);
	iPauseTimer(attack3EffectTimer);
	iPauseTimer(attack4EffectTimer);
	iPauseTimer(freezeEffectTimer);
	iPauseTimer(storyAnimation);	
	iPauseTimer(textAnimation);
	iPauseTimer(msgAnimation);

	iStart();
	return 0;
}