#include "../Modo_Lib/input_output.h"

int main(void)
{
	//Dados para inserir no 'arquivo.txt'
	char *data = "dados test";

	//Teste da função de biblioteca IO_write
	IO_write(data, 10);

	//Teste da função de biblioteca IO_read
	IO_read(0, 10);

	return 0;
}