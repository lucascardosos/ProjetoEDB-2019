#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

int *criarVetor(int tamanho){
	return new int[tamanho];
}
void inserirFimVetor(int *ls, int N, int *Q, int el){
	if(ls==NULL || *Q==N) return;
	ls[*Q] = el;
	*Q = *Q + 1;
}
void inserirMeioVetor(int *ls, int N, int *Q, int el, int pos){
	if(ls==NULL || *Q==N || pos >= *Q) return;
	for(int ii=*Q;ii>pos;ii--) ls[ii] = ls[ii-1];
	ls[pos] = el;
	*Q = *Q + 1;
}
void inserirInicioVetor(int *ls, int N, int *Q, int el){
	if(ls==NULL || *Q==N) return;
	for(int ii=*Q; ii>0; ii--){
       ls[ii] = ls[ii-1];
	}
	ls[0] = el;
	*Q = *Q + 1;
}
int acessarMeioVetor(int* lista, int tamanho, int pos){
	if(pos >= tamanho || pos > 0) return -1;
	return lista[pos];
}

int acessarInicioVetor(int* lista, int tamanho){
	if(tamanho == 0) return -1;
	return lista[0];
}
int acessarFimVetor(int* lista, int tamanho){
	if(tamanho == 0) return -1;
	return lista[tamanho-1];
}
void destruirVetor(int** lista){
	if(*lista != NULL) delete[] *lista;
	*lista == NULL;
}
void removerMeioVetor(int *ls, int *Q, int pos){
	if(ls==NULL || *Q==0 || pos > *Q) return;
	for(int ii=pos;ii<(*Q-1);ii++) ls[ii] = ls[ii+1];
	*Q = *Q - 1;
}
void removerInicioVetor(int *ls, int *Q){
	if(ls==NULL || *Q==0) return;
	for(int ii=0;ii<(*Q-1);ii++) ls[ii] = ls[ii+1];
	*Q = *Q - 1;
}
void removerFimVetor(int *ls, int *Q){
	if(ls==NULL || *Q==0) return;
	*Q = *Q - 1;
}
void imprimirVetor(int *ls, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		cout<< ls[i] << " ";
	}
	cout<<endl;
	cout<<endl;
}
struct node{
    int dado;
    node *prox;
};
int acessoInicioLista(struct node *ls){
    if(ls == NULL) return -1;
    return ls->dado;
}
int acessoMeioLista(struct node *ls, int pos){
    if(ls == NULL) return -1;
    struct node *iter = ls;
    for (int ii=0; ii<pos;ii++){
        iter = iter->prox;
        if(iter == NULL) return -1;
    }
    return iter->dado;
}
int acessoFimLista(struct node *ls){
    if(ls == NULL) return -1;
    struct node *iter = ls;
    while(iter->prox != NULL) iter = iter->prox;
    return iter->dado;
}
void inserirInicioLista(struct node **ls, int el, int *Q){
    struct node *tmp = *ls;
    *ls = new struct node;
    (*ls) ->prox = tmp;
    (*ls) ->dado = el;
    *Q = *Q + 1;
}
void inserirMeioLista(struct node **ls, int el, int pos, int *Q){
    if(pos == 0) inserirInicioLista(ls, el, Q);
    else{
        struct node *tmp = *ls;
        for(int ii= 0; ii<pos-1 && tmp->prox!=NULL; ii++) tmp = tmp->prox;
        struct node *tmp2 = tmp->prox;
        tmp->prox= new struct node;
        tmp->prox->prox= tmp2;
        tmp->prox->dado = el;
    }
    *Q = *Q + 1;
}
void inserirFimLista(node **ls, int el, int *Q){
    if(*ls==NULL) inserirInicioLista(ls, el, Q);
    else{ struct node *tmp = *ls;
    while(tmp->prox!=NULL) tmp = tmp->prox;
    tmp->prox= new struct node;
    tmp->prox->prox= NULL;
    tmp->prox->dado = el;
    }
    *Q = *Q + 1;
}
void removerInicioLista(struct node **ls, int *Q){
    if(*ls != NULL){
        struct node *tmp = *ls;
        (*ls) = (*ls)->prox;
        delete tmp;
        *Q = *Q - 1;
    }

}
void removerMeioLista(struct node **ls, int pos, int *Q){
    if (*ls == NULL) return;
    struct node* tmp = *ls;
    if (pos == 0)
    {
        removerInicioLista(ls, Q);               // free old head
        return;
    }
    for (int i=0; tmp!=NULL && i<pos-1; i++) tmp = tmp->prox;
    if (tmp == NULL || tmp->prox == NULL) return;
    struct node *prox = tmp->prox->prox;
    delete(tmp->prox);
    tmp->prox = prox;
    *Q = *Q - 1;
}
node* removerFimLista(struct node *ls, int *Q){
    if (ls == NULL)
        return NULL;

    if (ls->prox == NULL) {
        delete ls;
        return NULL;
    }

    // Find the second last node
    node* penultimo = ls;
    while (penultimo->prox->prox != NULL)
        penultimo = penultimo->prox;

    // Delete last node
    delete (penultimo->prox);
    penultimo->prox = NULL;
    *Q = *Q - 1;
    return ls;
}
void destruirLista(struct node **ls){
	if(*ls != NULL) delete[] *ls;
	*ls == NULL;
}
void imprimirLista(struct node* ls)
{
    struct node* tmp = ls;
    while (tmp) {
        cout << tmp->dado << " -> ";
        tmp = tmp->prox;
    }

    cout << "NULL"<<endl;
}
void insertionSort(int *ls, int N){
	// são realizadas N ciclos de seleção/inserção
	for(int ii=0; ii<N; ii++){
		// seleciona elemento dentre os não ordenados
		int elemento = ls[ii];
		// insere elemento na lista dos ordenados
		int pInsercao = ii;
		while(pInsercao > 0 && ls[pInsercao-1]>elemento){
			ls[pInsercao] = ls[pInsercao-1];
			pInsercao--;
			cout<<"Intermediario "<<ii<<": ";
			imprimirVetor(ls, N);
		}
		ls[pInsercao] = elemento;
	}
}
void selectionSort(int *ls, int N){
	// são realizadas N ciclos de seleção/inserção
	for(int ii=0; ii<N; ii++){
		// seleciona elemento dentre os não ordenados
		int insertPos = ii;
		for(int jj=ii+1; jj<N; jj++){
            if(ls[jj]<ls[insertPos]){
                insertPos = jj;
            }
		}
	// insere elemento na lista dos ordenados
	cout<<"Intermediario "<<ii<<": ";
	cout<<"Eleito: "<<ls[ii]<<endl;
	imprimirVetor(ls, N);
	int tmp = ls[ii];
	ls[ii] = ls[insertPos];
	ls[insertPos] = tmp;
	}
}
void troca(int *ls, int i, int j){
    int aux;
    aux = ls[i];
    ls[i] = ls[j];
    ls[j] = aux;
}
int particao(int *ls, int p, int r){
    int pivo, i, j, x;
    x=1;
    pivo = ls[(p+r)/2];
    i = p-1;
    j = r+1;
    while(i < j){
        do{
            j = j -1;
            cout<<"Intermediario: "<<endl;
            cout<<"Pivo: "<<pivo<<endl;
            imprimirVetor(ls, r+1);
            x++;
        }
        while(ls[j] > pivo);
        do{
            i = i + 1;
            cout<<"Intermediario: "<<endl;
            cout<<"Pivo: "<<pivo<<endl;
            imprimirVetor(ls, r+1);
            x++;
        }
        while(ls[i] < pivo);
        if(i < j) troca(ls, i, j);
    }
    return j;
}
void quickSort(int *ls, int p, int r){
	int q;
	if(p < r){
        q = particao(ls, p, r);
        quickSort(ls, p, q);
        quickSort(ls, q+1, r);
	}
}
void intercala(int *ls, int inicio, int fim, int meio){
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	int aux[fim];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	poslivre = inicio;
	while(inicio_vetor1 <= meio && inicio_vetor2 <= fim){
        if(ls[inicio_vetor1] <= ls[inicio_vetor2]){
            aux[poslivre] = ls[inicio_vetor1];
            inicio_vetor1 = inicio_vetor1 + 1;
        }
        else{
            aux[poslivre] = ls[inicio_vetor2];
            inicio_vetor2 = inicio_vetor2 + 1;
        }
        poslivre = poslivre + 1;
	}
	//se ainda existem numeros no primeiro vetor
	//que não foram intercalados
	for(i = inicio_vetor1; i<= meio; i++){
        aux[poslivre] = ls[i];
        poslivre = poslivre + 1;
	}
	//se ainda existem numeros no primeiro vetor
	//que não foram intercalados
	for(i = inicio_vetor2; i <= fim; i++){
        aux[poslivre] = ls[i];
        poslivre = poslivre + 1;
	}
	//retorna os valores do vetor aux para o vetor ls
	for(i = inicio; i <= fim; i++){
        ls[i] = aux[i];
	}
}
void mergeSort(int *ls, int inicio, int fim){
	int meio;
	cout<<"Intermediario: "<<endl;
	imprimirVetor(ls, fim+1);
	if(inicio < fim){
		meio = (inicio + fim)/2;
		mergeSort(ls, inicio, meio);
		mergeSort(ls, meio+1, fim);
		intercala(ls, inicio, fim, meio);
	}
}
bool buscaSequencialVetor(int *ls, int elemento, int tamanho){
    int i=0;
    while(i < tamanho){
        cout<<"Comparando "<<ls[i]<<" com "<<elemento<<endl;
        if(ls[i] == elemento){
            return true;
        }
        else if(i == tamanho-1){
            return false;
        }
        i++;
    }
}
bool buscaBinariaVetor(int *ls, int elemento, int tamanho){
    int inicio = 0;
    int fim = tamanho-1;
    while(fim >= inicio){
        int indice = (inicio + fim)/2;
        int valorMemoria = ls[indice];
        cout<<"Comparando "<<valorMemoria<<" com "<<elemento<<endl;
        if (valorMemoria==elemento) return true;
        else if (valorMemoria>elemento){
            fim = indice-1;
        }
        else if(valorMemoria<elemento){
            inicio = indice+1;
        }
    }
    return false;
}
bool buscaSequencialLista(struct node *ls, int elemento){
    struct node* tmp = ls;
    while(tmp){
        cout<<"Comparando "<<tmp->dado<<" com "<<elemento<<endl;
        if(tmp->dado == elemento){
            return true;
        }
        else if(tmp->prox == NULL){
            return false;
        }
        tmp = tmp->prox;
    }
}
int main(){
	int elemento;
	int tamanho;
	int escolha1;
	int escolha2;
	int qntd;
	qntd = 0;
	int pos;
	int resultado;
	int i;
	escolha1=1;

    while(escolha1!=0){
        cout<<"Por favor, informe se será uma lista ligada ou vetor:"<<endl;
        cout<<"1 - Vetor"<<endl;
        cout<<"2 - Lista Ligada"<<endl;
        cout<<"0 - Sair"<<endl;
        cin>>escolha1;
        escolha2 = 1;

        switch(escolha1){
            case 1:
				cout<<"Insira o tamanho do vetor: ";
                cin>>tamanho;
                int *vetor;
				vetor = criarVetor(tamanho);

                while(escolha2!=0){
                    cout<<"Por favor, informe a opção desejada: "<<endl;
                    cout<<"1  - Inserir no inicio"<<endl;
                    cout<<"2  - Inserir no meio"<<endl;
                    cout<<"3  - Inserir no fim"<<endl;
                    cout<<"4  - Acessar no inicio"<<endl;
                    cout<<"5  - Acessar no meio"<<endl;
                    cout<<"6  - Acessar no fim"<<endl;
                    cout<<"7  - Remover no inicio"<<endl;
                    cout<<"8  - Remover no meio"<<endl;
                    cout<<"9  - Remover no fim"<<endl;
                    cout<<"10 - Ordenar por Inserção"<<endl;
                    cout<<"11 - Ordenar por Seleção"<<endl;
                    cout<<"12 - Ordenar por Quick"<<endl;
                    cout<<"13 - Ordenar por Merge"<<endl;
                    cout<<"14 - Realizar uma busca sequencial"<<endl;
                    cout<<"15 - Realizar uma busca binaria"<<endl;
                    cout<<"16 - Exibir vetor"<<endl;
                    cout<<"0  - Sair"<<endl;
                    cin>>escolha2;

                    switch(escolha2){
                        case 1:
                            cout<<"Digite o elemento a ser inserido: ";
                            cin>>elemento;
                            inserirInicioVetor(vetor, tamanho, &qntd, elemento);
                            imprimirVetor(vetor, qntd);
                            break;
                        case 2:
                            cout<<"Digite o elemento a ser inserido: ";
                            cin>>elemento;
                            cout<<"Informe a posição a ser inserida: ";
                            cin>>pos;
                            inserirMeioVetor(vetor, tamanho, &qntd, elemento, pos);
                            imprimirVetor(vetor, qntd);
                            break;
                        case 3:
                            cout<<"Digite o elemento a ser inserido: ";
                            cin>>elemento;
                            inserirFimVetor(vetor, tamanho, &qntd, elemento);
                            imprimirVetor(vetor, qntd);
                            break;
                        case 4:
                            resultado = acessarInicioVetor(vetor, tamanho);
                            cout<<resultado<<endl;
                            break;
                        case 5:
                            cout<<"Informe a posição a ser acessada: ";
                            cin>>pos;
                            resultado = acessarMeioVetor(vetor, tamanho, pos);
                            cout<<resultado<<endl;
                            break;
                        case 6:
                            resultado = acessarFimVetor(vetor, tamanho);
                            cout<<resultado<<endl;
                            break;
                        case 7:
                            removerInicioVetor(vetor, &qntd);
                            imprimirVetor(vetor, qntd);
                            break;
                        case 8:
                            cout<<"Informe a posição do elemento a ser removido: ";
                            cin>>pos;
                            removerMeioVetor(vetor, &qntd, pos);
                            imprimirVetor(vetor, qntd);
                            break;
                        case 9:
                            removerFimVetor(vetor, &qntd);
                            imprimirVetor(vetor, qntd);
                            break;
                        case 10:
                            insertionSort(vetor, qntd);
                            cout<<"Vetor ordenado:"<<endl;
                            imprimirVetor(vetor, qntd);
                            break;
                        case 11:
                            selectionSort(vetor, qntd);
                            cout<<"Vetor ordenado:"<<endl;
                            imprimirVetor(vetor, qntd);
                            break;
                        case 12:
                            quickSort(vetor,0, qntd-1);
                            cout<<"Vetor ordenado:"<<endl;
                            imprimirVetor(vetor, qntd);
                            break;
                        case 13:
                            mergeSort(vetor, 0, qntd-1);
                            cout<<"Vetor ordenado:"<<endl;
                            imprimirVetor(vetor, qntd);
                            break;

                        case 14:
                            cout<<"Insira qual o elemento a ser procurado: ";
                            cin>>elemento;
                            if(buscaSequencialVetor(vetor, elemento, qntd)==true){
                                cout<<"Elemento encontrado!"<<endl;
                            }
                            else cout<<"Elemento não encontrado!"<<endl;
                            break;
                        case 15:
                            cout<<"Insira qual o elemento a ser procurado: ";
                            cin>>elemento;
                            insertionSort(vetor, qntd);
                            if(buscaBinariaVetor(vetor, elemento, qntd)==true){
                                cout<<"Elemento encontrado!"<<endl;
                            }
                            else cout<<"Elemento não encontrado!"<<endl;
                            break;
                        case 16:
                            imprimirVetor(vetor, qntd);
                            break;
                        case 0:
                            qntd = 0;
                            destruirVetor(&vetor);
                            break;
                    }
                }
                    break;
                    case 2:
                        node *ls = NULL;
                        while(escolha2!=0){
                            cout<<"Por favor, informe a opção desejada: "<<endl;
                            cout<<"1  - Inserir no inicio"<<endl;
                            cout<<"2  - Inserir no meio"<<endl;
                            cout<<"3  - Inserir no fim"<<endl;
                            cout<<"4  - Acessar no inicio"<<endl;
                            cout<<"5  - Acessar no meio"<<endl;
                            cout<<"6  - Acessar no fim"<<endl;
                            cout<<"7  - Remover no inicio"<<endl;
                            cout<<"8  - Remover no meio"<<endl;
                            cout<<"9  - Remover no fim"<<endl;
                            cout<<"10 - Realizar uma busca sequencial"<<endl;
                            cout<<"11 - Exibir lista"<<endl;
                            cout<<"0  - Sair"<<endl;
                            cin>>escolha2;

                            switch(escolha2){
                                case 1:
                                    cout<<"Digite o elemento a ser inserido: ";
                                    cin>>elemento;
                                    inserirInicioLista(&ls, elemento, &qntd);
                                    imprimirLista(ls);
                                    break;
                                case 2:
                                    cout<<"Digite o elemento a ser inserido: ";
                                    cin>>elemento;
                                    cout<<"Informe a posição a ser inserida: ";
                                    cin>>pos;
                                    inserirMeioLista(&ls, elemento, pos, &qntd);
                                    imprimirLista(ls);
                                    break;
                                case 3:
                                    cout<<"Digite o elemento a ser inserido: ";
                                    cin>>elemento;
                                    inserirFimLista(&ls, elemento, &qntd);
                                    imprimirLista(ls);
                                    break;
                                case 4:
                                    resultado = acessoInicioLista(ls);
                                    cout<<resultado<<endl;
                                    break;
                                case 5:
                                    cout<<"Informe a posição a ser acessada: ";
                                    cin>>pos;
                                    resultado = acessoMeioLista(ls, pos);
                                    cout<<resultado<<endl;
                                    break;
                                case 6:
                                    resultado = acessoFimLista(ls);
                                    cout<<resultado<<endl;
                                    break;
                                case 7:
                                    removerInicioLista(&ls, &qntd);
                                    imprimirLista(ls);
                                    break;
                                case 8:
                                    cout<<"Informe a posição do elemento a ser removido: ";
                                    cin>>pos;
                                    removerMeioLista(&ls, pos, &qntd);
                                    imprimirLista(ls);
                                    break;
                                case 9:
                                    ls = removerFimLista(ls, &qntd);
                                    imprimirLista(ls);
                                    break;
                                case 10:
                                    cout<<"Insira qual o elemento a ser procurado: ";
                                    cin>>elemento;
                                    cout<<"qntd = "<<qntd<<endl;
                                    if(buscaSequencialLista(ls, elemento)==true){
                                        cout<<"Elemento encontrado!"<<endl;
                                    }
                                    else cout<<"Elemento não encontrado!"<<endl;
                                    break;
                                case 11:
                                    imprimirLista(ls);
                                    break;
                                case 0:
                                    qntd = 0;
                                    destruirLista(&ls);
                                    break;
                            }
                    }
                    break;
            }
        }
	return 0;
}
