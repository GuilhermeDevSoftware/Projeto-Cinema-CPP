#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
using std::cout;
using std::endl;

void arquivo_filme(vector<string>& filmes){
    ifstream arquivo;
    arquivo.open("filmes.txt");
    if(arquivo.is_open()){
        int qtd_filmes;
        arquivo >> qtd_filmes;
        arquivo.ignore(); // Ignorar a quebra de linha após a leitura do número de filmes

        cout<< "FILMES EM CARTAZ: "<< endl;
        for(int i = 0; i < qtd_filmes; i++){
            string filme_acessado;
            getline(arquivo, filme_acessado);
            filmes.push_back(filme_acessado); // Adiciona o filme ao vetor
            cout<<"  "<<filme_acessado<< endl;
        }
        
        arquivo.close();
    }
    else{
        cout<<"Arquivo de filmes nao encontrado. "<< endl;
        exit(0);
    }
}

void escolher_sessao(const vector<string>& filmes){
    cout<< "Digite o filme desejado: (NUMERO)" <<endl;
    int escolha;
    cin >> escolha;

    if(escolha >= 1 && escolha <= filmes.size()){
        cout <<"Filme selecionado: " << filmes[escolha - 1] << endl;
    }
    else{
        cout <<"Filme nao encontrado." << endl;
    }
}

int main(){
    cout<< "Iniciando projeto cinema! " <<endl;
    vector<string> filmes;
    arquivo_filme(filmes);

    cout<< endl;
    escolher_sessao(filmes);
    return 0;

}