#include "tron.attributes.h"

static int nr = 10;

static double f(double *w) {
  double result = 0;
  for(auto i = 0;i < nr;i++) {
    result += (w[i] - 1) * (w[i] - 1);
  }
  return result;
}

static void grad(double *w, double *g) {
  for(auto i = 0;i < nr;i++) {
    g[i] = 2 * w[i] - 2;
  }
}

static void Hv(double *s, double *Hs) {
  for(auto i = 0;i < nr;i++) {
    Hs[i] = 2 * s[i];
  }
}

#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
SEXP test_tron_attributes() {
  XPtr<Fun> pf(new Fun(static_cast<Fun>(&f)));
  XPtr<Grad> pgrad(new Grad(static_cast<Grad>(&grad)));
  XPtr<HessianV> phv(new HessianV(static_cast<HessianV>(&Hv)));
  XPtr<Cfunction> RCfun(init_tronC(pf, pgrad, phv, nr));
  NumericVector w(nr);
  tronC(RCfun, w, 0.0001, true);
  return w;
}