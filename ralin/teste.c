#include <stdio.h>
#include <unistd.h>


void function(int *counter){
	for(int i = 0; i<4; i++){
		fork();
		(*counter)++;
	}
}

int main(){
	int counter = 0;
	function(&counter);
	printf("%d\n", counter);
	return 0;
}