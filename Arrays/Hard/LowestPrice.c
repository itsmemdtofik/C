#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int startTime;
    int endTime;
    int price;
} Interval;

typedef struct
{
    int key;
    int value;
} MapEntry;

typedef struct
{
    MapEntry *entries;
    int size;
    int capacity;
} Map;

void initMap(Map *map, int capacity)
{
    map->entries = (MapEntry *)malloc(sizeof(MapEntry) * capacity);
    map->size = 0;
    map->capacity = capacity;
}

void put(Map *map, int key, int value)
{
    for (int i = 0; i < map->size; i++)
    {
        if (map->entries[i].key == key)
        {
            if (map->entries[i].value > value)
                map->entries[i].value = value;
            return;
        }
    }
    if (map->size < map->capacity)
    {
        map->entries[map->size].key = key;
        map->entries[map->size].value = value;
        map->size++;
    }
}

int cmp(const void *a, const void *b)
{
    return ((MapEntry *)a)->key - ((MapEntry *)b)->key;
}

Interval *getMinimumPriceIntervals(Interval *priceIntervals, int n, int *resultSize)
{
    Map map;
    initMap(&map, 100);

    for (int i = 0; i < n; i++)
    {
        int currentPrice = priceIntervals[i].price;
        for (int j = priceIntervals[i].startTime; j < priceIntervals[i].endTime; j++)
        {
            put(&map, j, currentPrice);
        }
    }

    qsort(map.entries, map.size, sizeof(MapEntry), cmp);

    Interval *result = (Interval *)malloc(sizeof(Interval) * map.size);
    int count = 0;

    for (int i = 0; i < map.size; i++)
    {
        if (count > 0)
        {
            if (result[count - 1].price != map.entries[i].value)
            {
                result[count - 1].endTime = map.entries[i].key;
                result[count].startTime = map.entries[i].key;
                result[count].endTime = map.entries[i].key + 1;
                result[count].price = map.entries[i].value;
                count++;
            }
            else
            {
                result[count - 1].endTime = map.entries[i].key + 1;
            }
        }
        else
        {
            result[count].startTime = map.entries[i].key;
            result[count].endTime = map.entries[i].key + 1;
            result[count].price = map.entries[i].value;
            count++;
        }
    }

    *resultSize = count;
    return result;
}

int main()
{
    Interval intervals[] = {
        {0, 4, 5},
        {2, 8, 3},
        {7, 11, 10}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int resultSize;
    Interval *result = getMinimumPriceIntervals(intervals, n, &resultSize);

    for (int i = 0; i < resultSize; i++)
    {
        printf("Start: '%d', End: '%d' Price: '%d'\n",
               result[i].startTime, result[i].endTime, result[i].price);
    }

    free(result);
    return 0;
}
