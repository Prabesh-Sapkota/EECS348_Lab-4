#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        
        // Handle non-numeric input (like letters)
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }

        if (score == 1)
            break;

        // Reject negative scores
        if (score < 0) {
            printf("Invalid input. Score cannot be negative.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n",
               score);
#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

        if (score == 1)
            break;

        printf("Possible combinations of scoring plays if a team's score is %d:\n",
               score);

        for (int td2 = 0; td2 * 8 <= score; td2++) {
            for (int td7 = 0; td2 * 8 + td7 * 7 <= score; td7++) {
                for (int td6 = 0;
                     td2 * 8 + td7 * 7 + td6 * 6 <= score;
                     td6++) {

                    for (int fg = 0;
                         td2 * 8 + td7 * 7 + td6 * 6 + fg * 3 <= score;
                         fg++) {

                        int remaining = score
                                      - td2 * 8
                                      - td7 * 7
                                      - td6 * 6
                                      - fg * 3;

                        if (remaining % 2 == 0) {
                            int safety = remaining / 2;

                            printf("%d TD + 2pt, %d TD + FG, %d TD, "
                                   "%d 3pt FG, %d Safety\n",
                                   td2, td7, td6, fg, safety);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
        for (int td2 = 0; td2 * 8 <= score; td2++) {
            for (int td7 = 0; td2 * 8 + td7 * 7 <= score; td7++) {
                for (int td6 = 0;
                     td2 * 8 + td7 * 7 + td6 * 6 <= score;
                     td6++) {

                    for (int fg = 0;
                         td2 * 8 + td7 * 7 + td6 * 6 + fg * 3 <= score;
                         fg++) {

                        int remaining = score
                                      - td2 * 8
                                      - td7 * 7
                                      - td6 * 6
                                      - fg * 3;

                        if (remaining % 2 == 0) {
                            int safety = remaining / 2;

                            printf("%d TD + 2pt, %d TD + FG, %d TD, "
                                   "%d 3pt FG, %d Safety\n",
                                   td2, td7, td6, fg, safety);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
