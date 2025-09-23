#ifndef PUZZLE_H
#define PUZZLE_H

#define CRYSTAL_WIDTH 120
#define CRYSTAL_HEIGHT 100
#define FLOWER_WIDTH 110
#define FLOWER_HEIGHT 90
#define ROCK_WIDTH 140
#define ROCK_HEIGHT 30
#define MAX_TRY 3
#define HEART_X 50
#define HEART_Y 500
#define HEART_W 300
#define HEART_H 60



int crystal[12];
int flower[12];
int rock;
int back1;
int back2;
int tries1 = MAX_TRY;
int tries2 = MAX_TRY;


int puzzleTry[4];

void updateTry(int t){
	if (t == 3){
		iShowImage(HEART_X, HEART_Y, HEART_W, HEART_H, puzzleTry[0]);
	}
	if (t == 2){
		iShowImage(HEART_X, HEART_Y, HEART_W, HEART_H, puzzleTry[1]);
	}
	if (t == 1){
		iShowImage(HEART_X, HEART_Y, HEART_W, HEART_H, puzzleTry[2]);
	}
	if (t == 0){
		iShowImage(HEART_X, HEART_Y, HEART_W, HEART_H, puzzleTry[3]);
	}
}

int crystalOrder[4] = { 0, 1, 2, 3 };

void randomOrder1(){
	for (int i = 3; i > 0; i--){
		int j = rand() % (i + 1);
		int temp = crystalOrder[i];
		crystalOrder[i] = crystalOrder[j];
		crystalOrder[j] = temp;
	}
}

int flowerOrder[6] = { 0, 1, 2, 3, 4, 5 };

void randomOrder2(){
	for (int i = 5; i > 0; i--){
		int j = rand() % (i + 1);
		int temp = flowerOrder[i];
		flowerOrder[i] = flowerOrder[j];
		flowerOrder[j] = temp;
	}
}

void loadPuzzle(){
	puzzleTry[0] = iLoadImage("heart1.png");
	puzzleTry[1] = iLoadImage("heart2.png");
	puzzleTry[2] = iLoadImage("heart3.png");
	puzzleTry[3] = iLoadImage("heart4.png");

	crystal[0] = iLoadImage("puzzle\\b1.png");
	crystal[1] = iLoadImage("puzzle\\g1.png");
	crystal[2] = iLoadImage("puzzle\\v1.png");
	crystal[3] = iLoadImage("puzzle\\w1.png");
	crystal[4] = iLoadImage("puzzle\\b2.png");
	crystal[5] = iLoadImage("puzzle\\g2.png");
	crystal[6] = iLoadImage("puzzle\\v2.png");
	crystal[7] = iLoadImage("puzzle\\w2.png");
	crystal[8] = iLoadImage("puzzle\\b3.png");
	crystal[9] = iLoadImage("puzzle\\g3.png");
	crystal[10] = iLoadImage("puzzle\\v3.png");
	crystal[11] = iLoadImage("puzzle\\w3.png");
	rock = iLoadImage("puzzle\\rock.png");
	back1 = iLoadImage("puzzle\\winterPuzzle.png");
	randomOrder1();

	flower[0] = iLoadImage("puzzle\\1.png");
	flower[1] = iLoadImage("puzzle\\2.png");
	flower[2] = iLoadImage("puzzle\\3.png");
	flower[3] = iLoadImage("puzzle\\4.png");
	flower[4] = iLoadImage("puzzle\\5.png");
	flower[5] = iLoadImage("puzzle\\6.png");
	flower[6] = iLoadImage("puzzle\\7.png");
	flower[7] = iLoadImage("puzzle\\8.png");
	flower[8] = iLoadImage("puzzle\\9.png");
	flower[9] = iLoadImage("puzzle\\10.png");
	flower[10] = iLoadImage("puzzle\\11.png");
	flower[11] = iLoadImage("puzzle\\12.png");
	back2 = iLoadImage("puzzle\\springPuzzle.png");
	randomOrder2();
}

//puzzle of winter
bool puzzle1Checked = false;

struct Crystal{
	int x, y;
	int mainX, mainY;
	int w, h;
	bool selected;
	bool placed;
	bool correct;
	int indexImg;
	int placedIndex;
};

Crystal crystals[4] = {
	{ 360, 110, 360, 100, CRYSTAL_WIDTH, CRYSTAL_HEIGHT, false, false, false, 0, -1 },
	{ 580, 110, 580, 100, CRYSTAL_WIDTH, CRYSTAL_HEIGHT, false, false, false, 1, -1 },
	{ 800, 110, 800, 100, CRYSTAL_WIDTH, CRYSTAL_HEIGHT, false, false, false, 2, -1 },
	{ 1020, 110, 1020, 100, CRYSTAL_WIDTH, CRYSTAL_HEIGHT, false, false, false, 3, -1 }
};

int rockX[4] = { 320, 560, 800, 1040 };
int rockY = 300;
bool rockOccupied[4] = { false, false, false, false };

bool allCrystalsPlaced() {
	for (int i = 0; i < 4; i++) {
		if (crystals[i].placedIndex == -1)
			return false;
	}
	return true;
}

void showPuzzle1(){
	if (puzzleLevel == 1){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, back1);
		for (int i = 0; i < 4; i++){
			iShowImage(rockX[i], rockY, ROCK_WIDTH, ROCK_HEIGHT, rock);
		}

		updateTry(tries1);

		if (puzzle1Completed){
			iText(600, 200, "Puzzle Completed! Press 'ENTER'.", GLUT_BITMAP_HELVETICA_18);
		}
		else if (!puzzle1Completed && tries1 <= MAX_TRY && tries1 > 0 && allCrystalsPlaced()){
			iText(600, 160, "Incorrect! Press 'Enter' to try again.", GLUT_BITMAP_HELVETICA_18);
		}
		else if (tries1 == 0 && allCrystalsPlaced()){
			iText(600, 160, "No more tries! Press 'Enter' to restart puzzle.", GLUT_BITMAP_HELVETICA_18);
		}
	}
}

void showCrystal(Crystal c){
	if (!c.selected && !c.correct){
		iShowImage(c.x, c.y, c.w, c.h, crystal[c.indexImg]);
	}
	else if (c.selected && !c.placed){
		iShowImage(c.x, c.y, c.w, c.h, crystal[c.indexImg + 4]);
	}
	else if (c.placed && c.correct){
		iShowImage(c.x, c.y, c.w, c.h, crystal[c.indexImg + 8]);
	}
}

void resetPuzzle1(){
	for (int i = 0; i < 4; i++){
		rockOccupied[i] = false;
	}
	for (int i = 0; i < 4; i++){
		if (crystals[i].correct && crystals[i].placedIndex != -1){
			rockOccupied[crystals[i].placedIndex] = true;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (!crystals[i].correct) {
			crystals[i].x = crystals[i].mainX;
			crystals[i].y = crystals[i].mainY;
			crystals[i].selected = false;
			crystals[i].placed = false;
			crystals[i].placedIndex = -1;
		}
	}

	puzzle1Completed = false;
	puzzle1Checked = false;
}

void checkPuzzleOne(){
	bool allCorrect = true;
	for (int i = 0; i < 4; i++){
		if (crystals[i].placedIndex == crystalOrder[i]){
			crystals[i].correct = true;
		}
		else {
			crystals[i].correct = false; // Incorrectly placed
			allCorrect = false;
		}
	}

	puzzle1Completed = allCorrect;

	if (!allCorrect){
		tries1--;
	}
	puzzle1Checked = true;
}

void placePuzzle(int mx, int my){
	for (int i = 0; i < 4; i++) {
		// Select crystal
		if (!crystals[i].placed && !crystals[i].correct && mx >= crystals[i].x && mx <= crystals[i].x + crystals[i].w && my >= crystals[i].y && my <= crystals[i].y + crystals[i].h) {
			crystals[i].selected = true;

			for (int k = 0; k < 4; k++) crystals[k].selected = false;

			crystals[i].selected = true;
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (crystals[i].selected) {
			for (int j = 0; j < 4; j++) {
				if (!rockOccupied[j] && mx >= rockX[j] && mx <= rockX[j] + ROCK_WIDTH && my >= rockY && my <= rockY + ROCK_HEIGHT + 70) {

					crystals[i].x = rockX[j] + 10;
					crystals[i].y = rockY + ROCK_HEIGHT;
					crystals[i].placedIndex = j;
					crystals[i].selected = false;
					crystals[i].placed = true;
					rockOccupied[j] = true;
					break;
				}
			}
			break;
		}
	}

	if (allCrystalsPlaced() && !puzzle1Completed && !puzzle1Checked) {
		checkPuzzleOne();
	}
}

void resetEntirePuzzle1() {
	randomOrder1();

	for (int i = 0; i < 4; i++) {
		crystals[i].x = crystals[i].mainX;
		crystals[i].y = crystals[i].mainY;
		crystals[i].selected = false;
		crystals[i].placed = false;
		crystals[i].correct = false;
		crystals[i].placedIndex = -1;
		rockOccupied[i] = false;
	}

	puzzle1Completed = false;
	puzzle1Checked = false;
	tries1 = MAX_TRY;
}

//puzzle of spring

int puzzle2State = 0;
bool waitingForInput = false;
bool playingSequence = false;
int tunePlaybackIndex = 0;
bool puzzle2Checked = false;

int currentTuneIndex = 0;
bool isPlayingTunes = false;
DWORD lastTuneTime = 0; 
const int TUNE_DELAY = 2000;

struct Flower{
	int x, y;
	int w, h;
	bool glowing;
	bool selected;
	bool correct;
	int index;
	int indexImg;
};

Flower flowers[6] = {
	{ 400, 200, FLOWER_WIDTH, FLOWER_HEIGHT, false, false, false, 0, 0 },
	{ 695, 200, FLOWER_WIDTH, FLOWER_HEIGHT, false, false, false, 1, 1 },
	{ 990, 200, FLOWER_WIDTH, FLOWER_HEIGHT, false, false, false, 2, 2 },
	{ 400, 390, FLOWER_WIDTH, FLOWER_HEIGHT, false, false, false, 3, 3 },
	{ 695, 390, FLOWER_WIDTH, FLOWER_HEIGHT, false, false, false, 4, 4 },
	{ 990, 390, FLOWER_WIDTH, FLOWER_HEIGHT, false, false, false, 5, 5 }
};

void showFlower(Flower f){
	if (!f.selected && !f.glowing){
		iShowImage(f.x, f.y, f.w, f.h, flower[f.indexImg]);
	}
	else if (f.selected || f.glowing){
		iShowImage(f.x, f.y, f.w, f.h, flower[f.indexImg + 6]);
	}
}

int selectOrder[6] = { -1, -1, -1, -1, -1, -1 };
int playerIndex = 0;

bool allFlowerSelected(){
	for (int i = 0; i < 6; i++) {
		if (flowers[i].selected == false)
			return false;
	}
	return true;
}

void showPuzzle2(){
	if (puzzleLevel == 2){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, back2);

		updateTry(tries2);

		if (puzzle2Completed){
			iText(600, 500, "Puzzle Completed! Press 'ENTER'.", GLUT_BITMAP_HELVETICA_18);
		}
		else if (!puzzle2Completed && tries2 <= MAX_TRY && tries2 > 0 && playerIndex == 6){
			iText(600, 500, "Incorrect! Press 'Enter' to try again.", GLUT_BITMAP_HELVETICA_18);
		}
		else if (tries2 == 0 && playerIndex == 6){
			iText(600, 500, "No more tries! Press 'Enter' to restart puzzle.", GLUT_BITMAP_HELVETICA_18);
		}
		else if (puzzle2State == 0 && isPlayingTunes){
			iText(600, 340, "Hear the fragments of Lullaby...", GLUT_BITMAP_HELVETICA_18);
		}
		else if (puzzle2State == 1 && !isPlayingTunes && playerIndex < 6){
			char msg[100];
			sprintf_s(msg, "Flowers Selected (%d/6)", playerIndex);
			iText(650, 340, msg, GLUT_BITMAP_HELVETICA_18);
		}
	}
}

void playPuzzleSound(){
	DWORD now = GetTickCount();

	if (isPlayingTunes && tunePlaybackIndex < 6) {
		if (now - lastTuneTime >= TUNE_DELAY) {

			if (tunePlaybackIndex > 0) {
				int prevIndex = flowerOrder[tunePlaybackIndex - 1];
				char stopCmd[50];
				sprintf_s(stopCmd, "stop %d", prevIndex + 1);
				mciSendString(stopCmd, NULL, 0, NULL);
				flowers[prevIndex].glowing = false;
			}

			currentTuneIndex = flowerOrder[tunePlaybackIndex];
			char playCmd[50];
			sprintf_s(playCmd, "play %d from 0", currentTuneIndex + 1);
			mciSendString(playCmd, NULL, 0, NULL);
			flowers[currentTuneIndex].glowing = true;

			lastTuneTime = now;
			tunePlaybackIndex++;
		}
	}

	if (isPlayingTunes && tunePlaybackIndex == 6 && now - lastTuneTime >= TUNE_DELAY) {
		int lastIndex = flowerOrder[5];
		char stopCmd[50];
		sprintf_s(stopCmd, "stop %d", lastIndex + 1);
		mciSendString(stopCmd, NULL, 0, NULL);
		flowers[lastIndex].glowing = false;

		isPlayingTunes = false;
		puzzle2State = 1;
	}
}

void checkPuzzleTwo(){
	bool allCorrect = true;
	for (int i = 0; i < 6; i++){
		if (selectOrder[i] == flowerOrder[i]){
			flowers[i].correct = true;
		}
		else {
			flowers[i].correct = false;
			allCorrect = false;
		}
	}

	puzzle2Completed = allCorrect;

	if (!allCorrect){
		tries2--;
	}

	puzzle2Checked = true;
}

void selectPuzzle(int mx, int my){
	if (puzzle2State != 1 || isPlayingTunes) return; 

	for (int i = 0; i < 6; i++) {
		if (!flowers[i].selected && !flowers[i].correct &&
			mx >= flowers[i].x && mx <= flowers[i].x + flowers[i].w &&
			my >= flowers[i].y && my <= flowers[i].y + flowers[i].h) {

			flowers[i].selected = true;
			selectOrder[playerIndex] = flowers[i].index;
			playerIndex++;
			break; 
		}
	}

	if (allFlowerSelected() && !puzzle2Completed && !puzzle2Checked) {
		checkPuzzleTwo();
	}
}

void resetPuzzle2(){
	for (int i = 0; i < 6; i++) {
		flowers[i].selected = false;
		flowers[i].correct = false;
		selectOrder[i] = -1;
	}
	playerIndex = 0;
	puzzle2Completed = false;
	puzzle2Checked = false;
}

void resetEntirePuzzle2() {
	randomOrder2();

	for (int i = 0; i < 6; i++) {
		flowers[i].selected = false;
		flowers[i].glowing = false;
		flowers[i].correct = false;
		selectOrder[i] = -1;
	}

	playerIndex = 0;
	puzzle2Completed = false;
	puzzle2Checked = false;
	tries2 = MAX_TRY;
}








#endif