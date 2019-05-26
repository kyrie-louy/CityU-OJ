#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

struct person{
    string name;
    int birth;
}list[105];

bool pCompare(const person &a,const person &b){
    return a.birth > b.birth;
}

int main(){
    int n;
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        char* name_input = new char[15];
        int d,m,y;
        scanf("%s%d%d%d",&name_input,&d,&m,&y);
        person newPerson = {name_input,y*10000+m*100+d};
        list[i] = newPerson;
    }

    sort(list, list+n, pCompare);

    printf("%s\n",list[0].name);
    printf("%s\n",list[n-1].name);
    return 0;
}