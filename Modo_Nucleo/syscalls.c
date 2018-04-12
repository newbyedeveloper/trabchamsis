#include <stdio.h>
#include <unistd.h>
#include "syscalls.h"

//Flag de controle pra modo nucleo
_Bool KERN_MODE = 0;

//Estruturas para passagem de parametros entre lib e nucleo

int SYSCALL_NUMBER;
struct ST_Read_Params READ_PARAMS;
struct ST_Write_Params WRITE_PARAMS;

//Função para tratar chamadas ao sistema
void syscall_handler(void)
{
	//Entrando em modo nucleo
	KERN_MODE = 1;

	//Selecionando a chamada de sistema
	switch (SYSCALL_NUMBER)
	{
		case SYS_READ:
			sys_read(READ_PARAMS.begin, READ_PARAMS.end);
			goto RET_TO_USER;
		case SYS_WRITE:
			sys_write(WRITE_PARAMS.write_buffer, WRITE_PARAMS.write_size);
			goto RET_TO_USER;
	}

	//Retornando ao modo usuario
	RET_TO_USER:
	KERN_MODE = 0;
}

void sys_read(long begin, long end)
{
	//Validando modo nucleo
	if (KERN_MODE != 1)
	{
		puts("User cant call sys_read");
		return;
	}

	FILE *file;
	int read_size;

	//Abrindo arquivo
	file = fopen("arquivo.txt", "r");

	//Posicionando para leitura
	fseek(file, begin, SEEK_SET);

	//Calculando quanto deve ser lido
	read_size = end - begin;

	//Alocando buffer pra leitura
	char read_buffer[read_size];

	//Efetuando a leitura
	fread(read_buffer, sizeof(char), read_size, file);

	//Fechando arquivo
	fclose(file);

	//Exibindo dados da leitura
	fwrite(read_buffer, sizeof(char), read_size, stdout);
}

void sys_write(char *write_buffer, int write_size)
{
	//Validando modo nucleo
	if (KERN_MODE != 1)
	{
		puts("User cant call sys_write");
		return;
	}

	FILE *file;
	
	//Abrindo arquivo
	file = fopen("arquivo.txt", "a");

	//Efetuando escrita
	fwrite(write_buffer, sizeof(char), write_size, file);

	//Fechando arquivo
	fclose(file);
}