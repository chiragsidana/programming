class Solution {
public:
    void dfs(int i,int j,int initialcolor,int newcolor,vector<vector<int>>&image){
        int n=image.size();
        int m=image[0].size();
        if(i<0 or j<0)return;
        if(i>=n or j>=m)return;
        if(image[i][j]!=initialcolor)return;
        image[i][j]=newcolor;
        dfs(i-1,j,initialcolor,newcolor,image);
        dfs(i+1,j,initialcolor,newcolor,image);
        dfs(i,j-1,initialcolor,newcolor,image);
        dfs(i,j+1,initialcolor,newcolor,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int initialcolor=image[sr][sc];
        if(initialcolor!=newcolor)dfs(sr,sc,initialcolor,newcolor,image);
        return image;
    }
};
