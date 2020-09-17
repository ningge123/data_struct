//
// Created by cocoyo on 2020/9/3.
// 顺序表
//

#include <stdio.h>
#include <stdlib.h>

const int InitSize = 10;

typedef struct {
    int *data;
    int MaxSize;
    int length;
}SeqList;

// 动态分配
void InitList(SeqList &L) {
    L.data = (int *)malloc(InitSize * sizeof(int));

    for (int i = 0; i < InitSize; ++i) {
        L.data[i] = 0;
    }

    L.length = 0;
    L.MaxSize = InitSize;
}

// 动态扩展
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));

    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }

    L.MaxSize = L.MaxSize + len;
    free(p);
}


bool ListInsert(SeqList &L, int i, int e) {
    if (i > L.length + 1 || i < 1) {
        return false;
    }

    if (L.length == L.MaxSize) {
        IncreaseSize(L, 1);


    }
}


int main()
{
    SeqList L;

    InitList(L);

    IncreaseSize(L, 5);

    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}

