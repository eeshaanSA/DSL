#include<iostream>
using namespace std;
 float a[20],b[20],c[20][20],wt[20][20];
    int r[20][20],n;
void const_obst(void){
    
    int i,j,k,l,min;
    for(i=0;i<n;i++){
        c[i][i]=0.0;
        r[i][i]=0;
        wt[i][i]=b[i];
    
    //i-j=1
    wt[i][i+1]=b[i]+b[i+1]+a[i+1];
    c[i][i+1]=b[i]+b[i+1]+a[i+1];
    r[i][i+1]=i+1;

    }
    
    c[n][n]=0.0;
    r[n][n]=0;
    wt[n][n]=b[n];
   
    //for i-j =2,3,4
    for(i=2;i<=n;i++){
        
        for(j=0;j<=n-i;j++){
            wt[j][j+i]=b[j+i]+a[j+i]+wt[j][j+i-1];
            c[j][j+i]=9999;
            
            for(l=j+1;l<=j+i;l++){
                if(c[j][j+i]>(c[j][l-1]+c[l][j+i])){
                    c[j][j+i]=c[j][l-1]+c[l][j+i];
                    r[j][j+i]=l;
                }
            }
            
            c[j][j+i]+=wt[j][j+i];
        }
        cout<<endl;
    }
    
    cout<<"-----------COST MATRIX---------------"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"---------------WEIGHT MATRIX--------------"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<wt[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"---------------RANK MATRIX----------------"<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<r[i][j]<<"\t";
        }
        cout<<endl;
    }
}


int main(){
   
    int i;
    cout<<"Enter no of nodes";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Entr the probability of successful search of "<<i;
        cin>>a[i];

            }
    for(int i=0;i<=n;i++){
            cout<<"Entr the probability of ubsuccessful search of "<<i;
        cin>>b[i];
    }
    const_obst();
    
    cout<<endl;
    return 0;
}