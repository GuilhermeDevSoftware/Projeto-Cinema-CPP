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
        arquivo.ignore(); 

        cout<< "FILMES EM CARTAZ: "<< endl;
        for(int i = 0; i < qtd_filmes; i++){
            string filme_acessado;
            getline(arquivo, filme_acessado);
            filmes.push_back(filme_acessado); 
            cout<<"  "<<filme_acessado<< endl;
        }
        
        arquivo.close();
    }
    else{
        cout<<"Arquivo de filmes nao encontrado. "<< endl;
        exit(0);
    }
}

void arquivo_cantina(vector<string>& comidas){
    ifstream arquivo;
    arquivo.open("cantina.txt");
    if(arquivo.is_open()){
        int qtd_comida;
        arquivo >> qtd_comida;
        arquivo.ignore();

        cout<< "CANTINA CINEMA GUI DEVSOFTWARE"<<endl;
        cout<<"-------Escolha sua opcao--------"<<endl;
        for(int i = 0; i < qtd_comida; i++){
            string comidas_disponiveis;
            getline(arquivo, comidas_disponiveis);
            comidas.push_back(comidas_disponiveis);
            cout<<"   "<<comidas_disponiveis<< endl;
        }

        arquivo.close();
    }
    else{
        cout<<"Cantina nao disponivel. "<< endl;
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

void escolher_comida(vector<string>& comidas){
    cout<< "Deseja selecionar a cantina (S) Sim -- (N) Nao"<<endl;
    char escolha;
    cin>> escolha;

    cout << endl;
    if(escolha == 'S' || escolha == 's'){
        arquivo_cantina(comidas);

        cout << "Digite o numero do produto desejado: " << endl;
        int produto;
        cin >> produto;
        if(produto >= 1 && produto <= comidas.size()){
            cout <<"Produto selecionado: " <<comidas[produto - 1] <<endl;
        }
        else
            cout<<"Produto nao encontrado."<<endl;
    }
    else   
        cout<< "Seguindo compra cinema." <<endl;


}

int main(){
    cout<< "Iniciando projeto cinema! " <<endl;
    vector<string> filmes;
    vector<string> comidas;
    arquivo_filme(filmes);

    cout<< endl;
    escolher_sessao(filmes);
    escolher_comida(comidas);

    return 0;
}