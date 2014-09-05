#include <stdio.h>


int main( int argc, char* argv[] )
{
	int tlen = 1024*1024*4;
	char *buf1 = new char [tlen];
	char *buf2 = new char [tlen];
	FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");

	int len1 = fread(buf1, 1, tlen, f1);
	int len2 = fread(buf2, 1, tlen, f2);

	printf("%d,%d\n", len1, len2);
	for(int i=0; i<len1; i++){
		if (buf1[i]!=buf2[i]) {
			printf("error %d, %d, %d\n", i, buf1[i], buf2[i]);
			break;
		}
	}


	delete buf1;
	delete buf2;
	fclose(f1);
	fclose(f2);
	return 0;
}


