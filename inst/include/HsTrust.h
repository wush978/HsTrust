#ifndef _HsTrust_H_
#define _HsTrust_H_

#include "HsTrust_RcppExports.h"

#include <stddef.h>
#include <R_ext/Rdynload.h>
#include "HsTrust_RcppExports.h"

static Cfunction* init_tronC(Fun fun, Grad grad, HessianV hv, int nr) {
  typedef Cfunction* (*InitTronC)(Fun fun, Grad grad, HessianV hv, int nr);
  static InitTronC f = NULL;
  if (!f) {
    f = reinterpret_cast<InitTronC>(HsTrust::get_init_tronC());
  }
  return f(fun, grad, hv, nr);
}

static void tronC(Cfunction* pCfun, double* w, double tol, void(*printer)(const char*)) {
  typedef void(*TronC)(Cfunction*, double*, double, void(*)(const char*));
  static TronC f = NULL;
  if (!f) {
    f = reinterpret_cast<TronC>(HsTrust::get_tronC());
  }
  return f(pCfun, w, tol, printer);
}


#endif // _HsTrust_H_