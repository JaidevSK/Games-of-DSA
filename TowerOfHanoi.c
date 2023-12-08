#include <stdio.h>

/*
 * Print steps for moving n disks from peg 'from'
 * to peg 'to' by using the remaining peg as an
 * intermediate peg.
 *
 * Pegs are numbered 0, 1, 2.
 *
 * Note: All base cases are handled.
 *       All recursive calls are to smaller instances.
 */
void hanoi(int n, int from, int to)
{
    if (n == 1) {
        printf("Shift disk 1 from pole number %d to pole number %d\n", from, to);
        return;
    }
    int intermediate = 3 - (from + to);
    hanoi(n-1, from, intermediate);
    printf("Shift disk %d from pole number %d to pole number %d\n", n, from, to);
    hanoi(n-1, intermediate, to);
}

int main()
{
    printf("Welcome to the game Tower of Hanoi\nInput the number of Disks:");
    int num;
    scanf("%d", &num);
    printf("Solving the Tower of Hanoi...\n");
    printf("\n\nSolution steps:\n");
    hanoi(num, 0, 2);
    return 0;
}
