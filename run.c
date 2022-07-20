#include "headers.h"
int main()
{
    FILE* data = fopen("data.dat", "wb+");

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
    while(strcmp(operacao, "F")) {   
        // fseek(stdin, 1, SEEK_CUR);
        char dados[250];

        // for(int i = 0; i < strlen(dados); i++) 
        // printf("%c", dados[i]); 
        // printf("\n");

        //fgets(dados, 250, stdin);

        if(!strcmp(operacao, "I")) { // insercao
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
            insert(arvore, newRec->codigoLivro); //insere na arvore
            // quando o nó tá cheio, ele não adiciona

            fwrite(newRec, sizeof(recordNode), 1, data); // adiciona no data.dat
            //pos++;

            // recordNode* nodeRead = malloc(sizeof(recordNode));
            // int numRead = fread(nodeRead, sizeof(recordNode), 1, data);
            //printf("%d\n", numRead);
            //printRec(nodeRead); 
            // traverse(arvore, arvore->root);
        } 
        else if(!strcmp(operacao, "R")) { // remocao
            fgets(dados, 250, stdin);
            int codigo = atoi(strtok(dados, ";"));
            
            removeFromTree(arvore, codigo); // lembrar de colocar a flag "-99999"

           /* found->codigoLivro = -99999;
            fwrite(found, sizeof(recordNode), 1, data);
            insert(arvore, found->codigoLivro); //insere na arvore
            */
            
        } 
        else if(!strcmp(operacao, "B")) { // busca
            fgets(dados, 250, stdin);
            int codigo = atoi(strtok(dados, ";"));
            if(search(arvore, codigo) != NULL) { // elemento encontrado
                printf("O livro com codigo %d existe\n", codigo);
            } else { // elemento nao encotrado
                printf("O livro com codigo %d nao existe\n", codigo);
            }
        }
        else if(!strcmp(operacao, "P1")) {
            traverse(arvore, arvore->root);
        }
        else if(!strcmp(operacao, "P2")){
            hardPrint(arvore);
        }
        else if(!strcmp(operacao, "P3")){

        }

        scanf("%s", operacao);
    }
    
    // $ I 1;T;A;2001
    fclose(data);
    free(arvore);
    return 0;
}