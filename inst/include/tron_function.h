#ifndef __TRON_FUNCTION_H__
#define __TRON_FUNCTION_H__

#include <functional>

class function
{
public:
	virtual double fun(double *w) = 0 ;
	virtual void grad(double *w, double *g) = 0 ;
	virtual void Hv(double *s, double *Hs) = 0 ;

	virtual int get_nr_variable(void) = 0 ;
	virtual ~function(void){}
};

#endif // __TRON_FUNCTION_H__
