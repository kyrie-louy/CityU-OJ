#include <stdio.h>
#include <cstring>
class townSet
{
public:
    int Find(int);
    void Union(int, int);
    void set();
    void setLimit(int);
    int largestGroup();
    void show();
private:
    int arr[30000];
    int sz[30000];
    int limit;
};

int townSet::largestGroup(){
    int result = -1;
    for(int i = 0; i<limit;i++){
        if(sz[i] > result)
            result = sz[i];
    }
    
    return result;
}
void townSet::setLimit(int l){
    limit = l;
}

int townSet::Find(int i)
{
    if(arr[i] < 0)
        return i;
    else
        return arr[i] = Find(arr[i]);
}

void townSet::Union(int i, int j)
{
    i--;
    j--;
    arr[Find(j)] = Find(i);
    sz[Find(i)] += sz[Find(j)];
}

void townSet::set(){
    for (int i = 0; i< limit; i++) {
        arr[i] = -1;
        sz[i] = 1;
    }
}

void townSet::show(){
    for(int i = 0;i<limit;i++){
        printf("%d ",arr[i]);
    }
}

int main() {
    int T;
    scanf("%d",&T);
    townSet ts;
    
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        ts.setLimit(n);
        ts.set();
        
        while (m--) {
            int a,b;
            scanf("%d%d",&a,&b);
            ts.Union(a, b);
        }
        
        printf("%d\n",ts.largestGroup());
    }
    return 0;
}
