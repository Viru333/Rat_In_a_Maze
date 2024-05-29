#include<bits/stdc++.h>

using namespace std;

void solve_maze(int r, int c, vector<vector<int>>& maze, vector<vector<int>>& path, int n){

    //Reached end of the maze
    if(r == n-1 && c == n-1){
        //Print the path
        path[n-1][n-1] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << path[i][j];
            }
            cout << endl;
        }
        return;
    }

    if(r>=n || r<0 || c>=n || c<0 || maze[r][c] == 0 || path[r][c] == 1){
        return;
    }

    path[r][c] = 1;

    solve_maze(r-1,c,maze,path,n); // Move up
    solve_maze(r,c+1,maze,path,n); // Move right
    solve_maze(r+1,c,maze,path,n); // Move down
    solve_maze(r,c-1,maze,path,n); // Move left
    
    path[r][c] = 0; // No solution found from this route therefore backtrack
}
int main(){

    vector<vector<int>> maze(10,vector<int>(10,0));
    //Take input from player for maze

    cout << "Enter the maze input, Type 0 for blocked path, 1 for valid path: \n Maze size --> 10 X 10\n";
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> maze[i][j];
        }
    }
    cout << "--------------------MAZE--------------------" << endl;
    cout << endl << "#########################################################" << endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "#########################################################" << endl;
    //2-D vector array for storing the path to end of the maze if it exist
    vector<vector<int>> path(10,vector<int>(10,0));

    solve_maze(0,0,maze,path,10);

    if(path[9][9] == 0) cout << "--------------------Maze cannot be solved.--------------------\n";

    cout << endl << "#########################################################" << endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "#########################################################" << endl;
}
