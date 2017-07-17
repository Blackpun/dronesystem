#include<stdio.h>
int getbits(int num)
{
	int n;
	if(num<10)
		n=1;
	else if(num<100 && num>=10)
		n=2;
	else if(num<1000)
		n=3;
	else if(num<10000)
		n=4;
	else if(num<100000)
			n=5;
return(n);
}
void split(int a[],int num,int n)
{
	int i;
	for(i=0;i<n;i++)
    {
        a[i]=num%10;
        num/=10;

    }

}
void sort(int a[],int n)
{
	int i,j,max,maxdx,temp;
	for(i=0;i<n-1;i++)
	{ 
		max=a[i];
		maxdx = i;
		for(j=i+1;j<n;j++)
			if(a[j]>max)
			{
				max=a[j];
				maxdx=j;
			}
			if(max>a[i])
			{
				temp=a[i];
				a[i]=max;
				a[maxdx]=temp;
			}
	}
}
void reverse(int a[],int n)
{
	int i,j,t;
	for(i=0,j=n-1;i<j;i++,j--)
		{t=a[i];a[i]=a[j];a[j]=t;}
}
int combine(int a[],int n)
{
	int i,num=0;
	for(i=0;i<n;i++)
		num=num*10+a[i];
	return(num);

}
int main()
{
	int num,k,num1,num2,oldnumber = -1,a[10];
	printf("Please input an integer number with 3 or 4 digits:\n");
	scanf("%d",&num);
	k =getbits(num);
while(num!=oldnumber)
{
	oldnumber = num;
	split(a,num,k);
	sort(a,k);
	num1=combine(a,k);
	reverse(a,k);
	num2=combine(a,k);
	num = num1-num2;
	printf("%d - %d = %d\n",num,num1,num2 );

}
return 0;
}
