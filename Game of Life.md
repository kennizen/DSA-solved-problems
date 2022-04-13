According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.

intuition - in place by introducing new cells 2: newly alive, 3: newly dead

class Solution {
private:
    int nc(int m, int n, int i, int j, vector<vector<int>>& board){
        int count = 0;
        
        if(i-1 >= 0 && (board[i-1][j] == 1 || board[i-1][j] == 3)) count++;
        
        if((i-1 >= 0) && (j-1 >= 0) && (board[i-1][j-1] == 1 || board[i-1][j-1] == 3)) count++;
        
        if((i-1 >= 0) && (j+1 < n) && (board[i-1][j+1] == 1 || board[i-1][j+1] == 3)) count++;
        
        if(j-1 >= 0 && (board[i][j-1] == 1 || board[i][j-1] == 3)) count++;
        
        if(j+1 < n && (board[i][j+1] == 1 || board[i][j+1] == 3)) count++;
        
        if(i+1 < m && (board[i+1][j] == 1 || board[i+1][j] == 3)) count++;
        
        if((i+1 < m) && (j-1 >= 0) && (board[i+1][j-1] == 1 || board[i+1][j-1] == 3)) count++;
        
        if((i+1 < m) && (j+1 < n) && (board[i+1][j+1] == 1 || board[i+1][j+1] == 3)) count++;
        
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 0){
                    int nbc = nc(m,n,i,j,board);
                    if(nbc == 3) board[i][j] = 2;
                }
                else{
                    int nbc = nc(m,n,i,j,board);
                    if(nbc < 2 || nbc > 3) board[i][j] = 3;
                }
            }
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};