#ifndef _HELPERS_FOR_QUICK
#define _HELPERS_FOR_QIOCK

#define MAX_ARRAY_LENGTH    100

struct quick
{
    int less_index, greatest_index, pivot, arr_size;
};

static struct quick divide(int [], int [], int [], struct quick);

static void collect(int [], int [], int [], struct quick);

#endif