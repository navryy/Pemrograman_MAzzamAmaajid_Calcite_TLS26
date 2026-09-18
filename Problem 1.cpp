#include <iostream>
using namespace std;

int main()
{
    int N,K;

    cout<<"Input jumlah astronot (N) : ";
    cin>>N;
    cout<<"Input nilai awal K : ";
    cin>>K;

    if (N<=0 || K<=0)//untuk memastikan nilai N dan K benar
        {
            cout<<"Nilai N dan K harus lebih besar dari 0";
            return 0;
        }
    
    int ast[100];
    for (int i=0; i<N; i++)
    {
        ast[i] = i+1;
    }

   int posisi = 0;
   int astro = N;
    cout<<"\nUrutan astronot yang dieliminasi :\n";

while (astro>1)
{
    posisi = (posisi + K -1) % astro;
    //menentukan posisi astronot yang dieliminasi
    
    int elim = ast[posisi];

    cout<<elim<< "  ";

    if (elim % 2 == 0)
        {
            K = K+2;
        }
    else
        {
            K = K-1;

            if (K<2)
            {
                K=2;
            }    
        }
        

    for (int i = posisi; i < astro -1 ; i++)
        {
            ast[i] = ast[i+1];
        }
        astro--;

    if (posisi == astro)
    {
        posisi = 0;
    }
}
    cout<<"\n\nAstronot yang berhasil bertahan : "<<ast[0]<<endl;
    cout<<"Nilai K terakhir : "<<K<<endl;

    return 0;




    
}