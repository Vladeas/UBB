#include<iostream> 
#include<fstream>

using namespace std; 

struct cifre{
	int y[10];
};

void aparitie_cifre(cifre a[],int n,int nr)
{
	while(nr!=0)
	{
		a[n].y[nr%10]=1;
		nr/=10;
	}
}


void citire(int &n,int x[],cifre a[])
{
	int i;
	ifstream f("text.txt");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>x[i];
		aparitie_cifre(a,i,x[i]);
	}
	f.close();
}


int ver_cif(int j,cifre a[],int k)
{
	int i;
	for(i=0;i<9;i++)
		if(a[j].y[i]==a[k].y[i] && a[j].y[i]==1)
			return 1;
	return 0;
}


void inserare(int &n,int x[],int j,int i)
{
	int k;
	n+=1;
	for(k=n;k>i;k--)
		x[k]=x[k-1];
	x[i]=j;
}


void adaugare(int &n,int x[],int i)
{
	int j;
	for(j=x[i]-1;j>1;j--)
		if(x[i]%j==0)
			inserare(n,x,j,++i);
}


void ver_perf(cifre a[],int &n,int x[])
{
	int i,j,ok;
	for(i=1;i<n;i++)
	{
		ok=1;
		for(j=i+1;j<=n && ok==1;j++)
			if(ver_cif(i,a,j)==0)
				ok=0;
		if(ok==1)
			adaugare(n,x,i);
	}
}


void afisare(int x[],int n)
{
	int i;
	for(i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<endl;
}


void inserare_poz(int n,int &m,int x[],int o[])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m && x[i]<o[j];j++);

	}
}


int main() 
{
	cifre a[200]={0};
	int n,x[30000],o[30000]={0},m=0; 
	citire(n,x,a);
	ver_perf(a,n,x);
	inserare_poz();
	afisare(x,n);
	system("pause"); 
} 
