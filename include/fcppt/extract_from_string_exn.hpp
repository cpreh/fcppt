//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EXTRACT_FROM_STRING_EXN_HPP_INCLUDED
#define FCPPT_EXTRACT_FROM_STRING_EXN_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/extract_from_string_error.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <locale>
#include <string>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	fcppt::type_traits::is_string<
		Source
	>,
	Dest
>::type
extract_from_string_exn(
	Source const &_source,
	std::locale const &_locale
		= std::locale()
)
{
	typedef fcppt::optional<
		Dest
	> dest_opt;

	dest_opt const ret(
		fcppt::extract_from_string<
			Dest
		>(
			_source,
			_locale
		)
	);

	if(
		!ret
	)
		throw fcppt::extract_from_string_error();

	return *ret;
}

}

#endif
