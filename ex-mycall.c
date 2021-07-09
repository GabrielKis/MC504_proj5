/* 
 * Teste da nova chamada de sistema
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WEIGHT 15

int main() {
	int root_uid = 0;
	
	printf("Peso inicial do usuario: %d:%d\n", root_uid, syscall(386, root_uid));
	if (!syscall(385, root_uid, WEIGHT)){
		printf("Alteracao de peso do usuario: %d para %d com sucesso\n", root_uid, WEIGHT);
	}else{
		printf("Alteracao de peso do usuario: %d para %d falhou\n", root_uid, WEIGHT);
	}
	printf("Peso final do usuario: %d:%d\n", root_uid, syscall(386, root_uid));
	return 0;
}
