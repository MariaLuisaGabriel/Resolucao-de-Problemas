//matriz 100*100 = 0.126 segundos

#include <iostream>
#include <queue>
#include <chrono>

int op1(int n,int *lib){
    int friends[4] = {0,0,0,0};
    int Max=0,f;
    int aux1 = n/2, aux2 = n*n/2;//economizar custo com aritmética

    //cada amigo, na ordem "JOANA, PEDRO, ARTHUR, SABRINA", recebe o somatório 
    //da qualidade dos livros que os pertencem
    for(int i = 0; i<aux2;){
        if(i<n/2){
            friends[0]+=lib[i];
            friends[1]+=lib[i+aux1];
            friends[2]+=lib[i+aux2];
            friends[3]+=lib[i+aux2+aux1];
            i++;
        }
        else i+=aux1;
    }

    //decisão de qual é o amigo que possui os melhores livros
    for(int i = 0; i<4; i++){
        if(friends[i]>Max) {
            Max=friends[i];
            f=i;
        }
        else if(friends[i]==Max) {
            f=-1;
        }
    }

    return f;
}

int main(){
    clock_t start,end;
    start = clock();
    int N,Q,op,f;
    int i=0,j=0,x;
    std::queue<int> q;

    //Recebendo os dados de entrada:
    std::cin >> N;
    if(N%2==1) return 0;

    int *lib = new int[N*N];

    if(N%4 == 0){
        for(int i = 0; i<N*N; i+=4){ 
            std::cin >> lib[i] >> lib[i+1] >> lib[i+2] >> lib[i+3];
        }
    }
    else{
        for(int i = 0; i<N*N; i+=2){ 
            std::cin >> lib[i] >> lib[i+1];
        }
    }

    std::cin >> Q;

    for(int k = 0; k<Q; k++){
        std::cin >> op;
        if(op==1) q.push(op1(N,lib));
        if(op==2) {
            std::cin >> i >> j >> x;
            lib[i*N+j] = x;
        }
    }

    while(!q.empty()){
        f = q.front();
        q.pop();
        switch(f){
        case -1:
            std::cout << "Nao eh possivel saber!" << std::endl;
            break;
        case 0:
            std::cout << "Joana" << std::endl;
            break;
        case 1:
            std::cout << "Pedro" << std::endl;
            break;
        case 2:
            std::cout << "Arthur" << std::endl;
            break;
        case 3:
            std::cout << "Sabrina" << std::endl;
            break;
        }
    }
    end = clock();
    printf("\ntempo de execução: %0.8f",((float)end-start)/CLOCKS_PER_SEC);
    return 0;
}