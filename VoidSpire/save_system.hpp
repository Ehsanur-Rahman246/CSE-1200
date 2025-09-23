#ifndef SAVE_SYSTEM_H
#define SAVE_SYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string currentPlayerName = "";

// Forward declarations for external variables
extern int gameProgress;
extern int gamePage;
extern int gameLevel;
extern int puzzleLevel;
extern int battleLevel;
extern bool isMapOn;
extern bool level1Completed;
extern bool level2Completed;
extern bool puzzle1Completed;
extern bool puzzle2Completed;
extern bool battle1Completed;
extern bool battle2Completed;
extern bool storyPlayed[15];
extern bool progressTracked[25];
extern int character1X;
extern int character2X;
extern int health1;
extern int health2;
extern int tries1;
extern int tries2;

// Battle variables
extern int battle1X;
extern int battle2X;
extern int battleY;
extern int boss1X;
extern int boss2X;
extern int bossY;
extern int playerCurrentHealth;
extern int maxPlayerHealth;
extern int bossCurrentHealth;
extern int maxBossHealth;
extern int currentMana;
extern bool battleOngoing;
extern bool battle1Over;
extern bool battle2Over;
extern bool battleWon;
extern bool boss1Attacking;
extern bool boss2Attacking;
extern int boss1AttackFrame;
extern int boss2AttackFrame;
extern bool boss1Frozen;
extern bool boss2Frozen;
extern bool attack2Cooldown;
extern int currentAttack;
extern bool projectileActive;
extern int projectileX;
extern int projectileY;

// Movement and animation variables
extern bool isFacingRight;
extern bool isRunning;
extern bool isJumping;
extern bool isAttacking;
extern bool isBlocking;
extern int runFrame;
extern int jumpFrame;
extern int attackFrame;
extern int blockFrame;
extern int characterY;
extern int jumpState;

// Level variables
extern float game1X;
extern float game1X1;
extern float game1X2;
extern float game1X3;
extern float game1X4;
extern float game2X;
extern float game2X1;
extern float game2X2;
extern float game2X3;
extern float game2X4;
extern float game2X5;
extern int obstacle1X;
extern int obstacle2X;
extern bool game1Over;
extern bool game2Over;

// Puzzle variables
extern int crystalOrder[4];
extern int flowerOrder[6];
extern int puzzle2State;
extern bool puzzle1Checked;
extern bool puzzle2Checked;
extern int playerIndex;
extern int selectOrder[6];
extern int tunePlaybackIndex;
extern bool isPlayingTunes;

// Story variables
extern int storyState;
extern bool storyTelling;
extern int storyFrame;

// Audio and UI variables
extern bool volumeOn;
extern bool musicOn;
extern bool isPaused;
extern bool showText;
extern int msgState;

// Forward declarations for story functions
void startStory(int state);
bool shouldPlayStory(int state);

// Save system states
enum SaveState {
	SAVE_MENU = 0,
	NAME_INPUT_NEW = 1,
	NAME_INPUT_RESUME = 2,
	RESUME_OPTIONS = 3,
	ERROR_DISPLAY = 4
};

// Enhanced Game save data structure
struct GameSaveData {
	char playerName[50];

	// Progress and levels
	int gameProgress;
	int gamePage;
	int gameLevel;
	int puzzleLevel;
	int battleLevel;

	// Completion flags
	bool isMapOn;
	bool level1Completed;
	bool level2Completed;
	bool puzzle1Completed;
	bool puzzle2Completed;
	bool battle1Completed;
	bool battle2Completed;

	// Story and progress tracking
	bool storyPlayed[15];
	bool progressTracked[25];

	// Character positions and health
	int character1X;
	int character2X;
	int characterY;
	int health1;
	int health2;
	int tries1;
	int tries2;

	// Battle variables
	int battle1X;
	int battle2X;
	int battleY;
	int boss1X;
	int boss2X;
	int bossY;
	int playerCurrentHealth;
	int maxPlayerHealth;
	int bossCurrentHealth;
	int maxBossHealth;
	int currentMana;
	bool battleOngoing;
	bool battle1Over;
	bool battle2Over;
	bool battleWon;
	bool boss1Attacking;
	bool boss2Attacking;
	int boss1AttackFrame;
	int boss2AttackFrame;
	bool boss1Frozen;
	bool boss2Frozen;
	bool attack2Cooldown;
	int currentAttack;
	bool projectileActive;
	int projectileX;
	int projectileY;

	// Movement and animation
	bool isFacingRight;
	bool isRunning;
	bool isJumping;
	bool isAttacking;
	bool isBlocking;
	int runFrame;
	int jumpFrame;
	int attackFrame;
	int blockFrame;
	int jumpState;

	// Level positions
	float game1X;
	float game1X1;
	float game1X2;
	float game1X3;
	float game1X4;
	float game2X;
	float game2X1;
	float game2X2;
	float game2X3;
	float game2X4;
	float game2X5;
	int obstacle1X;
	int obstacle2X;
	bool game1Over;
	bool game2Over;

	// Puzzle variables
	int crystalOrder[4];
	int flowerOrder[6];
	int puzzle2State;
	bool puzzle1Checked;
	bool puzzle2Checked;
	int playerIndex;
	int selectOrder[6];
	int tunePlaybackIndex;
	bool isPlayingTunes;

	// Story variables
	int storyState;
	bool storyTelling;
	int storyFrame;

	// Audio and UI
	bool volumeOn;
	bool musicOn;
	bool isPaused;
	bool showText;
	int msgState;

	GameSaveData() {
		strcpy_s(playerName, "");
		gameProgress = 0;
		gamePage = 0;
		gameLevel = 0;
		puzzleLevel = 0;
		battleLevel = 0;
		isMapOn = false;
		level1Completed = false;
		level2Completed = false;
		puzzle1Completed = false;
		puzzle2Completed = false;
		battle1Completed = false;
		battle2Completed = false;

		for (int i = 0; i < 15; i++) storyPlayed[i] = false;
		for (int i = 0; i < 25; i++) progressTracked[i] = false;

		character1X = 200;
		character2X = 200;
		characterY = 80;
		health1 = 3;
		health2 = 3;
		tries1 = 3;
		tries2 = 3;

		// Battle defaults
		battle1X = 200;
		battle2X = 200;
		battleY = 200;
		boss1X = 900;
		boss2X = 900;
		bossY = 200;
		playerCurrentHealth = 1000;
		maxPlayerHealth = 1000;
		bossCurrentHealth = 1000;
		maxBossHealth = 1000;
		currentMana = 200;
		battleOngoing = false;
		battle1Over = false;
		battle2Over = false;
		battleWon = false;
		boss1Attacking = false;
		boss2Attacking = false;
		boss1AttackFrame = 0;
		boss2AttackFrame = 0;
		boss1Frozen = false;
		boss2Frozen = false;
		attack2Cooldown = false;
		currentAttack = 0;
		projectileActive = false;
		projectileX = 0;
		projectileY = 0;

		// Movement defaults
		isFacingRight = true;
		isRunning = false;
		isJumping = false;
		isAttacking = false;
		isBlocking = false;
		runFrame = 0;
		jumpFrame = 0;
		attackFrame = 0;
		blockFrame = 0;
		jumpState = 0;

		// Level defaults
		game1X = 0;
		game1X1 = 0;
		game1X2 = 0;
		game1X3 = 0;
		game1X4 = 0;
		game2X = 0;
		game2X1 = 0;
		game2X2 = 0;
		game2X3 = 0;
		game2X4 = 0;
		game2X5 = 0;
		obstacle1X = 0;
		obstacle2X = 0;
		game1Over = false;
		game2Over = false;

		// Puzzle defaults
		for (int i = 0; i < 4; i++) crystalOrder[i] = i;
		for (int i = 0; i < 6; i++) {
			flowerOrder[i] = i;
			selectOrder[i] = -1;
		}
		puzzle2State = 0;
		puzzle1Checked = false;
		puzzle2Checked = false;
		playerIndex = 0;
		tunePlaybackIndex = 0;
		isPlayingTunes = false;

		// Story defaults
		storyState = 0;
		storyTelling = false;
		storyFrame = 0;

		// Audio and UI defaults
		volumeOn = true;
		musicOn = false;
		isPaused = false;
		showText = false;
		msgState = 0;
	}
};

// Global save system variables
SaveState currentSaveState = SAVE_MENU;
string saveInputName = "";
string saveErrorMessage = "";
bool saveNameInputActive = false;
bool saveSystemActive = false;
string resumePlayerName = "";

// Function declarations
void showSaveSystem();
void handleSaveInput(unsigned char key);
void savePlayerName(const string& playerName);
bool loadPlayerName(const string& playerName);
bool checkPlayerNameExists(const string& playerName);
void saveGameData(const string& playerName);
bool loadGameData(const string& playerName);
void deleteGameData(const string& playerName);
void collectCurrentGameState(GameSaveData& saveData, const string& playerName);
void applyLoadedGameState(const GameSaveData& saveData);
void activateSaveSystem();
void deactivateSaveSystem();
void resetGameProgress();

// File operations
void savePlayerName(const string& playerName) {

	vector<pair<string, int>> allPlayers;

	ifstream inFile("playernames.txt");
	if (inFile.is_open()) {
		string line;
		while (getline(inFile, line)) {
			size_t spacePos = line.find_last_of(' ');
			if (spacePos != string::npos) {
				string existingName = line.substr(0, spacePos);
				int existingProgress = stoi(line.substr(spacePos + 1));
				if (existingName != playerName) {
					allPlayers.push_back({ existingName, existingProgress });
				}
			}
			else {
				if (line != playerName) {
					allPlayers.push_back({ line, 0 });
				}
			}
		}
		inFile.close();
	}

	allPlayers.push_back({ playerName, gameProgress });

	ofstream outFile("playernames.txt");
	if (outFile.is_open()) {
		for (const auto& player : allPlayers) {
			outFile << player.first << " " << player.second << endl;
		}
		outFile.close();
	}
}

bool checkPlayerNameExists(const string& playerName) {
	ifstream file("playernames.txt");
	if (!file.is_open()) {
		return false;
	}

	string line;
	while (getline(file, line)) {
		size_t spacePos = line.find_last_of(' ');
		if (spacePos != string::npos) {
			string existingName = line.substr(0, spacePos);
			if (existingName == playerName) {
				file.close();
				return true;
			}
		}
		else {
			if (line == playerName) {
				file.close();
				return true;
			}
		}
	}
	file.close();
	return false;
}

int getPlayerProgress(const string& playerName) {
	ifstream file("playernames.txt");
	if (!file.is_open()) {
		return 0;
	}

	string line;
	while (getline(file, line)) {
		size_t spacePos = line.find_last_of(' ');
		if (spacePos != string::npos) {
			string existingName = line.substr(0, spacePos);
			if (existingName == playerName) {
				int progress = stoi(line.substr(spacePos + 1));
				file.close();
				return progress;
			}
		}
		else {
			if (line == playerName) {
				file.close();
				return 0;
			}
		}
	}
	file.close();
	return 0;
}

void collectCurrentGameState(GameSaveData& saveData, const string& playerName) {
	strcpy_s(saveData.playerName, playerName.c_str());

	// Basic game state
	saveData.gameProgress = gameProgress;
	saveData.gamePage = gamePage;
	saveData.gameLevel = gameLevel;
	saveData.puzzleLevel = puzzleLevel;
	saveData.battleLevel = battleLevel;
	saveData.isMapOn = isMapOn;

	// Completion flags
	saveData.level1Completed = level1Completed;
	saveData.level2Completed = level2Completed;
	saveData.puzzle1Completed = puzzle1Completed;
	saveData.puzzle2Completed = puzzle2Completed;
	saveData.battle1Completed = battle1Completed;
	saveData.battle2Completed = battle2Completed;

	// Character state
	saveData.character1X = character1X;
	saveData.character2X = character2X;
	saveData.characterY = characterY;
	saveData.health1 = health1;
	saveData.health2 = health2;
	saveData.tries1 = tries1;
	saveData.tries2 = tries2;

	// Battle state
	saveData.battle1X = battle1X;
	saveData.battle2X = battle2X;
	saveData.battleY = battleY;
	saveData.boss1X = boss1X;
	saveData.boss2X = boss2X;
	saveData.bossY = bossY;
	saveData.playerCurrentHealth = playerCurrentHealth;
	saveData.maxPlayerHealth = maxPlayerHealth;
	saveData.bossCurrentHealth = bossCurrentHealth;
	saveData.maxBossHealth = maxBossHealth;
	saveData.currentMana = currentMana;
	saveData.battleOngoing = battleOngoing;
	saveData.battle1Over = battle1Over;
	saveData.battle2Over = battle2Over;
	saveData.battleWon = battleWon;
	saveData.boss1Attacking = boss1Attacking;
	saveData.boss2Attacking = boss2Attacking;
	saveData.boss1AttackFrame = boss1AttackFrame;
	saveData.boss2AttackFrame = boss2AttackFrame;
	saveData.boss1Frozen = boss1Frozen;
	saveData.boss2Frozen = boss2Frozen;
	saveData.attack2Cooldown = attack2Cooldown;
	saveData.currentAttack = currentAttack;
	saveData.projectileActive = projectileActive;
	saveData.projectileX = projectileX;
	saveData.projectileY = projectileY;

	// Movement and animation
	saveData.isFacingRight = isFacingRight;
	saveData.isRunning = isRunning;
	saveData.isJumping = isJumping;
	saveData.isAttacking = isAttacking;
	saveData.isBlocking = isBlocking;
	saveData.runFrame = runFrame;
	saveData.jumpFrame = jumpFrame;
	saveData.attackFrame = attackFrame;
	saveData.blockFrame = blockFrame;
	saveData.jumpState = jumpState;

	// Level positions
	saveData.game1X = game1X;
	saveData.game1X1 = game1X1;
	saveData.game1X2 = game1X2;
	saveData.game1X3 = game1X3;
	saveData.game1X4 = game1X4;
	saveData.game2X = game2X;
	saveData.game2X1 = game2X1;
	saveData.game2X2 = game2X2;
	saveData.game2X3 = game2X3;
	saveData.game2X4 = game2X4;
	saveData.game2X5 = game2X5;
	saveData.obstacle1X = obstacle1X;
	saveData.obstacle2X = obstacle2X;
	saveData.game1Over = game1Over;
	saveData.game2Over = game2Over;

	// Puzzle state
	for (int i = 0; i < 4; i++) {
		saveData.crystalOrder[i] = crystalOrder[i];
	}
	for (int i = 0; i < 6; i++) {
		saveData.flowerOrder[i] = flowerOrder[i];
		saveData.selectOrder[i] = selectOrder[i];
	}
	saveData.puzzle2State = puzzle2State;
	saveData.puzzle1Checked = puzzle1Checked;
	saveData.puzzle2Checked = puzzle2Checked;
	saveData.playerIndex = playerIndex;
	saveData.tunePlaybackIndex = tunePlaybackIndex;
	saveData.isPlayingTunes = isPlayingTunes;

	// Story state
	saveData.storyState = storyState;
	saveData.storyTelling = storyTelling;
	saveData.storyFrame = storyFrame;

	// Audio and UI
	saveData.volumeOn = volumeOn;
	saveData.musicOn = musicOn;
	saveData.isPaused = isPaused;
	saveData.showText = showText;
	saveData.msgState = msgState;

	// Copy arrays
	for (int i = 0; i < 15; i++) {
		saveData.storyPlayed[i] = storyPlayed[i];
	}
	for (int i = 0; i < 25; i++) {
		saveData.progressTracked[i] = progressTracked[i];
	}
}

void applyLoadedGameState(const GameSaveData& saveData) {
	// Set current player name
	currentPlayerName = string(saveData.playerName);

	// Basic game state
	gameProgress = saveData.gameProgress;
	gamePage = saveData.gamePage;
	gameLevel = saveData.gameLevel;
	puzzleLevel = saveData.puzzleLevel;
	battleLevel = saveData.battleLevel;
	isMapOn = saveData.isMapOn;

	// Completion flags
	level1Completed = saveData.level1Completed;
	level2Completed = saveData.level2Completed;
	puzzle1Completed = saveData.puzzle1Completed;
	puzzle2Completed = saveData.puzzle2Completed;
	battle1Completed = saveData.battle1Completed;
	battle2Completed = saveData.battle2Completed;

	// Character state
	character1X = saveData.character1X;
	character2X = saveData.character2X;
	characterY = saveData.characterY;
	health1 = saveData.health1;
	health2 = saveData.health2;
	updateHealth(health1, heart1);
	updateHealth(health2, heart2);
	tries1 = saveData.tries1;
	tries2 = saveData.tries2;

	// Battle state
	battle1X = saveData.battle1X;
	battle2X = saveData.battle2X;
	battleY = saveData.battleY;
	boss1X = saveData.boss1X;
	boss2X = saveData.boss2X;
	bossY = saveData.bossY;
	playerCurrentHealth = saveData.playerCurrentHealth;
	maxPlayerHealth = saveData.maxPlayerHealth;
	bossCurrentHealth = saveData.bossCurrentHealth;
	maxBossHealth = saveData.maxBossHealth;
	currentMana = saveData.currentMana;
	battleOngoing = saveData.battleOngoing;
	battle1Over = saveData.battle1Over;
	battle2Over = saveData.battle2Over;
	battleWon = saveData.battleWon;
	boss1Attacking = saveData.boss1Attacking;
	boss2Attacking = saveData.boss2Attacking;
	boss1AttackFrame = saveData.boss1AttackFrame;
	boss2AttackFrame = saveData.boss2AttackFrame;
	boss1Frozen = saveData.boss1Frozen;
	boss2Frozen = saveData.boss2Frozen;
	attack2Cooldown = saveData.attack2Cooldown;
	currentAttack = saveData.currentAttack;
	projectileActive = saveData.projectileActive;
	projectileX = saveData.projectileX;
	projectileY = saveData.projectileY;

	// Movement and animation
	isFacingRight = saveData.isFacingRight;
	isRunning = saveData.isRunning;
	isJumping = saveData.isJumping;
	isAttacking = saveData.isAttacking;
	isBlocking = saveData.isBlocking;
	runFrame = saveData.runFrame;
	jumpFrame = saveData.jumpFrame;
	attackFrame = saveData.attackFrame;
	blockFrame = saveData.blockFrame;
	jumpState = saveData.jumpState;

	// Level positions
	game1X = saveData.game1X;
	game1X1 = saveData.game1X1;
	game1X2 = saveData.game1X2;
	game1X3 = saveData.game1X3;
	game1X4 = saveData.game1X4;
	game2X = saveData.game2X;
	game2X1 = saveData.game2X1;
	game2X2 = saveData.game2X2;
	game2X3 = saveData.game2X3;
	game2X4 = saveData.game2X4;
	game2X5 = saveData.game2X5;
	obstacle1X = saveData.obstacle1X;
	obstacle2X = saveData.obstacle2X;
	game1Over = saveData.game1Over;
	game2Over = saveData.game2Over;

	// Puzzle state
	for (int i = 0; i < 4; i++) {
		crystalOrder[i] = saveData.crystalOrder[i];
	}
	for (int i = 0; i < 6; i++) {
		flowerOrder[i] = saveData.flowerOrder[i];
		selectOrder[i] = saveData.selectOrder[i];
	}
	puzzle2State = saveData.puzzle2State;
	puzzle1Checked = saveData.puzzle1Checked;
	puzzle2Checked = saveData.puzzle2Checked;
	playerIndex = saveData.playerIndex;
	tunePlaybackIndex = saveData.tunePlaybackIndex;
	isPlayingTunes = saveData.isPlayingTunes;

	// Story state
	storyState = saveData.storyState;
	storyTelling = saveData.storyTelling;
	storyFrame = saveData.storyFrame;

	// Audio and UI
	volumeOn = saveData.volumeOn;
	musicOn = saveData.musicOn;
	isPaused = saveData.isPaused;
	showText = saveData.showText;
	msgState = saveData.msgState;

	// Copy arrays
	for (int i = 0; i < 15; i++) {
		storyPlayed[i] = saveData.storyPlayed[i];
	}
	for (int i = 0; i < 25; i++) {
		progressTracked[i] = saveData.progressTracked[i];
	}
}

void saveGameData(const string& playerName) {
	vector<GameSaveData> allSaves;
	GameSaveData currentSave;
	collectCurrentGameState(currentSave, playerName);

	// Read existing saves
	ifstream inFile("gamesaves.dat", ios::binary);
	if (inFile.is_open()) {
		GameSaveData tempSave;
		while (inFile.read(reinterpret_cast<char*>(&tempSave), sizeof(GameSaveData))) {
			if (string(tempSave.playerName) != playerName) {
				allSaves.push_back(tempSave);
			}
		}
		inFile.close();
	}

	// Add current save
	allSaves.push_back(currentSave);

	// Write all saves back
	ofstream outFile("gamesaves.dat", ios::binary);
	if (outFile.is_open()) {
		for (const auto& save : allSaves) {
			outFile.write(reinterpret_cast<const char*>(&save), sizeof(GameSaveData));
		}
		outFile.close();
	}

	// Update progress in playernames.txt
	savePlayerName(playerName);
}

bool loadGameData(const string& playerName) {
	ifstream file("gamesaves.dat", ios::binary);
	if (!file.is_open()) {
		return false;
	}

	GameSaveData tempSave;
	while (file.read(reinterpret_cast<char*>(&tempSave), sizeof(GameSaveData))) {
		if (string(tempSave.playerName) == playerName) {
			applyLoadedGameState(tempSave);
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}

void deleteGameData(const string& playerName) {
	vector<GameSaveData> allSaves;

	// Read all saves except the one to delete
	ifstream inFile("gamesaves.dat", ios::binary);
	if (inFile.is_open()) {
		GameSaveData tempSave;
		while (inFile.read(reinterpret_cast<char*>(&tempSave), sizeof(GameSaveData))) {
			if (string(tempSave.playerName) != playerName) {
				allSaves.push_back(tempSave);
			}
		}
		inFile.close();
	}

	// Write remaining saves back
	ofstream outFile("gamesaves.dat", ios::binary);
	if (outFile.is_open()) {
		for (const auto& save : allSaves) {
			outFile.write(reinterpret_cast<const char*>(&save), sizeof(GameSaveData));
		}
		outFile.close();
	}

	vector<pair<string, int>> allPlayers;
	ifstream nameFile("playernames.txt");
	if (nameFile.is_open()) {
		string line;
		while (getline(nameFile, line)) {
			size_t spacePos = line.find_last_of(' ');
			if (spacePos != string::npos) {
				string existingName = line.substr(0, spacePos);
				int existingProgress = stoi(line.substr(spacePos + 1));
				if (existingName != playerName) {
					allPlayers.push_back({ existingName, existingProgress });
				}
			}
			else {
				if (line != playerName) {
					allPlayers.push_back({ line, 0 });
				}
			}
		}
		nameFile.close();
	}

	ofstream nameOutFile("playernames.txt");
	if (nameOutFile.is_open()) {
		for (const auto& player : allPlayers) {
			nameOutFile << player.first << " " << player.second << endl;
		}
		nameOutFile.close();
	}
}

void activateSaveSystem() {
	saveSystemActive = true;
	currentSaveState = SAVE_MENU;
	saveInputName = "";
	saveErrorMessage = "";
}

void deactivateSaveSystem() {
	saveSystemActive = false;
	saveNameInputActive = false;
}

void showSaveSystem() {
	if (!saveSystemActive) return;

	iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, ui);
	string playerInfo;

	switch (currentSaveState) {
	case SAVE_MENU:
		iSetColor(255, 255, 255);
		iText(600, 400, "GAME OPTIONS", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(550, 350, "Press 'N' for New Game", GLUT_BITMAP_HELVETICA_18);
		iText(550, 320, "Press 'R' to Resume Game", GLUT_BITMAP_HELVETICA_18);
		iText(550, 290, "Press 'B' to go Back", GLUT_BITMAP_HELVETICA_18);
		break;
		 
	case NAME_INPUT_NEW:
		iSetColor(255, 255, 255);
		iText(500, 400, "NEW GAME - Enter Your Name:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500, 350, "Name: ", GLUT_BITMAP_HELVETICA_18);
		iText(570, 350, const_cast<char*>(saveInputName.c_str()), GLUT_BITMAP_HELVETICA_18);
		iText(500, 320, "Press ENTER to confirm", GLUT_BITMAP_HELVETICA_12);
		iText(500, 300, "Press ESC to go back", GLUT_BITMAP_HELVETICA_12);


		if (saveNameInputActive && saveInputName.length() < 49) {
			iText(570 + saveInputName.length() * 10, 350, "_", GLUT_BITMAP_HELVETICA_18);
		}
		break;

	case NAME_INPUT_RESUME:
		iSetColor(255, 255, 255);
		iText(500, 400, "RESUME GAME - Enter Your Name:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(500, 350, "Name: ", GLUT_BITMAP_HELVETICA_18);
		iText(570, 350, const_cast<char*>(saveInputName.c_str()), GLUT_BITMAP_HELVETICA_18);
		iText(500, 320, "Press ENTER to confirm", GLUT_BITMAP_HELVETICA_12);
		iText(500, 300, "Press ESC to go back", GLUT_BITMAP_HELVETICA_12);

		if (saveNameInputActive && saveInputName.length() < 49) {
			iText(570 + saveInputName.length() * 10, 350, "_", GLUT_BITMAP_HELVETICA_18);
		}
		break;

	case RESUME_OPTIONS:
		iSetColor(255, 255, 255);
		iText(550, 400, "RESUME OPTIONS", GLUT_BITMAP_TIMES_ROMAN_24);
		playerInfo = "Player: " + resumePlayerName;
		iText(550, 350, const_cast<char*>(playerInfo.c_str()), GLUT_BITMAP_HELVETICA_18);
		iText(550, 320, "Press 'R' to Resume Game", GLUT_BITMAP_HELVETICA_18);
		iText(550, 290, "Press 'D' to Delete Save", GLUT_BITMAP_HELVETICA_18);
		iText(550, 260, "Press 'C' to Cancel", GLUT_BITMAP_HELVETICA_18);
		break;

	case ERROR_DISPLAY:
		iSetColor(255, 255, 255);
		iText(600, 400, "ERROR", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(400, 350, const_cast<char*>(saveErrorMessage.c_str()), GLUT_BITMAP_HELVETICA_18);
		iText(500, 320, "Press any key to continue", GLUT_BITMAP_HELVETICA_12);
		break;
	}
}

void handleSaveInput(unsigned char key) {
	if (!saveSystemActive) return;

	switch (currentSaveState) {
	case SAVE_MENU:
		if (key == 'n' || key == 'N') {
			currentSaveState = NAME_INPUT_NEW;
			saveInputName = "";
			saveNameInputActive = true;
		}
		else if (key == 'r' || key == 'R') {
			ifstream file("playernames.txt");
			if (!file.is_open()) {
				saveErrorMessage = "No saved games found!";
				currentSaveState = ERROR_DISPLAY;
			}
			else {
				file.close();
				currentSaveState = NAME_INPUT_RESUME;
				saveInputName = "";
				saveNameInputActive = true;
			}
		}
		else if (key == 'b' || key == 'B') {
			deactivateSaveSystem();
			gamePage = 0;
			b[0].isHovering = false;
			b[0].isClicked = false;
		}
		break;

	case NAME_INPUT_NEW:
		if (saveNameInputActive) {
			if (key == '\r' || key == '\n') {
				if (!saveInputName.empty()) {
					if (checkPlayerNameExists(saveInputName)) {
						saveErrorMessage = "Player name already exists! Choose different name.";
						currentSaveState = ERROR_DISPLAY;
					}
					else {
						// Start new game - Set the current player name
						currentPlayerName = saveInputName;
						savePlayerName(saveInputName);

						// Reset game to fresh state
						resetGameProgress();

						// Initialize all game variables to starting state
						gameProgress = 0;
						gamePage = 1;
						gameLevel = 0;
						puzzleLevel = 0;
						battleLevel = 0;
						isMapOn = false;
						level1Completed = false;
						level2Completed = false;
						puzzle1Completed = false;
						puzzle2Completed = false;
						battle1Completed = false;
						battle2Completed = false;

						// Reset all story flags
						for (int i = 0; i < 15; i++) {
							storyPlayed[i] = false;
						}

						// Reset character positions
						character1X = 200;
						character2X = 200;
						characterY = 80;
						health1 = 3;
						health2 = 3;
						tries1 = 3;
						tries2 = 3;

						// Reset level positions
						game1X = 0;
						game1X1 = 0;
						game1X2 = 0;
						game1X3 = 0;
						game1X4 = 0;
						game2X = 0;
						game2X1 = 0;
						game2X2 = 0;
						game2X3 = 0;
						game2X4 = 0;
						game2X5 = 0;
						obstacle1X = 0;
						obstacle2X = 0;
						game1Over = false;
						game2Over = false;

						// Reset battle variables
						battle1X = 200;
						battle2X = 200;
						battleY = 200;
						boss1X = 900;
						boss2X = 900;
						bossY = 200;
						playerCurrentHealth = 1000;
						maxPlayerHealth = 1000;
						bossCurrentHealth = 1000;
						maxBossHealth = 1000;
						currentMana = 200;
						battleOngoing = false;
						battle1Over = false;
						battle2Over = false;
						battleWon = false;
						boss1Attacking = false;
						boss2Attacking = false;
						boss1AttackFrame = 0;
						boss2AttackFrame = 0;
						boss1Frozen = false;
						boss2Frozen = false;
						attack2Cooldown = false;
						currentAttack = 0;
						projectileActive = false;
						projectileX = 0;
						projectileY = 0;

						// Reset movement and animation
						isFacingRight = true;
						isRunning = false;
						isJumping = false;
						isAttacking = false;
						isBlocking = false;
						runFrame = 0;
						jumpFrame = 0;
						attackFrame = 0;
						blockFrame = 0;
						jumpState = 0;

						// Reset story variables
						storyState = 0;
						storyTelling = false;
						storyFrame = 0;

						// Reset UI variables
						isPaused = false;
						showText = false;
						msgState = 0;

						deactivateSaveSystem();

						// Auto-save the initial state
						saveGameData(saveInputName);

						// Check if story should play - always play intro story for new game
						startStory(0);
					}
				}
			}
			else if (key == 27) {
				currentSaveState = SAVE_MENU;
				saveNameInputActive = false;
				saveInputName = "";
			}
			else if (key == '\b' || key == 127) {
				if (!saveInputName.empty()) {
					saveInputName.pop_back();
				}
			}
			else if (key >= 32 && key <= 126 && saveInputName.length() < 49) {
				saveInputName += key;
			}
		}
		break;

	case NAME_INPUT_RESUME:
		if (saveNameInputActive) {
			if (key == '\r' || key == '\n') {
				if (!saveInputName.empty()) {
					if (!checkPlayerNameExists(saveInputName)) {
						saveErrorMessage = "No saved game found for this player!";
						currentSaveState = ERROR_DISPLAY;
						saveNameInputActive = false;
					}
					else {
						resumePlayerName = saveInputName;
						currentSaveState = RESUME_OPTIONS;
						saveNameInputActive = false;
					}
				}
			}
			else if (key == 27) {
				currentSaveState = SAVE_MENU;
				saveNameInputActive = false;
				saveInputName = "";
			}
			else if (key == '\b' || key == 127) {
				if (!saveInputName.empty()) {
					saveInputName.pop_back();
				}
			}
			else if (key >= 32 && key <= 126 && saveInputName.length() < 49) {
				saveInputName += key;
			}
		}
		break;

	case RESUME_OPTIONS:
		if (key == 'r' || key == 'R') {
			// Resume game
			if (loadGameData(resumePlayerName)) {
				deactivateSaveSystem();
				gamePage = 1;
				isMapOn = true;
				// Resume timers based on game state
				if (battleOngoing && battleLevel != 0) {
					// Resume battle timers if in battle
					extern int bossAnimation, bossAttackTimer, attackAnimation;
					extern int blockAnimation, attack2EffectTimer, attack3EffectTimer;
					extern int attack4EffectTimer, freezeEffectTimer, runAnimation;

					iResumeTimer(bossAnimation);
					iResumeTimer(bossAttackTimer);
					if (isAttacking) iResumeTimer(attackAnimation);
					if (isBlocking) iResumeTimer(blockAnimation);
					iResumeTimer(attack2EffectTimer);
					iResumeTimer(attack3EffectTimer);
					iResumeTimer(attack4EffectTimer);
					iResumeTimer(freezeEffectTimer);
					if (isRunning) iResumeTimer(runAnimation);
				}

				if (puzzleLevel == 2 && gamePage == 1 && !isMapOn) {
					extern int obstacleAnimation;
					iResumeTimer(obstacleAnimation);
				}

				if (storyTelling) {
					extern int storyAnimation, textAnimation;
					iResumeTimer(storyAnimation);
					iResumeTimer(textAnimation);
				}

				if (gamePage == 1) {
					if (gameLevel == 0 && puzzleLevel == 0 && battleLevel == 0 && !storyTelling) {
						isMapOn = true;
					}
				}
			}
			else {
				saveErrorMessage = "Failed to load game data!";
				currentSaveState = ERROR_DISPLAY;
			}
		}
		else if (key == 'd' || key == 'D') {
			// Delete save
			deleteGameData(resumePlayerName);
			saveErrorMessage = "Game data deleted successfully!";
			currentSaveState = ERROR_DISPLAY;
		}
		else if (key == 'c' || key == 'C') {
			// Cancel
			currentSaveState = NAME_INPUT_RESUME;
			saveInputName = "";
			saveNameInputActive = true;
		}
		break;

	case ERROR_DISPLAY:
		// Return to appropriate state based on context
		if (saveErrorMessage.find("deleted") != string::npos) {
			currentSaveState = NAME_INPUT_RESUME;
			saveInputName = "";
			saveNameInputActive = true;
		}
		else if (saveErrorMessage.find("No saved game") != string::npos) {
			currentSaveState = NAME_INPUT_RESUME;
			saveInputName = "";
			saveNameInputActive = true;
		}
		else if (saveErrorMessage.find("already exists") != string::npos) {
			currentSaveState = NAME_INPUT_NEW;
			saveInputName = "";
			saveNameInputActive = true;
		}
		else {
			currentSaveState = SAVE_MENU;
		}
		saveErrorMessage = "";
		break;
	}
}

// Function to automatically save when returning to main menu or at checkpoints
void autoSaveGame() {
	if (currentPlayerName.empty()) {
		return;
	}

	if (gamePage == 0 && !saveSystemActive) {
		// Auto-save when returning to main menu
		saveGameData(currentPlayerName);
	}
}

void saveCurrentGame(const string& playerName) {
	if (!playerName.empty()) {
		saveGameData(playerName);
	}
}


void displayAllPlayersWithProgress() {
	ifstream file("playernames.txt");
	if (!file.is_open()) {
		cout << "No player data found!" << endl;
		return;
	}

	cout << "Players and their progress:" << endl;
	cout << "===========================" << endl;

	string line;
	while (getline(file, line)) {
		size_t spacePos = line.find_last_of(' ');
		if (spacePos != string::npos) {
			string playerName = line.substr(0, spacePos);
			int progress = stoi(line.substr(spacePos + 1));
			cout << playerName << " - Progress: " << progress << "%" << endl;
		}
		else {
			// Handle old format
			cout << line << " - Progress: 0%" << endl;
		}
	}
	file.close();
}



#endif