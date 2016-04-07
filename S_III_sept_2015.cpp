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
	}
}


void citire(int &n,int x[],cifre a[])
{
	int i;
	ifstream f("text.txt");
	f>>n;
	for(i=1;i<=n;i++)
		f>>x[i];
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


void adaugare(int &n)
{
	int i;

}


int ver_perf(cifre a[],int &n)
{
	int i,j,ok;
	for(i=1;i<n;i++)
	{
		ok=1;
		for(j=i+1;j<=n && ok==1;j++)
			if(!ver_cif(i,a,j))
				ok=0;
		if(ok==1)
			adaugare();
	}
}


int main() 
{
	cifre a[200]={0};
	int n;  
	cin>>n; 
	cout<<n/13;
	system("pause"); 
} 
