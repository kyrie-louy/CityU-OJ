#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;

int table[1024][1024];
int arr[1398105];
int sz[1398105];

// black: 1, white: 0, both: 2
void fullfill(int index, int start_row, int start_col, int end_row, int end_col) {
    if ((end_row - start_row) == 1){
        arr[index] = table[start_row][start_col];
    }
    else
    {
        fullfill((4 * index + 1), start_row, start_col, (start_row + end_row) / 2, (start_col + end_col) / 2);
        fullfill((4 * index + 2), start_row, (start_col + end_col) / 2, (start_row + end_row) / 2, end_col);
        fullfill((4 * index + 3), (start_row + end_row) / 2, start_col, end_row, (start_col + end_col) / 2);
        fullfill((4 * index + 4), (start_row + end_row) / 2, (start_col + end_col) / 2, end_row, end_col);
        
        if (arr[4*index+1] != 2 &&
            arr[4 * index + 1] == arr[4 * index + 2] &&
            arr[4 * index + 1] == arr[4 * index + 3] &&
            arr[4 * index + 1] == arr[4 * index + 4]){
            arr[index] = arr[4 * index + 1];
        }
        else{
            arr[index] = 2;
            sz[index]  = 1 + (sz[4*index+1]+sz[4*index+2]+sz[4*index+3]+sz[4*index+4]);
        }
    }
}

void reset(int index, int tr, int tc, int start_row, int start_col, int end_row, int end_col) {
    if ((end_row - start_row) == 1) {
        arr[index] ^= 1;
    }
    else
    {
        if (tr >= start_row && tr < (start_row + end_row) / 2 && tc >= start_col && tc < (start_col + end_col) / 2) {
            reset((4*index+1), tr, tc, start_row, start_col, (start_row + end_row) / 2, (start_col + end_col) / 2);
        }
        else if (tr >= start_row && tr < (start_row + end_row) / 2 && tc >= (start_col + end_col) / 2 && tc < end_col) {
            reset((4 * index + 2), tr, tc, start_row, (start_col + end_col) / 2, (start_row + end_row) / 2, end_col);
        }
        else if (tr >= (start_row + end_row) / 2 && tr < end_row && tc >= start_col && tc < (start_col + end_col) / 2) {
            reset((4 * index + 3), tr, tc, (start_row + end_row) / 2, start_col, end_row, (start_col + end_col) / 2);
        }
        else if (tr >= (start_row + end_row) / 2 && tr < end_row && tc >= (start_col + end_col) / 2 && tc < end_col) {
            reset((4 * index + 4), tr, tc, (start_row + end_row) / 2, (start_col + end_col) / 2, end_row, end_col);
        }
        
        if (arr[4*index+1] != 2 &&
            arr[4 * index + 1] == arr[4 * index + 2] &&
            arr[4 * index + 1] == arr[4 * index + 3] &&
            arr[4 * index + 1] == arr[4 * index + 4]){
            arr[index] = arr[4 * index + 1];
            sz[index] = 1;
        }
        else
        {
            arr[index] = 2;
            sz[index]  = 1 + (sz[4*index+1]+sz[4*index+2]+sz[4*index+3]+sz[4*index+4]);
        }
        
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        // initialization
        fill(sz, sz+1398105, 1);
        int k;
        scanf("%d", &k);
        int size = 1 << k;
        // input the table
        for (int i = 0; i < size; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < size; j++) {
                table[i][j] = ((int)str[j] - 48);
            }
        }
        
        fullfill(0, 0, 0, size, size);
        
        // read the change
        int m;
        scanf("%d", &m);
        while (m--) {
            int r, c;
            scanf("%d%d", &r, &c);
            r--;
            c--;
            
            reset(0, r, c, 0, 0, size, size);
   
            cout<<sz[0]<<endl;
        }
    }
    
    return 0;
}
