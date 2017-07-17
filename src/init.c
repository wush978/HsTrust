#include <stddef.h>
#include <R_ext/Rdynload.h>
#include "registration.h"

void R_init_HsTrust(DllInfo *dll) {
  export_tron();
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
