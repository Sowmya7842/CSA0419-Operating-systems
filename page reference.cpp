#include <stdio.h>
#define MAX_FRAMES 3
int main()
{
    int page_frames[MAX_FRAMES] = {0};
    int page_faults = 0;
    int page_reference[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int n = sizeof(page_reference) / sizeof(page_reference[0]);
    int i, j, k;

    for (i = 0; i < n; i++) {
        int page = page_reference[i];
        int found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (page_frames[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int lru_page = 0;
            for (j = 0; j < MAX_FRAMES; j++) {
                int found_later = 0;
                for (k = i + 1; k < n; k++) {
                    if (page_frames[j] == page_reference[k]) {
                        found_later = 1;
                        break;
                    }
                }
                if (!found_later) {
                    lru_page = j;
                    break;
                }
            }
            page_frames[lru_page] = page;
            page_faults++;
        }
    }
    printf("Page Faults: %d\n", page_faults);
    return 0;
}


