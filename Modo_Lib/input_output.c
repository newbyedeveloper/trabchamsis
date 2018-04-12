#include "../Modo_Nucleo/syscalls.h"

//Função de leitura da biblioteca
void IO_read(long begin, long end)
{
	//Selecionando rotina do sistema
	SYSCALL_NUMBER = SYS_READ;

	//Passando parametros pra rotina de sistema via variaveis globais
	READ_PARAMS.begin = begin;
	READ_PARAMS.end	  = end;

	//Realizando chamada ao sistema
	syscall_handler();
}

//Função de escrita da biblioteca
void IO_write(char *write_buffer, int write_size)
{
	//Selecionando rotina do sistema
	SYSCALL_NUMBER = SYS_WRITE;
	
	//Passando parametros pra rotina de sistema via variaveis globais
	WRITE_PARAMS.write_buffer = write_buffer;
	WRITE_PARAMS.write_size	  = write_size;

	//Realizando chamada ao sistema
	syscall_handler();
}