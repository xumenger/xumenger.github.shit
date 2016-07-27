#define MEM_SIZE 32

struct cpustatus
{
	long total;
	float user;
	float nice;
	float system;
	float idle;
};
struct meminfo
{
	char total[MEM_SIZE];
	char free[MEM_SIZE];
};
