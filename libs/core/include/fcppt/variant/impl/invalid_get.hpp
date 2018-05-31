//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_IMPL_INVALID_GET_HPP_INCLUDED
#define FCPPT_VARIANT_IMPL_INVALID_GET_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/variant/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


inline
fcppt::variant::invalid_get::invalid_get(
	fcppt::string &&_error
)
:
	fcppt::variant::exception{
		std::move(
			_error
		)
	}
{
}

#endif
