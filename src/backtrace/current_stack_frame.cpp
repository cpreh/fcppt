//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/backtrace/current_stack_frame.hpp>
#include <fcppt/backtrace/stack_frame.hpp>
#include <fcppt/backtrace/stack_limit.hpp>
#include <fcppt/config.hpp>
#if defined(FCPPT_HAVE_BACKTRACE)
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/c_deleter.hpp>
#include <vector>
#include <execinfo.h>
#endif

fcppt::backtrace::stack_frame const
fcppt::backtrace::current_stack_frame(
	backtrace::stack_limit const &
#if defined(FCPPT_HAVE_BACKTRACE)
	max
#endif
)
{
#if defined(FCPPT_HAVE_BACKTRACE)
	typedef
	std::vector<void*>
	symbol_sequence;

	symbol_sequence resulting_symbols(
		static_cast<symbol_sequence::size_type>(
			max.get()));

	int const number_of_symbols = 
		::backtrace(
			&resulting_symbols[0],
			static_cast<int>(
				max.get()));

	backtrace::stack_frame result;
	result.reserve(
		static_cast<backtrace::stack_frame::size_type>(
			number_of_symbols));

	fcppt::scoped_ptr<char*,fcppt::c_deleter> raw_symbols(
		backtrace_symbols(
			&resulting_symbols[0],
			number_of_symbols));

	for(int i = 0; i < number_of_symbols; ++i)
		result.push_back(
			fcppt::from_std_string(
				raw_symbols.get()[i]));

	return result;
#else
	return 
		fcppt::backtrace::stack_frame();
#endif
}
