#ifndef PROGRESS_H
#define PROGRESS_H

int gameProgress = 0;
bool progressTracked[25] = { false };

enum ProgressEvents {
	STORY_0_COMPLETE = 0,
	STORY_1_COMPLETE = 1,
	STORY_2_COMPLETE = 2,
	STORY_3_COMPLETE = 3,
	STORY_4_COMPLETE = 4,
	STORY_5_COMPLETE = 5,
	STORY_6_COMPLETE = 6,
	STORY_8_COMPLETE = 7,
	STORY_9_COMPLETE = 8,
	STORY_10_COMPLETE = 9,
	STORY_11_COMPLETE = 10,
	STORY_12_COMPLETE = 11,
	STORY_13_COMPLETE = 12,
	LEVEL_1_ENTERED = 13,
	LEVEL_2_ENTERED = 14,
	PUZZLE_1_ENTERED = 15,
	PUZZLE_2_ENTERED = 16,
	BATTLE_1_HALFWAY = 17,
	BATTLE_2_HALFWAY = 18,
	BATTLE_1_ENTERED = 19,
	BATTLE_2_ENTERED = 20,
	LEVEL_PUZZLE_COMPLETION = 21
};

void updateGameProgress() {

	if (storyPlayed[0] && !storyTelling && !progressTracked[STORY_0_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_0_COMPLETE] = true;
	}

	if (storyPlayed[1] && !storyTelling && !progressTracked[STORY_1_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_1_COMPLETE] = true;
	}

	if (storyPlayed[2] && !progressTracked[STORY_2_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_2_COMPLETE] = true;
	}

	if (storyPlayed[3] && !storyTelling && !progressTracked[STORY_3_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_3_COMPLETE] = true;
	}

	if (storyPlayed[4] && !progressTracked[STORY_4_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_4_COMPLETE] = true;
	}

	if (storyPlayed[5] && !storyTelling && !progressTracked[STORY_5_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_5_COMPLETE] = true;
	}

	if (storyPlayed[8] && !storyTelling && !progressTracked[STORY_8_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_8_COMPLETE] = true;
	}

	if (storyPlayed[9] && !progressTracked[STORY_9_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_9_COMPLETE] = true;
	}

	if (storyPlayed[10] && !storyTelling && !progressTracked[STORY_10_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_10_COMPLETE] = true;
	}

	if (storyPlayed[11] && !progressTracked[STORY_11_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_11_COMPLETE] = true;
	}

	if (storyPlayed[12] && !storyTelling && !progressTracked[STORY_12_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_12_COMPLETE] = true;
	}

	if (storyPlayed[6] && !storyTelling && !progressTracked[STORY_6_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_6_COMPLETE] = true;
	}

	if (storyPlayed[13] && !storyTelling && !progressTracked[STORY_13_COMPLETE]) {
		gameProgress += 2;
		progressTracked[STORY_13_COMPLETE] = true;
	}

	if (gameLevel == 1 && !progressTracked[LEVEL_1_ENTERED]) {
		gameProgress += 5;
		progressTracked[LEVEL_1_ENTERED] = true;
	}

	if (gameLevel == 2 && !progressTracked[LEVEL_2_ENTERED]) {
		gameProgress += 5;
		progressTracked[LEVEL_2_ENTERED] = true;
	}

	if (puzzleLevel == 1 && !progressTracked[PUZZLE_1_ENTERED]) {
		gameProgress += 5;
		progressTracked[PUZZLE_1_ENTERED] = true;
	}

	if (puzzleLevel == 2 && !progressTracked[PUZZLE_2_ENTERED]) {
		gameProgress += 5;
		progressTracked[PUZZLE_2_ENTERED] = true;
	}

	if (battleLevel == 1 && !progressTracked[BATTLE_1_ENTERED]) {
		gameProgress += 4;
		progressTracked[BATTLE_1_ENTERED] = true;
	}

	if (battleLevel == 2 && !progressTracked[BATTLE_2_ENTERED]) {
		gameProgress += 4;
		progressTracked[BATTLE_2_ENTERED] = true;
	}

	static int completionProgress = 0;
	int expectedCompletions = 0;

	if (level1Completed) expectedCompletions++;
	if (level2Completed) expectedCompletions++;
	if (puzzle1Completed) expectedCompletions++;
	if (puzzle2Completed) expectedCompletions++;

	if (expectedCompletions > completionProgress) {
		int newCompletions = expectedCompletions - completionProgress;
		gameProgress += newCompletions * 6;
		completionProgress = expectedCompletions;
	}

	if (battleLevel == 1 && bossCurrentHealth <= 500 && bossCurrentHealth > 0 && !progressTracked[BATTLE_1_HALFWAY]) {
		gameProgress += 5;
		progressTracked[BATTLE_1_HALFWAY] = true;
	}

	if (battleLevel == 2 && bossCurrentHealth <= 500 && bossCurrentHealth > 0 && !progressTracked[BATTLE_2_HALFWAY]) {
		gameProgress += 5;
		progressTracked[BATTLE_2_HALFWAY] = true;
	}

	if (storyState == 6 && storyTelling && !progressTracked[STORY_6_COMPLETE]) {
		gameProgress += 6;
		progressTracked[STORY_6_COMPLETE] = true;
	}

	if (storyState == 13 && storyTelling && !progressTracked[STORY_13_COMPLETE]) {
		gameProgress += 6;
		progressTracked[STORY_13_COMPLETE] = true;
	}

	if (gameProgress > 100) {
		gameProgress = 100;
	}
}

int getCurrentProgress() {
	return gameProgress;
}

void resetGameProgress() {
	gameProgress = 0;
	for (int i = 0; i < 25; i++) {
		progressTracked[i] = false;
	}
}

#endif