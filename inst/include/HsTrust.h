#ifndef __HSTRUST_H__
#define __HSTRUST_H__

#include <stdexcept>
#include <R_ext/Rdynload.h>
#include <tron.h>
#include <tron_function.h>

namespace HsTrust {

typedef TRON*(*InitTron)(const ::function*, double, int);
typedef void(*FinalizeTron)(TRON*);
typedef void(*SetPrintString)(TRON*, std::function<void(const char*)>);
typedef void(*Tron)(TRON*, double*);

InitTron init_tron = nullptr;
FinalizeTron finalize_tron = nullptr;
SetPrintString set_print_string = nullptr;
Tron tron = nullptr;

void init() {
  init_tron = (InitTron) R_GetCCallable("HsTrust", "init_tron");
  finalize_tron = (FinalizeTron) R_GetCCallable("HsTrust", "finalize_tron");
  tron = (Tron) R_GetCCallable("HsTrust", "tron");
  set_print_string = (SetPrintString) R_GetCCallable("HsTrust", "set_print_string");
}

}

#endif // __HSTRUST_H__