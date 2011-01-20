//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
		throw fcppt::bad_lexical_cast(
			typeid(Src),
			typeid(Dest)
		);

	return result;
}

template<
	typename Src
>
Src
lexical_cast(
	Src const &s
)
{
	return s;
}

}

#endif
