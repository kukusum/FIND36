#ifndef GAME_H
#define GAME_H

#define IMG_HEIGHT 7
#define IMG_WIDTH 18
#define MAX_IMAGES 16
#define BOARD_SIZE 4
#define BOARD_AREA (BOARD_SIZE * BOARD_SIZE)

extern char images[MAX_IMAGES][IMG_HEIGHT][IMG_WIDTH + 1];
extern int board[BOARD_AREA];
extern int revealedCards[BOARD_AREA];
extern int score;

/**
 * @brief 게임 보드 초기화 함수.
 *
 * 게임 시작 전 보드와 카드를 초기화.
 */
void initializeBoard();

/**
 * @brief 카드 섞기 함수.
 *
 * 주어진 배열의 카드를 셔플.
 *
 * @param array 섞을 배열.
 * @param size 배열의 크기.
 */
void shuffleCards(int *array, int size);

/**
 * @brief 게임 보드 출력 함수.
 *
 * 사용자에게 현재 게임 보드 상태를 보여줌.
 *
 * @param cursorPosition 현재 커서 위치.
 */
void printBoard(int cursorPosition);

/**
 * @brief 사용자 입력 처리 함수.
 *
 * 사용자로부터 입력을 받아 게임 상태를 업데이트.
 *
 * @param cursorPosition 현재 커서 위치.
 * @param selectedCards 선택된 카드의 인덱스 배열.
 * @param selectedCount 선택된 카드의 수.
 */
void processInput(int* cursorPosition, int* selectedCards, int* selectedCount);

/**
 * @brief 카드 일치 검사 함수.
 *
 * 사용자가 선택한 두 카드가 일치하는지 검사.
 *
 * @param selectedCards 선택된 카드의 인덱스 배열.
 * @param selectedCount 선택된 카드의 수.
 */
void checkMatch(int* selectedCards, int* selectedCount);

/**
 * @brief 게임 플레이 메인 함수.
 *
 * 게임의 주요 루프와 로직을 관리합니다.
 */
void play_game();

#endif
