#include <stdio.h>
#include <conio.h>
#include <stdlib.h>//Necessário para as funções rand() e srand()
#include <time.h>//Necessário para função time()
#define MAX 5000//Usar RAND_MAX no lugar para ir até 32762

int trocabubblecre, compbubblecre, trocabubbledec, compbubbledec;
int trocaquickcre, compquickcre, trocaquickdec, compquickdec;
clock_t iniciobubblecre, fimbubblecre, iniciobubbledec, fimbubbledec, inicioquickcre, fimquickcre, inicioquickdec, fimquickdec;

// Função de Ordenação por Bolha Crescente
void bubble_sortcrescente(int *a){
     int i, j, tmp;     
     for(i = 0; i < MAX; i++){
           for(j = i+1; j < MAX; j++){       // sempre 1 elemento à frente 
                 compbubblecre++;              
                 if(a[j] < a[i]){           //se dir for menor q esq, troca                      
                         tmp = a[i];
                         a[i] = a[j];
                         a[j] = tmp;
                         trocabubblecre++;
                 }
           }
     }
}

// Função de Ordenação por Bolha Decrescente
void bubble_sortdecrescente(int *a){
     int i, j, tmp;
     for(i = 0; i < MAX; i++){
           for(j = i+1; j < MAX; j++){      // sempre 1 elemento à frente  
                 compbubbledec++;      
                 if(a[j] > a[i]){           //se dir for maior q esq                         
                         tmp = a[j];
                         a[j] = a[i];
                         a[i] = tmp;
                         trocabubbledec++;
                 }
           }
     }
}

//Função de Ordenação por Quick Sort Crescente
void quick_sortcrescente(int *a, int esq, int dir) {
    //inicioquickcre = clock();
    int i, j, x, y;
    i = esq;
    j = dir;
    x = a[(esq + dir) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < dir) {
            i++;
            compquickcre++;
        }
        while(a[j] > x && j > esq) {
            j--;
            compquickcre++;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
            trocaquickcre++;
        }
    }
     
    if(j > esq) {
        quick_sortcrescente(a, esq, j);
    }
    if(i < dir) {
        quick_sortcrescente(a, i, dir);
    }
    //fimquickcre = clock();
}

//Função de Ordenação por Quick Sort Decrescente
void quick_sortdecrescente(int *a, int esq, int dir) {
    //inicioquickdec = clock();
    int i,j,x,y;
    i = esq;
    j = dir;
    x = a[(esq+dir)/2];
    
    do{
       while(a[i] > x && i < dir){
            i++; 
            compquickdec++;
       }
       while(x > a[j] && j > esq){
            j--;
            compquickdec++;
       }
       if(i<=j){
          y = a[i];
          a[i] = a[j];
          a[j] = y;
          i++;
          j--;
          trocaquickdec++;
       }
    }while(i<=j);
          if(esq<j) quick_sortdecrescente(a, esq, j);
          if(i<dir) quick_sortdecrescente(a, i, dir);
          //fimquickdec = clock();
}

//Alimenta vetor
void setVet(int vet[]){
    int i; 
    srand(time(NULL));//Alimenta o vetor para que ele não apresente sempre os mesmos números
    for(i = 0; i < MAX; i++){
          vet[i] = rand()% 100;//Expressão para que seja criado números de 0 à 1000 
    }
}

//Imprime vetor
void printVet(int vet[]){
     int i;
     for(i = 0; i < MAX; i++){        
          printf("%d, ", vet[i]);
     }      
}

void voltarMenu(int resp){
     printf("\n\n\tDeseja voltar ao menu? (1 - sim / 2 - nao)");
               scanf("\t%d",&resp);
               
               if(resp == 1){
                       menu();                        
               }else if(resp == 2){
                     exit(0);
                     }else{
                           printf("\n\n\tEscolha uma opcao valida! \n\n");
                           printf("\tTecle enter para continuar! \n\n");
                           system("pause"); 
                           system("cls");                    
                           voltarMenu(resp);
                     }                             
}
    
int menu(){   
    int resp, opc = 0;    
    int i, vet[MAX];

    do{
    printf("\n\n --- APS TERCEIRO SEMESTRE - CIENCIA DA COMPUTACAO --- \n");
    printf(" --------------- ESTRUTURA DE DADOS ------------------ \n");
    printf(" -------------------- ORDENACAO ---------------------- \n\n");
    printf("\t1 - Bubble Sort\n");    
    printf("\t2 - Quick Sort\n");
    printf("\t3 - Sair\n");
    printf("\n\tQual tipo de ordenacao deseja executar? ");
    scanf ("\t%d", &opc);
    switch(opc){
                case 1:                  
                     printf("\n\n\t\t\tBUBBLE SORT");
                     printf("\n\n\t\t\tBUBBLE ORDEM CRESCENTE");                     
                     printf("\n\n\t\t\tVALORES DESORDENADOS\n\n");
                     setVet(vet);
                     printVet(vet);
                     iniciobubblecre = clock();
                     bubble_sortcrescente(vet);
                     fimbubblecre = clock();
                
                     printf("\n\n\t\t\tVALORES ORDENADOS\n\n");
                     printVet(vet);
                     
                     printf("\n\n\t\t\tBUBBLE ORDEM DECRESCENTE");                     
                     printf("\n\n\t\t\tVALORES DESORDENADOS\n\n");
                     setVet(vet);
                     printVet(vet);
                     iniciobubbledec = clock();
                     bubble_sortdecrescente(vet);
                     fimbubbledec = clock();

                     printf("\n\n\t\t\tVALORES ORDENADOS\n\n");
                     printVet(vet);   
                                      
                     printf("\n\n\tO vetor de %d posicoes foi ordenado pelo metodo Bubble Sort em ordem CRESCENTE %d ms", MAX, (fimbubblecre - iniciobubblecre));
                     printf("\n\n\tO vetor de %d posicoes foi ordenado pelo metodo Bubble Sort em ordem DECRESCENTE %d ms", MAX, (fimbubbledec - iniciobubbledec));
                     
                     printf("\n\n\tNumeros de MOVIMENTACOES em ordem CRESCENTE: %d\n", trocabubblecre);
                     printf("\n\tNumeros de COMPARACOES em ordem CRESCENTE: %d\n", compbubblecre);
                     printf("\n\tNumeros de MOVIMENTACOES em ordem DECRESCENTE: %d\n", trocabubbledec);
                     printf("\n\tNumeros de COMPARACOES em ordem DECRESCENTE: %d\n", compbubbledec);
                     voltarMenu(resp);
                     break;
                case 2:
                     printf("\n\n\t\t\tQUICK SORT");
                     printf("\n\n\t\t\tQUICK ORDEM CRESCENTE");                     
                     printf("\n\n\t\t\tVALORES DESORDENADOS\n\n");
                     setVet(vet);
                     printVet(vet);  
                     inicioquickcre = clock();                   
                     quick_sortcrescente(vet, 0, MAX - 1);   
                     fimquickcre = clock();                             
                     printf("\n\n\t\t\tVALORES ORDENADOS\n\n");
                     printVet(vet);
                     
                     printf("\n\n\t\t\tQUICK ORDEM DECRESCENTE");                     
                     printf("\n\n\t\t\tVALORES DESORDENADOS\n\n");
                     setVet(vet);
                     printVet(vet);   
                     inicioquickdec = clock();       
                     quick_sortdecrescente(vet, 0, MAX - 1);  
                     fimquickdec = clock();
                     printf("\n\n\t\t\tVALORES ORDENADOS\n\n");
                     printVet(vet);                      
                     
                     printf("\n\n\tO vetor de %d posicoes foi ordenado pelo metodo Quick Sort em ordem CRESCENTE %d ms", MAX, (fimquickcre - inicioquickcre));                     
                     printf("\n\n\tO vetor de %d posicoes foi ordenado pelo metodo Quick Sort em ordem DECRESCENTE %d ms", MAX, (fimquickdec - inicioquickdec));
                     
                     printf("\n\n\tNumeros de MOVIMENTACOES em ordem CRESCENTE: %d\n", trocaquickcre);
                     printf("\n\tNumeros de COMPARACOES em ordem CRESCENTE: %d\n", compquickcre);
                     printf("\n\tNumeros de MOVIMENTACOES em ordem DECRESCENTE: %d\n", trocaquickdec);
                     printf("\n\tNumeros de COMPARACOES em ordem DECRESCENTE: %d\n", compquickdec);
                     
                     voltarMenu(resp);
                     break;
                     
                case 3:
                     exit(0);                  
                default:
                        printf("\n\n\tEscolha uma opcao valida! \n\n");
                        printf("\tTecle enter para continuar! \n\n");
                        system("pause");
                        system("cls");
                        menu();             
                }    
    }while(resp == 1);    
    return opc;    
}

int main(){     
    menu();    
    getch();    
}
