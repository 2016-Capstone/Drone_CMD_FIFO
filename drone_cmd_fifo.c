#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define SIZE 3
#define FIFO "cmd_fifo"
#define EEXIST 17


#define QUIT "113"
#define UP "65"
#define DOWN "66"
#define RIGHT "67"
#define LEFT "68"
#define EMERGENCY "101"
#define TAKEOFF "116"
#define LAND "32"
#define GO "114"
#define REVERSE "102"
#define MOVE_LEFT "100"
#define MOVE_RIGHT "103"


/**
 *
 *  1. 상수화- keymap참고 작성 - 작성완료
 *  2. fifo 존재여부 검사
 *  3. fifo 생성 디렉토리를 변경
 *
 * */

int main(){
    int fd;
    char buff[SIZE];

    if(mkfifo(FIFO, 0666) == -1){
		
		if(errno == EEXIST)
		{
			//printf("errno : %d", errno);
			printf("file exists, keep running\n");
		}
		/*
		perror("mkfifo failed");
		exit(1);
		*/
    }

	if((fd = open(FIFO, O_WRONLY)) == -1){
        perror("open failed");
        exit(1);
    }

    sleep(7);

    strcpy(buff, TAKEOFF);
    if(write(fd, buff, SIZE) == -1){
        perror("write failed");
        exit(1);
    }

    sleep(7);
    
    strcpy(buff, LAND);
    if(write(fd, buff, SIZE) == -1){
       perror("write failed");
       exit(1);
    }


    sleep(7);

    strcpy(buff, TAKEOFF);
    if(write(fd, buff, SIZE) == -1){
        perror("write failed");
        exit(1);
    }

    sleep(7);
    
    strcpy(buff, LAND);
    if(write(fd, buff, SIZE) == -1){
       perror("write failed");
       exit(1);
    }


    sleep(7);

    strcpy(buff, TAKEOFF);
    if(write(fd, buff, SIZE) == -1){
        perror("write failed");
        exit(1);
    }

    sleep(7);
    
    strcpy(buff, LAND);
    if(write(fd, buff, SIZE) == -1){
       perror("write failed");
       exit(1);
    }
sleep(2);
    strcpy(buff, QUIT);
    if(write(fd, buff, SIZE) == -1){
       perror("write failed");
       exit(1);
    }
    exit(0);
}
