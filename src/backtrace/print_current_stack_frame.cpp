//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/backtrace/print_current_stack_frame.hpp>
#include <fcppt/private_config.hpp>

#if defined(FCPPT_HAVE_BACKTRACE)
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <execinfo.h>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>
#endif

#if defined(FCPPT_HAVE_BACKTRACE)
namespace
{

std::size_t const max_stacktrace_size = 128;

}
#endif

void
fcppt::backtrace::print_current_stack_frame()
{
#if defined(FCPPT_HAVE_BACKTRACE)
	typedef
	std::array
	<
		void *,
		max_stacktrace_size
	>
	symbol_sequence;

	symbol_sequence resulting_symbols;

	int const number_of_symbols(
		::backtrace(
			resulting_symbols.data(),
			fcppt::cast::size<
				int
			>(
				fcppt::cast::to_signed(
					max_stacktrace_size
				)
			)
		)
	);

	::backtrace_symbols_fd(
		resulting_symbols.data(),
		number_of_symbols,
		STDERR_FILENO
	);
#endif
}
