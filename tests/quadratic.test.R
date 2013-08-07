
library(HsTrust)

set.seed(1)
beta <- rnorm(1)
n <- 1
fun <- function(w) {
	sum((w-beta)^4)
}

grad <- function(w) {
	4 * (w-beta)^3
}

Hs <- function(w, s) {
	12 * (w-beta)^2 %*% s
}

obj <- new(HsTrust, fun, grad, Hs, n)
print(obj$tron(1e-7, TRUE))
print(beta)