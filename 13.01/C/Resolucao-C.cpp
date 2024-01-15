#include <iostream>

void op1(int n,int **lib){
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
            Max=-1;
            break;
        }
    }

    if(Max==-1) {
        std::cout << "Nao eh possivel saber!" << std::endl;
        return;
    }
    
    switch(f){
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

int main(){
    int N,Q,op;

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
        if(op==1) op1(N,lib);
        if(op==2) {
            int i,j,x;
            std::cin >> i >> j >> x;
            lib[i][j] = x;
        }
    }

    return 0;
}