#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
};

void extractLogEntries(struct LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[100];
    char *token;
    int lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        if (lineCount == 0) {  // Skip the header line
            lineCount++;
            continue;
        }

        struct LogEntry entry;
        token = strtok(line, ",");
        entry.entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entry.sensorNo, token);

        token = strtok(NULL, ",");
        entry.temperature = atof(token);

        token = strtok(NULL, ",");
        entry.humidity = atoi(token);

        token = strtok(NULL, ",");
        entry.light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entry.timestamp, token);

        logEntries[lineCount - 1] = entry;
        lineCount++;
    }

    *numEntries = lineCount - 1;
    fclose(file);
}

void displayLogEntries(struct LogEntry logEntries[], int numEntries) {
    printf("%-8s %-10s %-12s %-8s %-6s\n", "EntryNo", "SensorNo", "Temperature", "Humidity", "Light");
    for (int i = 0; i < numEntries; i++) {
        printf("%-8d %-10s %-12.1f %-8d %-6d\n", logEntries[i].entryNo, logEntries[i].sensorNo,
               logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogEntries(logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}
