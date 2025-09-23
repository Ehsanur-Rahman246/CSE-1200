#ifndef UTILS_H
#define UTILS_H


#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 600

int gamePage = 0;
bool volumeOn = true;


bool storyPlayed[15] = { false };

int mouseX = 0;
int mouseY = 0;
bool isMapOn = false;
bool musicOn = false;
bool storyTelling = false;
int storyAnimation;
int textAnimation;
bool showText = false;
int msgAnimation;
int storyState = 0;
int msgState = 0;

bool volumeHovering = false;
bool instructionsHovering = false;
bool gameLogHovering = false;
bool instructionOn = false;
bool gameLogOn = false;



int gameLevel = 0;
int puzzleLevel = 0;
int battleLevel = 0;

bool level1Completed = false;
bool level2Completed = false;
bool level3Completed = false;
bool level4Completed = false;
bool puzzle1Completed = false;
bool puzzle2Completed = false;
bool puzzle3Completed = false;
bool puzzle4Completed = false;
bool battle1Completed = false;
bool battle2Completed = false;
bool battle3Completed = false;
bool battle4Completed = false;

int obstacleAnimation;

int bossAnimation;
int bossAttackTimer;
bool battleOngoing = false;

int battle1;
int battle2;
bool battle1Over = false;
bool battle2Over = false;
int healthBar;
int magicBar[7];
int icon[5];
bool battleWon = false;

bool boss1Attacking = false;
bool boss2Attacking = false;
int boss1AttackFrame = 0;
int boss2AttackFrame = 0;
bool projectileActive = false;
int projectileX = 0;
int projectileY = 0;
int projectileSpeed = 5;

int attackMaxFrames[4] = { 12, 15, 16, 15 };
int currentAttack = 0;
bool isBlocking = false;
int blockFrame = 0;
bool attackKeyPressed = false;
bool blockKeyPressed = false;
int blockAnimation;

bool attack2EffectActive = false;
int attack2EffectFrame = 0;
int attack2EffectTimer;
bool boss1Frozen = false;
bool boss2Frozen = false;
int freezeTimer = 0;
bool attack2Cooldown = false;


bool attack3EffectActive = false;
int attack3EffectTimer;
int freezeEffectTimer;
int attack3EffectFrame = 0;
int attack3ProjectileX = 0;
int attack3ProjectileY = 0;
bool attack3ProjectileMoving = false;


bool attack4EffectActive = false;
int attack4EffectFrame = 0;
int attack4EffectTimer;

bool attack2CloseToBoss = false;
int originalBattleX = 0;


bool hasHitBoss = false;

int battle1X = 200;
int battle2X = 200;
int battleY = 200;

int boss1X = 900;
int boss2X = 900;
int bossY = 200;

int playerCurrentHealth = 1000;
int maxPlayerHealth = 1000;
int bossCurrentHealth = 1000;
int maxBossHealth = 1000;
int bossHealthX = 500;
int currentMana = 200;

bool level1StoryPlayed = false;
bool level2StoryPlayed = false;
bool puzzle1StoryPlayed = false;
bool puzzle2StoryPlayed = false;
bool enterKeyProcessed = false;
DWORD lastStoryCompleteTime = 0;


bool isLoading = true;
int loadingBgFrame = 0;
int loadingBarFrame = 0;
int maxLoadingBgFrames = 21;
int maxLoadingBarFrames = 100;
int loadingBgTimer, loadingBarTimer;

int loadTextIndex = rand() % 6;
int loadTxt;

void loadImages();
void loadStory();
void loadLevels();
void loadObstacles();
void loadPuzzle();
void loadBattle();

int loadBack[21];
void loadingImg(){
	for (int i = 0; i < 21; i++){
		char l[50];
		sprintf_s(l, "loading\\l (%d).png", i + 1);
		loadBack[i] = iLoadImage(l);
	}
}

void generateIndex(){
	loadTextIndex = rand() % 6;
}

void simulateResourceLoading() {
	if (loadingBarFrame == 20) {
		loadImages();
	}
	else if (loadingBarFrame == 35) {
		loadStory();
	}
	else if (loadingBarFrame == 52) {
		loadLevels();
	}
	else if (loadingBarFrame == 68) {
		loadObstacles();
	}
	else if (loadingBarFrame == 84){
		loadPuzzle();
	}
	else if (loadingBarFrame == 97){
		loadBattle();
	}
}

void updateLoadingBar() {
	if (loadingBarFrame < maxLoadingBarFrames - 1) {
		loadingBarFrame++;
		simulateResourceLoading();
	}
	else {
		isLoading = false;
		gamePage = 0;
		iPauseTimer(loadingBgTimer);
		iPauseTimer(loadingBarTimer);
		iPauseTimer(loadTxt);
	}
}

void updateLoadingBg() {
	if (isLoading) {
		loadingBgFrame = (loadingBgFrame + 1) % maxLoadingBgFrames;
	}
}


#endif