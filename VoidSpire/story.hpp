#ifndef STORY_H
#define STORY_H

int story[200];
int sword1Frame = 0;
int sword2Frame = 0;
int storyFrame = 0;
int storyR;
int storyG;
int storyB;

char *sword1[25][6] = {
	{ "sword1\\1.bmp" },
	{ "sword1\\2.bmp" },
	{ "sword1\\3.bmp" },
	{ "sword1\\4.bmp" },
	{ "sword1\\5.bmp" },
	{ "sword1\\6.bmp" },
	{ "sword1\\7.bmp" },
	{ "sword1\\8.bmp" },
	{ "sword1\\9.bmp" },
	{ "sword1\\10.bmp" },
	{ "sword1\\11.bmp" },
	{ "sword1\\12.bmp" },
	{ "sword1\\13.bmp" },
	{ "sword1\\14.bmp" },
	{ "sword1\\15.bmp" },
	{ "sword1\\16.bmp" },
	{ "sword1\\17.bmp" },
	{ "sword1\\18.bmp" },
	{ "sword1\\19.bmp" },
	{ "sword1\\20.bmp" },
	{ "sword1\\21.bmp" },
	{ "sword1\\22.bmp" },
	{ "sword1\\23.bmp" },
	{ "sword1\\24.bmp" },
	{ "sword1\\25.bmp" }
};

char *sword2[46][6] = {
	{ "sword2\\1.bmp" },
	{ "sword2\\2.bmp" },
	{ "sword2\\3.bmp" },
	{ "sword2\\4.bmp" },
	{ "sword2\\5.bmp" },
	{ "sword2\\6.bmp" },
	{ "sword2\\7.bmp" },
	{ "sword2\\8.bmp" },
	{ "sword2\\9.bmp" },
	{ "sword2\\10.bmp" },
	{ "sword2\\11.bmp" },
	{ "sword2\\12.bmp" },
	{ "sword2\\13.bmp" },
	{ "sword2\\14.bmp" },
	{ "sword2\\15.bmp" },
	{ "sword2\\16.bmp" },
	{ "sword2\\17.bmp" },
	{ "sword2\\18.bmp" },
	{ "sword2\\19.bmp" },
	{ "sword2\\20.bmp" },
	{ "sword2\\21.bmp" },
	{ "sword2\\22.bmp" },
	{ "sword2\\23.bmp" },
	{ "sword2\\24.bmp" },
	{ "sword2\\25.bmp" },
	{ "sword2\\26.bmp" },
	{ "sword2\\27.bmp" },
	{ "sword2\\28.bmp" },
	{ "sword2\\29.bmp" },
	{ "sword2\\30.bmp" },
	{ "sword2\\31.bmp" },
	{ "sword2\\32.bmp" },
	{ "sword2\\33.bmp" },
	{ "sword2\\34.bmp" },
	{ "sword2\\35.bmp" },
	{ "sword2\\36.bmp" },
	{ "sword2\\37.bmp" },
	{ "sword2\\38.bmp" },
	{ "sword2\\39.bmp" },
	{ "sword2\\40.bmp" },
	{ "sword2\\41.bmp" },
	{ "sword2\\42.bmp" },
	{ "sword2\\43.bmp" },
	{ "sword2\\44.bmp" },
	{ "sword2\\45.bmp" },
	{ "sword2\\46.bmp" }
};

void loadStory(){
	for (int i = 0; i < 30; i++){
		char s1[50];
		sprintf_s(s1, "story\\s1 (%d).png", i + 1);
		story[i] = iLoadImage(s1);
	}
	story[30] = iLoadImage("story\\s2.png");
	for (int i = 0; i < 6; i++){
		char s3[50];
		sprintf_s(s3, "story\\s3 (%d).png", i + 1);
		story[i + 31] = iLoadImage(s3);
	}
	story[37] = iLoadImage("story\\s4.png");
	story[38] = iLoadImage("story\\s5.png");
	for (int i = 0; i < 40; i++){
		char s6[50];
		sprintf_s(s6, "story\\s6 (%d).png", i + 1);
		story[i + 39] = iLoadImage(s6);
	}
	for (int i = 0; i < 7; i++){
		char s7[50];
		sprintf_s(s7, "story\\s7 (%d).png", i + 1);
		story[i + 79] = iLoadImage(s7);
	}
	for (int i = 0; i < 6; i++){
		char s8[50];
		sprintf_s(s8, "story\\s8 (%d).png", i + 1);
		story[i + 86] = iLoadImage(s8);
	}
	story[92] = iLoadImage("story\\s9.png");
	for (int i = 0; i < 19; i++){
		char s10[50];
		sprintf_s(s10, "story\\s10 (%d).png", i + 1);
		story[i + 93] = iLoadImage(s10);
	}
	story[112] = iLoadImage("story\\s0.png");
}



void storyAnimated(){
	if (storyTelling){
		if (storyState == 0){
			storyFrame = 112;
		}
		else if (storyState == 1){
			if (storyFrame < 0 || storyFrame >= 29) storyFrame = 0;
			else storyFrame++;
		}
		else if (storyState == 2){
			storyFrame = 30;
		}
		else if (storyState == 3){
			if (storyFrame < 31 || storyFrame >= 36) storyFrame = 31;
			else storyFrame++;
		}
		else if (storyState == 4){
			storyFrame = 37;
			sword1Frame++;
			if (sword1Frame >= 24){
				sword1Frame = 0;
			}
		}
		else if (storyState == 5){
			storyFrame = 38;
		}
		else if (storyState == 8){
			if (storyFrame < 39 || storyFrame >= 78) storyFrame = 39;
			else storyFrame++;
		}
		else if (storyState == 9){
			if (storyFrame < 79 || storyFrame >= 85) storyFrame = 79;
			else storyFrame++;
		}
		else if (storyState == 10){
			if (storyFrame < 86 || storyFrame >= 91) storyFrame = 86;
			else storyFrame++;
		}
		else if (storyState == 11){
			storyFrame = 92;
			sword2Frame++;
			if (sword2Frame >= 46){
				sword2Frame = 0;
			}
		}
		else if (storyState == 12){
			if (storyFrame < 93 || storyFrame >= 111) storyFrame = 93;
			else storyFrame++;
		}
	}
}


char line[] = "Press 'Enter' to continue...";

char msg1[] = "Venture through Frostmere before you continue.";
char msg2[] = "Venture through Blossowyn before you continue.";
char msg3[] = "You’ve ventured through here already - another path awaits.";
char msg4[] = "Rest for now... your adventure will soon continue.";

char* stories[][4] = {
	{
		"The blade once held the world together - until it shattered. Now, its fragments whisper through the seasons, waiting to be found… and remembered.",
		"Begin your journey in FROSTMERE, where silence hides the truth and the first shard, FROSTFANG, lies buried in ice.",
		"",
		""
	},
	{
		"Beyond this point lies the SILENT PEAK of FROSTMERE. Cloaked in eternal snow, the mountain hides its secrets beneath layers of ice and silence.",
		"The wind here doesn’t howl - it slices. It buries all voices. FROSTMERE does not welcome travelers - it tests them. But those who conquer the ",
		"SILENT PEAK do not merely climb a mountain… they survive its legend.",
		""
	},
	{
		"You've braved the treacherous ascent of the SILENT PEAK of FROSTMERE, where even the wind dares not whisper. Now, before you yawns the entrance",
		"to the Crystal Cave. Legends say the first fragment of the vanished sword disappeared into its depths long ago. Few who entered returned…",
		"and none spoke of what they saw. Step forward and restore the lost spirit fragment.",
		""
	},
	{
		"Before you looms the CAVERN of MIRRORS. Deep within, the CRYSTALS of ECHO lie scattered, dulled and silent. Once, their reflections sang with",
		"light… now, they murmur only with sorrow - echoes of regrets long buried and never forgiven. They no longer shine, but they remember. Uncover",
		"the true positions of the lost crystals and return them to their rightful altars. Only then may the cavern awaken, bathed once more in",
		"spectral light. Should you succeed, the elusive spirit known as FROSTFANG - the first fragment - may stir from slumber… and speak your name."
	},
	{
		"You have reclaimed the spirit known as FROSTFANG. Yet, it does not speak… not yet. Its silence is not refusal, but judgment. Beyond the",
		"shimmering veil at the cave’s end, a presence waits. Bound by oath and shadow, this sentinel has lingered through centuries, allowing none to",
		"claim what they have not earned. Take FROSTFANG with you into the forgotten depths. Face the guardian in battle - not just of strength, but of",
		"will. Only by proving your worth can you awaken the true power of the spirit and claim the right to wield its frostbound soul."
	},
	{
		"Before you stands BOREALIS, the Frostbound King - cold, sorrowful, and bound to guard what he no longer remembers. To claim FROSTFANG, you must",
		"defeat him and prove your worth. If your spirit is true, FROSTFANG may awaken and lend you its icy power. Use it to freeze the king’s fury.",
		"Only then will the spirit recognize you… and the path ahead be revealed.",
		""
	},
	{
		"BOREALIS: You have done what so many could not... You’ve earned the right to wield FROSTFANG. May its chill guide your hand, not to destroy - but",
		"to restore. The blade was broken when the world lost its way. Seek the other fragments… and with them, mend what remains. Go now - to BLOSSOWYN.",
		"Learn the truths buried in shadow. This world is not yet lost - but its salvation lies in your will.",
		""
	},
	{
		"BOREALIS: You have spirit… but not yet the strength. FROSTFANG does not yield to the unproven. Return when your resolve is sharper, your soul",
		"steadier. Only then will I grant you passage, and the right to wield what was once broken. Go. Grow stronger. And when you are ready… face me again.",
		"", 
		""
	},
	{
		"Beyond this point stretches the ECHOING MEDOW of BLOSSOWYN - a place where trees grow with unnatural speed, yet bear no life. Their roots twist",
		"like veins across the earth, reaching for something long lost. The overgrowth will try to stop you, wrapping the path in silence and shadow.",
		"Press on. Only by pushing through this can you uncover the deeper mysteries that lie ahead.",
		""
	},
	{
		"You made it through the choking wilds of BLOSSOWYN, a hush has fallen over the land. The air has turned gentle, laced with strange warmth and",
		"distant harmony. Now you know - you’ve reached the threshold of MELODY GROVE, where silence listens, and forgotten songs still linger in the wind.",
		"",
		""
	},
	{
		"Before you lies the hidden garden of MELODY GROVE - a place where the wind carries the notes of a forgotten lullaby, echoing through petals",
		"and leaves. When the melody begins, listen closely. It is the key to awakening VERDANCE, the spirit bound to another fragment of the shattered ",
		"sword. Let the song guide your hand. When the final note fades, choose the flowers in the order they were sung. Only then will VERDANCE stir…",
		"and the garden reveal its secret."
	},
	{
		"You have woven together the fragments of the forgotten lullaby. VERDANCE stirs - awakening from its slumber, yet wary and fierce. But beware,",
		"before it yields its spirit to you, it will test your strength in battle. Only those truly worthy may claim its power.",
		"",
		""
	},
	{
		"Before you rises VIRELLA, the Bloom Widow - her form woven from sorrowful vines and fading petals. She strikes not with hatred, but with grief,",
		"guarding the forgotten garden with unwavering resolve. To prove yourself to VERDANCE, you must face her. As a sign of trial, VERDANCE grants",
		"you fragment of its strength crushing surge, and the gift of healing. Wield them in battle, and let nature’s fury and grace guide your hand.",
		"Only through victory will the spirit recognize your worth."
	},
	{
		"VIRELLA: You have proven your heart - resolute and just. VERDANCE has seen your truth… and now grants you its strength. Wield it not for power,",
		"but for healing. Let the gift guide your path. Go forth - to VERDWILD. Fight every battle against injustice with purpose. And may you rise",
		"victorious not only in combat… but in restoring what the world has lost.",
		""
	},
	{
		"VIRELLA: Your will is fierce… but not yet enough to bear the weight of VERDANCE. Strengthen your resolve. Let your purpose grow deeper than fear",
		"or doubt. When you are ready - return. Face me again, and only then may you claim the spirit’s blessing.",
		"",
		""
	}
};

char buffer1[200] = "";
char buffer2[200] = "";
char buffer3[200] = "";
char buffer4[200] = "";
int index1 = 0;
int index2 = 0;
int index3 = 0;
int index4 = 0;
bool blinkingText = false;
int blinkingCounter = 0;
bool storyFinised = false;


void resetStory() {
	memset(buffer1, 0, sizeof(buffer1));
	memset(buffer2, 0, sizeof(buffer2));
	memset(buffer3, 0, sizeof(buffer3));
	memset(buffer4, 0, sizeof(buffer4));
	index1 = 0;
	index2 = 0;
	index3 = 0;
	index4 = 0;
	storyFinised = false;
	blinkingText = false;
	blinkingCounter = 0;
}

void setStoryRGB(int state){
	if (state == 0){
		storyR = 200;
		storyG = 200;
		storyB = 200;
	}
	else if (state == 1){
		storyR = 0;
		storyG = 0;
		storyB = 50;
	}
	else if (state == 2){
		storyR = 70;
		storyG = 0;
		storyB = 0;
	}
	else if (state == 3 || state == 6 || state == 7 || state == 10 || state == 11 || state == 13 || state == 14){
		storyR = 0;
		storyG = 0;
		storyB = 0;
	}
	else if (state == 4){
		storyR = 255;
		storyG = 255;
		storyB = 255;
	}
	else if (state == 5){
		storyR = 0;
		storyG = 0;
		storyB = 70;
	}
	else if (state == 8 || state == 12){
		storyR = 220;
		storyG = 220;
		storyB = 220;
	}
	else if (state == 9){
		storyR = 20;
		storyG = 20;
		storyB = 20;
	}
}


bool shouldPlayStory(int state) {
	if (state == 6 || state == 7) {
		if (state == 7) {
			return battle1Over && !storyPlayed[7];
		}
		return !storyPlayed[6];
	}
	if (state == 13 || state == 14) {
		if (state == 14) {
			return battle2Over && !storyPlayed[14];
		}
		return !storyPlayed[13];
	}

	return !storyPlayed[state];
}

void resetBattleLossStory(int battleLevel) {
	if (battleLevel == 1) {
		storyPlayed[7] = false;
	}
	else if (battleLevel == 2) {
		storyPlayed[14] = false;
	}
}


void startStory(int state) {
	resetStory();
	setStoryRGB(state);
	storyState = state;
	storyTelling = true;
	enterKeyProcessed = false;

	if (state != 7 && state != 14) {
		storyPlayed[state] = true;
	}
	iResumeTimer(storyAnimation);
	iResumeTimer(textAnimation);
}



void handleStoryComplete() {
	DWORD currentTime = GetTickCount();
	if (currentTime - lastStoryCompleteTime < 500) {
		return;
	}
	lastStoryCompleteTime = currentTime;

	storyTelling = false;
	blinkingText = false;
	storyFinised = false;

	iPauseTimer(storyAnimation);
	iPauseTimer(textAnimation);

	if (storyState == 0) {
		isMapOn = true;
	}
	else if (storyState == 1) {
		gameLevel = 1;
	}
	else if (storyState == 2) {
		level1StoryPlayed = true;
		startStory(3);
		return;
	}
	else if (storyState == 3) {
		gameLevel = 0;
		puzzleLevel = 1;
	}
	else if (storyState == 4){
		puzzle1StoryPlayed = true;
		startStory(5);
		return;
	}
	else if (storyState == 5){
		puzzleLevel = 0;
		battleLevel = 1;
		startBattle();
		iResumeTimer(bossAnimation);
		iResumeTimer(bossAttackTimer);
	}
	else if (storyState == 6){
		battleLevel = 0;
		isMapOn = true;
		storyPlayed[7] = true;
	}
	else if (storyState == 7){
		battleOngoing = true;
		restartGame();
		iResumeTimer(bossAnimation);
		iResumeTimer(bossAttackTimer);
		storyPlayed[7] = true;
	}
	else if (storyState == 8){
		gameLevel = 2;
	}
	else if (storyState == 9){
		level2StoryPlayed = true;
		startStory(10);
		return;
	}
	else if (storyState == 10){
		gameLevel = 0;
		puzzleLevel = 2;
		puzzle2State = 0;
		isPlayingTunes = true;
		tunePlaybackIndex = 0;
		lastTuneTime = GetTickCount();
	}
	else if (storyState == 11){
		puzzle2StoryPlayed = true;
		startStory(12);
		return;
	}
	else if (storyState == 12){
		puzzleLevel = 0;
		battleLevel = 2;
		startBattle();
		iResumeTimer(bossAnimation);
		iResumeTimer(bossAttackTimer);
	}
	else if (storyState == 13){
		battleLevel = 0;
		isMapOn = true;
		storyPlayed[14] = true;
	}
	else if (storyState == 14){
		battleOngoing = true;
		restartGame();
		iResumeTimer(bossAnimation);
		iResumeTimer(bossAttackTimer);
		storyPlayed[14] = true;
	}

	storyState = -1;
	enterKeyProcessed = false;
}

void updateText() {
	if (!storyFinised){
		char* line1 = stories[storyState][0];
		char* line2 = stories[storyState][1];
		char* line3 = stories[storyState][2];
		char* line4 = stories[storyState][3];

		if (line1[index1] != '\0') {
			buffer1[index1] = line1[index1];
			index1++;
			buffer1[index1] = '\0';
		}
		else if (line2[index2] != '\0') {
			buffer2[index2] = line2[index2];
			index2++;
			buffer2[index2] = '\0';
		}
		else if (line3[index3] != '\0') {
			buffer3[index3] = line3[index3];
			index3++;
			buffer3[index3] = '\0';
		}
		else if (line4[index4] != '\0') {
			buffer4[index4] = line4[index4];
			index4++;
			buffer4[index4] = '\0';
		}

		if (line1[index1] == '\0' && line2[index2] == '\0' && line3[index3] == '\0' && line4[index4] == '\0') {
			storyFinised = true;
			blinkingText = true;
		}
	}

	if (storyFinised) {
		blinkingCounter++;
		if (blinkingCounter >= 10) {
			blinkingText = !blinkingText;
			blinkingCounter = 0;
		}
	}
}

int getStoryLineCount(int state) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (strlen(stories[state][i]) > 0) {
			count++;
		}
	}
	return count;
}

int getStoryRectHeight(int state) {
	int lineCount = getStoryLineCount(state);
	int baseHeight = 40;
	int lineHeight = 30;
	int padding = 20;

	return baseHeight + ((lineCount - 1) * lineHeight) + padding;
}

void showStoryLine(){
	if (!storyTelling) return;

	glLineWidth(7);

	int height = getStoryRectHeight(storyState);
	iSetColor(storyR, storyG, storyB);
	iRectangle(80, 80, 1340, height);

	char* line1 = stories[storyState][0];
	char* line2 = stories[storyState][1];
	char* line3 = stories[storyState][2];
	char* line4 = stories[storyState][3];

	int textY = 100;
	int spacing = 30;
	int lineCount = getStoryLineCount(storyState);
	iSetColor(storyR, storyG, storyB);
	if (stories[storyState][0] != '\0'){
		iText(100, textY + spacing * (lineCount - 1) + 10, buffer1, GLUT_BITMAP_9_BY_15);
	}
	if (stories[storyState][1] != '\0'){
		iText(100, textY + spacing * (lineCount - 2) + 10, buffer2, GLUT_BITMAP_9_BY_15);
	}
	if (stories[storyState][2] != '\0'){
		iText(100, textY + spacing * (lineCount - 3) + 10, buffer3, GLUT_BITMAP_9_BY_15);
	}
	if (stories[storyState][3] != '\0'){
		iText(100, textY + spacing * (lineCount - 4) + 10, buffer4, GLUT_BITMAP_9_BY_15);
	}

	if (line1[index1] == '\0' &&
		line2[index2] == '\0' &&
		line3[index3] == '\0' &&
		line4[index4] == '\0') {
		if (blinkingText) {
			iText(1200, 85, line, GLUT_BITMAP_HELVETICA_18);
		}
	}
}


void showStory(){
	if (storyTelling){
		if (storyState == 6 || storyState == 7 || storyState == 13 || storyState == 14){

		}
		else {
			iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, story[storyFrame]);
			if (storyState == 4){
				iShowBMP2(620, 280, *sword1[sword1Frame], 0);
			}
			else if (storyState == 11){
				iShowBMP2(850, 180, *sword2[sword2Frame], 0);
			}
		}
		showStoryLine();
	}
}

void startText(int num){
	if (showText) {
		iPauseTimer(msgAnimation);
	}

	msgState = num;
	showText = true;
	iResumeTimer(msgAnimation);
}

void showMessages(){
	if (isMapOn && showText){
		iSetColor(0, 0, 0);
		if (msgState == 1){
			iText(550, 560, msg1, GLUT_BITMAP_HELVETICA_18);
		}
		else if (msgState == 2){
			iText(550, 560, msg2, GLUT_BITMAP_HELVETICA_18);
		}
		else if (msgState == 3){
			iText(550, 560, msg3, GLUT_BITMAP_HELVETICA_18);
		}
		else if (msgState == 4){
			iText(550, 560, msg4, GLUT_BITMAP_HELVETICA_18);
		}
		else {
			showText = false;
			iPauseTimer(msgAnimation);
		}
	}
}


void hideText() {
	showText = false;
	iPauseTimer(msgAnimation);
}






#endif