#!/bin/bash

if [[ $1 == 'run' ]]; then
	shift
	prettify_includes.py --reserved-prefix fcppt "$@" 2>>/tmp/prettify_errors
else
#find src include/ \( \( -name '*.hpp' -o -name '*.cpp' \) -a ! -path '../src/model/obj/basic_tokens_decl.hpp' -a ! -path '../src/model/obj/basic_grammar_decl.hpp' -a ! -path '../src/model/obj/token.hpp' \) | xargs $0 run
	find libs examples test \( \( -name '*.hpp' -o -name '*.cpp' \) \) | xargs $0 run
fi
