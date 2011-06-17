//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/backtrace/print_current_stack_frame.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/config.hpp>
#include <cstddef>

#if defined(FCPPT_HAVE_BACKTRACE)
#include <execinfo.h>
#include <unistd.h>
#endif

namespace
{
std::size_t const max_stacktrace_size = 128;
}

void
fcppt::backtrace::print_current_stack_frame()
{
#if defined(FCPPT_HAVE_BACKTRACE)
	typedef
	fcppt::container::array<void*,max_stacktrace_size>
	symbol_sequence;

	symbol_sequence resulting_symbols;

	int const number_of_symbols = 
		::backtrace(
			resulting_symbols.data(),
			static_cast<int>(
				max_stacktrace_size));

	::backtrace_symbols_fd(
		resulting_symbols.data(),
		number_of_symbols,
		STDERR_FILENO);
#else
#endif
}
