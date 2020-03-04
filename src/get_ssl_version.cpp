#include <Rcpp.h>
#include <openssl/opensslv.h>

using namespace Rcpp;

//' Returns the OpenSSL version number
//'
//' @return List with 1 element - the OpenSSL version number.
//'
//' @details The function returns the value of the OPENSSL_VERSION_NUMBER macro.
//' For more information, see:
//' \url{https://www.openssl.org/docs/manmaster/man3/OPENSSL_VERSION_NUMBER.html}
//'
//' OPENSSL_VERSION_NUMBER is deprecated, but kept for backward compatibility.
//' For a definition of OPENSSL_VERSION_NUMBER following its deprecation, see
//' \url{https://github.com/openssl/openssl/blob/26b7cc0d20d180df28831931b5e75c14c015c5b9/include/openssl/opensslv.h.in#L92}.
//' An alternative way to get the OpenSSL version is through
//' \href{https://github.com/jeroen/openssl/blob/62d7d8c5efb86396b2f267dd6e90d84e47d6c3b0/R/info.R#L7}{openssl::openssl_config()}.
//' It returns the OPENSSL_VERSION_TEXT macro.
//' However, the latter is harder to use for comparison.
//' The version components
//' \code{OPENSSL_VERSION_MAJOR, OPENSSL_VERSION_MINOR, OPENSSL_VERSION_PATCH}
//' appear in:
//' \url{https://github.com/openssl/openssl/tree/3a63dbef15b62b121c5df8762f8cb915fb06b27a}
//' committed on Dec 6, 2018 (i.e. after 1.1.1 which was released on Sep 11, 2018).
//'
//' @useDynLib webshot
//'
//' @importFrom Rcpp sourceCpp
//'
//'
// [[Rcpp::export]]
List get_ssl_version() {
  List res;
  res["OPENSSL_VERSION_NUMBER"] = IntegerVector::create(OPENSSL_VERSION_NUMBER);
  return res;
}
