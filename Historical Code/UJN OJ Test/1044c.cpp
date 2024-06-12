#include <stdio.h>

void multiplyByTwo(char *a)

{

int i;

for (i=0; i<19; i++)

a[i] *= 2;

for (i=0; i<19; i++)

if (a[i]>9)

{

a[i] -= 10;

a[i+1]++;

}

}

int main(void)

{

char a[20] = {'\0'};

int i;

int n;

//printf("«Î ‰»Înµƒ÷µ:");

scanf("%d",&n);

a[0] = 1;

for (i = 0; i<n; i++)

multiplyByTwo(a);

//printf("%d",n);

for (i = 19; i>=0; i--)

if (a[i] != '\0') break;
int j;

for (j=i; j>=0; j--)

putchar(a[j] + '0');

printf("\n");

return 0;

}
