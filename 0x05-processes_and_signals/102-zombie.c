#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinite_while - creates an infinite loop to make the program hang
 * @duration: the duration of the infinite loop in seconds
 * Return: always 0
 */
int infinite_while(int duration)
{
	while (1)
	{
		sleep(duration);
	}
	return (0);
}

/**
 * main - creates zombie processes
 * @num_zombies: the number of zombie processes to create
 * @loop_duration: the duration of the infinite loop in seconds
 * Return: always 0
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <num_zombies> <loop_duration>\n", argv[0]);
		return (1);
	}

	int i;
	pid_t zombie;
	int num_zombies = atoi(argv[1]);
	int loop_duration = atoi(argv[2]);

	for (i = 0; i < num_zombies; i++)
	{
		zombie = fork();
		if (!zombie)
			return (0);
		printf("Zombie process created, PID: %d\n", zombie);
	}

	infinite_while(loop_duration);
	return (0);
}
