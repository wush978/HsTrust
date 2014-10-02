#'@export HsTrust
#'@importFrom Rcpp evalCpp
#'@importFrom Rcpp loadRcppModules
#'@useDynLib HsTrust
.onLoad <- function(libname, pkgname) {
	loadRcppModules()
}