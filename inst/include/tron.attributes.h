#ifndef __TRON_ATTRIBUTES_H__
#define __TRON_ATTRIBUTES_H__

#include <memory>
#include <tron.h>

typedef std::function<double(double*)> Fun;
typedef std::function<void(double*, double*)> Grad;
typedef Grad HessianV;

class Cfunction : public function {

  Fun _f;
  Grad _grad;
  HessianV _hv;
  int _nr;
  
public:
  Cfunction(Fun f, Grad grad, HessianV hv, int nr)
    : _f(f), _grad(grad), _hv(hv), _nr(nr)
  { }
  
  virtual ~Cfunction() { }
  
  virtual double fun(double *w) {
    return _f(w);
  }
  
  virtual void grad(double *w, double *g) {
    _grad(w, g);
  }
  
  virtual void Hv(double *s, double *Hs) {
    _hv(s, Hs);
  }
  
  virtual int get_nr_variable(void) {
    return _nr;
  }
  
};

#include <RcppCommon.h>

SEXP init_tronC(SEXP, SEXP, SEXP, int);

void tronC(SEXP, SEXP, double, bool);

#endif //__TRON_ATTRIBUTES_H__