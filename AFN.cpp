#include <iostream>
#include<stack>
#include<vector>

using namespace std;
int w,i,p,*W1,f,*F,nrl,**contor,n,h=0;
std::vector <int> a;
std::vector <int> **s;
int verificare() //verifica daca se ajunge la o stare finala
{int ok=0;
    for(int k=0;k<f;k++)
        if(p==F[k]) ok=1;
 return ok;
}
void functie()
{
  while(i<w)
  {if(!s[p][W1[i]].empty() && contor[p][W1[i]]!=0)
     {
      p=s[p][W1[i]][contor[p][W1[i]]-1];
      for(int j=0;j<a.size();j++)
        if(a[i]==p && contor[p][W1[i]]<s[p][W1[i]].size())
          contor[p][W1[i]]++;
      a.push_back(p);
      cout<<p<<" ";
      i++;
      if(i==w) {
          if(verificare()) {
                cout<<"cuvant acceptat \n";
                cout<<"se ajunge la "<<p<<"\n";
                return;}

          else {
                 cout<<"nu am ajuns intr o stare finala in "<<a.back()<<" si ne intoarcem \n";
                 a.pop_back();
                 if(a.empty()){cout<<"neacceptat1\n";
                               return;}
                 p=a.back();
                 i--;
                 while(contor[p][W1[i]]<2)
                    {a.pop_back();
                     if(a.empty()){cout<<"neacceptat1\n";
                                   return;}
                     p=a.back();
                     i--;}
                 contor[p][W1[i]]--;
                 cout<<"continuam din"<< p<<"\n";
                        }
                    }



       }
   else {  cout<<"am ajuns intr-o fundatura in "<<a.back()<<"\n";
           while(contor[p][W1[i]]<2){
                a.pop_back();
                if(a.empty()){cout<<"neacceptat3\n";
                              return;}
                p=a.back();
                i--;}
           contor[p][W1[i]]--;
           cout<<"continuam din"<< p<<"\n";
                        }

     }
}
int main()
{   //stari totale

    cout<<"cate stari are automatul?\n"; cin>>n;
    int Q[n],i,q0;
    for(i=0;i<n;i++) Q[i]=i;



    //alfabet
    cout<<"cate litere are alfabetul?\n"; cin>>nrl;
    char A[nrl],c;
    for(i=0;i<nrl;i++)
        {cin>>c;
          A[i]=c;}

    //starea initiala
    cout<<"care este starea initiala?"; cin>>q0;

    //starile finale

    cout<<"cate stari finale are automatul?\n"; cin>>f;
    F=new int[f];
    cout<<"care sunt acestea?\n";
    for(i=0;i<f;i++)
    {
        cin>>F[i];
    }
   int z,y;
    //functia de tranzitie
   s=new vector<int> *[n];
   for(i=0;i<n;i++)
   s[i]=new vector <int> [nrl];
   cout<<"functia de tranzitie:\n";
   for(i=0;i<n;i++)
        for(int j=0;j<nrl;j++){
           cout<<Q[i]<<"->"<<A[j]<<"\n";
           cout<<"introduceti numarul de stari in care ajunge:\n";
           cin>>z;
           if(z!=0)
              cout<<"in ce stari ajunge?\n";
           for(int k=0;k<z;k++)
               {cin>>y;
                s[i][j].push_back(y);}
              }
       contor=new int * [n];
        for(i=0;i<n;i++)
            contor[i]=new int [nrl];
       for(i=0;i<n;i++)
        for(int j=0;j<nrl;j++)
            contor[i][j]=s[i][j].size();
    //cuvant
   cout<<"Cate litere are cuvantul pe care doriti sa il verificati?\n";
   cin>>w;
   char W[w];
   cout<<"introduceti cuvantul:\n";
   for(i=0;i<w;i++)
   cin>>W[i];
   //transformarea in cifre a cuvantului
   W1=new int[w];
   for(i=0;i<w;i++)
    for(int j=0;j<nrl;j++)
      if(W[i]==A[j]){
                      W1[i]=j;
                      break;
                      }   //W1 este cuvantul,el ia pozitiile literelor in alfabetul A

   i=0;
   p=q0;
   cout<<p<<" ";
   a.push_back(p);
   functie();
   return 0;
}
