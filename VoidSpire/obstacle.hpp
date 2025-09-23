#ifndef OBSTACLE_H
#define OBSTACLE_H

#define OBSTACLE_WIDTH 50
#define OBSTACLE_Y 80
#define BIG_HEIGHT 60
#define SMALL_HEIGHT 40
#define FLOOR_HEIGHT 20
#define H_1 80
#define H_2 60
#define H_3 40
#define H_4 20
#define CHARACTER_WIDTH 50
#define CHARACTER_HEIGHT 70

#define HEART_SIZE 50

#define SP_MAX_FRAME 4
int spF1 = 0;
int spF2 = 4;
int spF3 = 8;
int spF4 = 12;
int h1 = H_4, h2 = H_4, h3 = H_4, h4 = H_4;

struct Winter{
	int x, y;
	int width, height;
	int index;
};

struct Spring{
	int x, y;
	int width, height;
	int index;
};


int winter[5];
int spring[16];
int summer[4];
int autumn[4];
int heartF;
int heartE;
void loadObstacles(){
	for (int i = 0; i < 5; i++){
		char a[50];
		sprintf_s(a, "obstacle\\w%d.png", i + 1);
		winter[i] = iLoadImage(a);
	}
	int k = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			char b[50];
			sprintf_s(b, "obstacle\\sp-%d-%d.png", i + 1, j + 1);
			spring[k++] = iLoadImage(b);
		}
	}
	/*for (int i = 0; i < 4; i++){
		char c[50];
		sprintf_s(c, "obstacle\\su%d.png", i + 1);
		summer[i] = iLoadImage(c);
	}
	for (int i = 0; i < 4; i++){
		char d[50];
		sprintf_s(d, "obstacle\\a%d.png", i + 1);
		autumn[i] = iLoadImage(d);
	}*/
	heartF = iLoadImage("heartfull.png");
	heartE = iLoadImage("heartempty.png");
}

int obstacle1X = 0;
int obstacle2X = 0;
int obstacle3X = 0;
int obstacle4X = 0;

Winter w[15] = {
	{ 600, OBSTACLE_Y, OBSTACLE_WIDTH, BIG_HEIGHT, 0 },
	{ 900, OBSTACLE_Y, OBSTACLE_WIDTH, BIG_HEIGHT, 2 },
	{ 1200, OBSTACLE_Y, OBSTACLE_WIDTH, SMALL_HEIGHT, 1 },
	{ 1500, OBSTACLE_Y, OBSTACLE_WIDTH, SMALL_HEIGHT, 3 },
	{ 1800, OBSTACLE_Y - 5, OBSTACLE_WIDTH, FLOOR_HEIGHT, 4 },
	{ 2100, OBSTACLE_Y, OBSTACLE_WIDTH, SMALL_HEIGHT, 1 },
	{ 2400, OBSTACLE_Y, OBSTACLE_WIDTH, BIG_HEIGHT, 0 },
	{ 2700, OBSTACLE_Y, OBSTACLE_WIDTH, BIG_HEIGHT, 2 },
	{ 3000, OBSTACLE_Y, OBSTACLE_WIDTH, SMALL_HEIGHT, 3 },
	{ 3300, OBSTACLE_Y - 5, OBSTACLE_WIDTH, FLOOR_HEIGHT, 4 },
	{ 3600, OBSTACLE_Y, OBSTACLE_WIDTH, BIG_HEIGHT, 2 },
	{ 3900, OBSTACLE_Y, OBSTACLE_WIDTH, SMALL_HEIGHT, 1 },
	{ 4200, OBSTACLE_Y - 5, OBSTACLE_WIDTH, FLOOR_HEIGHT, 4 },
	{ 4500, OBSTACLE_Y, OBSTACLE_WIDTH, SMALL_HEIGHT, 3 },
	{ 4800, OBSTACLE_Y, OBSTACLE_WIDTH, BIG_HEIGHT, 0 }
};


Spring sp[8] = {
	{ 600, OBSTACLE_Y, OBSTACLE_WIDTH, h1, spF1 },
	{ 900, OBSTACLE_Y, OBSTACLE_WIDTH, h2, spF2 },
	{ 1200, OBSTACLE_Y, OBSTACLE_WIDTH, h3, spF3 },
	{ 1500, OBSTACLE_Y, OBSTACLE_WIDTH, h4, spF4 },
	{ 1800, OBSTACLE_Y, OBSTACLE_WIDTH, h2, spF2 },
	{ 2100, OBSTACLE_Y, OBSTACLE_WIDTH, h4, spF4 },
	{ 2400, OBSTACLE_Y, OBSTACLE_WIDTH, h3, spF3 },
	{ 2700, OBSTACLE_Y, OBSTACLE_WIDTH, h1, spF1 }
};

void spObstacle(){
	static int globalFrame = 0;
	globalFrame++;

	if (globalFrame >= SP_MAX_FRAME) {
		globalFrame = 0;
	}

	int currentHeight;
	switch (globalFrame) {
	case 0: currentHeight = H_4; break;
	case 1: currentHeight = H_3; break;
	case 2: currentHeight = H_2; break;
	case 3: currentHeight = H_1; break;
	default: currentHeight = H_4; break;
	}

	for (int i = 0; i < 8; i++) {
		sp[i].height = currentHeight;
		sp[i].index = globalFrame + (i % 4) * 4;
	}
}


int health1 = 3;
int health2 = 3;
bool game1Over = false;
bool game2Over = false;


struct Heart{
	int x, y;
	int width, height;
	bool full;
};

Heart heart1[3] = {
	{ 300, 400, HEART_SIZE, HEART_SIZE, true },
	{ 400, 400, HEART_SIZE, HEART_SIZE, true },
	{ 500, 400, HEART_SIZE, HEART_SIZE, true }
};
Heart heart2[3] = {
	{ 300, 400, HEART_SIZE, HEART_SIZE, true },
	{ 400, 400, HEART_SIZE, HEART_SIZE, true },
	{ 500, 400, HEART_SIZE, HEART_SIZE, true }
};

void updateHealth(int h, Heart heart[]){
	for (int i = 0; i < 3; i++){
		if (i < h){
			heart[i].full = true;
		}
		else {
			heart[i].full = false;
		}
	}
}


void obstacleShow1(Winter w){
	if (gameLevel == 1){
		iShowImage(obstacle1X + w.x, w.y, w.width, w.height, winter[w.index]);
		if (game1Over){
			iSetColor(255, 255, 255);
			iText(500, 400, "YOU STUMBLED!! Press 'R' to restart.", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (level1Completed){
			iSetColor(255, 255, 255);
			iText(500, 400, "LEVEL COMPLETED!! Press 'ENTER'.", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (!game1Over && !level1Completed){
			if (puzzleLevel == 0){
				for (int i = 0; i < 3; i++){
					if (heart1[i].full){
						iShowImage(heart1[i].x, heart1[i].y, heart1[i].width, heart1[i].height, heartF);
					}
					else {
						iShowImage(heart1[i].x, heart1[i].y, heart1[i].width, heart1[i].height, heartE);
					}
				}
			}
		}
	}
}

void obstacleShow2(Spring sp){
	if (gameLevel == 2){
		iShowImage(obstacle2X + sp.x, sp.y, sp.width, sp.height, spring[sp.index]);
		if (game2Over){
			iSetColor(0, 0, 0);
			iText(500, 400, "YOU STUMBLED!! Press 'R' to restart.", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (level2Completed){
			iSetColor(0, 0, 0);
			iText(500, 400, "LEVEL COMPLETED!! Press 'ENTER'.", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (!game2Over && !level2Completed){
			if (puzzleLevel == 0){
				for (int i = 0; i < 3; i++){
					if (heart2[i].full){
						iShowImage(heart2[i].x, heart2[i].y, heart2[i].width, heart2[i].height, heartF);
					}
					else {
						iShowImage(heart2[i].x, heart2[i].y, heart2[i].width, heart2[i].height, heartE);
					}
				}
			}
		}
	}
}



bool isHit1(){
	int marginX = 25;
	int marginY = 10;

	int charLeft = character1X + marginX;
	int charRight = character1X + CHARACTER_WIDTH - marginX;
	int charTop = characterY + CHARACTER_HEIGHT - marginY;
	int charBottom = characterY + marginY;

	for (int i = 0; i < 15; i++) {
		int obsX = obstacle1X + w[i].x;
		int obsY = w[i].y;
		int obsW = w[i].width;
		int obsH = w[i].height;

		if (!(charRight< obsX || charLeft > obsX + obsW || charTop< obsY || charBottom > obsY + obsH)) {
			return true;
		}
	}
	return false;
}

bool isHit2(){
	int marginX = 25;
	int marginY = 10;

	int charLeft = character2X + marginX;
	int charRight = character2X + CHARACTER_WIDTH - marginX;
	int charTop = characterY + CHARACTER_HEIGHT - marginY;
	int charBottom = characterY + marginY;

	for (int i = 0; i < 8; i++) {
		int obsX = obstacle2X + sp[i].x;
		int obsY = sp[i].y;
		int obsW = sp[i].width;
		int obsH = sp[i].height;

		if (!(charRight< obsX || charLeft > obsX + obsW || charTop< obsY || charBottom > obsY + obsH)) {
			return true;
		}
	}
	return false;
}


#endif