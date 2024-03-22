#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Find36_GAME.h"

// 전역 변수 정의
int board[BOARD_AREA] = {0};
int revealedCards[BOARD_AREA] = {0};
int score = 0;

// ASCII 아트 이미지 배열
char images[MAX_IMAGES][IMG_HEIGHT][IMG_WIDTH + 1] = {
        {
        	"|----------------|",
			"|                |",
			"|     (\\_/)      |",
			"|    (>'.'<)     |",
			"|    (\")_(\")     |",
			"|                |",
			"|----------------|"
        }
        ,
        {   
            "|----------------|",
            "|^__^            |",
            "|(oo)\\_______    |",
            "|(__)\\       )\\  |",
            "|    ||----w |   |",
            "|    ||     ||   |",
            "|----------------|"
        },
        {        
            "|----------------|",
            "|                |",
            "|     /\\_/\\      |",
            "|    ( o.o )     |",
            "|     > ^ <      |",
            "|                |",
            "|----------------|"
        },
        {
            "|----------------|",
            "|    / \\___      |",
            "|   (     @\\___  |",
            "|   /         O  |",
            "|  /    (_____/  |",
            "|  /_____/   U   |",
            "|----------------|"
        },
        {     
            "|----------------|",
            "|    ,--./,-.    |",
            "|   / #      \\   |",
            "|   |        |   |",
            "|   \\        /   |",
            "|    `._,._,'    |",
            "|----------------|"
        },
        {
            "|----------------|",
            "|     \\~~~/      |",
            "|      \\ /       |",
            "|       V        |",
            "|       |        |",
            "|      ---       |",
            "|----------------|"
        },
        {
            "|----------------|",
            "|      ,-.       |",
            "|    _(*_*)_     |",
            "|   (_  o  _)    |",
            "|     / o \\      |",
            "|    (_/ \\_)     |",
            "|----------------|"
        },
		{
            "|----------------|",
			"|    .'o O'-.    |",
			"|   / O o_.-`|   |",
			"|  /O_.-'  O |   |",  
			"|  | o  o_.-`    |",
			"|  '---`         |",
			"|----------------|"
        }
};

/**
 * @brief 카드를 섞는 함수.
 *
 * 이 함수는 주어진 배열의 원소들을 무작위로 셔플.
 *
 * @param array 섞을 배열.
 * @param size 배열의 크기.
 */
void shuffleCards(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * @brief 게임 보드를 초기화하는 함수.
 *
 * 게임 보드를 초기화하고 카드를 쌍으로 배치하는 함수.
 */
void initializeBoard() {
    int placements[BOARD_AREA] = {0};

    for (int i = 0; i < BOARD_AREA / 2; i++) {
        placements[i] = i % (MAX_IMAGES / 2);
        placements[i + BOARD_AREA / 2] = i % (MAX_IMAGES / 2);
    }

    shuffleCards(placements, BOARD_AREA);

    for (int i = 0; i < BOARD_AREA; i++) {
        board[i] = placements[i];
    }
}

/**
 * @brief 게임 보드를 출력하는 함수.
 *
 * 현재 게임 보드의 상태를 출력하는 함수.
 *
 * @param cursorPosition 현재 커서 위치.
 */
void printBoard(int cursorPosition) {
	printf("Match Score: %d\n", score);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            int cardIndex = i * BOARD_SIZE + j;
            // 카드 상단 경계 출력
            printf("------------------");
        }
        printf("+\n"); // 줄의 끝에서만 경계 닫기

        for (int k = 0; k < IMG_HEIGHT; ++k) { // 이미지 높이(7)만큼 반복
            for (int j = 0; j < BOARD_SIZE; ++j) {
                int cardIndex = i * BOARD_SIZE + j;
                if (revealedCards[cardIndex]) { // 카드가 공개된 경우
                    // 실제 이미지 데이터가 있다면 여기서 이미지 라인을 출력합니다.
                    // 예제에서는 간단한 텍스트로 대체합니다.
                        for (int m = 0; m < IMG_WIDTH+1; m++){
                            printf("%c", images[board[cardIndex]][k][m]);

                        }
                 } else if (cardIndex == cursorPosition && k == 0) { // 커서 위치의 첫 번째 라인에만 선택 표시
                     printf("|     선택됨      ");
                } else {
                    printf("|                 "); // 공개되지 않은 카드
                }
                // } else{
                //         for (int m = 0; m < IMG_WIDTH+1; m++){
                //             printf("%c", images[board[cardIndex]][k][m]);

                //         }
                // }
            }   
            printf("|\n");
        }

        for (int j = 0; j < BOARD_SIZE; ++j) {
            // 카드 하단 경계 출력
            printf("------------------");
        }
        printf("+\n");
    }
}

/**
 * @brief 사용자 입력을 처리하는 함수.
 *
 * 사용자 입력에 따라 커서 위치를 업데이트하거나 카드 선택을 처리하는 함수.
 *
 * @param cursorPosition 현재 커서 위치.
 * @param selectedCards 선택된 카드의 인덱스 배열.
 * @param selectedCount 선택된 카드의 수.
 */
void processInput(int* cursorPosition, int* selectedCards, int* selectedCount) {
    char c = getchar();
    switch (c) {
        case 'w':
            if (*cursorPosition >= BOARD_SIZE) *cursorPosition -= BOARD_SIZE;
            break;
        case 's':
            if (*cursorPosition < BOARD_AREA - BOARD_SIZE) *cursorPosition += BOARD_SIZE;
            break;
        case 'a':
            if (*cursorPosition % BOARD_SIZE != 0) (*cursorPosition)--;
            break;
        case 'd':
            if (*cursorPosition % BOARD_SIZE != BOARD_SIZE - 1) (*cursorPosition)++;
            break;
        case ' ':
            if (*selectedCount < 2 && !revealedCards[*cursorPosition]) {
                selectedCards[(*selectedCount)++] = *cursorPosition;
                revealedCards[*cursorPosition] = 1;
            }
            break;
    }
}

/**
 * @brief 선택된 카드가 일치하는지 확인하는 함수.
 *
 * 사용자가 선택한 두 카드가 일치하는지 확인함.
 *
 * @param selectedCards 선택된 카드의 인덱스 배열.
 * @param selectedCount 선택된 카드의 수.
 */
// 일치 검사 로직
void checkMatch(int* selectedCards, int* selectedCount) {
    if (*selectedCount == 2) {
        if (board[selectedCards[0]] == board[selectedCards[1]]) {
            score++;
            printf("found!");
        } else {
            revealedCards[selectedCards[0]] = 0;
            revealedCards[selectedCards[1]] = 0;
            printf("No match. Try again.\n");
        }
        *selectedCount = 0;
        sleep(1);
        // 사용자가 결과를 볼 수 있도록 잠시 대기
    }
}
/**
 * @brief 게임 플레이 메인 함수.
 *
 * 이 함수는 게임의 메인 루프를 실행하고 사용자의 입력에 따라 게임을 진행함.
 */
void play_game() {
    int cursorPosition = 0; // 현재 커서 위치
    int selectedCards[2]; // 선택된 카드의 인덱스
    int selectedCount = 0; // 현재 선택된 카드의 수

    enableRawMode();

    initializeBoard(); // 게임 보드 초기화
    while (score < (BOARD_AREA / 2)) { // 모든 쌍을 찾을 때까지 반복
        system("clear");
        printBoard(cursorPosition); // 현재 게임 보드 출력, 커서 위치 인자 전달
        processInput(&cursorPosition, selectedCards, &selectedCount); // 사용자 입력 처리
        if (selectedCount == 2) { // 두 카드가 모두 선택되면
            checkMatch(selectedCards, &selectedCount); // 카드가 일치하는지 확인
        }
    }

    disableRawMode();
    printf("Congratulations! You've completed the game with a score of %d.\n", score);
}
