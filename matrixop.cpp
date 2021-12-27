#include<iostream>
#define max 3
using namespace std;
class matrix
{
    int mat[max][max];
public:
    void insert();
    void add(matrix,matrix);
    void sub(matrix,matrix);
    void mul (matrix,matrix);
    void trans(matrix);
};
void matrix::insert()
{
    cout<<"Enter the matrix elements row wise:"<<endl;
     for(int i=0;i<max;i++)
     {
         for(int j=0;j<max;j++)
         {
             cin>>mat[i][j];
         }
     }
}
void matrix::add(matrix m1,matrix m2)
{
    cout<<"************************************************************************"<<endl;
    cout<<"After insertion of matrix m1 and m2\n The resultant matrix is\n\n";
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        mat[i][j]=m1.mat[i][j]+m2.mat[i][j];
    }
    for(int i=0;i<max;i++)
    {
        cout<<"    "<<endl;
        for(int j=0;j<max;j++)
            cout<<" "<<mat[i][j]<<endl;
    }
    cout<<"**************************************************************************"<<endl;
}
/*void matrix::add(matrix m1,matrix m2)
{
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
            mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
    }
    for(int i=0;i<max;i++)
    {
        cout<<" ";
        for(int j=0;j<max;j++)
            cout<<" "<<mat[i][j];
        cout<<endl;
    }
    cout<<"\n---------------------------------"<<endl;
}*/
void matrix::sub(matrix m1,matrix m2)
{
    cout<<"***********************************"<<endl;
    cout<<"after subtraction of matrix m1 and matrix m2\n the resultant matrix is\n\n";
    for (int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
            mat[i][j]=m1.mat[i][j]-m2.mat[i][j];
        }
        for(int i=0;i<max;i++)
        {
            cout<<"   ";
            for(int j=0;j<max;j++)
                cout<<" "<<mat[i][j];
            cout<<endl;
        }
        cout<<"\n****************************************************"<<endl;
}
void matrix::mul(matrix m1,matrix m2)
{
    cout<<"**********************************************************"<<endl;
    cout<<"after multiplication of matrix m1 and matrix m2 \n the resultant matrix is \n\n";
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            mat[i][j]=0;
            for(int k=0;k<max;k++)
            {
                mat[i][j]+=m1.mat[i][k]*m2.mat[k][j];
            }
        }
       for(int i=0;i<max;i++)
       {
           cout<<"   "<<endl;
           for(int j=0;j<max;j++)
            cout<<"  "<<mat[i][j]<<endl;
       }
    }
}
void matrix ::trans(matrix m)
{
    cout<<"transpose of matrix is:"<<endl;
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
            mat[i][j]=m.mat[j][i];
    }
    for (int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            cout<<"   "<<endl;
            cout<<"   "<<mat[i][j]<<endl;
        }
    }
}
int main()
{
    matrix m1,m2,m3,m4;
    int n;
    char ch;
    do
    {
     cout<<"Enter \n1:Insertion\n2:Add\n3:Subtraction\n4:multiplication\n5:Transpose\n6:exit"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>n;
    switch(n)
    {
    case 1:
        m1.insert();
        break;
    case 2:
        cout<<"enter the second matrix"<<endl;
        m2.insert();
        m3.add(m1,m2);
        break;
    case 3:
        cout<<"enter the second matrix"<<endl;
        m2.insert();
        m3.sub(m1,m2);
        break;
    case 4:
        cout<<"enter the second matrix"<<endl;
        m2.insert();
        m3.mul(m1,m2);
        break;
    case 5:
        cout<<"Enter '1' or '2' to get transpose of ist or second matrix respectively"<<endl;
        int num;
        cin>>num;
        if(num==1)
            m3.trans(m1);
        else if(num==2)
            m3.trans(m2);
        else
            cout<<"matrix does not exist"<<endl;
            break;
    case 6:
        return 0;
    default:
        cout<<" invalid option!!!!"<<endl;
    }
    cout<<"Enter 'y' to exit or 'N' to start again"<<endl;
    cin>>ch;
    }while(ch!='y');
}
