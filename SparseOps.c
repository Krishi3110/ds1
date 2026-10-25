#include <stdio.h>

void sparse(int r, int c, int a[r][c], int z, int nz)
{
    printf("\nNumber of Zero Elements = %d\n", z);
    printf("Number of Non-Zero Elements = %d\n", nz);

    if (z > nz)
        printf("The matrix is a Sparse Matrix.\n");
    else
        printf("The matrix is not a Sparse Matrix.\n");
}

void comp(int r, int c, int a[r][c], int nz)
{
    int comp[nz + 1][3];
    int i, j, k = 1;

    comp[0][0] = r;
    comp[0][1] = c;
    comp[0][2] = nz;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                comp[k][0] = i;
                comp[k][1] = j;
                comp[k][2] = a[i][j];
                k++;
            }
        }
    }

    printf("\nCompact Form:\n");
    printf("C1  C2  C3\n");

    for (i = 0; i <= nz; i++)
        printf("%3d %3d %5d\n",
               comp[i][0], comp[i][1], comp[i][2]);
}

void strans(int r, int c, int a[r][c], int nz)
{
    int comp[nz + 1][3];
    int trans[nz + 1][3];
    int i, j, k = 1;

    comp[0][0] = r;
    comp[0][1] = c;
    comp[0][2] = nz;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                comp[k][0] = i;
                comp[k][1] = j;
                comp[k][2] = a[i][j];
                k++;
            }
        }
    }

    trans[0][0] = c;
    trans[0][1] = r;
    trans[0][2] = nz;

    k = 1;

    for (i = 0; i < c; i++)
    {
        for (j = 1; j <= nz; j++)
        {
            if (comp[j][1] == i)
            {
                trans[k][0] = comp[j][1];
                trans[k][1] = comp[j][0];
                trans[k][2] = comp[j][2];
                k++;
            }
        }
    }

    printf("\nSimple Transpose:\n");
    printf("C1  C2  C3\n");

    for (i = 0; i <= nz; i++)
        printf("%3d %3d %5d\n",
               trans[i][0], trans[i][1], trans[i][2]);
}

void ftrans(int r, int c, int a[r][c], int nz)
{
    int comp[nz + 1][3];
    int trans[nz + 1][3];
    int count[c], index[c];
    int i, j, k = 1;

    comp[0][0] = r;
    comp[0][1] = c;
    comp[0][2] = nz;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                comp[k][0] = i;
                comp[k][1] = j;
                comp[k][2] = a[i][j];
                k++;
            }
        }
    }

    trans[0][0] = c;
    trans[0][1] = r;
    trans[0][2] = nz;

    for (i = 0; i < c; i++)
        count[i] = 0;

    for (i = 1; i <= nz; i++)
        count[comp[i][1]]++;

    index[0] = 1;

    for (i = 1; i < c; i++)
        index[i] = index[i - 1] + count[i - 1];

    for (i = 1; i <= nz; i++)
    {
        j = index[comp[i][1]];

        trans[j][0] = comp[i][1];
        trans[j][1] = comp[i][0];
        trans[j][2] = comp[i][2];

        index[comp[i][1]]++;
    }

    printf("\nFast Transpose:\n");
    printf("C1  C2  C3\n");

    for (i = 0; i <= nz; i++)
        printf("%3d %3d %5d\n",
               trans[i][0], trans[i][1], trans[i][2]);
}

int main()
{
    int r, c, i, j;
    int z = 0, nz = 0, ch;

    printf("Enter number of rows: ");
    scanf("%d", &r);

    printf("Enter number of columns: ");
    scanf("%d", &c);

    int a[r][c];

    printf("Enter the elements of the matrix:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);

            if (a[i][j] == 0)
                z++;
            else
                nz++;
        }
    }

    printf("\nMatrix is:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }

    do
    {
        printf("\n1. Check Sparse Matrix\n");
        printf("2. Compact Form\n");
        printf("3. Simple Transpose\n");
        printf("4. Fast Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                sparse(r, c, a, z, nz);
                break;

            case 2:
                if (z > nz)
                    comp(r, c, a, nz);
                else
                    printf("The matrix is not a Sparse Matrix.\n");
                break;

            case 3:
                if (z > nz)
                    strans(r, c, a, nz);
                else
                    printf("The matrix is not a Sparse Matrix.\n");
                break;

            case 4:
                if (z > nz)
                    ftrans(r, c, a, nz);
                else
                    printf("The matrix is not a Sparse Matrix.\n");
                break;

            case 5:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 5);

    return 0;
}
