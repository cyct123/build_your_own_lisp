#include "mpc.h"

static mpc_val_t *print_token(mpc_val_t *x) {
  	printf("Token: '%s'\n", (char*)x);
  	return x;
}

int main(int argc, char **argv) {

  	const char *input = "  hello 4352 ,  \n foo.bar   \n\n  test:ing   ";

 	mpc_parser_t* Tokens = mpc_many(
		mpcf_all_free,
		mpc_apply(mpc_strip(mpc_re("\\s*([a-zA-Z_]+|[0-9]+|,|\\.|:)")), print_token));

  mpc_result_t r;
  mpc_parse("input", input, Tokens, &r);

  mpc_delete(Tokens);

  return 0;
}