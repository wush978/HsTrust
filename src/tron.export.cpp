#include <memory>
#include <tron.h>

extern "C" TRON* init_tron(const function *fun_obj, double eps, int max_iter) {
  return new TRON(fun_obj, eps, max_iter);
}

extern "C" void finalize_tron(TRON* tron) {
  delete tron;
}

extern "C" void set_print_string(TRON* tron, std::function<void(const char*)> printer) {
  tron->set_print_string(printer);
}

extern "C" void tron(TRON* obj, double *w) {
  obj->tron(w);
}
