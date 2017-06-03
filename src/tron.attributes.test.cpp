#include "HsTrust.h"

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
void test_tron_attributes() {
  std::shared_ptr<Cfunction> cfun(init_tronC(&f, &grad, &Hv, 10));
  std::vector<double> w(10, 0.0);
  tronC(cfun.get(), &w[0], 0.001, true);
}