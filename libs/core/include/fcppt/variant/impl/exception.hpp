//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_IMPL_EXCEPTION_HPP_INCLUDED
#define FCPPT_VARIANT_IMPL_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


inline
fcppt::variant::exception::exception(
	fcppt::string &&_string
)
:
	fcppt::exception{
		FCPPT_TEXT("variant: ")
		+
		std::move(
			_string
		)
	}
{
}

#endif
