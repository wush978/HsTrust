#ifndef __TRON_H__
#define __TRON_H__

#include <tron_function.h>

class TRON {
public:
  TRON(const function *fun_obj, double eps = 0.1, int max_iter = 1000);
  ~TRON();
  
  void tron(double *w);
  void set_print_string(std::function<void(const char*)>);
  
private:
  int trcg(double delta, double *g, double *s, double *r);
  double norm_inf(int n, double *x);
  
  double eps;
  int max_iter;
  function *fun_obj;
  void info(const char *fmt,...);
  std::function<void(const char*)> tron_print_string;
};

#endif // __TRON_H__