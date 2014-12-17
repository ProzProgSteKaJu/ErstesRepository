/*****************************************************************************
* ppn_calculator.c                                                           *
*                                                                            *
*   Prozedurale Programmierung WS 2014/2015 - Exercise Sheet 8               *
*                                                                            *
*   parameter: none                                                          *
*   return value: 0                                                          *
*                                                                            *
* Autor: M. Lange,                                                           *
* E-Mail: marko.lange@tu-harburg.de                                          *
*                                                                            *
* Date: 03.11.2014                                                           *
*****************************************************************************/

/**
 * includes
**/
#include <stdio.h>
#include <stdlib.h>

#include "rpn_eval.h"
#include "prefix2postfix.h"


/**
 * definitions
**/
#define PPN_LENGTH  200


/**
 * main function to read and evaluate function string (from stdin)
**/
int main( void ) {

  /* variable initialization */
  double val;
  double *xvec;
  char ppn[PPN_LENGTH];
  char *rpn;
  int n_x, i, fail, input_ok;

  /* get number of variables */
  while ( 1 ) {
    printf( "\nWieviele Variablen hat das Funktional?\n-> " );
    fflush( stdout );
    input_ok = scanf( "%d", &n_x );
    while( getchar() != '\n' )
      continue;
    if ( input_ok == 0 )
      printf( "\nFehler: Eingabe nicht akzeptiert.\n" );
    else
      break;
  }

  /* allocate memory */
  if ( n_x > 0 )
    xvec = ( double * ) malloc( n_x * sizeof( double ) );
  if ( xvec == NULL && n_x > 0 ) {
    printf( "\nFehler bei Speicherallokation!\n" );
    return ALLOCATION_FAILURE;
  }

  /* read prefix function string */
  printf( "\nSie koennen nun das Funktional in Prefixnotation uebergeben:\n->  " );
  fflush( stdout );
  while ( 1 ) {
    fgets( ppn, PPN_LENGTH, stdin );
    rpn = prefix2postfix( ppn );
    printf( "\nDer zugehoerige Ausdruck in Postfixnotation ist: \n    %s", rpn);
    printf( "\nSoll das Funktional so uebernommen werden? [y/N]" );
    fflush( stdout );
    if ( getchar() == 'y' && getchar() == '\n' )
      break;
    while ( getchar() != '\n' )
      continue;
    free( rpn );
    printf( "Geben Sie das Funktional erneut ein!\n->  " );
    fflush( stdout );
  }

  /* computation loop */
  while ( 1 ) {

    /* import variable values */
    if ( n_x > 0 )
      printf( "\nTragen Sie bitte die Werte der Variablen ein.\n" );
    for ( i = 0; i < n_x; i++ ) {
      while ( 1 ) {
        printf( "x%d = ", i );
        fflush( stdout );
        input_ok = scanf( "%lf", &xvec[ i ] );
        while( getchar() != '\n' )
          continue;
        if ( input_ok == 0 )
          printf( "\nFehler: Eingabe nicht akzeptiert.\n" );
        else
          break;
      }
    }

    /* compute and output result */
    fail = rpn_eval( xvec, n_x, rpn, &val );
    if ( fail ) {
      printf( "\nFehler: Das Funktional konnte nicht ausgewertet werden!\nFehlercode: %d\n", fail );
      return fail;
    }
    printf( "\nDer Funktionswert ist:  %f\n", val );
    fflush( stdout );
    if ( n_x > 0 ) {
      printf( "\nWollen Sie eine erneute Berechnung mit neuen Eingabedaten starten? [y/N]" );
      fflush( stdout );
      if ( getchar() == 'y' && getchar() == '\n' )
        continue;
    }
    break;
  }

  /* free memory */
  if ( n_x > 0 )
    free( xvec );
  free( rpn );

  return 0;
}

