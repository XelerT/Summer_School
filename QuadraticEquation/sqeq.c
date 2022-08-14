#include <stdio.h>
#include <math.h>

static const int MAXLINE = 1000;

int getNumbers(char s[], int maxlength, float num[]) {
    int j, i, f;
    bool have_dot, negative;
    have_dot = negative = false;
    ++num;
    for (i = 0; (j = getchar()) != EOF; i++) {
        if (j >= '0' && j <= '9') {
            if (have_dot) {
                *num = *num + (float)(j - '0')/(pow(10, f));
                f++;
            } else {
            *num = *num * 10 + j - '0';
            }
        } else if (j == ',' || j == '.') {
            f = 1;
            have_dot = true;
        } else if (j == '-') {
            negative = true;
        } else if (j == '\n') {
            if (negative) {
                *num *= -1;
            }
            ++num;
            negative = false;
            have_dot = false;
        }
    }
    return i;
}

int main() {
    float num[MAXLINE]; // len, a, b, c, D, x1, x2;
    char    s[MAXLINE]; //   0, 1, 2, 3, 4,  5,  6;
    printf("Enter a, b, c of quadratic equation\nExample:\n\t115\n\t2\n\t5\n");
    while (num[0] = getNumbers(s, MAXLINE, num)) {
        ;
    }
    printf("a = %f, b = %f, c = %f\n", num[1], num[2], num[3]);
    num[4] = num[2] * num[2] - 4 * num[1] * num[3];
    if (num[4] > 0) {
        num[5] = (-1 * num[2] + sqrt(num[4]))/(2 * num[1]);
        num[6] = (-1 * num[2] - sqrt(num[4]))/(2 * num[1]);
        printf("\tD = %f,\n\tx1 = %f,\n\tx2 = %f", num[4], num[5], num[6]);
    } else if (num[4] == 0) {
        num[6] = num[5] = (-1 * num[2])/(2 * num[1]);
        printf("\tD = %f,\n\tx1 = x2 = %f", num[4], num[5]);
    } else {
        printf("\tD = %f,\n\tx1, x2 in complex field", num[4]);
    }
}