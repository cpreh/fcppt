//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_IMPL_DUPLICATE_NAMES_HPP_INCLUDED
#define FCPPT_OPTIONS_IMPL_DUPLICATE_NAMES_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


inline
fcppt::options::duplicate_names::duplicate_names(
	fcppt::string &&_string
)
:
	fcppt::options::exception{
		std::move(
			_string
		)
	}
{
}

#endif
