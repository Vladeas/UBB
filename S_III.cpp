#include<iostream>
#include<fstream>

using namespace std;


struct mat{//structura care tine loc de matrice
	int l,c,v;//l-linia; c-coloana; v-valoarea
};


int mmf(int i1,int i2,int j1,int j2)
{
	return i2<i1 || (i1==i2 && j2<j1);//conditie pentru ordonare crescatoare dupa lini si coloane, a elementelor unei matrici
}


void inserare(mat x[],mat y,int &k)
{
	int i,j;
	for(i=0;i<k && mmf(y.l,x[i].l,y.c,x[i].c);i++);//gasesc pozitia pe care trebuie inserat elementul
	if(x[i].l==y.l && x[i].c==y.c);//verific sa nu citesc de doua ori pe acceasi pozitie
	else
	{
		for(j=k;j>i;j--)//mut toate elementele de la pozitia respectiva cu un pas la dreapta
			x[j]=x[j-1];
		x[i]=y;//inserarea propriu zisa
		k++;
	}
}


void citire(mat x[],int &k)//citesc linia, coloana si valoarea in structura data, inserand-o in ordine crescatoare in sir
{
	system("cls");
	k=0;
	mat y;//citesc mai intai in structura y
	cout<<"Linie : ";
	cin>>y.l;
	cout<<"Coloana : ";
	cin>>y.c;
	cout<<"Valoare : ";
	cin>>y.v;
	cout<<endl;
	while(y.l!=-1 && y.c!=-1 && y.v!=-1)//conditie de oprire
	{
		inserare(x,y,k);//apelez inserarea
		cout<<"Linie : ";//Trec la urmatorul element
		cin>>y.l;
		cout<<"Coloana : ";
		cin>>y.c;
		cout<<"Valoare : ";
		cin>>y.v;
		cout<<endl;
	}
}


void suma(mat C[],mat B[],mat A[],int &q,int m,int n)
{
	system("cls");
	q=0;//Numarul de elemente din structura C[] este initializat cu '0' la inceput
	int i,j;
	for(i=0,j=0;i<n && j<m;)//Parcurg ambele Structuri folosind un singur 'for' i<-0,n-1 pt A[] si j<-0,m-1 pt B[]
	{
		if(A[i].l==B[j].l && i<n && j<m)
		{
			if(A[i].c==B[j].c)//Daca elementele se afla pe aceeasi pozitie in matrice atunci C[] i-1 coloana si linia lui A[] sau B[] si valoarea A[].v + B[].v
			{
				if(A[i].v + B[j].v != 0)//Daca suma valorilor este '0' nu este introdusa pozitia in sirul C[]
				{
					C[q]=A[i];
					C[q++].v = A[i++].v + B[j++].v;
				}
				else//Se trece la urmatoarea pozitie
				{
					i++;
					j++;
				}
			}
			else//Se alege structua cu numarul coloanei mai mic
			{
				if(A[i].c<B[j].c)
					C[q++]=A[i++];
				else
					C[q++]=B[j++];
			}
		}
		else//Se alege structua cu numarul liniei mai mic
		{
			if(A[i].l<B[j].l && i<n)
				C[q++]=A[i++];
			else
				if(j<m)
					C[q++]=B[j++];
		}
	}
	//Daca mai ramane vreun elemet in una dintre structuri acesta este introdus acum
	if(i<n)
		while(i<n)
			C[q++]=A[i++];
	if(j<m)
		while(j<m)
			C[q++]=B[j++];
}


void afisare(mat x[],int k)//Se afiseaza structura data, precum si numarul de elemente din aceasta
{
	int i;
	cout<<k<<endl;
	for(i=0;i<k;i++)
		cout<<x[i].l<<" "<<x[i].c<<" "<<x[i].v<<endl;
	cout<<endl;
}


void tiparire(int nr_l,int nr_c,int q,mat C[])
{
	int i,j,k=0;
	for(i=1;i<=nr_l;i++)
	{
		for(j=1;j<=nr_c;j++)
		{
			if(i==C[k].l && j==C[k].c)//Daca pozitia linilor si coloanelor din matrice corespund ce cele din structura, respactiv C[].l si C[].c atunci afisam valoarea C[].v
				cout<<C[k++].v<<" ";
			else cout<<"0"<<" ";//Altfel afisam cifra '0'
		}
		cout<<endl;
	}
}


int main()
{
	system("COLOR 2");
	mat A[100],B[100],C[100];
	int n,m,q,nr_l,nr_c;//n, m si q sunt numarul de elemente din structurile A[], B[] si respectiv C[]
	cout<<"Numar lini : ";//Numarul de lini al matricei 
	cin>>nr_l;
	cout<<"Numar coloane : ";//Numarul de coloane al matricei
	cin>>nr_c;
	citire(A,n);//Apelez citire structura A
	citire(B,m);//Apelez citire structura B
	suma(C,B,A,q,m,n);//Construiesc structura C[] prin suma structurilor A[] si B[]
	afisare(A,n);
	afisare(B,m);
	afisare(C,q);
	tiparire(nr_l,nr_c,q,C);//Tiparesc structura sub forma unei matrica rare
	system("pause");
}
