#include "mpc.h"

int main(int argc, char** argv) {
	/* Build a parser 'Adjective' to recognize descriptions */
	mpc_parser_t* Adjective = mpc_or(4, 
	mpc_sym("wow"), mpc_sym("many"),
	mpc_sym("so"),  mpc_sym("such"));

	/* Build a parser 'Noun' to recognize things */
	mpc_parser_t* Noun = mpc_or(5,
    mpc_sym("lisp"), mpc_sym("language"),
    mpc_sym("book"), mpc_sym("build"), 
    mpc_sym("c"));
	
	mpc_parser_t* Phrase = mpc_and(2, mpcf_strfold, 
	Adjective, Noun, free);
	
	mpc_parser_t* Doge = mpc_many(mpcf_strfold, Phrase);
	
	/* Do some parsing here... */
	mpc_result_t r;

	const char* input = "many build wow c";
	if (mpc_parse("input", input, Doge, &r)) {
		mpc_ast_print(r.output);
		mpc_ast_delete(r.output);
		} else {
		mpc_err_print(r.error);
		mpc_err_delete(r.error);
		}
	
	mpc_delete(Doge);
	
	return 0;

}