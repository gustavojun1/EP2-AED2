#include "headers.h"
int main()
{
    //FILE* data = fopen("data.dat", "wb");

    bTree* arvore = createTree("tree.dat", fileExists("tree.dat"));

   /* recordNode* newNode = malloc(sizeof(recordNode));

    newNode->codigoLivro = 5849;
    strcpy(newNode->titulo, "T");
    strcpy(newNode->nomeCompletoPrimeiroAutor, "A");
    newNode->anoPublicacao = 2001;

    insert(arvore, newNode->codigoLivro);

    traverse(arvore, arvore->root);
    printf("chegou aqui\n");
    */
    
    char operacao[2];
    scanf("%s", operacao);
    printf("%s\n", operacao);
    while(operacao != "F") {   
        printf("entrou no while\n");
        // fseek(stdin, 1, SEEK_CUR);
        char dados[250];

        // for(int i = 0; i < strlen(dados); i++) 
        // printf("%c", dados[i]); 
        // printf("\n");

        //fgets(dados, 250, stdin);

        if(!strcmp(operacao, "I")) { // insercao
            printf("entrou em I\n");
            fgets(dados, 250, stdin);
            char* campos[4];
            char* token = strtok(dados, ";");
            int i = 0;
            
            while( token != NULL ) {
                campos[i] = token;
                i++;
                token = strtok(NULL, ";");
            }
            recordNode* newRec = malloc(sizeof(recordNode));
            enterData(newRec, atoi(campos[0]), campos[1], campos[2], atoi(campos[3]));
            insert(arvore, newRec->codigoLivro);
            // quando o nó tá cheio, ele não adiciona
            traverse(arvore, arvore->root);
        } 
        else if(!strcmp(operacao, "R")) { // remocao
            printf("entrou em R\n");
            fgets(dados, 250, stdin);
            int codigo = atoi(strtok(dados, ";"));
            removeFromTree(arvore, codigo); // lembrar de colocar a flag "-99999"
        } 
        else if(!strcmp(operacao, "B")) { // busca
            printf("entrou em B\n");
            fgets(dados, 250, stdin);
            int codigo = atoi(strtok(dados, ";"));
            printf("Codigo a ser buscado: %d\n", codigo);
            if(search(arvore, codigo) != NULL) { // elemento encontrado
                printf("livro existe\n");
            } else { // elemento nao encotrado
                printf("livro nao existe\n");
            }
        }
        else if(!strcmp(operacao, "P1")) {
            traverse(arvore, arvore->root);
        }
        else if(!strcmp(operacao, "P2")){

        }
        else if(!strcmp(operacao, "P3")){

        }

        scanf("%s", operacao);
    }
    
    // $ I 1;T;A;2001
    free(arvore);
    return 0;
}