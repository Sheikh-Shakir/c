#include<iostream>
using namespace std;
#define max1 10
#define max2 10
class matrix
{
	private:
	int row,col,count;
	int mat[max1][max2];
	public:
	void read();
	void add(matrix,matrix);
	void sub(matrix,matrix);
	void display();
	void mul(matrix,matrix);
	void sparse();

};
void matrix::read()
{
	count=0;
	cout<<"enter the size of matrix :\n";
	cin>>row ;
	cin>>col;

	cout<<"enter the elements of matrix:\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		 {
			cin>>mat[i][j];
			if(mat[i][j]==0)
				count++;
		 }
	 }
	 sparse();
}
void matrix::sparse()
{
	if(((row*col)-count)<count)
		cout<<"Matrix is sparse"<<endl;
	else
		cout<<"Matrix is not sparse"<<endl;	
}

void matrix::add(matrix one,matrix two)
{
	if(one.row==two.row&&one.col==two.col)
	{
		row=one.row;
		col=one.col;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				mat[i][j]=one.mat[i][j]+two.mat[i][j];
			}
		}
		cout<<"Result matrix"<<endl;
		display();
	}
	else
	{
		cout<<"addition not possible\n";
	}
}
void matrix::sub(matrix one,matrix two)
{
	if(one.row==two.row&&one.col==two.col)
	{
		row=one.row;
		col=one.col;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				mat[i][j]=one.mat[i][j]-two.mat[i][j];
			}
		}
		cout<<"Result matrix"<<endl;
		display();
	}
	else
	{
		cout<<"subtraction not possible\n";
	}
}
void matrix::mul(matrix one,matrix two)
{	
	if(one.col==two.row)
	{
		row=one.row;
		col=two.col;
		for (int i=0;i<row;i++)
			for(int j=0;j<col;j++)
			   mat[i][j]=0;
		
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					for(int k=0;k<two.row;k++)
						mat[i][j]=one.mat[i][k]*two.mat[k][j]+mat[i][j];
		
		cout<<"Result matrix"<<endl;
		display();	
	}	
	else
	{
		cout<<"multiplication not posssible"<<endl;
	}
	
	
}
void matrix::display()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		 {
			cout<<mat[i][j];
			cout<<"\t";

		 }
		 cout<<"\n";
	}
}
int main()
{

	int ch;
	matrix mat_res;
    while(1)
    {

		cout<<"press 1 to read matrix 1\n";
		cout<<"press 2 to read matrix 2\n";
		cout<<"press 3 to add\n";
		cout<<"press 4 to subtract\n";
		cout<<"press 5 to multiply\n";
		cout<<"press 6 to exit\n";
		cout<<"enter ur choice"<<endl;
		cin>>ch;

		  switch(ch)
		  {
		
			case 1:
				matrix mat_one;
				mat_one.read();
			break;
		
			case 2:
				matrix mat_two;
				mat_two.read();
			break;
		
			case 3:
				mat_res.add(mat_one,mat_two);
				cout<<"First matrix"<<endl;
				mat_one.display();
				cout<<"Second matrix"<<endl;
				mat_two.display();
			break;
		
			case 4:
				mat_res.sub(mat_one,mat_two);
				cout<<"First matrix"<<endl;
				mat_one.display();
				cout<<"Second matrix"<<endl;
				mat_two.display();
			break;
			
			case 5:
				mat_res.mul(mat_one,mat_two);
				cout<<"First matrix"<<endl;
				mat_one.display();
				cout<<"Second matrix"<<endl;
				mat_two.display();
			break;
			
			case 6:
			exit(0);
			break;
		
			default:
			cout<<"wrong input";
		    }
 	}
return 0;
}
