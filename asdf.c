#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void count_down(int minute, int second);

int main(int argc, char* argv[]) {
    if (argc < 2){
        fprintf(stderr, "usage: %s <minute> <second>\n", argv[0]);
        exit(1);
    }

    int minute = atoi(argv[1]);
    int second;

    if (argc == 3)
        second = atoi(argv[2]);
    else
        second = 0;

    if (second >= 60){
        fprintf(stderr, "Error: Enter the right number\n");
        exit(1);
    }

    //printf("%d %d\n", minute, second);
    count_down(minute, second);

    return 0;
}


void count_down(int minute, int second) {
    while (minute || second){
        system("clear");
        printf("%02d:%02d\n", minute, second);
        second--;
        if (second == -1){
            second = 59;
            minute--;
        }
        sleep(1);
    }
}
