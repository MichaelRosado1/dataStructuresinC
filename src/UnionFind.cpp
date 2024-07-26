#include "UnionrFind.h"


// instantiates the subsets;
void makeSet(Subset subsets[], int n) {
	for (int i = 0; i < n; i++) {
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
}


// recursive function to find the parent of a subset
int find(Subset subsets[], int i) {
	if (subsets[i].parent != i) {
		subsets[i].parent = find(subsets, i);
	}
	return subsets[i].parent; 
}


void unionSets(Subset subsets[], int x, int y) {
	int x_root = find(subsets, x);  // returns an index
	int y_root = find(subsets, y);

	// this means we merge y to 
	if (subsets[x_root].rank > subsets[y_root].rank) {
		subsets[y_root].parent = x_root;
	} else if (subsets[y_root].rank > subsets[x_root].rank) {
		subsets[x_root].parent = x_root;
	} else {
		subsets[y_root].parent = x_root;
		subsets[x_root].rank++;
	}
}