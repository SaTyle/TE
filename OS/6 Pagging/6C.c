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

// Function to find the index of the page that will not be used for the longest time (Optimal)
int findOptimalPage(int pages[], int frames[], int frameSize, int currentIndex) {
    int farthestIndex = -1;
    int farthestDistance = -1;
    int pageCount;

    for (int i = 0; i < frameSize; i++) {
        int j;
        for (j = currentIndex + 1; j < pageCount; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthestDistance) {
                    farthestDistance = j;
                    farthestIndex = i;
                }
                break;
            }
        }

        if (j == pageCount) {
            return i; // If a page will not be used anymore, replace it
        }
    }

    return farthestIndex; // Replace the page that will be used farthest in the future
}

// Function to perform Optimal page replacement algorithm
void optimal(int pages[], int pageCount, int frameSize) {
    int frames[frameSize];
    int pageFaults = 0;

    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < pageCount; i++) {
        if (!isPagePresent(pages[i], frames, frameSize)) {
            int replaceIndex = findOptimalPage(pages, frames, frameSize, i);
            frames[replaceIndex] = pages[i];
            pageFaults++;
        }
    }

    printf("Total page faults using Optimal: %d\n", pageFaults);
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
    optimal(pages, pageCount, frameSize);

    return 0;
}