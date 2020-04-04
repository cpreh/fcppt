# Set FCPPT_UTILS_CLANG_TIDY_HEADER_FILTER to specify the header-filter option.
# This defaults to .*

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
	# "-fuchsia-trailing-return" complains about code like X<decltype(_param)>
	set(
		FCPPT_UTILS_CLANG_TIDY_CHECKS
		"*"
		"-bugprone-macro-parentheses"
		"-cppcoreguidelines-macro-usage"
		"-cert-dcl21-cpp"
		"-fuchsia-overloaded-operator"
		"-fuchsia-trailing-return"
		"-google-readability-namespace-comments"
		"-llvm-header-guard"
		"-llvm-include-order"
		"-llvm-namespace-comment"
		"-modernize-use-default-member-init"
		"-modernize-use-trailing-return-type"
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
	)
endif()
