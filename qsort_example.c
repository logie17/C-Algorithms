// Prototype for qsort
void qsort_it(char *arr_words[], int left, int right);

// Prototype for the swap function
void swap_it(char *arr_words[], int i, int j);     


void qsort_it(char *arr_words[], int left, int right)
/*  qsort_it
    Purpose:    An implementation of the qsort function. The aglorithm is outlined in the K&O book
    Input:      1. Pointer to an array of chars
                2. Left index value of the array of pointers
                3. Right index value of the array of pointers
    Output:     Void
*/ 
{
    int i, last;

    // We're done if left is larger than right
    if (left >= right ) 
        return;

    // Swap the middle item to the beginning of the array
    swap_it(arr_words, left, (left + right)/2);

    // Start index value is at the beginning
    last = left;

    // Start moving right comparing the far left + 1 value swapping into place
    for (i = left+1; i <= right; i++)
    {
        if (strcmp(arr_words[i],arr_words[left]) < 0 )
            swap_it(arr_words, ++last, i);
    }
    
    // Move the index of the original swap back into it's position 
    swap_it(arr_words, left, last);

    // Beging the process again recursively for left side and right side
    qsort_it(arr_words, left, last-1);
    qsort_it(arr_words, last+1, right);
 
}

void swap_it(char * arr_words[], int i, int j)
/*  swap_it
    Purpose:    The swap function swaps to values in a pointer array - see qsort_it
    Input:      1. Pointer to an array of chars
                2. First value to swap (index)
                2. Second value to swap (index)
    Output:     Void
*/ 
{
    char * temp;        //Temp pointer to hold address of the swap index

    temp         = arr_words[i];
    arr_words[i] = arr_words[j];
    arr_words[j] = temp;

}
