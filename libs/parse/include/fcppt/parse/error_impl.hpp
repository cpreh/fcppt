//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_ERROR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_IMPL_HPP_INCLUDED

#include <fcppt/parse/error_decl.hpp>
#include <fcppt/parse/fatal_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::error<
	Ch
>::error(
	value_type &&_value
)
:
	value_{
		std::move(
			_value
		)
	},
	is_fatal_{
		false
	}
{
}

template<
	typename Ch
>
fcppt::parse::error<
	Ch
>::error(
	value_type &&_value,
	fcppt::parse::fatal_tag const &
)
:
	value_{
		std::move(
			_value
		)
	},
	is_fatal_{
		true
	}
{
}

template<
	typename Ch
>
bool
fcppt::parse::error<
	Ch
>::is_fatal() const
{
	return
		this->is_fatal_;
}

template<
	typename Ch
>
typename
fcppt::parse::error<
	Ch
>::value_type &
fcppt::parse::error<
	Ch
>::get()
{
	return
		this->value_;
}

template<
	typename Ch
>
typename
fcppt::parse::error<
	Ch
>::value_type const &
fcppt::parse::error<
	Ch
>::get() const
{
	return
		this->value_;
}

#endif
