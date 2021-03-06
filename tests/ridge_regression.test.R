library(HsTrust)

m <- model.matrix(~ ., iris)
w <- rep(0, ncol(m))
y <- rnorm(150)

fun <- function(w) {
	sum((m %*% w - y)^2)
}

grad <- function(w) {
	c(2 * t(m) %*% m %*% w) - c(2 * t(y) %*% m)
}

Hs <- function(w, s) {
	c(2 * t(m) %*% m %*% s)
}

fun(w)
grad(w)
Hs(w, w)

obj <- new(HsTrust, fun, grad, Hs, length(w))
r <- obj$tron(1e-7, TRUE)
r
g <- lm(y ~ m - 1)
stopifnot(isTRUE(all.equal(as.vector(coef(g)), r, tolerance = 1e-6)))
