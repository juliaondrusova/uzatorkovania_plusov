#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHYBA 100

FILE* sub;


void vypln_plusmi (char* pole_znakov, int zaciatok, int koniec) {

	int i;

	for (i=zaciatok; i<=koniec; i++) {
		pole_znakov[i]='+';
	}
}

void umiestni_zatvorky (char* pole_znakov, int zaciatok, int koniec) {

	int pozicia_lavej, pozicia_pravej;

	if ((koniec-zaciatok)<1)
		return;

	for (pozicia_lavej=zaciatok; pozicia_lavej<koniec; pozicia_lavej++) {
		for (pozicia_pravej=pozicia_lavej+1; pozicia_pravej<=koniec; pozicia_pravej++) {
			
			pole_znakov[pozicia_lavej]='(';
			pole_znakov[pozicia_pravej]=')';
			//printf ("%s\n", pole_znakov);
			fprintf(sub, "%s\n", pole_znakov);
	
	/*
			//zatvorky pre lavu cast
			umiestni_zatvorky(pole_znakov, zaciatok, pozicia_lavej-1);
	*/	
			//zatvorky pre vnutornu cast
			umiestni_zatvorky(pole_znakov, pozicia_lavej+1, pozicia_pravej-1);
			
			//zatovrky pre pravu cast
			umiestni_zatvorky(pole_znakov, pozicia_pravej+1, koniec);
			
			vypln_plusmi(pole_znakov, zaciatok, koniec);
		}
	}
}




void uzatvorkovania_plusov(char size) {

	int i;

	// +1 pretoze posledny znak musi byt 0
	char* pole_znakov= (char*)malloc(sizeof(char)*(size+1));

	if (pole_znakov==NULL) {
		printf ("Chyba pri allokovani");
		return;
	}

	for (i=0; i<size; i++) {
		pole_znakov[i]='+';
	}

	pole_znakov[size]='\0';
	fprintf (sub,"%s\n", pole_znakov);
	umiestni_zatvorky(pole_znakov, 0, size-1);
	free(pole_znakov);

}

main () {
	
	
	sub=fopen("data.txt", "w");
	
	if (sub==NULL)
		return CHYBA;
		
	uzatvorkovania_plusov(4);
	
	fclose(sub);
}
