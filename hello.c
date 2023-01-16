#include <stdio.h>
int findmax(int* px, int* py, int* pmax);
int main(void)
{
    int max, x, y;

    scanf("%d %d", &x, &y);
    findmax(&x, &y, &max);
    printf("%d\n", max);
    cout << (findmax(3,5)) << endl;

    return 0;
}
int findmax(int* px, int* py, int* pmax)
{
	*pmax = *px;
	if (*px < *py)
	{
		*pmax = *py;
	}
	return 0;
}
