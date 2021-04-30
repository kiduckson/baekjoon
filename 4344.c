#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total, students;
    int *scores;
    double avg;
    double *avgs;
    
    scanf("%d", &total);
    avgs = (double *)calloc(total, sizeof(double));
    for (int i = 0; i < total; i++)
    {
        scanf("%d", &students);
        scores = (int *)calloc(students, sizeof(int));
        avg = 0;
        for (int j = 0; j < students; j++)
        {
            scanf("%d", &scores[j]);
            avg += (double)scores[j];
        }
        avg /= (double)students;
        for (int k = 0; k < students; k++)
        {
            if (scores[k] > avg)
                avgs[i]++; 
        }
        free(scores);
        avgs[i] /= (double)students;
    }
    for (int i = 0; i < total; i++)
        printf("%.3lf%%\n", (avgs[i] * 1000) / 10);
    free(avgs);
}