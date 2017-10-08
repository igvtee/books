#include <stdio.h>
#include <string.h>

#define SIZE 128

void palindrome(const char *str)
{
	char buffer[SIZE];
	char *front, *rear;

	strncpy(buffer, str, SIZE);
	buffer[SIZE-1] = '\0';

	front = buffer;
	rear = buffer + (strlen(buffer) - 1);
	while (front < rear) {
		if (*front != *rear)
			break;
		front++;
		rear--;
	}
	if (front >= rear) {
		printf("It is a palindrome!\n");
	}
}

int main(void)
{
	char buf[] = "madam";

	palindrome(buf);

	return 0;
}
