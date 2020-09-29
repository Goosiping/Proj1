#include<iostream>
#include<ostream>
using namespace std;
/*class t1{
    public:
        int shape[2][3];
        t1(){shape={{1, 1, 1},{0, 1, 0}};
};*/
int main(){
    int col, row;
    //t1 a;
    int shape[2][3] = {{1, 1, 1},{0, 1, 0}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout<<shape[i][j]<<" ";
        }
        cout<<endl;
    }
}