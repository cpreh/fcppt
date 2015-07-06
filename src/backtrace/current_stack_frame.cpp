//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/backtrace/current_stack_frame.hpp>
#include <fcppt/backtrace/stack_frame.hpp>
#include <fcppt/backtrace/stack_limit.hpp>
#include <fcppt/private_config.hpp>
#if defined(FCPPT_HAVE_BACKTRACE)
#include <fcppt/make_int_range_count.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/container/raw_vector.hpp>
#include <fcppt/c_deleter.hpp>
#include <fcppt/from_std_string.hpp>
#include <execinfo.h>
#endif


fcppt::backtrace::stack_frame
fcppt::backtrace::current_stack_frame(
	backtrace::stack_limit const &
#if defined(FCPPT_HAVE_BACKTRACE)
		max
#endif
)
{
#if defined(FCPPT_HAVE_BACKTRACE)
	typedef
	fcppt::container::raw_vector<
		void *
	>
	symbol_sequence;

	symbol_sequence resulting_symbols(
		fcppt::cast::size<
			symbol_sequence::size_type
		>(
			max.get()
		)
	);

	int const number_of_symbols(
		::backtrace(
			resulting_symbols.data(),
			fcppt::cast::size<
				int
			>(
				fcppt::cast::to_signed(
					max.get()
				)
			)
		)
	);

	fcppt::unique_ptr<
		char *,
		fcppt::c_deleter<
			char *
		>
	> raw_symbols(
		::backtrace_symbols(
			resulting_symbols.data(),
			number_of_symbols
		)
	);

	return
		fcppt::algorithm::map<
			fcppt::backtrace::stack_frame
		>(
			fcppt::make_int_range_count(
				number_of_symbols
			),
			[
				&raw_symbols
			](
				int const _index
			)
			{
				return
					fcppt::from_std_string(
						raw_symbols.get_pointer()[
							_index
						]
					);
			}
		);
#else
	return
		fcppt::backtrace::stack_frame();
#endif
}
