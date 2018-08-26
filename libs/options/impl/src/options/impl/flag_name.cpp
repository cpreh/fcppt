//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/impl/flag_name.hpp>


fcppt::string
fcppt::options::impl::flag_name(
	fcppt::string const &_name,
	fcppt::options::detail::flag_is_short const _is_short
)
{
	return
		(
			_is_short.get()
			?
				FCPPT_TEXT("-")
			:
				FCPPT_TEXT("--")
		)
		+
		_name;
}
