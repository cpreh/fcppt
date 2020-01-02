//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_optional_error_code.hpp>
#include <fcppt/optional_error_code.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/config/external_begin.hpp>
#include <system_error>
#include <fcppt/config/external_end.hpp>


fcppt::optional_error_code
fcppt::make_optional_error_code(
	std::error_code const &_error
)
{
	return
		fcppt::optional::make_if(
			_error
			!=
			std::error_code{},
			[
				&_error
			]{
				return
					_error;
			}
		);
}
