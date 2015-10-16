#include<iostream.h>
#include<math.h>
int main() {
c1x1[200],c1x2[200],c2x1[200],c2x2[200],c3x1[200],c3x2[200],c4
x1[200],c4x2[200];
    double c1x1[800]={Training X1 data here };
    double c1x2[800]={Training X2 data here };
    double tc1x1[800]={Testing X1 data here };
    double tc1x2[800]={Testing X2data here };
    double ii[2],wi[2],oi[2],bi[2];
    double eh1[50],eh2[50],eo[4];
    double n=0.1;
    int l1,l2;
    cout<<”Enter number of neurons in Layer 1: ";
    cin>>l1;
    cout<<"Enter number of neurons in Layer 2: ";
    cin>>l2;
    double h1w[l1][4],h1sum[l1],h1o[l1],h2w[l2][l1],h2sum[l2],h2o[l2],wo[4][l2],oo[4];
    double err_o[4],err_h1[l1],err_h2[l2];
    double d[4]={1,0,0,0};;
   double sum;
int itr=0;
int er_count=0;
int fl=0;
//Initial random weights
cout<<"Initializing weights..\n";
for (int i=0;i<2;i++)
{
oi[i]=1; }
for(int i=0;i<l1;i++)
{
   for(int j=0;j<4;j++)
   {
       h1w[i][j]=1;
￼} }
for(int i=0;i<l2;i++)
{
   for(int j=0;j<l1;j++)
   {
       h2w[i][j]=1;
   }
}
for(int i=0;i<4;i++)
￼ {
    for(int j=0;j<l2;j++)
    {
        wo[i][j]=1;
    }
 }
 for(int i=0;i<100;i++)
 {
         itr++;
          er_count=0;
// Input t neurons
 for(int i=0;i<200;i++)
 {
     if(fl==0)
     {
     ii[0]=c1x1[i];
     ii[1]=c1x2[i];
     fl=1;
     cout<<"Training...\n";
     }
    else if(fl==1)
    {
    ii[0]=tc1x1[i];
     ii[1]=tc1x2[i];
     fl=0;
￼ cout<<"Testing...\n";
}
 oi[0]=ii[0]*wi[0]+1;
 oi[1]=ii[1]*wi[1]+1;
 oi[0]=tanh(oi[0]);
 oi[1]=tanh(oi[1]);
 //Input layer to hidden layer 1
 for(int i=0;i<l1;i++)
{
sum=0;
   for(int j=0;j<2;j++)
   {
      sum=(oi[j]*h1w[i][j])+sum;
   }
￼  sum=sum+1;
  h1sum[i]=sum;
  h1o[i]=tanh(sum);
}
//Hidden layer 1 to hidden layer 2
for(int i=0;i<l2;i++)
{
//cout<<"hidden 1 to 2 I :"<<i<<"\n";
  sum=0;
  for(int j=0;j<l1;j++)
￼   {
      sum=(h1o[j]*h2w[i][j])+sum;
   }
   sum=sum+1;
   h2sum[i]=sum;
   h2o[i]=tanh(sum);
 }
 //Hidden layer 2 to output layer
 for(int i=0;i<4;i++)
 {
   sum=0;
   for(int j=0;j<l2;j++)
   {
      sum=(h2o[j]*wo[i][j])+sum;
   }
sum=sum+1;
   oo[i]=tanh(sum);
 }
 //Feedforward complete
 if(d[0]!=oo[0]&&d[1]!=oo[1]&&d[2]!=oo[2]&&d[3]!=oo[3])
 {
//   if(fl==0)
￼//
 // {
    er_count++;
   //}
//if(fl==1)
//{
   cout<<"Error corec..\n";
for(int i=0;i<4;i++) //output layer errors
{
   err_o[i]=oo[i]*(1-oo[i])*(d[i]-oo[i]);
}
for(int i=0;i<4;i++) //weight changes in output layer
{
￼  for(int j=0;j<l2;j++)
  {
    wo[i][j]= wo[i][j]+(n*err_o[i]*h2o[i]);
  }
}
for(int i=0;i<l2;i++) //hidden layer 2 errors
{
  sum=0;
  for(int j=0;j<4;j++)
  {
     sum=err_o[j]*wo[j][i]+sum;
￼          }
          err_h2[i]=h2o[i]*(1-h2o[i])*sum;
           //err_h2[i]=h20[i]*(1-
h2o[i])*((err_o[0]*wo[i][0])+(err_o[1]*wo[i][1])+(err_o[2]*wo[
i][2])+(err_o[3]*wo[i][3]));
}
        for(int i=0;i<l2;i++) //weight changes for layer 2
        {
           for(int j=0;j<l1;j++)
           {
              h2w[i][j]= h2w[i][j]+(n*err_h2[i]*h1o[i]);
           }
}
for(int i=0;i<l1;i++)
{
  sum=0;
  for(int j=0;j<l2;j++)
  {
//errors for hidden layer 1
    sum=err_h2[j]*h2w[j][1]+sum;
  }
  err_h1[i]=h1o[i]*(1-h1o[i])*sum;
}
￼        for(int i=0;i<l1;i++) //weight changes for hidden
layer 1
        {
           for(int j=0;j<2;j++)
           {
              h1w[i][j]= h1w[i][j]+(n*err_h1[i]*oi[j]);
           }
}
//} //if
}// if
    }// for 200
    cout<<"ITR: "<<itr<<"\n";
    cout<<"Errors: "<<er_count<<"\n";
}// for itr
    int dummy;
    cin>>dummy;
return 0; }