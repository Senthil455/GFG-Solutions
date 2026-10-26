
class DisjointSet{
    public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
        
    }


    int findUPar(int node){
        if(node==parent[node])return node;

      return  parent[node]=findUPar(parent[node]);
    }


    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v)return;

        if(size[ulp_u]>size[ulp_v]){
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }else{
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};
bool isValid(int nrow,int ncol,int n,int m){
    if(nrow<n && nrow>=0 && ncol>=0 && ncol<m)return true;
    return false;
}
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
      int n=grid.size();
      int m=grid[0].size();

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        DisjointSet dsu(n*m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;

                int node=i*m+j;

                for(int k=0;k<4;k++){
                    int nrow=i+dr[k];
                    int ncol=j+dc[k];

                    int adjNode=nrow*m+ncol;

                    if(isValid(nrow,ncol,n,m) &&dsu.findUPar(node)!=dsu.findUPar(adjNode) && grid[nrow][ncol]>0){
                        dsu.unionBySize(node,adjNode);
                    }
                }
            }
        }


    
      vector<long long>comp(n*m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  int node=i*m+j;
              int par=dsu.findUPar(node);
                comp[par]+=grid[i][j];
                
            }
        }


        int cnt=0;

        for(int i=0;i<n*m;i++){
            if(comp[i]>0 && comp[i]%k==0)cnt++;
        }
        return cnt;
        
    }
};