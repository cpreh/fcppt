//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/args.hpp>
#include <fcppt/args_char.hpp>
#include <fcppt/args_vector.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/detail/main_wchar.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

#if defined(FCPPT_DETAIL_MAIN_WCHAR)
#include <fcppt/from_std_wstring.hpp>
#else
#include <fcppt/from_std_string.hpp>
#endif


fcppt::args_vector
fcppt::args(
	int const _argc,
	fcppt::args_char const *const *const _argv
)
{
	return
		fcppt::algorithm::map<
			fcppt::args_vector
		>(
			boost::make_iterator_range(
				_argv,
				_argv + _argc
			),
			[](
				fcppt::args_char const *const _arg
			)
			{
				typedef
				std::basic_string<
					fcppt::args_char
				>
				args_string;

				return
#if defined(FCPPT_DETAIL_MAIN_WCHAR)
					fcppt::from_std_wstring(
#else
					fcppt::from_std_string(
#endif
						args_string{
							_arg
						}
					);
			}
		);
}
