
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
	12 * (w-beta)^2 * s
}

obj <- new(HsTrust, fun, grad, Hs, n)
print(r1 <- obj$tron(1e-4, TRUE))
stopifnot(length(capture.output(r2 <- obj$tron_with_begin(1e-4, TRUE, r1))) == 0)
stopifnot(r1 == r2)
# print(fun(r))
# print(beta)
# print(fun(beta))
# print(r <- obj$tron_with_begin(1e-4, TRUE, rnorm(length(r))))


obj <- new(HsTrust, fun, grad, Hs, n)
l1 <- capture.output(r1 <- obj$tron_with_begin(1e-4, TRUE, 0.0))

obj <- new(HsTrust, fun, grad, Hs, n)
l2 <- capture.output(r1 <- obj$tron_with_begin_iter(1e-4, length(l1) - 1, TRUE, 0.0))
stopifnot(length(l1) - 1 == length(l2))
stopifnot(head(l1, length(l2)) == l2)
