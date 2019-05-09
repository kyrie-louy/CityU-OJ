#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

class min_heap
{
private:
    int size;
    int items[100005];
public:
    void Inset(int key);
    int Pop();
    min_heap(){
        size = 0;
    }
    int getSize(){
        return size;
    }
};

int min_heap::Pop(){
    int value = items[0];
    int child;
    items[0] = items[size-1];
    int hole = 0;
    int temp = items[0];
    for(;hole*2+1 < size;hole = child){
        child = hole*2+1;
        if(items[child+1] < items[child] && child+1<size)
            child++;
        if(items[child] < temp)
            items[hole] = items[child];
        else
            break;
    }
    items[hole] = temp;
    size--;
    return value;
}

void min_heap::Inset(int key){
    int i = size;
    items[i] = key;
    while(items[i] < items[(i-1)/2] && i != 0){
        swap(items[i], items[(i-1)/2]);
        i = (i-1)/2;
    }
    size++;
}

int main() {
    int n;
    while (cin >> n) {
        min_heap mh;
        for (int i = 0; i<n; i++) {
            int m;
            cin>>m;
            mh.Inset(m);
        }
        
        int sum = 0;
        while (mh.getSize() > 1 ) {
            int min1 = mh.Pop();
            int min2 = mh.Pop();
            
            sum += (min1 + min2);
            mh.Inset(min1+min2);
        }
        cout<<sum<<endl;
    }
    return 0;
}

