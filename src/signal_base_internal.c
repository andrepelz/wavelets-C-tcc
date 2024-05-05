int double_compare_function(const void *a,const void *b) {
    double *x = (double *) a;
    double *y = (double *) b;

    if (*x < *y) return -1;
    else if (*x > *y) return 1;
    return 0;
}

int int_compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;

    return *x - *y;
}