#'@export HsTrust
#'@useDynLib HsTrust
.onLoad <- function(libname, pkgname) {
	loadRcppModules()
}