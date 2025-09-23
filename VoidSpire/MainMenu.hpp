#ifndef MAINMENU_H
#define MAINMENU_H
#include "Movement.hpp"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define BUTTON_WIDTH 120
#define BUTTON_HEIGHT 60
#define BUTTON_X 170

int gameLogPage = 0;
int totalGameLogPages = 0;
vector<pair<string, int>> playerList;

void startStory(int state);
void startText(int num);
bool shouldPlayStory(int state);
void activateSaveSystem();

int previousGamePage = 0;
DWORD lastMessageTime = 0;

struct Button{
	int x, y;
	int width, height;
	bool isHovering;
	bool isClicked;
};

Button b[4] = {
	{ BUTTON_X, 330, BUTTON_WIDTH, BUTTON_HEIGHT, false, false },
	{ BUTTON_X, 250, BUTTON_WIDTH, BUTTON_HEIGHT, false, false },
	{ BUTTON_X, 170, BUTTON_WIDTH, BUTTON_HEIGHT, false, false },
	{ BUTTON_X, 90, BUTTON_WIDTH, BUTTON_HEIGHT, false, false }
};



bool isPaused = false;
bool isQuitting = false;

int ui;
int homepage;
int settingPage;
int option[10];
int instructions[10];
int iPage = 0;
int button[4];
int book[22];
int cursor;
int puzzleCursor;
int pause;
int resume;
int map;
int settings;
int mainmenu;
int quit;
int quitY;
int quitN;
int mapMain;
int mapW;
int mapSu;
int mapSp;
int mapA;
int mapBack;


void playMusic(){
	bool shouldPlayMusic = (gamePage == 0 || gamePage == 2 || gamePage == 3) ||
		(gamePage == 1 && (isMapOn || storyTelling));

	bool shouldPlayPuzzle = (puzzleLevel == 1 && gamePage == 1 && !isMapOn && !puzzle1Completed && !isPaused);
	bool shouldPlaySpring = (gameLevel == 2 && gamePage == 1 && !isMapOn && !level2Completed && !isPaused);
	bool shouldPlayBattle1 = (battleLevel == 1 && battleOngoing && gamePage == 1 && !isPaused && !isMapOn);
	bool shouldPlayBattle2 = (battleLevel == 2 && battleOngoing && gamePage == 1 && !isPaused && !isMapOn);

	bool actuallyPlayMusic = volumeOn && shouldPlayMusic;
	bool actuallyPlayPuzzle = volumeOn && shouldPlayPuzzle;
	bool actuallyPlaySpring = volumeOn && shouldPlaySpring;
	bool actuallyPlayBattle1 = volumeOn && shouldPlayBattle1;
	bool actuallyPlayBattle2 = volumeOn && shouldPlayBattle2;

	if (actuallyPlayMusic && !musicOn && !actuallyPlayPuzzle && !actuallyPlaySpring && !actuallyPlayBattle1 && !actuallyPlayBattle2) {
		musicOn = true;
		mciSendString("play mmsong repeat", NULL, 0, NULL);
	}
	else if ((!actuallyPlayMusic && musicOn) || ((actuallyPlayPuzzle || actuallyPlaySpring || actuallyPlayBattle1 || actuallyPlayBattle2) && musicOn)) {
		musicOn = false;
		mciSendString("stop mmsong", NULL, 0, NULL);
	}

	static bool puzzleMusicOn = false;
	if (actuallyPlayPuzzle && !puzzleMusicOn) {
		puzzleMusicOn = true;
		mciSendString("play puzzle repeat", NULL, 0, NULL);
	}
	else if (!actuallyPlayPuzzle && puzzleMusicOn) {
		puzzleMusicOn = false;
		mciSendString("stop puzzle", NULL, 0, NULL);
	}

	static bool springMusicOn = false;
	if (actuallyPlaySpring && !springMusicOn) {
		springMusicOn = true;
		mciSendString("play spring repeat", NULL, 0, NULL);
	}
	else if (!actuallyPlaySpring && springMusicOn) {
		springMusicOn = false;
		mciSendString("stop spring", NULL, 0, NULL);
	}

	static bool battle1MusicOn = false;
	if (actuallyPlayBattle1 && !battle1MusicOn && !puzzleMusicOn && !springMusicOn) {
		battle1MusicOn = true;
		mciSendString("play battle1 repeat", NULL, 0, NULL);
	}
	else if (!actuallyPlayBattle1 && battle1MusicOn) {
		battle1MusicOn = false;
		mciSendString("stop battle1", NULL, 0, NULL);
	}

	static bool battle2MusicOn = false;
	if (actuallyPlayBattle2 && !battle2MusicOn && !puzzleMusicOn && !springMusicOn && !battle1MusicOn) {
		battle2MusicOn = true;
		mciSendString("play battle2 repeat", NULL, 0, NULL);
	}
	else if (!actuallyPlayBattle2 && battle2MusicOn) {
		battle2MusicOn = false;
		mciSendString("stop battle2", NULL, 0, NULL);
	}
}

void loadImages(){
	ui = iLoadImage("ui.png");
	cursor = iLoadImage("cursor.png");
	puzzleCursor = iLoadImage("pCursor.png");
	homepage = iLoadImage("gamebackground\\menu.png");
	settingPage = iLoadImage("gamebackground\\setting.png");


	for (int i = 0; i < 4; i++){
		char a[50];
		sprintf_s(a, "gameUi\\button%d.png", i + 1);
		button[i] = iLoadImage(a);
	}

	option[0] = iLoadImage("gameUi\\v1.png");
	option[1] = iLoadImage("gameUi\\v2.png");
	option[2] = iLoadImage("gameUi\\on.png");
	option[3] = iLoadImage("gameUi\\off.png");
	option[4] = iLoadImage("gameUi\\i.png");
	option[5] = iLoadImage("gameUi\\g.png");
	instructions[0] = iLoadImage("gameUi\\i1.png");
	instructions[1] = iLoadImage("gameUi\\i2.png");

	pause = iLoadImage("p.png");
	resume = iLoadImage("pr.png");
	map = iLoadImage("pm.png");
	settings = iLoadImage("ps.png");
	mainmenu = iLoadImage("pmm.png");
	quit = iLoadImage("q.png");
	quitY = iLoadImage("qy.png");
	quitN = iLoadImage("qn.png");
	mapBack = iLoadImage("mapcover.png");
	mapMain = iLoadImage("m.png");
	mapW = iLoadImage("m1.png");
	mapSp = iLoadImage("m2.png");
	mapSu = iLoadImage("m3.png");
	mapA = iLoadImage("m4.png");

	book[0] = iLoadImage("book\\cover.png");
	book[1] = iLoadImage("book\\b1.png");
	book[2] = iLoadImage("book\\b2.png");
	book[3] = iLoadImage("book\\b3.png");
	book[4] = iLoadImage("book\\p1.png");
	book[5] = iLoadImage("book\\p2.png");
	book[6] = iLoadImage("book\\p3.png");
	book[7] = iLoadImage("book\\p4.png");
	book[8] = iLoadImage("book\\p5.png");
	book[9] = iLoadImage("book\\p6.png");
	book[10] = iLoadImage("book\\pf1.png");
	book[11] = iLoadImage("book\\pf2.png");
	book[12] = iLoadImage("book\\pf3.png");
	book[13] = iLoadImage("book\\pf4.png");
	book[14] = iLoadImage("book\\pf5.png");
	book[15] = iLoadImage("book\\pf6.png");
	book[16] = iLoadImage("book\\pb1.png");
	book[17] = iLoadImage("book\\pb2.png");
	book[18] = iLoadImage("book\\pb3.png");
	book[19] = iLoadImage("book\\pb4.png");
	book[20] = iLoadImage("book\\pb5.png");
	book[21] = iLoadImage("book\\pb6.png");
}

bool isBookOpening = false;
bool isBookClosing = false;
bool isFlippingForward = false;
bool isFlippingBackward = false;
int pageAnimation;
int currentPage = 0;
int displayFrame = 0;
int animationStep = 0;

void bookFlip(){
	if (isBookOpening) {
		displayFrame = animationStep;
		animationStep++;
		if (animationStep > 3) {
			isBookOpening = false;
			currentPage = 1;
			displayFrame = currentPage + 3;
			iPauseTimer(pageAnimation);
		}
	}
	else if (isBookClosing) {
		displayFrame = animationStep;
		animationStep--;
		if (animationStep < 1) {
			isBookClosing = false;
			currentPage = 0;
			displayFrame = 0;
			iPauseTimer(pageAnimation);
		}
	}
	else if (isFlippingForward) {
		displayFrame = animationStep;
		animationStep++;
		if (animationStep > 15) {
			isFlippingForward = false;
			currentPage++;
			displayFrame = currentPage + 3;
			iPauseTimer(pageAnimation);
		}
	}
	else if (isFlippingBackward) {
		displayFrame = animationStep;
		animationStep++;
		if (animationStep > 21) {
			isFlippingBackward = false;
			currentPage--;
			displayFrame = currentPage + 3;
			iPauseTimer(pageAnimation);
		}
	}

}


void loadPlayerList() {
	playerList.clear();
	ifstream file("playernames.txt");
	if (!file.is_open()) {
		totalGameLogPages = 0;
		return;
	}

	string line;
	while (getline(file, line)) {
		size_t spacePos = line.find_last_of(' ');
		if (spacePos != string::npos) {
			string playerName = line.substr(0, spacePos);
			int progress = stoi(line.substr(spacePos + 1));
			playerList.push_back({ playerName, progress });
		}
		else {
			playerList.push_back({ line, 0 });
		}
	}
	file.close();

	totalGameLogPages = (playerList.size() + 9) / 10;
	if (totalGameLogPages == 0) totalGameLogPages = 1;
	gameLogPage = 0;
}

void showGameLog() {
	if (!gameLogOn) return;

	iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, settingPage);

	// Title
	iSetColor(255, 255, 255);
	iText(600, 550, "GAME LOG", GLUT_BITMAP_TIMES_ROMAN_24);

	if (playerList.empty()) {
		iText(600, 400, "No saved games found!", GLUT_BITMAP_HELVETICA_18);
		iText(500, 50, "Press ESC to go back", GLUT_BITMAP_HELVETICA_12);
		return;
	}

	int startIndex = gameLogPage * 10;
	int endIndex = min(startIndex + 10, (int)playerList.size());

	int yPos = 480;
	for (int i = startIndex; i < endIndex; i++) {
		char playerInfo[100];
		sprintf_s(playerInfo, "%d. %s - Progress: %d%%",
			i + 1, playerList[i].first.c_str(), playerList[i].second);
		iText(400, yPos, playerInfo, GLUT_BITMAP_HELVETICA_18);
		yPos -= 35;
	}

	char pageInfo[50];
	sprintf_s(pageInfo, "Page %d of %d", gameLogPage + 1, totalGameLogPages);
	iText(650, 100, pageInfo, GLUT_BITMAP_HELVETICA_12);

	if (totalGameLogPages > 1) {
		iText(500, 70, "Use UP/DOWN arrows to navigate pages", GLUT_BITMAP_HELVETICA_12);
	}
	iText(500, 50, "Press ESC to go back", GLUT_BITMAP_HELVETICA_12);
}
	

void buttonHover(int mx, int my){

	if (gamePage == 0){
		for (int i = 0; i < 4; i++){
			if (mx >= b[i].x && mx <= b[i].x + b[i].width && my >= b[i].y && my <= b[i].y + b[i].height)
				b[i].isHovering = true;

			else b[i].isHovering = false;
		}
	}
}

void buttonClick(int mx, int my){

	if (gamePage == 0){
		for (int i = 0; i < 4; i++){
			if (mx >= b[i].x && mx <= b[i].x + b[i].width && my >= b[i].y && my <= b[i].y + b[i].height)
				b[i].isClicked = true;

			else b[i].isClicked = false;
		}
	}
}

void buttonShow(Button b, int index){
	if (gamePage == 0){
		if (b.isClicked){
			iShowImage(b.x + 5, b.y + 5, b.width - 10, b.height - 10, button[index]);
		}
		else if (b.isHovering){
			iShowImage(b.x - 5, b.y - 5, b.width + 10, b.height + 10, button[index]);
		}

		else {
			iShowImage(b.x, b.y, b.width, b.height, button[index]);
		}
	}
}


int px = 610;
int pxw = 860;
int qy = 220;
int qyh = 280;
int pauseScreen;
int quitScreen;
int mapScreen;

void pauseScreenHover(int mx, int my){
	if (isPaused){
		if (mx >= px && mx <= pxw && my >= 390 && my <= 440){
			pauseScreen = 1;
		}
		else if (mx >= px && mx <= pxw && my >= 310 && my <= 360){
			pauseScreen = 2;
		}
		else if (mx >= px && mx <= pxw && my >= 230 && my <= 280){
			pauseScreen = 3;
		}
		else if (mx >= px && mx <= pxw && my >= 150 && my <= 200){
			pauseScreen = 4;
		}
		else {
			pauseScreen = 0;
		}
	}
}


void pauseScreenClick(int mx, int my){
	if (isPaused){
		if (mx >= px && mx <= pxw && my >= 390 && my <= 440){
			isPaused = false;
			gamePage = 1;

			if (puzzleLevel == 2){
				iResumeTimer(obstacleAnimation);
			}
			if (battleLevel != 0 && battleOngoing) {
				iResumeTimer(bossAnimation);
				iResumeTimer(bossAttackTimer);
				if (isAttacking) iResumeTimer(attackAnimation);
				if (isBlocking) iResumeTimer(blockAnimation);
				iResumeTimer(attack2EffectTimer);
				iResumeTimer(attack3EffectTimer);
				iResumeTimer(attack4EffectTimer);
				iResumeTimer(freezeEffectTimer);
			}
		}
		else if (mx >= px && mx <= pxw && my >= 310 && my <= 360){
			// Map button
			isPaused = false;
			isMapOn = true;
		}
		else if (mx >= px && mx <= pxw && my >= 230 && my <= 280){
			// Settings button
			isPaused = false;
			previousGamePage = 1;
			gamePage = 3;
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
		else if (mx >= px && mx <= pxw && my >= 150 && my <= 200){
			isPaused = false;
			gamePage = 0;
			for (int i = 0; i < 4; i++){
				b[i].isHovering = false;
				b[i].isClicked = false;
			}
		}
	}
}


void quitScreenHover(int mx, int my){
	if (mx >= 590 && mx <= 720 && my >= qy && my <= qyh){
		quitScreen = 1;
	}
	else if (mx >= 780 && mx <= 910 && my >= qy && my <= qyh){
		quitScreen = 2;
	}
	else {
		quitScreen = 0;
	}
}


void quitScreenClick(int mx, int my){
	if (mx >= 590 && mx <= 720 && my >= qy && my <= qyh){
		isQuitting = false;
		exit(0);
	}
	else if (mx >= 780 && mx <= 910 && my >= qy && my <= qyh){
		isQuitting = false;
		gamePage = 0;
		for (int i = 0; i < 4; i++){
			b[i].isHovering = false;
			b[i].isClicked = false;
		}
	}
}


void mapHover(int mx, int my){
	if (isMapOn){
		if ((mx >= 160 && mx <= 470 && my >= 430 && my <= 550) || (mx >= 330 && mx <= 460 && my >= 300 && my <= 350)){
			mapScreen = 1;
		}
		else if ((mx >= 160 && mx <= 520 && my >= 310 && my <= 390) || (mx >= 130 && mx <= 400 && my >= 90 && my <= 270)){
			mapScreen = 2;
		}
		else if ((mx >= 490 && mx <= 830 && my >= 140 && my <= 300) || (mx >= 630 && mx <= 910 && my >= 420 && my <= 530)){
			mapScreen = 3;
		}
		else if ((mx >= 960 && mx <= 1340 && my >= 100 && my <= 290) || (mx >= 930 && mx <= 1210 && my >= 360 && my <= 490)){
			mapScreen = 4;
		}
		else {
			mapScreen = 0;
		}
	}
}

void mapClick(int mx, int my){
	if (isMapOn){
		DWORD currentTime = GetTickCount();

		if ((mx >= 160 && mx <= 470 && my >= 430 && my <= 550) || (mx >= 330 && mx <= 460 && my >= 300 && my <= 350)){
			if (level1Completed && puzzle1Completed && battle1Completed){
				if (currentTime - lastMessageTime > 500) {
					startText(3);
					lastMessageTime = currentTime;
				}
			}
			else {
				isMapOn = false;
				if (shouldPlayStory(1)) {
					startStory(1);
				}
				else {
					gameLevel = 1;
				}
			}
		}

		else if ((mx >= 160 && mx <= 520 && my >= 310 && my <= 390) || (mx >= 130 && mx <= 400 && my >= 90 && my <= 270)){
			if (!level1Completed || !puzzle1Completed || !battle1Completed){
				if (currentTime - lastMessageTime > 500) {
					startText(1);
					lastMessageTime = currentTime;
				}
			}
			else if (level1Completed && puzzle1Completed && battle1Completed &&
				(!level2Completed || !puzzle2Completed || !battle2Completed)){
				isMapOn = false;
				if (shouldPlayStory(8)) {
					startStory(8);
				}
				else {
					gameLevel = 2;
				}
			}
			else {
				if (currentTime - lastMessageTime > 500) {
					startText(3);
					lastMessageTime = currentTime;
				}
			}
		}

		else if ((mx >= 490 && mx <= 830 && my >= 140 && my <= 300) || (mx >= 630 && mx <= 910 && my >= 420 && my <= 530)){
			if (!level1Completed || !puzzle1Completed || !battle1Completed){
				if (currentTime - lastMessageTime > 500) {
					startText(1);
					lastMessageTime = currentTime;
				}
			}
			else if (level1Completed && puzzle1Completed && battle1Completed &&
				(!level2Completed || !puzzle2Completed || !battle2Completed)){
				if (currentTime - lastMessageTime > 500) {
					startText(2);
					lastMessageTime = currentTime;
				}
			}
			else {
				if (currentTime - lastMessageTime > 500) {
					startText(4);
					lastMessageTime = currentTime;
				}
			}
		}

		else if ((mx >= 960 && mx <= 1340 && my >= 100 && my <= 290) || (mx >= 930 && mx <= 1210 && my >= 360 && my <= 490)){
			if (!level1Completed || !puzzle1Completed || !battle1Completed){
				if (currentTime - lastMessageTime > 500) {
					startText(1);
					lastMessageTime = currentTime;
				}
			}
			else if (level1Completed && puzzle1Completed && battle1Completed &&
				(!level2Completed || !puzzle2Completed || !battle2Completed)){
				if (currentTime - lastMessageTime > 500) {
					startText(2);
					lastMessageTime = currentTime;
				}
			}
			else {
				if (currentTime - lastMessageTime > 500) {
					startText(4);
					lastMessageTime = currentTime;
				}
			}
		}
	}
}


void optionScreenHover(int mx, int my){
	if (gamePage == 3 && !instructionOn && !gameLogOn){
		if (mx >= 370 && mx <= 440 && my >= 350 && my <= 420){
			volumeHovering = true;
		}
		else if (mx >= 200 && mx <= 350 && my >= 250 && my <= 320){
			instructionsHovering = true;
		}
		else if (mx >= 200 && mx <= 350 && my >= 150 && my <= 220){
			gameLogHovering = true;
		}
		else{
			volumeHovering = false;
			instructionsHovering = false;
			gameLogHovering = false;
		}
	}
}

void optionScreenClick(int mx, int my){
	if (gamePage == 3 && !instructionOn && !gameLogOn){
		if (mx >= 370 && mx <= 440 && my >= 350 && my <= 420){
			if (volumeOn){
				volumeOn = false;
			}
			else {
				volumeOn = true;
			}
		}
		else if (mx >= 200 && mx <= 350 && my >= 250 && my <= 320){
			instructionOn = true;
		}
		else if (mx >= 200 && mx <= 350 && my >= 150 && my <= 220){
			gameLogOn = true;
			loadPlayerList();
		}
	}
}

void buttonAction(int mx, int my){
	if (gamePage == 0 && mx >= b[0].x && mx <= b[0].x + b[0].width && my >= b[0].y && my <= b[0].y + b[0].height){
		activateSaveSystem();
	}

	else if (gamePage == 0 && mx >= b[1].x && mx <= b[1].x + b[1].width && my >= b[1].y && my <= b[1].y + b[1].height){
		gamePage = 2;
	}

	else if (gamePage == 0 && mx >= b[2].x && mx <= b[2].x + b[2].width && my >= b[2].y && my <= b[2].y + b[2].height){
		previousGamePage = 0;
		gamePage = 3;
	}

	else if (gamePage == 0 && mx >= b[3].x && mx <= b[3].x + b[3].width && my >= b[3].y && my <= b[3].y + b[3].height){
		isQuitting = true;
		b[3].isClicked = false;
		quitScreenHover(mx, my);
		quitScreenClick(mx, my);
	}
}



#endif