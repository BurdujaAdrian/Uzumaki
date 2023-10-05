//all comments are scafolding for looking whats going on in the code,ignore it

#include <iostream>
using namespace std;

void spiral(int x, int y ,int ox, int oy, int tab[][100],int aray[],int c, int k)
{
    if(k<x*y)
            {
                tab[ox][oy]=aray[k];
                k++;
            }
    //cout<<"begining of right \n";
    if (ox==c && oy==c && ox<x-c-1)
    { ox++;
        for(int i = ox; i<x-c;i++)
        {   ox=i;
            if(k<x*y)
            {
                tab[ox][oy]=aray[k];
                k++;
            }
        }
    }
    //cout<<"begining of down \n";
    if (ox==x-c-1 && oy==c && oy<y-c-1 )
    {   oy++;
        for(int i = oy; i<y-c;i++)
        {   oy=i;
            if(k<x*y)
            {
                tab[ox][oy]=aray[k];
                k++;
            }
        }
    }
    //cout<<"begining of left \n";
    if (ox==x-c-1 && oy==y-c-1 && ox>c)
    {   ox--;
        for(int i = ox; i>=c;i--)
        {   ox=i;
            if(k<x*y)
            {
                tab[ox][oy]=aray[k];
                k++;
            }
        }
    }

    //cout<<"begining of up \n";
    if (ox==c && oy==y-c-1 && oy>c)
    { oy--;
        for(int i = oy; i>c; i--)
        {   oy=i;
            if(k<x*y)
            {
                tab[ox][oy]=aray[k];
                k++;
            }
        }
    }
    //cout<<"end of up \n \n";

    ox++; c++;
    //cout<<"final values:"<<ox<<oy<<" k="<<k<<" c="<<c;

    if(k<x*y){
        //cout<<"continue \n";
        spiral(x,y,oy,oy,tab,aray,c,k);}
}

void insertionSort(int arr[], int l)
{
  int key;
  int j = 0;
  for (int i = 1; i < l; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }

}

int main()
{ int x,y; string r;
cout<<"Insert the number of columns:"; cin>>x;
cout<<"Insert the number of rows:"; cin>>y;

int aray[100][100];
int linarray[10000];

cout<<"display matrix?"; cin>>r;
int k=0;
for(int l=0;l<y;l++)
{
    for(int w=0; w<x; w++)
    {
    k++;
    aray[w][l]=rand()%1000;
    linarray[k-1]=aray[w][l];
    if(r=="yes")
        {
        if (aray[w][l]>99)
        cout<<aray[w][l]<<" ";
    else
        if (aray[w][l]>9)
        cout<<aray[w][l]<<"  ";
    else cout<<aray[w][l]<<"   ";
        }

    }

if(r=="yes")
cout<<endl;

}
insertionSort(linarray, x*y);

for(int k=0;k<x*y; k++){
    //cout<<linarray[k]<<" ";
    }
//cout<<endl;
int c=0;

//clearing the origial array
for(int l=0;l<y;l++)
{
    for(int w=0; w<x; w++)
    {
    aray[w][l]=0;
    }
}


spiral(x,y,0,0,aray,linarray,0,c);

cout<<"display matrix?"; cin>>r;
k=0;
for(int l=0;l<y;l++)
{
    for(int w=0; w<x; w++)
    {
    k++;
    if(r=="yes")
        {
        if (aray[w][l]>99)
        cout<<aray[w][l]<<" ";
    else
        if (aray[w][l]>9)
        cout<<aray[w][l]<<"  ";
    else cout<<aray[w][l]<<"   ";
        }

    }

if(r=="yes")
cout<<endl;
}

return 0;
}

