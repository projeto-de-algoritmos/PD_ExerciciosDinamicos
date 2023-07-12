#include <cstdio>
#include <iostream>
using namespace std;
#define max(a, b) a > b ? a : b
 
struct Pedido{
    int peso;
    int quantidade;
};
 
struct Pedido array[21];
int matriz[21][31];
 
int main()
{
    int N, P;
 

    while(cin >> N && N){
        cin >> P;

        for(int i = 1; i <= N; i++)
           cin >> array[i].peso >> array[i].quantidade;
 
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= P; j++){
                if(i == 0 || j == 0)
                    matriz[i][j] = 0;
                else{
                    if(array[i].quantidade > j)
                        matriz[i][j] = matriz[i - 1][j];
                    else
                        matriz[i][j] = max(matriz[i - 1][j - array[i].quantidade] + array[i].peso, matriz[i - 1][j]);
                }
            }
        }
 
        printf("%d min.\n", matriz[N][P]);
    }
 
    return 0;
}
