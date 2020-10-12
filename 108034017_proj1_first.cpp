#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

bool t1[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}};
bool t2[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}};
bool t3[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}};
bool t4[4][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}};

bool l1[4][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}};
bool l2[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {1, 0, 0, 0}};
bool l3[4][4] = {{0, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
bool l4[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 1, 0}};

bool j1[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
bool j2[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}};
bool j3[4][4] = {{0, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
bool j4[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 1, 0}};

bool s1[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}};
bool s2[4][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}};

bool z1[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}};
bool z2[4][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}};

bool i1[4][4] = {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
bool i2[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}};

bool o[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}};

void SetBlock(bool source[4][4], bool aim[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            aim[i][j] = source[i][j];
        }
    }
}

int main(){
    static bool **puzzle;
    int col = 0;
    int row = 0;
    
    //open file
    ifstream Infile;
    Infile.open("108034017_proj1.data", fstream::in);
    if(!Infile.is_open()) {
        cout<<"Error:Failed to open input file."<<endl;
        return 1;
    }
    
    //start loop
    char temp[4];
    int move;
    int pos;
    while(Infile>>temp && strcmp(temp, "End") != 0){
        //init map
        if(row == 0 && col == 0){
            row = 10 * (temp[0] - 48) + temp[1] - 48;
            Infile>>col;
            cout<<row<<" "<<col<<endl;
            puzzle = new bool *[row];
            for(int i = 0; i < row; i++){
                puzzle[i] = new bool [col];
            }
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    puzzle[i][j] = 0;
                }
            }

            //Test:print map
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    cout<<puzzle[i][j];
                }
                cout<<endl;
            }
        }
        
        //put the block
        else{
            //Test
            cout<<"b";
            Infile>>pos>>move;
            pos--;
            bool block[4][4];
            int rh = -1;
            bool legal = true;
            //judge the block
            if(strcmp(temp, "T1") == 0){
                SetBlock(t1, block);
            }
            else{
                SetBlock(o, block);
            }

            int height = 0;
            while(legal || height <= row){
                //continue to fall
                //Test
                cout<<"f";
                for(int i = 0; i < (height >= 4) ? 4 : height && legal; i++){
                    for(int j = 0; j < 4; j++){
                        if(block[3 - i][j] == 1 && puzzle[height + i][pos + j] == 1){
                            legal = false;
                            continue;
                        }
                    }
                }
                rh = height;
                height ++;
            }
            //put the block
            if(rh > 0){
                for(int a = 0; a < 4; a ++){
                    for(int b = 0; b < 4; b++){
                        if(block[a][b] == 1){
                            puzzle[rh + a][pos + b] = 1;
                        }
                    }
                }
            }
            else{
                cout<<"Error:Wrong Height"<<rh<<endl;
            }
        }
        //Test
        cout<<"e";
    }
    //Test
    cout<<endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<puzzle[i][j]<<" ";
        }
        cout<<endl;
    }
    //close the file
    Infile.close();
}

