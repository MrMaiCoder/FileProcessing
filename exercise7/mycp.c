#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
	FILE *reader, *copy;
	int readnum, copynum;
	char buffer[100];

	if(argc!=3){
		fprintf(stderr, "Enter: mycp input output \n");
		exit(1);
	}

	if((reader=fopen(argv[1], "rb"))==NULL){
		fprintf(stderr, "Error opening read file.\n");
		exit(1);
	}
	if((copy=fopen(argv[2],"wb"))==NULL){
		fprintf(stderr, "Error opening write file.\n");
		exit(1);
	}
	while(feof(reader)==0){
		if(readnum=fread(buffer, 1, 100, reader))!=100{
			if(ferror(reader)!=0){
				fprint(stderr, "Error reading file.\n");
				exit(1);
			}else if(feof(reader)!=0);
		}
		if((copynum=fwrite(buffer,1,readnum,copynu,))!=readnum){
			fprintf(stderr, "Error writing file.\n");
			exit(1);
		}
	}
	fclose(reader);
	fclose(copy);
	
	return 0;
}

