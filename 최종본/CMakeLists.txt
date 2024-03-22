cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 설정
project(FIND34)

# C 표준 설정
set(CMAKE_C_STANDARD 99)

# 헤더 파일 위치 지정
include_directories(${PROJECT_SOURCE_DIR})

# 실행 파일 및 관련 소스 파일 정의
add_executable(FIND34 Find36_MAIN.c Find36_GAME.c Find36_UT.c Find36_GAME.h Find36_UT.h)

