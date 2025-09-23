#ifndef BATTLE_H
#define BATTLE_H
#include "save_system.hpp"

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 600
#define RUN_FRAME_NO 12

#define MAX_PROJECTILES 10


typedef struct {
	int x, y;
	bool active;
	int effectFrame;
	bool moving;
} Attack3Projectile;

Attack3Projectile attack3Projectiles[MAX_PROJECTILES];


char *boss1Stand[6] = { "boss1\\s.bmp" };
char *boss1Freeze[6] = { "boss1\\f.bmp" };
char *ice[6] = { "boss1\\0.bmp" };

char *boss1Attack[5][6] = {
	{ "boss1\\1.bmp" },
	{ "boss1\\2.bmp" },
	{ "boss1\\3.bmp" },
	{ "boss1\\4.bmp" },
	{ "boss1\\5.bmp" }
};

char *boss2Stand[6] = { "boss2\\s.bmp" };
char *boss2Freeze[6] = { "boss2\\f.bmp" };
char *fire[6] = { "boss2\\0.bmp" };

char *boss2Attack[24][6] = {
	{ "boss2\\1.bmp" },
	{ "boss2\\2.bmp" },
	{ "boss2\\3.bmp" },
	{ "boss2\\4.bmp" },
	{ "boss2\\5.bmp" },
	{ "boss2\\6.bmp" },
	{ "boss2\\7.bmp" },
	{ "boss2\\8.bmp" },
	{ "boss2\\9.bmp" },
	{ "boss2\\10.bmp" },
	{ "boss2\\11.bmp" },
	{ "boss2\\12.bmp" },
	{ "boss2\\13.bmp" },
	{ "boss2\\14.bmp" },
	{ "boss2\\15.bmp" },
	{ "boss2\\16.bmp" },
	{ "boss2\\17.bmp" },
	{ "boss2\\18.bmp" },
	{ "boss2\\19.bmp" },
	{ "boss2\\20.bmp" },
	{ "boss2\\21.bmp" },
	{ "boss2\\22.bmp" },
	{ "boss2\\23.bmp" },
	{ "boss2\\24.bmp" }
};

char *block[8][6] = {
	{ "block\\1.bmp" },
	{ "block\\2.bmp" },
	{ "block\\3.bmp" },
	{ "block\\4.bmp" }
};


void loadBattle(){
	battle1 = iLoadImage("battle\\1.png");
	battle2 = iLoadImage("battle\\2.png");
	magicBar[0] = iLoadImage("battle\\a0.png");
	magicBar[1] = iLoadImage("battle\\a1.png");
	magicBar[2] = iLoadImage("battle\\a2.png");
	magicBar[3] = iLoadImage("battle\\a3.png");
	magicBar[4] = iLoadImage("battle\\a4.png");
	magicBar[5] = iLoadImage("battle\\a5.png");
	magicBar[6] = iLoadImage("battle\\a6.png");
	icon[0] = iLoadImage("battle\\hero.png");
	icon[1] = iLoadImage("battle\\boss1.png");
	icon[2] = iLoadImage("battle\\boss2.png");
}




void showHealthBars() {
	if (!battleOngoing){
		return;
	}

		int r, g, b;
		if (currentAttack == 0){
			r = 220, g = 180, b = 150;
		}
		else if (currentAttack == 1){
			r = 130, g = 230, b = 210;
		}
		else if (currentAttack == 2){
			r = 20, g = 30, b = 210;
		}
		else if (currentAttack == 3){
			r = 100, g = 200, b = 40;
		}

		iSetColor(255, 255, 255);
		iFilledRectangle(180, SCREEN_HEIGHT - 150, 200, 20);
		iSetColor(r, g, b);
		iFilledRectangle(180, SCREEN_HEIGHT - 150, currentMana, 20);
		iSetColor(210, 175, 55);
		glLineWidth(5);
		iRectangle(180, SCREEN_HEIGHT - 150, 200, 20);
		iShowImage(140, 440, 40, 40, magicBar[currentAttack]);

		iSetColor(0, 0, 0);
		if (!currentPlayerName.empty()) {
			iText(150, 540, const_cast<char*>(currentPlayerName.c_str()), GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else {
			iText(150, 540, "PLAYER", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iSetColor(255, 255, 255);
		iFilledRectangle(150, SCREEN_HEIGHT - 100, 300, 30);
		iSetColor(0, 255, 0);
		int playerHealthWidth = (playerCurrentHealth * 300) / maxPlayerHealth;
		iFilledRectangle(150, SCREEN_HEIGHT - 100, playerHealthWidth, 30);
		iSetColor(210, 175, 55);
		glLineWidth(5);
		iRectangle(150, SCREEN_HEIGHT - 100, 300, 30);
		iShowImage(100, 490, 50, 50, icon[0]);
		iSetColor(0, 0, 0);
		glLineWidth(2);
		iRectangle(100, 490, 50, 50);

		iSetColor(255, 255, 255);
		iFilledRectangle(SCREEN_WIDTH - 450, SCREEN_HEIGHT - 100, 300, 30);
		iSetColor(255, 100, 0);
		int bossHealthWidth = (bossCurrentHealth * 300) / maxBossHealth;
		int backX = bossHealthWidth + 150;
		iFilledRectangle(SCREEN_WIDTH - backX, SCREEN_HEIGHT - 100, bossHealthWidth, 30);

		iSetColor(210, 175, 55);
		glLineWidth(5);
		iRectangle(SCREEN_WIDTH - 450, SCREEN_HEIGHT - 100, 300, 30);
		iSetColor(0, 0, 0);
		glLineWidth(2);
		iRectangle(1350, 490, 50, 50);
		if (battleLevel == 1){
			iSetColor(0, 0, 0);
			iText(1230, 540, "BOREALIS", GLUT_BITMAP_TIMES_ROMAN_24);
			iShowImage(1350, 490, 50, 50, icon[1]);
		}
		else if (battleLevel == 2){
			iSetColor(0, 0, 0);
			iText(1250, 540, "VIRELLA", GLUT_BITMAP_TIMES_ROMAN_24);
			iShowImage(1350, 490, 50, 50, icon[2]);
		}
}

void checkGameEnd();


void throwProjectile(){
	if (!projectileActive) {
		projectileActive = true;
		if (battleLevel == 1) {
			projectileX = boss1X - 60;
			projectileY = bossY + 30;
		}
		else if (battleLevel == 2) {
			projectileX = boss2X - 60;
			projectileY = bossY + 10;
		}
	}
}



void updateProjectile(){

	if (!battleOngoing) {
		return;
	}

	if (projectileActive) {
		projectileX -= projectileSpeed;

		int playerX = (battleLevel == 1) ? battle1X : battle2X;

		if (projectileX <= playerX + 100){
			if (!isBlocking){
				playerCurrentHealth -= 50;
				checkGameEnd();
			}
			projectileActive = false;
		}
	}
}

void updateAttack2Effect() {

	if (!battleOngoing) {
		return;
	}

	if (attack2EffectActive) {
		attack2EffectFrame++;
		if (attack2EffectFrame >= 7) {
			attack2EffectFrame = 0;
			attack2EffectActive = false;
			iPauseTimer(attack2EffectTimer);

			bossCurrentHealth -= 100;

			if (battleLevel == 1) {
				boss1Frozen = true;
			}
			else if (battleLevel == 2) {
				boss2Frozen = true;
			}
			checkGameEnd();
			freezeTimer = 100;
			iResumeTimer(freezeEffectTimer);
			attack2Cooldown = true;
		}
	}
}

void spawnAttack3Projectile() {
	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (!attack3Projectiles[i].active) {
			attack3Projectiles[i].x = (battleLevel == 1) ? battle1X + 100 : battle2X + 100;
			attack3Projectiles[i].y = battleY + 20;
			attack3Projectiles[i].active = true;
			attack3Projectiles[i].moving = true;
			attack3Projectiles[i].effectFrame = 0;
			break;
		}
	}
}

void updateAttack3Effect() {

	if (!battleOngoing) {
		return;
	}

	bool anyActive = false;

	for (int i = 0; i < MAX_PROJECTILES; i++) {
		if (!attack3Projectiles[i].active) continue;
		anyActive = true;

		if (attack3Projectiles[i].moving) {
			attack3Projectiles[i].x += 20;
			int bossX = (battleLevel == 1) ? boss1X : boss2X;

			if (attack3Projectiles[i].x >= bossX - 200) {
				attack3Projectiles[i].moving = false;
				attack3Projectiles[i].effectFrame = 0;
				bossCurrentHealth -= 50;
				checkGameEnd();
			}
		}
		else {
			attack3Projectiles[i].effectFrame++;
			if (attack3Projectiles[i].effectFrame >= 8) {
				attack3Projectiles[i].active = false;
			}
		}
	}

	if (!anyActive) {
		iPauseTimer(attack3EffectTimer);
		attack3EffectActive = false;
	}
}

void updateAttack4Effect() {

	if (!battleOngoing) {
		return;
	}

	if (attack4EffectActive) {
		attack4EffectFrame++;
		if (attack4EffectFrame >= 9) {
			attack4EffectFrame = 0;
			attack4EffectActive = false;
			iPauseTimer(attack4EffectTimer);

			playerCurrentHealth += 100;
			if (playerCurrentHealth > maxPlayerHealth) {
				playerCurrentHealth = maxPlayerHealth;
			}
		}
	}
}

void updateFreezeTimer() {

	if (!battleOngoing) {
		return;
	}

	if (battleLevel == 1 && boss1Frozen) {
		freezeTimer--;
		if (freezeTimer <= 0) {
			boss1Frozen = false;
			attack2Cooldown = false;
			iPauseTimer(freezeEffectTimer);
		}
	}
	else if (battleLevel == 2 && boss2Frozen) {
		freezeTimer--;
		if (freezeTimer <= 0) {
			boss2Frozen = false;
			attack2Cooldown = false;
			iPauseTimer(freezeEffectTimer);
		}
	}
}


void bossHit(){
	if (isAttacking && currentAttack == 0){
		if (battleLevel == 1){
			if (battle1X + 150 >= boss1X){
				bossCurrentHealth -= 10;
				bossHealthX -= 10;
				checkGameEnd();
			}
		}
		if (battleLevel == 2){
			if (battle2X + 150 >= boss2X){
				bossCurrentHealth -= 10;
				bossHealthX -= 10;
				checkGameEnd();
			}
		}
	}
}

void attack(){

	if (!battleOngoing) {
		return;
	}

	if (isAttacking){
		attackFrame++;
		if (currentAttack == 1) {
			if (attackFrame == 6 && !attack2CloseToBoss) {
				originalBattleX = (battleLevel == 1) ? battle1X : battle2X;
				attack2CloseToBoss = true;

				if (battleLevel == 1) {
					battle1X = boss1X - 100;
				}
				else if (battleLevel == 2) {
					battle2X = boss2X - 100;
				}
			}
		}

		if (currentAttack == 2 && attackFrame == attackMaxFrames[currentAttack] - 1) {
			spawnAttack3Projectile();
			attack3EffectActive = true;
			iResumeTimer(attack3EffectTimer);
		}

		if (currentAttack == 3 && attackFrame == 5) {
			attack4EffectActive = true;
			attack4EffectFrame = 0;
			iResumeTimer(attack4EffectTimer);
		}

		if (attackFrame == 5 && !hasHitBoss && currentAttack == 0) {
			bossHit();
			hasHitBoss = true;
		}

		if (attackFrame >= attackMaxFrames[currentAttack]){
			attackFrame = 0;
			isAttacking = false;
			hasHitBoss = false;

			if (currentAttack == 1) {
				currentMana -= 40;
			}
			else if (currentAttack == 2 || currentAttack == 3){
				currentMana -= 20;
			}

			if (currentAttack == 1 && attack2CloseToBoss) {
				attack2EffectActive = true;
				attack2EffectFrame = 0;
				attack2CloseToBoss = false;
				iResumeTimer(attack2EffectTimer);

				if (battleLevel == 1) {
					battle1X = originalBattleX;
				}
				else if (battleLevel == 2) {
					battle2X = originalBattleX;
				}
			}

			iPauseTimer(attackAnimation);
		}
	}
}

void blocked(){
	if (!battleOngoing) {
		return;
	}

	if (!isRunning && !isAttacking && isBlocking){
		blockFrame++;
		if (blockFrame >= 4){
			blockFrame = 0;
			isBlocking = false;
			blockKeyPressed = false;
			iPauseTimer(blockAnimation);
		}
	}
}

void battleCharacterShow(){
	if (battleLevel == 1){

		if (battle1Over){
			isFacingRight = true;
			iShowBMP2(battle1X, battleY, *standR, 0);
			return;
		}

		if (isRunning && !isAttacking && !isBlocking){
			if (isFacingRight){
				iShowBMP2(battle1X, battleY, *runR[runFrame], 0);
			}
			else if (!isFacingRight){
				iShowBMP2(battle1X, battleY, *runL[runFrame], 0);
			}
		}
		else if (!isRunning && !isAttacking && !isBlocking){
			if (isFacingRight){
				switch (currentAttack) {
				case 0:
					iShowBMP2(battle1X, battleY, *attack1[0], 0);
					break;
				case 1:
					iShowBMP2(battle1X, battleY, *attack2[0], 0);
					break;
				default:
					iShowBMP2(battle1X, battleY, *standR, 0);
					break;
				}
			}
			else {
				iShowBMP2(battle1X, battleY, *standL, 0);
			}
		}
		if (isAttacking){
			if (isFacingRight){
				switch (currentAttack) {
				case 0:
					iShowBMP2(battle1X, battleY, *attack1[attackFrame], 0);
					break;
				case 1:
					iShowBMP2(battle1X, battleY, *attack2[attackFrame], 0);
					break;
				}
			}
			else {
				iShowBMP2(battle1X, battleY, *standL, 0);
			}
		}
		if (isBlocking){
			if (isFacingRight){
				iShowBMP2(battle1X, battleY, *block[blockFrame], 0);
			}
			else {
				iShowBMP2(battle1X, battleY, *standL, 0);
			}
		}
		if (battle1Over){
			isFacingRight = true;
			iShowBMP2(battle1X, battleY, *standR, 0);
		}
	}

	if (battleLevel == 2){

		if (battle2Over){
			isFacingRight = true;
			iShowBMP2(battle2X, battleY, *standR, 0);
			return;
		}

		if (isRunning && !isAttacking && !isBlocking){
			if (isFacingRight){
				iShowBMP2(battle2X, battleY, *runR[runFrame], 0);
			}
			else if (!isFacingRight){
				iShowBMP2(battle2X, battleY, *runL[runFrame], 0);
			}
		}
		else if (!isRunning && !isAttacking && !isBlocking){
			if (isFacingRight){
				switch (currentAttack) {
				case 0:
					iShowBMP2(battle2X, battleY, *attack1[0], 0);
					break;
				case 1:
					iShowBMP2(battle2X, battleY, *attack2[0], 0);
					break;
				case 2:
					iShowBMP2(battle2X, battleY, *attack3[0], 0);
					break;
				case 3:
					iShowBMP2(battle2X, battleY, *attack4[0], 0);
					break;
				default:
					iShowBMP2(battle2X, battleY, *standR, 0);
					break;
				}
			}
			else {
				iShowBMP2(battle2X, battleY, *standL, 0);
			}
		}
		if (isAttacking){
			if (isFacingRight){
				switch (currentAttack) {
				case 0:
					iShowBMP2(battle2X, battleY, *attack1[attackFrame], 0);
					break;
				case 1:
					iShowBMP2(battle2X, battleY, *attack2[attackFrame], 0);
					break;
				case 2:
					iShowBMP2(battle2X, battleY, *attack3[attackFrame], 0);
					break;
				case 3:
					iShowBMP2(battle2X, battleY, *attack4[attackFrame], 0);
					break;
				}
			}
			else {
				iShowBMP2(battle2X, battleY, *standL, 0);
			}
		}
		if (isBlocking){
			if (isFacingRight){
				iShowBMP2(battle2X, battleY, *block[blockFrame], 0);
			}
			else {
				iShowBMP2(battle2X, battleY, *standL, 0);
			}
		}
		if (battle2Over){
			isFacingRight = true;
			iShowBMP2(battle2X, battleY, *standR, 0);
		}
	}
}

void showAttackEffects() {

	if (!battleOngoing) {
		return;
	}

	if (attack2EffectActive) {
		int bossX = (battleLevel == 1) ? boss1X : boss2X;
		iShowBMP2(bossX, bossY, *attack2Effect[attack2EffectFrame], 0);
	}

	if (attack3EffectActive) {
		for (int i = 0; i < MAX_PROJECTILES; i++) {
			if (!attack3Projectiles[i].active) continue;

			if (attack3Projectiles[i].moving) {
				iShowBMP2(attack3Projectiles[i].x, attack3Projectiles[i].y, *attack3Effect[0], 0);
			}
			else {
				int bossX = (battleLevel == 1) ? boss1X : boss2X;
				iShowBMP2(bossX - 150, bossY, *attack3Effect[attack3Projectiles[i].effectFrame], 0);
			}
		}
	}

	if (attack4EffectActive) {
		int playerX = (battleLevel == 1) ? battle1X : battle2X;
		iShowBMP2(playerX - 160, battleY, *attack4Effect[attack4EffectFrame], 0);
	}
}

void bossShow(){
	if (battleLevel == 1){

		if (battle1Over){
			iShowBMP2(boss1X, bossY, *boss1Stand, 0);
			return;
		}

		if (boss1Frozen) {
			iShowBMP2(boss1X, bossY, *boss1Freeze, 0);
		}
		else if (!boss1Attacking){
			iShowBMP2(boss1X, bossY, *boss1Stand, 0);
		}
		else if (boss1Attacking){
			iShowBMP2(boss1X, bossY, *boss1Attack[boss1AttackFrame], 0);
		}
		else if (battle1Over){
			iShowBMP2(boss1X, bossY, *boss1Stand, 0);
		}
	}

	if (battleLevel == 2){

		if (battle2Over){
			iShowBMP2(boss2X, bossY, *boss2Stand, 0);
			return;
		}

		if (boss2Frozen) {
			iShowBMP2(boss2X, bossY, *boss2Freeze, 0);
		}
		else if (!boss2Attacking){
			iShowBMP2(boss2X, bossY, *boss2Stand, 0);
		}
		else if (boss2Attacking){
			iShowBMP2(boss2X, bossY, *boss2Attack[boss2AttackFrame], 0);
		}
		else if (battle2Over){
			iShowBMP2(boss2X, bossY, *boss2Stand, 0);
		}
	}
}

void showProjectile(){

	if (!battleOngoing) {
		return;
	}

	if (projectileActive) {
		if (battleLevel == 1) {
			iShowBMP2(projectileX, projectileY, *ice, 0);
		}
		else if (battleLevel == 2) {
			iShowBMP2(projectileX, projectileY, *fire, 0);
		}
	}
}

void bossMovement(){

	if (gamePage != 1 || !battleOngoing || isPaused || isMapOn) {
		return;
	}

	if ((battleLevel == 1 && boss1Frozen) || (battleLevel == 2 && boss2Frozen)) {
		return;
	}

	if (battleLevel == 1){
		if (boss1Attacking){
			boss1AttackFrame++;
			if (boss1AttackFrame >= 5){
				boss1AttackFrame = 0;
				boss1Attacking = false;
				iPauseTimer(bossAnimation);
				throwProjectile();
			}
		}
	}

	if (battleLevel == 2){
		if (boss2Attacking){
			boss2AttackFrame++;
			if (boss2AttackFrame >= 24){
				boss2AttackFrame = 0;
				boss2Attacking = false;
				iPauseTimer(bossAnimation);
				throwProjectile();
			}
		}
	}
}


void startBossAttack(){

	if (gamePage != 1 || !battleOngoing || isPaused || isMapOn) {
		return;
	}

	if ((battleLevel == 1 && boss1Frozen) || (battleLevel == 2 && boss2Frozen)) {
		return;
	}

	if (battleLevel == 1 && !boss1Attacking) {
		boss1Attacking = true;
		boss1AttackFrame = 0;
		iResumeTimer(bossAnimation);
	}

	if (battleLevel == 2 && !boss2Attacking) {
		boss2Attacking = true;
		boss2AttackFrame = 0;
		iResumeTimer(bossAnimation);
	}
}

void showBattle1(){
	if (battleLevel == 1){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, battle1);
	}

	bossShow();
	battleCharacterShow();
	showProjectile();
	showAttackEffects();
	showHealthBars();
}
void showBattle2(){
	if (battleLevel == 2){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, battle2);
	}

	bossShow();
	battleCharacterShow();
	showProjectile();
	showAttackEffects();
	showHealthBars();
}

void checkGameEnd() {
	if (bossCurrentHealth <= 0) {
		battleWon = true;
		battleOngoing = false;

		if (battleLevel == 1) {
			battle1Completed = true;
			battle1Over = true;
			battle1X = 600;
			boss1X = 800;

			attackFrame = 0;
			blockFrame = 0;
			runFrame = 0;
			boss1AttackFrame = 0;

			iPauseTimer(bossAttackTimer);
			iPauseTimer(bossAnimation);
			iPauseTimer(runAnimation);
			iPauseTimer(attackAnimation);
			iPauseTimer(blockAnimation);
			iPauseTimer(attack2EffectTimer);
			iPauseTimer(attack3EffectTimer);
			iPauseTimer(attack4EffectTimer);
			iPauseTimer(freezeEffectTimer);
			startStory(6);

			playerCurrentHealth = maxPlayerHealth;
			bossCurrentHealth = maxBossHealth;
			currentMana = 200;

			isAttacking = false;
			isBlocking = false;
			isRunning = false;
			boss1Attacking = false;
			boss1Frozen = false;
			attack2Cooldown = false;
			projectileActive = false;

			attack2EffectActive = false;
			attack3EffectActive = false;
			attack4EffectActive = false;

			for (int i = 0; i < MAX_PROJECTILES; i++) {
				attack3Projectiles[i].active = false;
			}
		}
		else if (battleLevel == 2) {
			battle2Completed = true;
			battle2Over = true;
			battle2X = 600;
			boss2X = 800;

			attackFrame = 0;
			blockFrame = 0;
			runFrame = 0;
			boss2AttackFrame = 0;

			iPauseTimer(bossAttackTimer);
			iPauseTimer(bossAnimation);
			iPauseTimer(runAnimation);
			iPauseTimer(attackAnimation);
			iPauseTimer(blockAnimation);
			iPauseTimer(attack2EffectTimer);
			iPauseTimer(attack3EffectTimer);
			iPauseTimer(attack4EffectTimer);
			iPauseTimer(freezeEffectTimer);
			startStory(13);
		}
	}
	else if (playerCurrentHealth <= 0) {
		battleWon = false;
		battleOngoing = false;

		attackFrame = 0;
		blockFrame = 0;
		runFrame = 0;

		if (battleLevel == 1) {
			battle1Over = true;
			battle1X = 600;
			boss1X = 800;
			boss1AttackFrame = 0;
			startStory(7);
		}
		else if (battleLevel == 2) {
			battle2Over = true;
			battle2X = 600;
			boss2X = 800;
			boss2AttackFrame = 0;
			startStory(14);
		}

		iPauseTimer(bossAttackTimer);
		iPauseTimer(bossAnimation);
		iPauseTimer(runAnimation);
		iPauseTimer(attackAnimation);
		iPauseTimer(blockAnimation);
		iPauseTimer(attack2EffectTimer);
		iPauseTimer(attack3EffectTimer);
		iPauseTimer(attack4EffectTimer);
		iPauseTimer(freezeEffectTimer);
	}
}

void startBattle() {
	battleOngoing = true;

	if (battleLevel == 1) {
		battle1X = 200;
		boss1X = 900;
		battle1Over = false;
	}
	else if (battleLevel == 2) {
		battle2X = 200;
		boss2X = 900;
		battle2Over = false;
	}

	playerCurrentHealth = maxPlayerHealth;
	bossCurrentHealth = maxBossHealth;
	currentMana = 200;

	isAttacking = false;
	isBlocking = false;
	isRunning = false;
	boss1Attacking = false;
	boss2Attacking = false;
	boss1Frozen = false;
	boss2Frozen = false;
	attack2Cooldown = false;
	projectileActive = false;

	attackKeyPressed = false;
	blockKeyPressed = false;
	attackFrame = 0;
	blockFrame = 0;
	runFrame = 0;
	boss1AttackFrame = 0;
	boss2AttackFrame = 0;

	attack2EffectActive = false;
	attack3EffectActive = false;
	attack4EffectActive = false;
	attack2CloseToBoss = false;

	for (int i = 0; i < MAX_PROJECTILES; i++) {
		attack3Projectiles[i].active = false;
		attack3Projectiles[i].moving = false;
		attack3Projectiles[i].effectFrame = 0;
	}
}

void handleAttackInput() {

	if (!battleOngoing || isBlocking || blockKeyPressed) {
		return;
	}

	int requiredMana = 0;
	if (currentAttack == 1) requiredMana = 40;
	else if (currentAttack == 2 || currentAttack == 3) requiredMana = 20;

	if (currentMana < requiredMana) {
		return;
	}

	if (currentAttack == 1 && attack2Cooldown) {
		return;
	}

	if (!isAttacking && !isRunning) {
		isAttacking = true;
		attackFrame = 0;
		hasHitBoss = false;
		attackKeyPressed = true;
		iResumeTimer(attackAnimation);
	}
}

void handleBlockInput() {
	if (!battleOngoing || isAttacking || isRunning) {
		return;
	}

	if (!isBlocking && !blockKeyPressed) {
		isBlocking = true;
		blockFrame = 0;
		blockKeyPressed = true;
		iResumeTimer(blockAnimation);
	}
}

void resetStoryProgression() {
	level1StoryPlayed = false;
	level2StoryPlayed = false;
	puzzle1StoryPlayed = false;
	puzzle2StoryPlayed = false;

	// Reset the storyPlayed array
	for (int i = 0; i < 15; i++) {
		storyPlayed[i] = false;
	}
}

void restartGame() {
	resetStoryProgression();

	battleWon = false;
	battleOngoing = true;
	playerCurrentHealth = maxPlayerHealth;
	bossCurrentHealth = maxBossHealth;
	currentMana = 200;

	isAttacking = false;
	isBlocking = false;
	isRunning = false;
	attack2Cooldown = false;
	projectileActive = false;

	attackKeyPressed = false;
	blockKeyPressed = false;
	attackFrame = 0;
	blockFrame = 0;
	runFrame = 0;

	attack2EffectActive = false;
	attack3EffectActive = false;
	attack4EffectActive = false;

	for (int i = 0; i < MAX_PROJECTILES; i++) {
		attack3Projectiles[i].active = false;
	}

	if (battleLevel == 1){
		battle1Over = false;
		battle1Completed = false;
		battle1X = 200;
		boss1X = 900;
		boss1Attacking = false;
		boss1Frozen = false;
		boss1AttackFrame = 0;
	}
	else if (battleLevel == 2){
		battle2Over = false;
		battle2Completed = false;
		battle2X = 200;
		boss2X = 900;
		boss2Attacking = false;
		boss2Frozen = false;
		boss2AttackFrame = 0;
	}
}





#endif