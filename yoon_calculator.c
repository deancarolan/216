#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *stream;
    char line[1024], assignment[81], filename[81];
    int points, max, weight_pct;
    float value, total_points = 0, grade, weighted_sum = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    if(!(stream = fopen(filename, "r"))){
        exit(EXIT_FAILURE);
    }

    while(fgets(line, 1024, stream)){
        
        sscanf(line, "%s %d %d %d", assignment, &points, &max, &weight_pct);

	printf("Name: %s, Points: %d, MAX: %d, Pct: %d\n", assignment, points, max, weight_pct);
	weighted_sum += (float)weight_pct;
	value = (float)weight_pct * ((float)points / (float)max);
        total_points += value;
    }

    grade = (float)total_points / (float)weighted_sum;

    printf("Grade is: %f\n", grade*100);

    fclose(stream);
    return 0;
    
}
