#include <stdio.h>
#include <stdlib.h>
#include "Find36_GAME.h"
#include "Find36_UT.h"

/**
 * @brief 메인 메뉴를 디스플레이하고 사용자 선택을 반환
 *
 * 메뉴 옵션은 게임 시작, 카드 확인, 크레딧 보기, 게임 종료. 사용자가 선택한 메뉴 옵션을 반환.
 *
 * @return 선택한 메뉴 옵션의 번호.
 */

int display_menu() {
    int menu;

    system("clear");    // 화면 지우기
    
    // 메뉴 디자인 출력
    printf("\n");
    printf("\033[94m▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ \n");
    printf("\033[94m▧                                                                                 ▧\n");
    printf("\033[94m▧ \033[0m ");
    printf("　　　■ ■ ■ ■ 　 ■ ■ ■ 　　■ ■ 　  ■ 　 ■ ■ ■ 　 　 ■ ■ ■ ■ 　 ■ ■ ■ ■　　     \033[94m▧\n");
    printf("\033[94m▧\033[0m ");
    printf("　　 　■ 　　　　　 ■ 　 　 ■  ■    ■ 　 ■ 　  ■ 　 　 　　■    ■　　  　       \033[94m▧ \n");
    printf("\033[94m▧ \033[0m ");
    printf(" 　　 ■ ■ ■ ■ 　　 ■ 　 　 ■   ■   ■ 　 ■  　 ■ 　 　 ■ ■ ■ 　 ■ ■ ■ ■       　\033[94m▧ \n");
    printf("\033[94m▧  \033[0m ");  
    printf(" 　  ■ 　　　　　 ■ 　 　 ■    ■  ■  　■  　 ■ 　 　 　　■    ■ 　  ■         \033[94m▧ \n");
    printf("\033[94m▧ \033[0m ");
    printf(" 　   ■ 　 　 　 ■ ■ ■ 　　■ 　  ■ ■　　■ ■ ■ 　 　 ■ ■ ■ ■ 　 ■ ■ ■ ■         \033[94m▧ \n");
    printf("\033[94m▧                                                                                 ▧ \n");
    printf("\033[94m▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ \n");// 테투리 색상

    printf("\033[0m");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("　　　　　　　　　　　　　 　 Find the Same Picture\n");
    printf("　　　　　　　　　　　　　 　-----------------------\n");
    printf("　　　　　　　　　　　　　 　 　　   M e n u\n");
    printf("　　　　　　　　　　　　 　  -----------------------\n");
    printf("　　　　　　　　　　　　　　   1.   Game Start\n");
    printf("　　　　　　　　　　　　　   　2.   Card Check\n");
    printf("　　　　　　　　　　　　　　   3.   Credit\n");
    printf("　　　　　　　　　　　　　　   4.   End\n");

    scanf("%d", &menu);
    return menu;
}

/**
 * @brief 메인 함수. 프로그램의 진입점
 *
 * 이 함수는 메인 메뉴를 표시하고 사용자의 선택에 따라 게임을 시작하거나 크레딧을 보여주는 등의 작업을 수행.
 * 사용자가 게임 종료를 선택할 때까지 반복됨.
 *
 * @return 프로그램의 종료 상태. 성공적으로 종료되면 0을 반환.
 */
int main() {
    srand(time(NULL));  // 난수 초기화
    int choice;

    while (1) {
        choice = display_menu();

        switch(choice) {
            case 1:
                play_game();
                break;
            case 2:
                display_images();
                break;
            case 3:
                display_credits();
                break;
            case 4:
                printf("\033[2J\033[H");
                printf("게임을 종료합니다\n");
                exit(0);
            default:
                printf("잘못된 선택입니다, 다시 시도하세요\n");
                sleep(1);
        }
    }

    return 0;
}
