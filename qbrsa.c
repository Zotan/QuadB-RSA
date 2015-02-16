/* File for Decoding Bob Page's RSA problem circa a long time ago */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "qbrsa.h"

/* Message 2 number details
   p   = 193734632960097745278242608129
   q   = 608880275017450056588762482689
   e   = 115
   n   = 117961196597149059480253145659311142150566350280892573178881
   phi = 117961196597149059480253145658508527242588802479025568088064

   d =   11283244891901214385067692193422554779725885454515489121467

   34 encoded =
   55636010253037548871124502396161458493388999204705270400538

   83 111 032 121 111 117 039 118 101 First word !!!!!
   83111032121111117039118101

   S  o       y   o   u   '   v    e
   Pari command line for decrypt of 34
   Mod(55636010253037548871124502396161458493388999204705270400538^1297573162568639654282784602243593799668476827269281248967679,
   117961196597149059480253145659311142150566350280892573178881)

*/

// Function prototypes
char * do_decrypt (mpz_t base, const char *decrypt, const char *modulus);

//Globals
char pword[61];
const char msg1_modulus[] = "-77905";
const char msg1_decrypt[] = "930353";

const char msg2_modulus[] = "117961196597149059480253145659311142150566350280892573178881";
const char msg2_decrypt[] = "11283244891901214385067692193422554779725885454515489121467";

int main(int argc, char *argv[])
{
	int     i;
	int     strpos;
	int     carryon = 1;
	FILE   *msg1_fp, *msg2_fp;
	mpz_t   base;
	char   *result;
	char   *currentWord;
	char    temp_str[4];
	ssize_t charsRead;
	size_t  bytesRead = 116;
	int     resultLength;
	char    clearChar;
	int     clearValue;
	int     loops;
	char testWord[52];

	msg1_fp = fopen("msg1.txt", "r");

	if (msg1_fp == NULL)
	{
		printf("Failed to open message file msg1.txt");
		exit(1);
	}

	msg2_fp = fopen("msg2.txt", "r");

	if (msg2_fp == NULL)
	{
		printf("Failed to open message file msg2.txt");
		exit(1);
	}

	currentWord = malloc(116 * sizeof(char));

	if (currentWord == NULL)
	{
		printf("Failed to allocate buffer for the encrypted word\n");
		exit(1);
	}

	printf(" -- Decrypting the first message -- \n");

	bytesRead = 104;
	charsRead = getline(&currentWord, &bytesRead, msg1_fp);
	loops = (int) strlen(currentWord);
	printf("Bytes Read: %u, String Length: %d\n", (unsigned)bytesRead, loops);


	for (i=1; i<loops; i++)
	{
		strncpy(testWord, currentWord, i);
		testWord[i] = '\0';
		mpz_init_set_str(base, testWord, 10);
		result = do_decrypt(base, msg1_decrypt, msg1_modulus);
		printf(" Output: %5s, MSG: ", result);

		strpos = 0;
		while (strpos < strlen(result))
		{
			// three digit codes start with 1, Two digit codes start with 3-9, 0 is used as padding
			if (result[strpos] == '0')
			{
				strpos++; //Skip it
			}
			else if (result[strpos] == '1')
			{
				temp_str[0] = result[strpos++];
				temp_str[1] = result[strpos++];
				temp_str[2] = result[strpos++];
				temp_str[3] = '\0';
				//printf("%s, ", temp_str);
				clearValue = atoi(temp_str);
				clearChar  = look_up(clearValue);
				printf("%c", clearChar);
			}
			else if (result[strpos] != '2')
			{
				temp_str[0] = result[strpos++];
				temp_str[1] = result[strpos++];
				temp_str[2] = '\0';
				//printf("%s, ", temp_str);
				clearValue = atoi(temp_str);
				clearChar  = look_up(clearValue);
				printf("%c", clearChar);
			}
			else
			{ // Parse or Data error
				strpos++; //Skip it
				printf("Error");
			}
		}
		printf("\n");
	}

	printf(" --   End of the first message   -- \n");


	printf(" -- Decrypting the second message -- \n");

	printf("\"");

	/* while (carryon) */
	/* { */
	/* 	charsRead = getline(&currentWord, &bytesRead, msg2_fp); */
	/* 	//printf("Bytes Read: %u", (unsigned)bytesRead); */
	/* 	if (charsRead == -1) */
	/* 	{ */
	/* 		break; */
	/* 	} */

	/* mpz_init_set_str(base, currentWord, 10); */

	/* 	result = do_decrypt(base, msg2_decrypt, msg2_modulus); */
	/* 	resultLength = (int) strlen(result); */

	/* 	strpos = 0; */
	/* 	while (strpos < resultLength) */
	/* 	{ */
	/* 		// three digit codes start with 1, Two digit codes start with 3-9, 0 is used as padding */
	/* 		if (result[strpos] == '0') */
	/* 		{ */
	/* 			strpos++; //Skip it */
	/* 		} */
	/* 		else if (result[strpos] == '1') */
	/* 		{ */
	/* 			temp_str[0] = result[strpos++]; */
	/* 			temp_str[1] = result[strpos++]; */
	/* 			temp_str[2] = result[strpos++]; */
	/* 			temp_str[3] = '\0'; */
	/* 			//printf("%s, ", temp_str); */
	/* 			clearValue = atoi(temp_str); */
	/* 			clearChar  = look_up(clearValue); */
	/* 			printf("%c", clearChar); */
	/* 		} */
	/* 		else if (result[strpos] != '2') */
	/* 		{ */
	/* 			temp_str[0] = result[strpos++]; */
	/* 			temp_str[1] = result[strpos++]; */
	/* 			temp_str[2] = '\0'; */
	/* 			//printf("%s, ", temp_str); */
	/* 			clearValue = atoi(temp_str); */
	/* 			clearChar  = look_up(clearValue); */
	/* 			printf("%c", clearChar); */
	/* 		} */
	/* 		else */
	/* 		{ // Parse or Data error */
	/* 			strpos++; //Skip it */
	/* 			printf("Parse or Data error\n"); */
	/* 		} */
	/* 	} */
	/* 	free(result); */
	/* 	/\* if (result) *\/ */
	/* 	/\* { *\/ */
	/* 	/\* 	if(*result != '1') *\/ */
	/* 	/\* 	{ *\/ */
	/* 	/\* 		temp_str[0] = *result++; *\/ */
	/* 	/\* 		temp_str[1] = *result++; *\/ */
	/* 	/\* 		temp_str[2] = '\0'; *\/ */
	/* 	/\* 		temp_res = atoi(temp_str); *\/ */
	/* 	/\* 		pchar = look_up(temp_res); *\/ */
	/* 	/\* 		printf("%c", pchar); *\/ */
	/* 	/\* 	} *\/ */
	/* 	/\* 	do *\/ */
	/* 	/\* 	{ *\/ */
	/* 	/\* 		temp_str[0] = *result++; *\/ */
	/* 	/\* 		temp_str[1] = *result++; *\/ */
	/* 	/\* 		temp_str[2] = *result++; *\/ */
	/* 	/\* 		temp_str[3] = '\0'; *\/ */
	/* 	/\* 		temp_res = atoi(temp_str); *\/ */
	/* 	/\* 		pchar = look_up(temp_res); *\/ */
	/* 	/\* 		printf("%c", pchar); *\/ */
	/* 	/\* 	} *\/ */
	/* 	/\* 	while(*result != '\0'); *\/ */
	/* 	/\* 	//printf("\n"); *\/ */
	/* 	/\* } *\/ */
	/* } */
	printf("\"");
	printf(" --   End of the second message   -- \n");

	//printf("\n");
	mpz_clear(base);
	fclose(msg1_fp);
	fclose(msg2_fp);
	return 0;
}


char * do_decrypt (mpz_t base, const char *decrypt, const char *modulus)
{
	mpz_t mod, gmp_result, decryptor, limit;
	char * result;
	//size_t outputLength;

	mpz_init(gmp_result);
	mpz_init_set_str(decryptor, decrypt, 10);
	mpz_init_set_str(mod,       modulus, 10);
	mpz_init_set_str(limit,     "999999999999999999999999999", 10);

	mpz_powm(gmp_result, base, decryptor, mod);

	if(mpz_cmp(limit, gmp_result) > 0)
	{
		result = mpz_get_str(NULL, 10, gmp_result);
		//printf("\nResult output length: (%u, ", (unsigned)strlen(result));
		//gmp_printf("In: %Zd, Out: %Zd\n", base, gmp_result);
	}
	else
	{
		result = NULL;
	}
	//gmp_printf("Result = %Zd\n",gmp_result);
	mpz_clear(mod);
	mpz_clear(gmp_result);
	mpz_clear(decryptor);
	return result;
}
