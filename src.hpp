#include <algorithm>

void Init(int **&p,int n){
    p = new int*[n + 1];
    for (int i = 0; i <= n; ++i) p[i] = nullptr;
}
void Add_element(int **&p,int x,int y){
    int *a = p[x];
    if (a == nullptr) {
        int cap = 1;
        a = new int[2 + cap];
        a[0] = cap;
        a[1] = 0;
        p[x] = a;
    }
    int cap = a[0];
    int sz = a[1];
    if (sz == cap) {
        int newcap = cap << 1;
        int *b = new int[2 + newcap];
        b[0] = newcap;
        b[1] = sz;
        std::copy(a + 2, a + 2 + sz, b + 2);
        delete [] a;
        a = b;
        p[x] = a;
    }
    a[2 + a[1]] = y;
    ++a[1];
}
int Get_element(int **&p,int x,int k){
    int *a = p[x];
    return a[2 + (k - 1)];
}
void Clear(int **&p,int n){
    for (int i = 1; i <= n; ++i) {
        if (p[i] != nullptr) delete [] p[i];
    }
    delete [] p;
    p = nullptr;
}
