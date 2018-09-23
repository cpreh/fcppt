//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CATCH_DETAIL_OUTPUT_HPP_INCLUDED
#define FCPPT_CATCH_DETAIL_OUTPUT_HPP_INCLUDED

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace catch_
{
namespace detail
{

template<
	typename Type
>
std::string
output(
	Type const &_value
)
{
	return
		fcppt::optional::maybe(
			fcppt::to_std_string(
				fcppt::output_to_fcppt_string(
					_value
				)
			),
			[]{
				return
					std::string{
						"Output failure"
					};
			},
			[](
				std::string &&_result
			)
			{
				return
					std::move(
						_result
					);
			}
		);
}

}
}
}

#endif
