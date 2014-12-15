/*****************************************************************************
* rpn_eval.c                                                                 *
*                                                                            *
*   Prozedurale Programmierung WS 2014/2015 - Exercise Sheet 7               *
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
#include <math.h>

#include "rpn_eval.h"


/** definitions **/
#define CCOM0  _command[ 0 ]
#define CCOM1  _command[ 1 ]
#define CCOM2  _command[ 2 ]
#define CCOM3  _command[ 3 ]


#define CSTACK0  _stack[ s_pos ]
#define CSTACK1  _stack[ s_pos - 1 ]
#define CSTACK2  _stack[ s_pos - 2 ]


/** global variables **/
char _command[ COMMAND_SIZE + 1 ];
double _stack[ STACK_SIZE ];


/**
 * evaluation of a functional term in reverse polish notation
 *   @parameter
 *       xvec    - array that contains values of variables x0, x1, x2 ...
 *       n_x     - length of xvec
 *       fnc     - pointer to expression string in RPN
 *       res     - reference to result of fnc evaluation
 *   @returns  
 *               0 - if everything went fine
 *      error flag - otherwise
**/
int rpn_eval( double xvec[], int n_x, char *fnc, double *res ) {

  int i = 0, k = 0, c_pos = 0, s_pos = -1;
  
  /* loop through commands */
  while ( 1 ) {
    
    /* remove spaces */
    while ( *fnc == ' ' )
      fnc++;
    
    /* read command */
    c_pos = 0;
    while ( *fnc != ' ' && *fnc != '\n' && *fnc != '\0' && c_pos < COMMAND_SIZE )
      _command[ c_pos++ ] = *fnc++;
    _command[ c_pos ] = '\0';
    
    if ( c_pos ) {
      
      /* import variable */
      if ( CCOM0 == 'x' ) {
        k = 0;
        for ( i = 1; i < c_pos; i++) {
          if ( _command[ i ] < '0' || _command[ i ] > '9' )
            return VARIABLE_FAILURE;
          k = k * 10 + _command[ i ] - '0';
        }
        if ( k >= n_x )
          return VARIABLE_FAILURE;
        if ( s_pos >= STACK_SIZE - 1 )
          return STACK_OVERFLOW;
        _stack[ ++s_pos ] = xvec[ k ];
      }
      
      /* read number */
      else if ( ( CCOM0 >= '0' && CCOM0 <= '9' ) ||
           ( ( CCOM0 == '.' || CCOM0 == '-' ) && c_pos > 1 ) ) {
        if ( s_pos >= STACK_SIZE - 1 )
          return STACK_OVERFLOW;
        else if ( sscanf( _command, "%lf", &_stack[ ++s_pos ] ) != 1 )
          return NUMBER_FAILURE;
      }
      
      /* treat 1-character command */
      else if ( c_pos == 1 ) {
        if ( s_pos < 1 )
          return STACK_UNDERFLOW;
        switch ( _command[ 0 ] ) {
          case '+':  CSTACK1 += CSTACK0;  break;
          case '-':  CSTACK1 -= CSTACK0;  break;
          case '*':  CSTACK1 *= CSTACK0;  break;
          case '/':  CSTACK1 /= CSTACK0;  break;
          case '^':  CSTACK1 = pow( CSTACK1, CSTACK0 );  break;
          default :  return UNKNOWN_COMMAND;
        }
        s_pos--;
      }
      
      /* treat 3-character command */
      else if ( c_pos == 3 ) {
        if ( s_pos < 0 )
          return STACK_UNDERFLOW;
        if ( CCOM0 == 's' && CCOM1 == 'i' && CCOM2 == 'n' )
          CSTACK0 = sin( CSTACK0 );
        else if ( CCOM0 == 'c' && CCOM1 == 'o' && CCOM2 == 's' )
          CSTACK0 = cos( CSTACK0 );
        else if ( CCOM0 == 't' && CCOM1 == 'a' && CCOM2 == 'n' )
          CSTACK0 = tan( CSTACK0 );
        else if ( CCOM0 == 's' && CCOM1 == 'q' && CCOM2 == 'r' )
          CSTACK0 *= CSTACK0;
        else if ( CCOM0 == 'e' && CCOM1 == 'x' && CCOM2 == 'p' )
          CSTACK0 = exp( CSTACK0 );
        else if ( CCOM0 == 'l' && CCOM1 == 'o' && CCOM2 == 'g' )
          CSTACK0 = log( CSTACK0 );
        else
          return UNKNOWN_COMMAND;
      }
      
      /* treat 4-character command */
      else if ( c_pos == 4 ) {
        if ( s_pos < 0 )
          return STACK_UNDERFLOW;
        if ( CCOM0 == 's' && CCOM1 == 'q' && CCOM2 == 'r' && CCOM3 == 't' )
          CSTACK0 = sqrt( CSTACK0 );
        else
          return UNKNOWN_COMMAND;
      }
      
      /* treat errors */
      else
        return UNKNOWN_COMMAND;
    }

    /* end of function evaluation */
    else if ( *fnc == '\n' || *fnc == '\0' ) {
      if ( s_pos != 0 )
        return NOT_UNIQUE;
      *res = _stack[ 0 ];
      return EVAL_SUCCESS;
    }
    
  }  /* while ( 1 ) */
  
  return UNKNOWN_FAILURE;
}

