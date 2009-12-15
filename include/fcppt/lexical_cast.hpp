/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_LEXICAL_CAST_HPP_INCLUDED
#define FCPPT_LEXICAL_CAST_HPP_INCLUDED

#include <fcppt/bad_lexical_cast.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/mpl/value_type.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <typeinfo>
#include <sstream>

namespace fcppt
{

template<
	typename Dest,
	typename Src
>
typename boost::disable_if<
	boost::is_same<
		Src,
		Dest
	>,
	Dest
>::type
lexical_cast(
	Src const &s
)
{
	BOOST_STATIC_ASSERT((
		boost::mpl::or_<
			fcppt::type_traits::is_string<
				Dest
			>,
			fcppt::type_traits::is_string<
				Src
			>
		>::value
	));

	std::basic_stringstream<
		typename boost::mpl::eval_if<
			fcppt::type_traits::is_string<
				Dest
			>,
			fcppt::mpl::value_type<
				Dest
			>,
			fcppt::mpl::value_type<
				Src
			>
		>::type
	> ss;

	Dest result;

	if (!(ss << s && ss >> result))
		throw bad_lexical_cast(
			typeid(Src),
			typeid(Dest)
		);

	return result;
}

template<
	typename Src
>
Src
sge::lexical_cast(
	Src const &s
)
{
	return s;
}

}

#endif
