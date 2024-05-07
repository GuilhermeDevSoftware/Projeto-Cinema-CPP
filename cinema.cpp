#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using std::cout;
using std::endl;

void arquivo_filme(){
    ifstream arquivo;
    arquivo.open("filmes.txt");
    if(arquivo.is_open()){
        int qtd_filmes;
        arquivo >> qtd_filmes;
        arquivo.ignore();

        for(int i = 0; i < qtd_filmes; i++){
            string filme_acessado;
            getline(arquivo, filme_acessado);
            cout<< "Linha : "<< i << ", FILME: "<<filme_acessado<< "."<< endl;
        }
        arquivo.close();
    }
    else{
        cout<<"Arquivo de filmes nao encontrado. "<< endl;
        exit(0);
    }
}


int main(){
    cout<< "Iniciando projeto cinema! " <<endl;
    arquivo_filme();

}