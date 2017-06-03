//[[Rcpp::interfaces(cpp)]]
#include <R.h>
#include <memory>
#include "tron.attributes.h"


static Cfunction* _init_tronC(Fun fun, Grad grad, HessianV hv, int nr) {
  return new Cfunction(fun, grad, hv, nr);
}

static void print_string_r(const char *s) {
  ::Rprintf("%s", s);
}

static void _tronC(Cfunction* pCfun, double* w, double tol, bool verbose) {
  TRON tron_obj(pCfun, tol);
  if (verbose) tron_obj.set_print_string(&print_string_r);
  tron_obj.tron(w);
}

#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
SEXP get_init_tronC() {
  return reinterpret_cast<SEXP>(&_init_tronC);
}

//[[Rcpp::export]]
SEXP get_tronC() {
  return reinterpret_cast<SEXP>(&_tronC);
}