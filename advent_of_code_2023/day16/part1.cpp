#include<iostream>
#include<queue>

using namespace std;

struct pos{
    int x, y;
    char dir;
};

const int SIZE = 110;

string map[SIZE];
string direction[SIZE][SIZE];
int vis[SIZE][SIZE];

int main(){
    for(int i = 0; i < SIZE; i++){
        cin >> map[i];
    }

    queue<pos> q;
    q.push({0,0,'R'});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.x, y = p.y;
        char dir = p.dir;
        while(x >= 0 && x < SIZE && y >= 0 && y < SIZE){
            vis[x][y] = 1;
            if(direction[x][y].find(dir) != string::npos){
                break;
            }
            direction[x][y] += dir;
            if(map[x][y] == '-'){
                if(dir == 'L'){
                    y--;
                }
                else if(dir == 'D'){
                    q.push({x,y-1,'L'});
                    q.push({x,y+1,'R'});
                    break;
                }
                else if(dir == 'R'){
                    y++;
                }
                else if(dir == 'U'){
                    q.push({x,y-1,'L'});
                    q.push({x,y+1,'R'});
                    break;
                }
            }
            else if(map[x][y] == '|'){
                if(dir == 'L'){
                    q.push({x+1,y,'D'});
                    q.push({x-1,y,'U'});
                    break;
                }
                else if(dir == 'D'){
                    x++;
                }
                else if(dir == 'R'){
                    q.push({x+1,y,'D'});
                    q.push({x-1,y,'U'});
                    break;
                }
                else if(dir == 'U'){
                    x--;
                }
            }
            else if(map[x][y] == '\\'){
                if(dir == 'L'){
                    dir = 'U';
                    x--;
                }
                else if(dir == 'D'){
                    dir = 'R';
                    y++;
                }
                else if(dir == 'R'){
                    dir = 'D';
                    x++;
                }
                else if(dir == 'U'){
                    dir = 'L';
                    y--;
                }
            }
            else if(map[x][y] == '/'){
                if(dir == 'L'){
                    dir = 'D';
                    x++;
                }
                else if(dir == 'D'){
                    dir = 'L';
                    y--;
                }
                else if(dir == 'R'){
                    dir = 'U';
                    x--;
                }
                else if(dir == 'U'){
                    dir = 'R';
                    y++;
                }
            }
            else if(map[x][y] == '.'){
                if(dir == 'L'){
                    y--;
                }
                else if(dir == 'D'){
                    x++;
                }
                else if(dir == 'R'){
                    y++;
                }
                else if(dir == 'U'){
                    x--;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < SIZE; i++){
        for(int k = 0; k < SIZE; k++){
            res += vis[i][k];
        }
    }

    cout << res;

    return 0;
}