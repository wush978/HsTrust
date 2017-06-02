// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/HsTrust.h"
#include "../inst/include/HsTrust_types.hpp"
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

// init_tronC
SEXP init_tronC(SEXP Rfun, SEXP Rgrad, SEXP Rhv, int nr);
static SEXP HsTrust_init_tronC_try(SEXP RfunSEXP, SEXP RgradSEXP, SEXP RhvSEXP, SEXP nrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< SEXP >::type Rfun(RfunSEXP);
    Rcpp::traits::input_parameter< SEXP >::type Rgrad(RgradSEXP);
    Rcpp::traits::input_parameter< SEXP >::type Rhv(RhvSEXP);
    Rcpp::traits::input_parameter< int >::type nr(nrSEXP);
    rcpp_result_gen = Rcpp::wrap(init_tronC(Rfun, Rgrad, Rhv, nr));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP HsTrust_init_tronC(SEXP RfunSEXP, SEXP RgradSEXP, SEXP RhvSEXP, SEXP nrSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(HsTrust_init_tronC_try(RfunSEXP, RgradSEXP, RhvSEXP, nrSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// tronC
void tronC(SEXP RCfun, SEXP w, double tol, bool verbose);
static SEXP HsTrust_tronC_try(SEXP RCfunSEXP, SEXP wSEXP, SEXP tolSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::traits::input_parameter< SEXP >::type RCfun(RCfunSEXP);
    Rcpp::traits::input_parameter< SEXP >::type w(wSEXP);
    Rcpp::traits::input_parameter< double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    tronC(RCfun, w, tol, verbose);
    return R_NilValue;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP HsTrust_tronC(SEXP RCfunSEXP, SEXP wSEXP, SEXP tolSEXP, SEXP verboseSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(HsTrust_tronC_try(RCfunSEXP, wSEXP, tolSEXP, verboseSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// test_tron_attributes
SEXP test_tron_attributes();
RcppExport SEXP HsTrust_test_tron_attributes() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(test_tron_attributes());
    return rcpp_result_gen;
END_RCPP
}

// validate (ensure exported C++ functions exist before calling them)
static int HsTrust_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("SEXP(*init_tronC)(SEXP,SEXP,SEXP,int)");
        signatures.insert("void(*tronC)(SEXP,SEXP,double,bool)");
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP HsTrust_RcppExport_registerCCallable() { 
    R_RegisterCCallable("HsTrust", "HsTrust_init_tronC", (DL_FUNC)HsTrust_init_tronC_try);
    R_RegisterCCallable("HsTrust", "HsTrust_tronC", (DL_FUNC)HsTrust_tronC_try);
    R_RegisterCCallable("HsTrust", "HsTrust_RcppExport_validate", (DL_FUNC)HsTrust_RcppExport_validate);
    return R_NilValue;
}

RcppExport SEXP _rcpp_module_boot_HsTrust();

static const R_CallMethodDef CallEntries[] = {
    {"HsTrust_init_tronC", (DL_FUNC) &HsTrust_init_tronC, 4},
    {"HsTrust_tronC", (DL_FUNC) &HsTrust_tronC, 4},
    {"HsTrust_test_tron_attributes", (DL_FUNC) &HsTrust_test_tron_attributes, 0},
    {"_rcpp_module_boot_HsTrust", (DL_FUNC) &_rcpp_module_boot_HsTrust, 0},
    {"HsTrust_RcppExport_registerCCallable", (DL_FUNC) &HsTrust_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_HsTrust(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
