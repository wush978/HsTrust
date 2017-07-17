//[[Rcpp::depends(HsTrust, RcppParallel)]]
//[[Rcpp::plugins(cpp14)]]
#include <cmath>
#include <HsTrust.h>
#include <Rcpp.h>
#include <RcppParallel.h>

static int nr = 10;

class TestLossFunction : public ::function {

  const int nr;

  double* last_w;

public:
  
  TestLossFunction(int _nr) : nr(_nr) { }
  
  virtual ~TestLossFunction() { }
  
  virtual double fun(double *w) {
    double result = 0;
    for(int i = 0;i < nr;i++) {
      result += std::exp(w[i]) - w[i];
    }
  }
  
  virtual void grad(double *w, double *g) {
    last_w = w;
    for(int i = 0;i < nr;i++) {
      g[i] = std::exp(w[i]) - 1;
    }
  }
  
  virtual void Hv(double *s, double *Hs) {
    for(int i = 0;i < nr;i++) {
      Hs[i] = s[i] * std::exp(last_w[i]);
    }
  }
  
  virtual int get_nr_variable() {
    return nr; 
  }
  
  
};


#include <Rcpp.h>
using namespace Rcpp;

void test_tron_attributes() {
  TestLossFunction loss(10);
  std::vector<double> w0(10, 0.0);
  for(int i = 0;i < w0.size();i++) {
    w0[i] = i - 5;
  }
  std::shared_ptr<TRON> tron(HsTrust::init_tron(&loss, 1e-4, 1000), [](TRON* tron) {
    HsTrust::finalize_tron(tron);
  });
  HsTrust::set_print_string(tron.get(), [](const char* s) {
    std::cout << s << std::endl;
  });
  HsTrust::tron(tron.get(), &w0[0]);
}

class Task : public RcppParallel::Worker {
public :
  void operator()(std::size_t begin, std::size_t end) {
    for(std::size_t i = begin; i < end; i++) {
      test_tron_attributes();
    }
  }
};

//[[Rcpp::export]]
void test_tron_attributes_parallel() {
  HsTrust::init();
  Task task;
  RcppParallel::parallelFor(0, 8, task);
}

/***R
library(HsTrust)
test_tron_attributes_parallel()
*/