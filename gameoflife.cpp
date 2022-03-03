#include<bits/stdc++.h>
using namespace std;

void printGeneration(vector<vector<int>> vect,int n, int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
          cout<<vect[i][j]<<" ";
    cout<<endl;
    }
    
    
}
bool isvalid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m)
      return true;
    return false;
    
}

int row[]={0,1,-1,0,1,1,-1,-1};
int col[]={1,0,0,-1,1,-1,1,-1};
vector<vector<int>> findNextGeneration(vector<vector<int>> vect, int n,int m)
{
     vector<vector<int>> output( n , vector<int> (m, 0));
     int i,j,k,aliveneighbour=0,x1,y1;
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
             aliveneighbour=0;
             for(k=0;k<8;k++)
             {
                 x1=row[k]+i;
                 y1=col[k]+j;
                     if(isvalid(x1,y1,n,m))
                       aliveneighbour+=vect[x1][y1];
             
             }
              // Cell is lonely and dies
                if ((vect[i][j] == 1) && (aliveneighbour < 2))
                    output[i][j] = 0;
 
                // Cell dies due to over population
                else if ((vect[i][j] == 1) && (aliveneighbour > 3))
                   output[i][j] = 0;
 
                // A new cell is born
                else if ((vect[i][j] == 0) && (aliveneighbour == 3))
                     output[i][j] = 1;
 
                // Remains the same
                else
                   output[i][j] = vect[i][j];
             
             
             
             
             
         }
         
     }
     return output;
    
    
    
    
    
}

int main()
{
    int n=10,m=10, input,i;
    //0 denotes deadcell
    // 1 denotes live cell
    vector<vector<int>> vect
   { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
        };
     // input is no of generation user want   
        input=2;
    for(i=0;i<input;i++)
    {
       cout<<i+1<<" Generation"<<endl;
       vect= findNextGeneration(vect,n,m);
       printGeneration(vect,n,m);
       cout<<endl;
        
    }
        
        
        
        
    
    

    
    return 0;
    
}
