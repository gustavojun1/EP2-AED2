#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

// 1 , AFG , DIST , 93 , 18
struct rec
{
	/*int key;
	// rest
	char country[5];
	char grate[10];
	int score;
	int rate;*/
    
	//pt2
	int codigoLivro; //chave
    char titulo[30];
	char nomeCompletoPrimeiroAutor[30];
	int anoPublicacao;
};
typedef struct rec recordNode;

struct bTreeNode
{
	int pos; //tells where in node array is this treeNode present.
	bool isLeaf; //leaf or not?, if its leaf it's 1, else 0.
	int noOfRecs;
	//recordNode* recordArr[2 * t - 1];

	//pt 2
	int keyRecArr[2 * t -1]; // as chaves dos registros, que sao no maximo 2t-1
	int posRecArr[2 * t -1]; // posicoes dos registros no arquivo data.dat, que sao no maximo 2t-1
	int children[2 * t]; // links
};
typedef struct bTreeNode bTreeNode;

struct tree
{
	char fileName[20];
	FILE* fp;
	FILE* arq;
	int root;
	int nextPos;
};
typedef struct tree bTree;

bTree* createTree(char* fileName,bool mode);
bTreeNode* nodeInit(bTreeNode* node,bool isLeaf,bTree* tree);
void insert(bTree* tree, int key);
void delete(bTree* tree,int key);
void traverse(bTree* tree, int root);
void dispNode(bTreeNode* node);
void writeFile(bTree* ptr_tree, bTreeNode* p, int pos);
void readFile(bTree* ptr_tree, bTreeNode* p, int pos);
int createData(bTree* file, int codigoLivro, char titulo[], char nomeCompletoPrimeiroAutor[], int anoPublicacao);


//void enterData(recordNode* record, int id_num, char country[], char Grate[], int Score, int Rate);
void enterData(recordNode* record, int codigoLivro, char titulo[], char nomeCompletoPrimeiroAutor[], int anoPublicacao);
recordNode* getData(char *filepath, int len);
recordNode* search(bTree* tree, int key);
//bool search(bTree* tree, int key);
int searchRecursive(bTree* tree, int key, bTreeNode* root);
bool removeFromTree(bTree* tree, int key);
bTreeNode* merge(bTree* tree, bTreeNode *node, int idx);
void borrowFromNext(bTree* tree, bTreeNode *node, int idx);
void borrowFromPrev(bTree* tree, bTreeNode *node, int idx);
void fill(bTree* tree, bTreeNode *node, int idx);
recordNode *getSucc(bTree* tree, bTreeNode *node, int idx);
recordNode *getPred(bTree* tree, bTreeNode *node, int idx);
void removeFromNonLeaf(bTree* tree, bTreeNode *node, int idx);
void removeFromLeaf (bTree* tree, bTreeNode *node, int idx);
void removeNode(bTree* tree, bTreeNode* node, int k);
int findKey(bTreeNode* node, int k);

bool fileExists(char* filename);