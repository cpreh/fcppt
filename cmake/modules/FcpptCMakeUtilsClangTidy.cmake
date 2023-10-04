# Set FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER to specify the header-filter option.
# This defaults to .* if FCPPT_UTILS_CLANG_TIDY_WHITELIST is not set.
# Set FCPPT_UTILS_CLANG_TIDY_WHITELIST to specify a list of libraries to include in clang-tidy's header filter.
# If this list is a_1, ..., a_m, where m >= 0, then FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER is set to a_1|...|a_m/.*.
# Use FCPPT_UTILS_CLANG_TIDY_EXTRA_ARGS to specify additional arguments.

set(
	FCPPT_UTILS_CLANG_TIDY
	""
	CACHE
	FILEPATH
	"Path to clang-tidy. If unset, clang-tidy will not be run."
)

if(
	NOT
	"${FCPPT_UTILS_CLANG_TIDY}"
	STREQUAL
	""
)
	# "-bugprone-exception-escape" triggers on every move constructor/assignment operator for classes containing a std::string.
	#                              Might be a problem with libc++. TODO: Investigate this again with clang-16.
	# "-clang-analyzer-cplusplus.NewDeleteLeaks" produces warnings with std::make_unique
	# "-fuchsia-trailing-return" complains about code like X<decltype(_param)>
	# "-readability-function-cognitive-complexity" triggers for almost every Catch2 test case
	# "-modernize-return-braced-init-list" also triggers on ()-initialization, breaking code

	set(
		FCPPT_UTILS_CLANG_TIDY_CHECKS
		"*"
		"-altera-id-dependent-backward-branch"
		"-altera-struct-pack-align"
		"-altera-unroll-loops"
		"-bugprone-macro-parentheses"
		"-bugprone-exception-escape"
		"-cppcoreguidelines-macro-usage"
		"-clang-analyzer-cplusplus.NewDeleteLeaks"
		"-cert-dcl21-cpp"
		"-fuchsia-default-arguments-calls"
		"-fuchsia-overloaded-operator"
		"-fuchsia-trailing-return"
		"-google-readability-namespace-comments"
		"-hicpp-named-parameter"
		"-llvm-header-guard"
		"-llvm-include-order"
		"-llvm-namespace-comment"
		"-llvmlibc-callee-namespace"
		"-llvmlibc-implementation-in-namespace"
		"-llvmlibc-inline-function-decl"
		"-llvmlibc-restrict-system-libc-headers"
		"-misc-no-recursion"
		"-modernize-return-braced-init-list"
		"-modernize-use-trailing-return-type"
		"-readability-function-cognitive-complexity"
		"-readability-identifier-length"
		"-readability-inconsistent-declaration-parameter-name"
		"-readability-named-parameter"
		"-readability-redundant-member-init"
	)

	list(
		APPEND
		FCPPT_UTILS_CLANG_TIDY_CHECKS
		${FCPPT_UTILS_CLANG_TIDY_ADDITIONAL_CHECKS}
	)

	string(
		JOIN
		","
		FCPPT_UTILS_CLANG_TIDY_CHECKS_ARG
		${FCPPT_UTILS_CLANG_TIDY_CHECKS}
	)

	if(
		"${FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER}"
		STREQUAL
		""
	)
		if(
			"${FCPPT_UTILS_CLANG_TIDY_WHITELIST}"
			STREQUAL
			""
		)
			set(
				FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER
				".*"
			)
		else()
			string(
				JOIN
				"|"
				FCPPT_UTILS_CLANG_TIDY_WHITELIST_ARGS
				${FCPPT_UTILS_CLANG_TIDY_WHITELIST}
			)

			set(
				FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER
				"${FCPPT_UTILS_CLANG_TIDY_WHITELIST_ARGS}/.*"
			)
		endif()

		message(
			STATUS
			"clang-tidy header filter set to ${FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER}"
		)
	endif()

	set(
		CMAKE_CXX_CLANG_TIDY
		${FCPPT_UTILS_CLANG_TIDY}
		"-header-filter=${FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER}"
		"-checks=${FCPPT_UTILS_CLANG_TIDY_CHECKS_ARG}"
		${FCPPT_UTILS_CLANG_TIDY_EXTRA_ARGS}
	)
endif()
