/* This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */

/* File for Decoding Bob Page's RSA problem circa a 1994 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>

#include <gmp.h>

#include "qbrsa.h"

/* Message 1 details
   n = 930353
   e = 143
   d = 154187
   p = 757
   q = 1229
*/

/* Message 2 details
   n   = 117961196597149059480253145659311142150566350280892573178881
   e   = 115
   d   = 11283244891901214385067692193422554779725885454515489121467
   p   = 193734632960097745278242608129
   q   = 608880275017450056588762482689
*/

bool decryptmsg1(FILE* ciphertext_fp)
{
  const char msg1_decrypt[] = "154187";
  const char msg1_modulus[] = "930353";

  int      currentValue;
  wchar_t  clearChars[2];
  int      clearValue;

  mpz_t modulus_gmp, result_gmp, decryptor_gmp, limit_gmp, input_gmp;

  // libgmp values have to be intitialised before they can be used.
  mpz_init(result_gmp);
  mpz_init(input_gmp);
  mpz_init_set_str(decryptor_gmp, msg1_decrypt, 10);
  mpz_init_set_str(modulus_gmp,   msg1_modulus, 10);
  mpz_init_set_str(limit_gmp,     "999999999999999999999999999", 10);

  swprintf(clearChars, 2, L"\0");

  printf(" -- Start of Message One -- \n");

  while (fscanf(ciphertext_fp, "%d,", &currentValue) >= 0)
  {
    mpz_set_si(input_gmp, currentValue);

    mpz_powm(result_gmp, input_gmp, decryptor_gmp, modulus_gmp);

    if(mpz_fits_sint_p(result_gmp))
    {
      clearValue = (int) mpz_get_si(result_gmp);
      look_up(clearValue, clearChars);
      printf("%ls", clearChars);
    }
  }
  mpz_clears(modulus_gmp, result_gmp, decryptor_gmp, limit_gmp, input_gmp, NULL);
  printf("\n -- End   of Message One -- \n");
  return true;
}

bool decryptmsg2(FILE* ciphertext_fp)
{
  const char msg2_modulus[] = "117961196597149059480253145659311142150566350280892573178881";
  const char msg2_decrypt[] = "11283244891901214385067692193422554779725885454515489121467";

  char   *currentWord;
  size_t  bytesRead = 116;
  char   *result;
  int     resultLength;
  int     strpos;
  wchar_t clearChars[2];
  int     clearValue;
  char    temp_str[4];

  mpz_t modulus_gmp, result_gmp, decryptor_gmp, limit_gmp, input_gmp;


  printf(" -- Start of Message Two -- \n");
  // libgmp values have to be intitialised before they can be used.
  mpz_init(result_gmp);
  mpz_init(input_gmp);
  mpz_init_set_str(decryptor_gmp, msg2_decrypt, 10);
  mpz_init_set_str(modulus_gmp,   msg2_modulus, 10);
  mpz_init_set_str(limit_gmp,     "999999999999999999999999999", 10);

  currentWord = malloc(116 * sizeof(char));

  swprintf(clearChars, 2, L"\0");

  if (currentWord == NULL)
  {
    printf("Failed to allocate buffer for the encrypted word\n");
    return false;
  }

  while (getline(&currentWord, &bytesRead, ciphertext_fp) != -1)
  {
    mpz_set_str(input_gmp, currentWord, 10);

    mpz_powm(result_gmp, input_gmp, decryptor_gmp, modulus_gmp);

    if(mpz_cmp(limit_gmp, result_gmp) > 0)
    {
      result = mpz_get_str(NULL, 10, result_gmp);
    }
    else
    {
      result = NULL;
    }
    resultLength = (int) strlen(result);

    strpos = 0;
    while (strpos < resultLength)
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
        look_up(clearValue, clearChars);
        printf("%ls", clearChars);
      }
      else if (result[strpos] != '2')
      {
        temp_str[0] = result[strpos++];
        temp_str[1] = result[strpos++];
        temp_str[2] = '\0';
        //printf("%s, ", temp_str);
        clearValue = atoi(temp_str);
        look_up(clearValue, clearChars);
        printf("%ls", clearChars);
      }
      else
      { // Parse or Data error
        strpos++; //Skip it
        printf("Parse or Data error\n");
      }
    }
    free(result);
  }
  free(currentWord);
  mpz_clears(modulus_gmp, result_gmp, decryptor_gmp, limit_gmp, input_gmp, NULL);
  printf("\n -- End   of Message Two -- \n");
  return true;
}

int main(int argc, char *argv[])
{
  FILE   *msg1_fp, *msg2_fp;
  (void)argc;
  (void)argv;

  /* Wide char voodoo */
  setlocale (LC_ALL,"");

  msg1_fp = fopen("msg1.txt", "r");

  if (msg1_fp == NULL)
  {
    printf("Failed to open message file msg1.txt\n");
  }
  else
  {
    if(!decryptmsg1(msg1_fp))
    {
      printf("Decryption of message 1 failed\n");
    }
  }

  msg2_fp = fopen("msg2.txt", "r");

  if (msg2_fp == NULL)
  {
    printf("Failed to open message file msg2.txt\n");
  }
  else
  {
    if (!decryptmsg2(msg2_fp))
    {
      printf("Decryption of message 2 failed\n");
    }
  }

  fclose(msg1_fp);
  fclose(msg2_fp);
  return 0;
}
