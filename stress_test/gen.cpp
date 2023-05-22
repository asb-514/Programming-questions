// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int w = rand(3,100);
    printf("%d ", w);
    int n = rand(3,50);
    printf("%d ", n);
    int k = rand(0,n-1);
    printf("%d\n", k);
    set<int> used;
    for(int i = 0; i < w; ++i) {
        int x;
        x = rand(1,n);
        printf("%d ", x);
        used.insert(x);
    }
    puts("");
}
    
