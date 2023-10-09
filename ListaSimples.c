//Lista é uma sequência de dados dispostos em ordem//cada elemento é precedido por um elemento e sucedido por outro


#include <stdio.h> //entrada e saída padrão
#include <stdlib.h>  //biblioteca padrão
#include <string.h> // manipula uma String em C

#define TAM 10


typedef struct produto { //typedef é usada para criar um novo nome para um tipo de dado existente
    int codigo; //armazena o código
    char nome[TAM]; //char da suporte a operadores de comparação, igualdade, incremento e decremento
    float preco; //float representa um número em ponto flutuante com precisão de 6 casas decimais
} tp_produto;


typedef struct nodo { //cria um novo tipo de dado
    tp_produto produto; //representa os detalhes do código
    struct nodo *prox; //aponta para o próximo nó na lista, permitindo a navegação de um nó para o próximo.
} tp_nodo;



// Função para inserir um produto na lista
//O ponteiro tipo lista aponta para o inicio da lista, a lista guarda o endereço de memória e aponta para o final//A função inserirProduto é responsável por adicionar um novo produto à lista.
//Ela recebe como parâmetros um ponteiro para a cabeça da lista (tp_nodo **lista) e um novo produto (tp_produto novoProduto).
void inserirProduto(tp_nodo **lista, tp_produto novoProduto) { //Lê na main //Retorna o endereço de memória do nodo //Toda vez um novo criado passa a ser o primeiro
    tp_nodo *novoNodo = (tp_nodo *)malloc(sizeof(tp_nodo)); //malloc função aloca o espaço
    novoNodo->produto = novoProduto; //atribui o valor do produto passado como parâmetro ao campo produto da nova estrutura de nó
    novoNodo->prox = *lista; // atribui o valor do primeiro elemento da lista encadeada ao campo prox
    *lista = novoNodo; // atualiza o valor do primeiro elemento da lista com o endereço de memória do novo nó
    printf("Produto inserido com sucesso!\n");
}




// Função para excluir um produto da lista
void excluirProduto(tp_nodo **lista, int codigo) { //um ponteiro da cabeça da lista e um inteiro que representa o código do produto a ser excluído
    tp_nodo *atual = *lista; // variável atual recebe o valor do ponteiro da cabeça da lista e a variável anterior recebe NULL
    tp_nodo *anterior = NULL; //nó de referência




    while (atual != NULL && atual->produto.codigo != codigo) { //de cada nodo, descobrir se o nodo que quer remover está na lista, fazer loop pra isso
        anterior = atual; //anterior é varivael auxiliarpara manter o nó anterior enquanto percorre a lista.
          //atribui o valor da variável atual à variável anterior
        atual = atual-> prox; //atribui o valor do próximo nó ao ponteiro atual// percorre uma lista encadeada
         //move o ponteiro atual para o próximo nó na lista
         //agora o primeiro nó da lista é o próximo nó depois do excluir
    }



    if (atual == NULL) { //Se atual for igual a nulo imprime a mensagem abaixo
        printf("Produto com código %d não encontrado.\n", codigo);
        return;
    }



    if (anterior == NULL) {
        *lista = atual->prox; //se anterior for igual a nulo retorna a lista original
    } else {
        anterior->prox = atual->prox; //Se o nó anterior não for nulo, o ponteiro do nó anterior é atualizado para apontar para o próximo nó na lista
        // Isso significa que o nó atual foi removido da lista e pode ser liberada a memória
    }



    free(atual); //função que é usada para liberar a memória alocada dinamicamente  // A alocação dinâmica de memória é uma técnica que permite que o programador aloque memória durante a execução do programa.
    //evita vazamentos de memória e ajuda a garantir q o programa use apenas a quantidade necessária de memória
    printf("Produto removido com sucesso!\n");
}



// Função para listar todos os produtos na lista
void listarProdutos(tp_nodo *lista) {
    tp_nodo *atual = lista;



    while (atual != NULL) { //enquanto a condição dentro dos parênteses é verdadeira, o loop continua a ser executado.
        printf("Código: %d, Nome: %s, Preço: %.2f\n", //instrução de impressão
               atual->produto.codigo, atual->produto.nome, atual->produto.preco); //informações do produto
        atual = atual->prox; //atualiza o valor da variável atual para o próximo nó na lista
    }
}






int main() { //não recebe nenhum argumento e retorna um valor inteiro.
    tp_nodo *lista = NULL; //declara uma variável lista do tipo tp_nodo e a inicializa com o valor NULL // declara uma variável inteira
    int opcao;
   
    do {
        printf("OPÇÕES DO MENU:\n");
        printf("(1) Para inserir um produto na lista.\n");
        printf("(2) Para excluir um elemento da lista.\n");
        printf("(3) Para listar todos os campos dos elementos da lista.\n");
        printf("(0) Para finalizar o programa.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); //armazena na variável um inteiro








        switch (opcao) {
            case 1:
                tp_produto novoProduto;
                printf("Digite o código do produto: ");
                scanf("%d", &novoProduto.codigo);
                printf("Digite o nome do produto: ");
                scanf("%s", novoProduto.nome);
                printf("Digite o preço do produto: ");
                scanf("%f", &novoProduto.preco);
                inserirProduto(&lista, novoProduto);
                break; //acaba o loop
            case 2:
                int codigoRemover;
                printf("Digite o código do produto a ser removido: ");
                scanf("%d", &codigoRemover);
                excluirProduto(&lista, codigoRemover);
                break; //acaba o loop
            case 3:
                printf("Lista de produtos:\n");
                listarProdutos(lista);
                break; //acaba o loop
            case 0:
                printf("Programa finalizado.\n");
                break; //acaba o loop
            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
                break; //acaba o loop
        }
    } while (opcao != 0); //condição que está sendo verificada //  O loop será executado até que a opção seja 0




   
    tp_nodo *atual = lista; //declara um ponteiro tp_nodo chamado atual e o inicializa com o endereço do primeiro nó da lista
    while (atual != NULL) { //percorre a lista enquanto o ponteiro atual não for nulo
        tp_nodo *temp = atual; //declara um novo ponteiro temp e o inicializa com o endereço do nó atual
        atual = atual->prox;//atualiza o ponteiro atual para apontar para o próximo nó da lista
        free(temp); // libera a memória alocada para o nodo atual
    }




    return 0;
}






















































 



