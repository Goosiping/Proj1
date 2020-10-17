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
bool l3[4][4] = {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};
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

int main(int argc, char* argv[]){
    static bool **puzzle;
    int col = 0;
    int row = 0;
    
    //open file
    ifstream Infile;
    Infile.open(argv[1], fstream::in);
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
            if(temp[1] >= 48 && temp[1] <= 58){
                row = 10 * (temp[0] - 48) + temp[1] - 48;
            }
            else{
                row = temp[0] - 48;
            }
            Infile>>col;
            //Test
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
            /*for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    cout<<puzzle[i][j];
                }
                cout<<endl;
            }*/
        }
        
        //put the block
        else{
            Infile>>pos>>move;
            pos--;
            bool block[4][4];
            int rh = -1;
            int rm = 0;
            bool legal = true;
            //judge the block
            //t
            if(strcmp(temp, "T1") == 0){
                SetBlock(t1, block);
            }
            else if(strcmp(temp, "T2") == 0){
                SetBlock(t2, block);
            }
            else if(strcmp(temp, "T3") == 0){
                SetBlock(t3, block);
            }
            else if(strcmp(temp, "T4") == 0){
                SetBlock(t4, block);
            }
            //l
            else if(strcmp(temp, "L1") == 0){
                SetBlock(l1, block);
            }
            else if(strcmp(temp, "L2") == 0){
                SetBlock(l2, block);
            }
            else if(strcmp(temp, "L3") == 0){
                SetBlock(l3, block);
            }
            else if(strcmp(temp, "L4") == 0){
                SetBlock(l4, block);
            }
            //j
            else if(strcmp(temp, "J1") == 0){
                SetBlock(j1, block);
            }
            else if(strcmp(temp, "J2") == 0){
                SetBlock(j2, block);
            }
            else if(strcmp(temp, "J3") == 0){
                SetBlock(j3, block);
            }
            else if(strcmp(temp, "J4") == 0){
                SetBlock(j4, block);
            }
            //s
            else if(strcmp(temp, "S1") == 0){
                SetBlock(s1, block);
            }
            else if(strcmp(temp, "S2") == 0){
                SetBlock(s2, block);
            }
            //z
            else if(strcmp(temp, "Z1") == 0){
                SetBlock(z1, block);
            }
            else if(strcmp(temp, "Z2") == 0){
                SetBlock(z2, block);
            }
            //o
            else if(strcmp(temp, "O") == 0){
                SetBlock(o, block);
            }
            else if(strcmp(temp, "I1") == 0){
                SetBlock(i1, block);
            }
            //i
            else if(strcmp(temp, "I2") == 0){
                SetBlock(i2, block);
            }
            else{
                cout << "Error:invalid block" << endl;
            }

            int height = 0;
            while(legal && height < row){
                //continue to fall
                for(int i = 0; i < ((height >= 4) ? 4 : height + 1) ; i++){
                    for(int j = 0; j < 4; j++){
                        if(block[3 - i][j] == 1 && puzzle[height - i][pos + j] == 1){
                            legal = false;
                        }
                    }
                }
                if(legal){
                    rh = height;
                    height ++; 
                }
            }
            //put the block
            if(rh > 0){
                if(move > 0){
                    for (int a = 1; a <= move; a++){
                        for (int i = 0; i < 4; i++){
                            for (int j = 0; j < 4; j++){
                                //prevent hitting the wall
                                if( !(block[3 - i][j] && puzzle[rh - i][pos + j + a])){
                                    rm = a;
                                }
                            }
                        }
                    }
                }
                else if(move < 0){
                    for (int a = -1; a >= move; a--){
                        for (int i = 0; i < 4; i++){
                            for (int j = 0; j < 4; j++){
                                if( !(block[3 - i][j] && puzzle[rh - i][pos + j + a])){
                                    rm = a;
                                }
                            }
                        }
                    }
                }
                else{
                    rm = 0;
                }
                //fall after move
                legal = true;
                pos += rm;
                while(legal && height < row){
                //continue to fall
                for (int i = 0; i < ((height >= 4) ? 4 : height + 1); i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (block[3 - i][j] == 1 && puzzle[height - i][pos + j] == 1)
                        {
                            legal = false;
                        }
                    }
                    }
                    if(legal){
                        rh = height;
                        height ++; 
                    }
                }
                //actually put the block
                for(int a = 0; a < 4; a ++){
                    for(int b = 0; b < 4; b++){
                        if(block[3 - a][b]){
                            puzzle[rh - a][pos + b] = 1;
                        }
                    }
                }
            }
            else{
                cout<<"Error:Wrong Height"<<rh<<endl;
            }
            //check line
            int line[row];
            int num_line = 0;
            for (int i = 0; i < row; i++)
                line[i] = -1;
            //record remove lines
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    if(!puzzle[i][j]){
                        break;
                    }
                    else if(j == col - 1 && puzzle[i][j]){
                        line[num_line++] = i;
                        //cout << i << endl;
                    }
                }
            }
            //blocks drop
            for (int a = 0; line[a] != -1; a++){
                for (int i = line[a]; i > 0; i--){
                    for (int j = 0; j < col; j++){
                        puzzle[i][j] = puzzle[i - 1][j];
                    }
                }
            }
        }
    }
    for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout<<puzzle[i][j]<<" ";
            }
            cout<<endl;
        }
    //output file
        fstream Outfile;
        Outfile.open("108034017_proj1.final", fstream::out);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                Outfile << puzzle[i][j] << " ";
            }
            Outfile << endl;
        }
            //close the file
            Infile.close();
            Outfile.close();
}