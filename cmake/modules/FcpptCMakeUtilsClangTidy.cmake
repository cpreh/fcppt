# Set FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER to specify the header-filter option.
# This defaults to .*
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
	#"-clang-analyzer-cplusplus.NewDeleteLeaks" produces warnings with std::make_unique
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
		"-cppcoreguidelines-macro-usage"
		"-clang-analyzer-cplusplus.NewDeleteLeaks"
		"-cert-dcl21-cpp"
		"-fuchsia-overloaded-operator"
		"-fuchsia-trailing-return"
		"-google-readability-namespace-comments"
		"-hicpp-named-parameter"
		"-llvm-header-guard"
		"-llvm-include-order"
		"-llvm-namespace-comment"
		"-llvmlibc-callee-namespace"
		"-llvmlibc-implementation-in-namespace"
		"-llvmlibc-restrict-system-libc-headers"
		"-misc-no-recursion"
		"-modernize-return-braced-init-list"
		"-modernize-use-default-member-init"
		"-modernize-use-trailing-return-type"
		"-readability-function-cognitive-complexity"
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
		set(
			FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER
			".*"
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
