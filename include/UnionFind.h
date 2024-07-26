#ifndef UNIONFIND_H
#define UNIONFIND_H

typedef struct {
	int parent;
	int rank;
} Subset;

void makeSet(Subset subsets[], int n);

int find(Subset subsets[], int i);

void unionSets(Subset subsets[], int x, int y);

#endif  // UNIONFIND_H