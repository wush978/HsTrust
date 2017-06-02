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
SEXP init_tronC(SEXP Rfun, SEXP Rgrad, SEXP Rhv, int nr) {
  XPtr<Fun> fun(Rfun);
  XPtr<Grad> grad(Rgrad);
  XPtr<HessianV> hv(Rhv);
  return XPtr<Cfunction>(_init_tronC(*fun, *grad, *hv, nr));
}

//[[Rcpp::export]]
void tronC(SEXP RCfun, SEXP w, double tol, bool verbose) {
  XPtr<Cfunction> Cfun(RCfun);
  double* pw = &NumericVector(w)[0];
  _tronC(Cfun.get(), pw, tol, verbose);
}
