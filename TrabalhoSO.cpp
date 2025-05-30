#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //recursos totais
    int rec[10];
    int disp[10];
    int aloc[10];
    int nec[20][10];
    int u=5,i,j,P=20;
    int cont=0,cont1=0;
    cout << "Listando Dados:\n";
    cout << "-----------------------------------\n";
    //recursos totais
    for(i=0;i<u;i++)
        cin >> rec[i];
    //recursos disponiveis
    for(i=0;i<u;i++)
        disp[i]=rec[i];
    //recursos alocadoss
    for(i=0;i<u;i++){
        aloc[i]=rec[i]-disp[i];
    }
    //recursos necessarios
    for (i=0;i<P;i++){
        for(j=0;j<u;j++){
            cin >> nec[i][j];
        }
    }
    //Relatorio
    cout<< "Recursos Existentes:";
    for(j=0;j<u;j++)
        printf("[%2d]",rec[j]);
    cout << "\n";
    cout<< "Alocados:";
    for(j=0;j<u;j++)
        printf("[%2d]",aloc[j]);
    cout << "\n";
    cout<< "Processos a serem Executados:\n";
    for (i=0; i < P; i++){
        for(j=0;j<u;j++)
            printf("[%2d]",nec[i][j]);
        cout << "\n";
    }
    cout << "\n---------------------------------------\n";
    cout << "\nIniciando Execucao De Processos:\n";
    cout << "\n---------------------------------------\n";
    //condição valida
    for(i=0;i<P;i++){
        for(j=0;j<u;j++){
            if(nec[i][j] <= disp[j]){
                cont++;
            }
            if(nec[i][j] > disp[j]){
                cont1++;
            }
        }
        if(cont==u)
            printf("Processo %2d: Em Execucao\nRECURSOS ALOCADOS\n",i);
        for(j=0;j<u;j++){
            if(cont==u){
                printf("[%2d]",nec[i][j]);
                aloc[j]=nec[i][j];
            }   
        }
        if(cont1>0)
            printf("Processo %2d: Em Execucao\n",i);
        for(j=0;j<u;j++){
            if(cont1>0){
                printf("[%2d]",nec[i][j]);
            }
        }
        if(cont1>0){
            cout <<"\nPROCESSO ENTROU EM DEADLOOK";
            cout <<"\n---------------------------------------\n";
        }
        if(cont==u){
            cout <<"\nRECURSOS DESALOCADOS";
            cout <<"\nPROCESSO EXECUTADO E LIBERADO";
            cout <<"\n---------------------------------------\n";
            for(j=0;j<u;j++)
                aloc[j]=0;
        }
        cont1=0;
        cont=0;
    }
    cout << "LIBERANDO PROCESSOS EM DEADLOOK\n";
    for(i=0;i<P;i++){
        for(j=0;j<u;j++){
            if(nec[i][j] > disp[j]){
                cont1++;
            }
        }
        if(cont1>0){
            printf("Processo %2d",i);      
            cout <<"\n";
        }
        cont1=0;
    }
}