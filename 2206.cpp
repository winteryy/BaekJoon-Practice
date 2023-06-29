#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

class Node{
public:
    bool crashed;
    int x, y, dist;

    Node(int x, int y, int dist, bool crashed){
        this->x = x;
        this->y = y;
        this->dist = dist;
        this->crashed = crashed;
    }
};

struct vertex{
    int cDist, nDist;
};

bool isFault(int x, int y){
    if(0<=x && m>x && 0<=y && n>y){
        return false;
    }else{
        return true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    char t;
    vector<vector<vertex> > matrix(n, vector<vertex>(m));

    for(int i=0; i<n; i++){ //0: ±æ->INF, 1: º®->-1
        for(int j=0; j<m; j++){
            cin >> t;
            if(t-'0'){
                matrix[i][j].cDist = -1;
                matrix[i][j].nDist = -1;                
            }else{
                matrix[i][j].cDist = INF;
                matrix[i][j].nDist = INF;
            }
        }
    }

    queue<Node> q;
    q.push(Node(0, 0, 1, false));
    
    int minDist = INF;
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        if(matrix[node.y][node.x].nDist!=-1){
            if(node.crashed && matrix[node.y][node.x].cDist>node.dist){
                matrix[node.y][node.x].cDist = node.dist;
            }else if(!node.crashed && matrix[node.y][node.x].nDist>node.dist){
                matrix[node.y][node.x].nDist = node.dist;   
            }else{
                continue;
            }
        }


    
        if(node.y==n-1 && node.x==m-1){
            minDist = min(minDist, node.dist);
        }else{
            for(int i=0; i<4; i++){
                int newX = node.x+dx[i];
                int newY = node.y+dy[i];
                if(!isFault(newX, newY)){
                    if(matrix[newY][newX].nDist>=0){
                        q.push(Node(newX, newY, node.dist+1, node.crashed));
                    }else if(matrix[newY][newX].nDist==-1 && !node.crashed){
                        q.push(Node(newX, newY, node.dist+1, true));                    
                    }
                }
            }
        }
    }

    if(minDist == INF){
        cout << "-1";
    }else{
        cout << minDist;
    }

}