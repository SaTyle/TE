#include <stdio.h>
#include <stdlib.h>

// Function to check if a page is present in frames
int isPagePresent(int page, int frames[], int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == page) {
            return 1; // Page is present
        }
    }
    return 0; // Page is not present
}

// Function to find the index of the oldest page in frames (FCFS)
int findOldestPage(int frames[], int frameSize) {
    int oldestIndex = 0;
    for (int i = 1; i < frameSize; i++) {
        if (frames[i] < frames[oldestIndex]) {
            oldestIndex = i;
        }
    }
    return oldestIndex;
}

// Function to perform FCFS page replacement algorithm
void fcfs(int pages[], int pageCount, int frameSize) {
    int frames[frameSize];
    int pageFaults = 0;

    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1; // Initialize frames with -1 to represent empty frames
    }

    for (int i = 0; i < pageCount; i++) {
        if (!isPagePresent(pages[i], frames, frameSize)) {
            frames[pageFaults % frameSize] = pages[i];
            pageFaults++;
        }
    }

    printf("Total page faults using FCFS: %d\n", pageFaults);
}

// Function to perform LRU page replacement algorithm
void lru(int pages[], int pageCount, int frameSize) {
    int frames[frameSize];
    int pageFaults = 0;
    int usedOrder[frameSize]; // Array to store the order in which frames are used

    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
        usedOrder[i] = 0; // Initialize used order to 0
    }

    for (int i = 0; i < pageCount; i++) {
        if (!isPagePresent(pages[i], frames, frameSize)) {
            int replaceIndex = findOldestPage(usedOrder, frameSize);
            frames[replaceIndex] = pages[i];
            usedOrder[replaceIndex] = i + 1; // Update the used order
            pageFaults++;
        } else {
            for (int j = 0; j < frameSize; j++) {
                if (frames[j] == pages[i]) {
                    usedOrder[j] = i + 1; // Update the used order
                    break;
                }
            }
        }
    }

    printf("Total page faults using LRU: %d\n", pageFaults);
}

int main() {
    int pageCount, frameSize;

    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);

    int pages[pageCount];

    printf("Enter the page sequence:\n");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the frame size (minimum 3): ");
    scanf("%d", &frameSize);

    if (frameSize < 3) {
        printf("Frame size should be minimum 3.\n");
        return 1;
    }

    fcfs(pages, pageCount, frameSize);
    lru(pages, pageCount, frameSize);

    return 0;
}