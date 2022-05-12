#include <stdio.h>
#include <stdlib.h>

char prochaineLettre(FILE* in)
{
	int c;
	char l;
	if(in!=NULL){
    do{
		c=fscanf(in,"%c",&l);
		if((l>='a' && l<='z')||(l>='A' && l<='Z')){
			return l;
		}
	}while(c!=EOF);
	}
	else{
		 return EXIT_FAILURE;
	}
	return EOF;
}


char lettreLaPlusFrequente(FILE* in)
{
	int occ=0,i;
	int tab[26]={0};
	char l;

	do{
		l=prochaineLettre(in);
		if(l>='A' && l<='Z'){
			tab[l-'A']++;
		}
		if(l>='a' && l<='z'){
			tab[l-'a']++;
		}
		
	}while(l!=EOF);
	for(i=0;i<26;i++){
		if(tab[i]>tab[occ]){
			occ=i;
		}		
	}
	return 'a'+occ;
}


void decodageCesar(FILE *in, FILE *out)
{
    char l;
	int c;
	char lf=lettreLaPlusFrequente(in);
	int dec=lf-'e';
	
	fseek(in,0L,SEEK_SET);
	c=fscanf(in, "%c", &l);
	while(c!=EOF)
    	{	
        	if(l>='a' && l<= 'z')
        	{
        	    l = (l-'a'-dec+26)%26 + 'a';
        	    fputc(l,out);
        	}else if(l>='A' && l<= 'Z')
        	{
        	    l = (l-'A'-dec+26)%26 + 'A';
        	    fputc(l,out);
        	}else{
				
				
	    		fputc(l,out);
        	}
			c=fscanf(in, "%c", &l);
	    }
}



int main(int argc, char*argv[]){
	
    FILE *in=NULL;
    FILE *out=NULL;
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if( in == NULL )
    {
		fprintf(stderr, "Ce fichier n'existe pas \n ");
        return EXIT_FAILURE;
    }else if( out == NULL )
    {
		fprintf(stderr, "ce fichier n'existe pas \n ");
        return EXIT_FAILURE;
    }else{	
		decodageCesar(in,out);
	}
	

    fclose(in);
    fclose(out);
    
    return EXIT_SUCCESS;

}
