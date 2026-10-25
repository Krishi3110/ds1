#include <stdio.h>

void read(int size, int array[size])
{
    int index;

    printf("Enter the elements in the array:\n");

    for (index = 0; index < size; index++)
        scanf("%d", &array[index]);
}

void display(int size, int array[size])
{
    int index;

    for (index = 0; index < size; index++)
        printf("%d ", array[index]);

    printf("\n");
}

void lSearch(int size, int key, int array[size])
{
    int index, found = 0;

    for (index = 0; index < size; index++)
    {
        if (array[index] == key)
        {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Found\n");
    else
        printf("Not Found\n");
}

void bSearch(int size, int key, int array[size])
{
    int low = 0;
    int high = size - 1;
    int mid;
    int found = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == key)
        {
            found = 1;
            break;
        }
        else if (key < array[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (found)
        printf("Found\n");
    else
        printf("Not Found\n");
}

void isort(int size, int array[size])
{
    int index, j, value;

    for (index = 1; index < size; index++)
    {
        value = array[index];
        j = index - 1;

        while (j >= 0 && array[j] > value)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = value;
    }
}

void sSort(int size, int array[size])
{
    int index, j, min, temp;

    for (index = 0; index < size - 1; index++)
    {
        min = index;

        for (j = index + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }

        if (min != index)
        {
            temp = array[index];
            array[index] = array[min];
            array[min] = temp;
        }
    }
}

void shsort(int size, int array[size])
{
    int gap, i, j, temp;

    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];

            for (j = i; j >= gap && array[j - gap] > temp;
                 j -= gap)
            {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }
}

int main()
{
    int size, choice, key;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size\n");
        return 1;
    }

    int array[size];

    read(size, array);

    do
    {
        printf("\n1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Shell Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                lSearch(size, key, array);
                break;

            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                bSearch(size, key, array);
                break;

            case 3:
                isort(size, array);
                printf("Insertion Sort:\n");
                display(size, array);
                break;

            case 4:
                sSort(size, array);
                printf("Selection Sort:\n");
                display(size, array);
                break;

            case 5:
                shsort(size, array);
                printf("Shell Sort:\n");
                display(size, array);
                break;

            case 6:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
