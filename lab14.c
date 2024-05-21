#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
FILE *file;
file = fopen("numbers.txt", "r");
if (file == NULL) {
    printf("Error opening the file.\n");
    return -1;
}

int numbers[100];
int num, count = 0;
float sum = 0, mean, deviation, min_deviation;

while (fscanf(file, "%d", &num) == 1) {
    numbers[count] = num;
    sum += num;
    count++;
}

mean = sum / count;

min_deviation = fabs(numbers[0] - mean);
for (int i = 1; i < count; i++) {
    deviation = fabs(numbers[i] - mean);
    if (deviation < min_deviation) {
        min_deviation = deviation;
    }
}

printf("The smallest deviation from the mean is: %.2f\n", min_deviation);

fclose(file);

return 0;
}