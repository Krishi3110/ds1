#include <stdio.h>

void accept(int r, int c, int mat[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
    }
}

void print(int r, int c, int mat[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%4d", mat[i][j]);

        printf("\n");
    }
}

void add(int r, int c, int a[r][c],
         int b[r][c], int res[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void sub(int r, int c, int a[r][c],
         int b[r][c], int res[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void mul(int r1, int c1, int c2,
         int a[r1][c1], int b[c1][c2],
         int res[r1][c2])
{
    int i, j, k;

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            res[i][j] = 0;

            for (k = 0; k < c1; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transpose(int r, int c, int a[r][c], int res[c][r])
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            res[j][i] = a[i][j];
}

int main()
{
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);

    int a[r1][c1];

    printf("Enter elements for Matrix A:\n");
    accept(r1, c1, a);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    int b[r2][c2];

    printf("Enter elements for Matrix B:\n");
    accept(r2, c2, b);

    do
    {
        printf("\n1. Add\n");
        printf("2. Subtract\n");
        printf("3. Transpose A\n");
        printf("4. Multiply (A*B)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (r1 == r2 && c1 == c2)
                {
                    int res[r1][c1];
                    add(r1, c1, a, b, res);
                    printf("Resultant Matrix:\n");
                    print(r1, c1, res);
                }
                else
                    printf("Addition requires same dimensions.\n");
                break;

            case 2:
                if (r1 == r2 && c1 == c2)
                {
                    int res[r1][c1];
                    sub(r1, c1, a, b, res);
                    printf("Resultant Matrix:\n");
                    print(r1, c1, res);
                }
                else
                    printf("Subtraction requires same dimensions.\n");
                break;

            case 3:
            {
                int res[c1][r1];
                transpose(r1, c1, a, res);
                printf("Transpose of Matrix A:\n");
                print(c1, r1, res);
                break;
            }

            case 4:
                if (c1 == r2)
                {
                    int res[r1][c2];
                    mul(r1, c1, c2, a, b, res);
                    printf("Resultant Matrix:\n");
                    print(r1, c2, res);
                }
                else
                    printf("Multiplication requires columns of A to equal rows of B.\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
