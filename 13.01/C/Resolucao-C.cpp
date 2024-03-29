//matriz 100*100 = 0.202 segundos

#include <iostream>
#include <queue>
#include <chrono>

int op1(int n,int **lib){
    int friends[4] = {0,0,0,0};
    int Max=0,f;

    //cada amigo, na ordem "JOANA, PEDRO, ARTHUR, SABRINA", recebe o somatório 
    //da qualidade dos livros que os pertencem
    for(int line=0; line<n; line++){
        for(int col=0; col<n; col++){
            if(line<n/2){
                if(col<n/2) friends[0]+=lib[line][col];
                else friends[1]+=lib[line][col];
            }
            else{
                if(col<n/2) friends[2]+=lib[line][col];
                else friends[3]+=lib[line][col];
            }
        }
    }

    //decisão de qual é o amigo que possui os melhores livros
    for(int i = 0; i<4; i++){
        if(friends[i]>Max) {
            Max=friends[i];
            f=i;
        }
        else if(friends[i]==Max) {
            return -1;
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
    int **lib = new int*[N];

    for(int line = 0; line<N; line++){
        lib[line] = new int[N]; 
        for(int col = 0; col<N; col++){
            std::cin >> lib[line][col];
        }
    }

    std::cin >> Q;

    for(int k = 0; k<Q; k++){
        std::cin >> op;
        if(op==1) q.push(op1(N,lib));
        if(op==2) {
            std::cin >> i >> j >> x;
            lib[i-1][j-1] = x;
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
    printf("\ntempo de execução: %0.20f",((double)end-start)/CLOCKS_PER_SEC);

    return 0;
}