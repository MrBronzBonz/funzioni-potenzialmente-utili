//lo scopo di questa funzione è darti un'idea di come controllare che il nome di un file passato sia quello corretto.
// WARNING! devo ancora testare il funzionamento, per ora è solo teoria.

#include <stdio.h>
#include <stdlib.h>

/*metodo alternativo e piú compatto suggerito da: https://github.com/vpescete

int	fdf_check(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	if (file[i] == '\0')
	{
		if(file[i-1] == 'f' && file[i-2] == 'd' && file[i-3] == 'f' && file[i-4] == '.')
			return (0);
	}
	printf("file formato sbagliato");
	return (0);
}*/

int fdf_check(char *file)
{
    int i = 0;
    
    while(file[i] != '\0')
    {
        if(file[i] == '.' && file[i+1] == 'f')
        {
            i++;
            if(file[i] == 'f' && file[i+1] == 'd')
            {
                i++;
                if(file[i] == 'd' && file[i+1] == 'f')
                {
                    i++;
                    if(file[i] == 'f' && file[i+1] == '\0')
                    return(0);
                }
            }
        }
        else
        i++;
    }
    printf("file formato sbagliato");
    return(0);
}

//dopo il suggerimento di partire dalla fine ho migliorato la funzione precedente:

/*int fdf_check(char *file)
{
    int i;

    i = 0;
    while (file[i] != '\0')
    {
        if(file[i] == '.' && file[i+1] == 'f' && file[i+2] == 'd' &&
                file[i+3] == 'f' && file[i+4] == '\0')
            return (0);
        else
            i++;
    }
    printf("file formato sbagliato");
    return (0);
}*/

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        fdf_check(argv[1]);
    }
    return 0;
}
