#include "Rcpp.h"
#include "tron.h"

#define HSTRUST_DEBUG

namespace HsTrust {

void print_string_r(const char *s) {
	::Rprintf("%s", s);
}


class Rfunction : public ::function {
	
	Rcpp::Function _fun, _grad, _Hv;
	Rcpp::NumericVector _w, _s;
	
public:

	Rfunction(SEXP fun, SEXP grad, SEXP Hv, int n) 
	: _fun(fun), _grad(grad), _Hv(Hv), _w(n), _s(n) { } 
	
	double fun(double *w) {
		cpw(w);
		return Rcpp::as<double>(_fun(Rcpp::wrap(_w)));
	}
	void grad(double *w, double *g) {
		cpw(w);
		Rcpp::NumericVector retval(_grad(Rcpp::wrap(_w)));
		memcpy(g, &retval[0], sizeof(double) * retval.size());
		#ifdef HSTRUST_DEBUG
		Rprintf("w");
		for(int i = 0;i < get_nr_variable();i++) {
			Rprintf("%4.4f ", w[i]);
		}
		Rprintf("\n");
		Rprintf("g:");
		for(int i = 0;i < get_nr_variable();i++) {
			Rprintf("%4.4f ", g[i]);
		}
		Rprintf("\n");
		#endif //HSTRUST_DEBUG
	}
	
	void Hv(double *s, double *Hs) {
		cps(s);
		Rcpp::NumericVector retval(_Hv(Rcpp::wrap(_w), Rcpp::wrap(_s)));
		memcpy(Hs, &retval[0], sizeof(double) * retval.size());
		#ifdef HSTRUST_DEBUG
		Rprintf("w:");
		for(int i = 0;i < get_nr_variable();i++) {
			Rprintf("%4.4f ", _w[i]);
		}
		Rprintf("\n");
		Rprintf("s:");
		for(int i = 0;i < get_nr_variable();i++) {
			Rprintf("%4.4f ", s[i]);
		}
		Rprintf("\n");
		Rprintf("Hs:");
		for(int i = 0;i < get_nr_variable();i++) {
			Rprintf("%4.4f ", Hs[i]);
		}
		Rprintf("\n");
		#endif //HSTRUST_DEBUG
	}

	int get_nr_variable(void) {
		return _w.size();
	}
	
	void init(Rcpp::NumericVector w) {
		if (w.size() != get_nr_variable()) throw std::invalid_argument("Inconsistent length of w");
		memcpy(&_w[0], &w[0], sizeof(double) * _w.size());
	}
	
private:
	inline void cpw(double* w) {
		memcpy(&_w[0], w, sizeof(double) * _w.size());		
	}

	inline void cps(double* s) {
		memcpy(&_s[0], s, sizeof(double) * _s.size());		
	}

friend SEXP tron(Rfunction*, double, bool);

};

SEXP tron(Rfunction* fun, double tol, bool verbose) {
	BEGIN_RCPP
	::TRON tron_obj(fun, tol);
	if (verbose) tron_obj.set_print_string(&print_string_r);
	Rcpp::NumericVector Rw(fun->get_nr_variable());
	Rw.fill(0);
	tron_obj.tron(&Rw[0]);
	return Rw;
	END_RCPP
}


}

using namespace Rcpp;

RCPP_MODULE(HsTrust) {
	
	class_<HsTrust::Rfunction>("HsTrust")
	.constructor<SEXP, SEXP, SEXP, int>()
	.property("n", &HsTrust::Rfunction::get_nr_variable, "Number of parameters")
	.method("tron", &HsTrust::tron)
	;
	
}