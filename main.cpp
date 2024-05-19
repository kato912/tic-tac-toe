#include <iostream>

void choose(int x,int *row,int *col){ //เลือกว่าจะลงช่องไหน
    if(x >= 7){
        *row = x-7;
        *col = 2;
    }
    else if(x >= 4){
        *row = x-4;
        *col = 1;
    }
    else if(x >= 1){
        *row = x-1;
        *col = 0;
    }
}
void check(char x[3][3],char *winner){
    for (int i = 0; i<3; i++){
        if(x[i][0] == x[i][1] && x[i][1] == x[i][2]){
            *winner = x[i][0];
            return;
        }
    }
    for (int i = 0; i<3; i++){
        if(x[0][i] == x[1][i] && x[1][i] == x[2][i]){
            *winner = x[0][i];
            return;
        }
    }
    if(x[0][0] == x[1][1] && x[1][1] == x[2][2] || x[0][2] == x[1][1] && x[1][1]== x[2][0]){
            *winner = x[1][1];
            return;
    }
}

int main(){
    char bord[3][3] = {{'-','-','-'},
                        {'-','-','-'},
                        {'-','-','-'}};
    int n = 0;
    int p;
    
    char winname;
    while (p != 0)
    {
        int xn=0;
        for(int i=0; i<3; i++){
            for(int j =0; j<3; j++){
                std::cout << bord[j][i] << " ";
                if(bord[j][i] != '-'){
                    xn += 1;
                }
                if (xn == 9){
                    std::cout << "\nDraw";
                    break;
                }
            }
            std::cout <<"\n";
        }
        check(bord,&winname); //ตรวจคำตอบ
        if(winname != '-'){
            std::cout << "winner is : " << "player " << winname;
            break;
        }
        if(n == 0){
            std::cout << "player X: ";
            std::cin >> p;
            int row,col;
            choose(p,&row,&col);
            if(bord[row][col] == '-'){
                bord[row][col] = 'X';
                n++;
            }
            else{
                std::cout << "can't do that!\n";
            }
            continue;
        }
        else{
            std::cout << "player O: ";
            std::cin >> p;
            int row,col;
            choose(p,&row,&col);
            if(bord[row][col] == '-'){
                bord[row][col] = 'O';
                n--;
            }
            else{
                std::cout << "can't do that!\n";
            }
        }
        
    }
}