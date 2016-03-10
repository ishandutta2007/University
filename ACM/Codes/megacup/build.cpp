#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main()
{

	char outfile[10];
	for(int i = 6880; i <= 7000; i+=2)
	{
		memset(outfile, 0, sizeof(outfile));
		sprintf(outfile, "%d.txt", i);
		freopen(outfile, "w", stdout);
		printf("%d\n", i);
		fclose(stdout);
	}


	return 0;
}
