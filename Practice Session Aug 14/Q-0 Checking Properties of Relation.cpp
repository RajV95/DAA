#include <iostream>
using namespace std;
#include <vector>
void checkreflexive(vector<vector<int>> &v)
{
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        if (v[i][i] == 1)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "it is reflexive" << endl;
    else
        cout << "it is not";
}
void checksymmetric(vector<vector<int>> &v)
{
    bool flag = false;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(v[i][j]==v[j][i])
            {
                flag=true;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==false)
        break;
    }
    if(flag)
    cout<<"symmetric"<<endl;
    else
    cout<<"not symmetric"<<endl;
}
void checktransitive(vector<vector<int>> &v)
{
    bool flag=true;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(v[i][j])
            {
               
                for(int k=0;k<5;k++)
                {
                    if(v[j][k]==0)
                    {
                        continue;
                    }
                    else if(v[j][k]==1&&v[i][k]==1)
                    {
                        flag=true;
                        continue;
                    }
                    else
                    {
                        cout<<i<<" "<<j<<" "<<k<<endl;
                        flag=false;
                        break;
                    }
                }
            }
            if(flag==false)
            break;
        }
        if(flag==false)
         break;
    }
    if(flag)
    cout<<"it is transitive"<<endl;
    else
    cout<<"not transitive"<<endl;
}
int main()
{
    vector<vector<int>> v = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    
    return 0;
}

