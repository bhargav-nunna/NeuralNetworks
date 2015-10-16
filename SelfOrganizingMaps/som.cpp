#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float cal_dist(float x1,float y1,float x2,float y2)
{
	float val=(x2-x1)*(x2-x1);
	val=val+(y2-y1)*(y2-y1);
	val=sqrt(val);

	return val;
}

float activation(float d,float sig)
{
	float val=exp(-(d*d)/2*(sig*sig));

	return val;

}

int main()
{
	int k=0;
	cout<<"Enter the grid value..\n";
	cin>>k;
	float wx[k][k], wy[k][k], d[k][k], act[k][k];
	float smalld,n=0.1;
	int smalli=0,smallj=0,run=0;
	float sig=0; //Change this

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout<<"Enter weight coordinate for "<<i<<" "<<j<<"\n";
			cin>>wx[i][j];
			cin>>wy[i][j];
		}
	}

while(run<=200)
{
	//Read file to get x and y inputs
	ifstream myfile(" ");
	if(myfile.is_open())
	{
		while(getline (myfile,line))
		{

       cout <<line<<'\n';
       
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			d[i][j]=cal_dist(wx[i][j],wy[i][j],x,y);
		}
	}

	smalld=d[0][0];

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(smalld > d[i][j])
			{
				smalld=d[i][j];
				smallj=j;
				smalli=i;
			}

		}
	}

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			act[i][j]=activation(d[i][j],sig);

		}
	}

	act[smalli][smallj]=1;

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			wx[i][j]=wx[i][j]+n*act[i][j]*(x-wx[i][j]);
			wy[i][j]=wy[i][j]+n*act[i][j]*(y-wy[i][j]);
		}
	}
//Write the new weights to an output file.
	}
}

	run++;
}




	return 0;
}