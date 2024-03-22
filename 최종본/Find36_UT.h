#ifndef UTILITY_H
#define UTILITY_H

/**
 * @brief 터미널 원시 모드 활성화.
 *
 * 터미널 입력을 원시 모드로 설정하여 세밀한 입력 처리를 가능하게 함.
 */
void enableRawMode();

/**
 * @brief 터미널 원시 모드 비활성화.
 *
 * 프로그램 종료 시 터미널 설정을 원래대로 복구.
 */
void disableRawMode();

/**
 * @brief 게임 크레딧 디스플레이.
 *
 * 게임 제작에 참여한 인원의 크레딧을 보여줌.
 */
void display_credits();

/**
 * @brief 게임 이미지 디스플레이.
 *
 * 사용자에게 게임에서 사용 가능한 모든 이미지를 보여줌.
 */
void display_images();

#endif
