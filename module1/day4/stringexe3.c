#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long computeTotalSeconds(char *timeString) {
    char *token;
    unsigned long totalSeconds = 0;
    int hour, minute, second;

    token = strtok(timeString, ":");

    hour = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");

    minute = strtoul(token, NULL, 10);
    token = strtok(NULL, ":");

    second = strtoul(token, NULL, 10);

    totalSeconds = hour * 3600 + minute * 60 + second;

    return totalSeconds;
}

int main() {
    char timeString1[] = "10:12:50";
    char timeString2[] = "13:10:40";

    unsigned long totalSeconds1 = computeTotalSeconds(timeString1);
    unsigned long totalSeconds2 = computeTotalSeconds(timeString2);

    printf("Input String 1: %s\n", timeString1);
    printf("Total Seconds 1: %lu\n", totalSeconds1);

    printf("Input String 2: %s\n", timeString2);
    printf("Total Seconds 2: %lu\n", totalSeconds2);

    return 0;
}
