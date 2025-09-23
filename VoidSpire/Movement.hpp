#ifndef MOVEMENT_H
#define MOVEMENT_H

#define RUN_FRAME_NO 12
#define JUMP_FRAME_NO 8
#define ATTACK_FRAME 12

int attackFrame = 0;

int character1X = 200;
int character2X = 200;
int characterY = 80;
int groundY = characterY;
int jumpheight = 110;
int jumpState = 0;
bool isFacingRight = true;

int runFrame = 0;
int jumpFrame = 0;
bool isRunning = false;
bool isJumping = false;
bool isAttacking = false;
int attackAnimation;
int runAnimation;
int jumpAnimation;

void running(){
	if (isRunning){
		runFrame++;
		if (runFrame >= RUN_FRAME_NO){
			runFrame = 0;
		}
	}
}

void jumping(){
	if (isJumping) {
		if (jumpState == 1) {
			jumpFrame = 1;
			characterY += 5;

			if (characterY >= groundY + jumpheight / 4) {
				characterY = groundY + jumpheight / 4;
				jumpFrame = 2;
				jumpState = 2;
			}
		}

		else if (jumpState == 2) {
			jumpFrame = 2;
			characterY += 5;

			if (characterY >= groundY + jumpheight) {
				jumpFrame = 3;
				jumpState = 3;
			}
		}
		else if (jumpState == 3){
			characterY = groundY + jumpheight;
			jumpFrame = 4;
			jumpState = 4;
		}
		else if (jumpState == 4) {
			characterY -= 5;

			if (characterY <= groundY + jumpheight / 2) {
				characterY = groundY + jumpheight / 2;
				jumpState = 5;
				jumpFrame = 5;
			}
		}
		else if (jumpState == 5) {
			characterY -= 5;

			if (characterY <= groundY) {
				characterY = groundY;
				jumpState = 6;
				jumpFrame = 6;
			}
		}
		else if (jumpState == 6){
			characterY = groundY;
			jumpState = 7;
			jumpFrame = 7;
		}
		else if (jumpState == 7){
			characterY = groundY;
			jumpState = 0;
			jumpFrame = 0;
			isJumping = false;
		}
	}
}




#endif