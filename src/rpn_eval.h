#ifndef _RPN_EVAL_H_
#define _RPN_EVAL_H_


/** define error flags **/
#define EVAL_SUCCESS         0
#define ALLOCATION_FAILURE  -1
#define STACK_UNDERFLOW     -2
#define STACK_OVERFLOW      -3
#define UNKNOWN_COMMAND     -4
#define VARIABLE_FAILURE    -5
#define NUMBER_FAILURE      -6
#define NOT_UNIQUE          -7
#define UNKNOWN_FAILURE     -8


/** further definitions **/
#define COMMAND_SIZE  10
#define STACK_SIZE    50


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
int rpn_eval( double xvec[], int n_x, char *fnc, double *res );


#endif
