#include <Rcpp.h>
#include <tron.h>
#include "registration.h"

using namespace Rcpp;

RcppExport SEXP _rcpp_module_boot_HsTrust();
extern "C" TRON* init_tron(const ::function *fun_obj, double eps, int max_iter);
extern "C" void finalize_tron(TRON* tron);
extern "C" void tron(TRON* obj, double *w);
extern "C" void set_print_string(TRON* tron, std::function<void(const char*)> printer);

const R_CallMethodDef CallEntries[] = {
  // {"init_tron", (DL_FUNC) &init_tron, 3},
  // {"finalize_tron", (DL_FUNC) &finalize_tron, 1},
  // {"tron", (DL_FUNC) &tron, 2},
  // {"set_print_string", (DL_FUNC) &set_print_string, 2},
  {"_rcpp_module_boot_HsTrust", (DL_FUNC) &_rcpp_module_boot_HsTrust, 0},
  {NULL, NULL, 0}
};

void export_tron() {
  R_RegisterCCallable("HsTrust", "init_tron", (DL_FUNC) &init_tron);
  R_RegisterCCallable("HsTrust", "finalize_tron", (DL_FUNC) &finalize_tron);
  R_RegisterCCallable("HsTrust", "tron", (DL_FUNC) &tron);
  R_RegisterCCallable("HsTrust", "set_print_string", (DL_FUNC) &set_print_string);
}
