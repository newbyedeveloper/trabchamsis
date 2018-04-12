//Constantes
#define SYS_READ 0
#define SYS_WRITE 1

//Estruturas
struct ST_Read_Params
{
	long begin;
	long end;
};

struct ST_Write_Params
{
	char *write_buffer;
	int write_size;
};

extern int SYSCALL_NUMBER;
extern struct ST_Read_Params READ_PARAMS;
extern struct ST_Write_Params WRITE_PARAMS;

//Prototipos
void syscall_handler(void);
void sys_read(long begin, long end);
void sys_write(char *write_buffer, int write_size);