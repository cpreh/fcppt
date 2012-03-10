//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_CONSTRUCT_CAST_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_CONSTRUCT_CAST_HPP_INCLUDED

#include <fcppt/is_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename StrongTypedef,
	typename Arg
>
typename boost::enable_if<
	fcppt::is_strong_typedef<
		StrongTypedef
	>,
	StrongTypedef
>::type const
strong_typedef_construct_cast(
	Arg const &_arg
)
{
	return
		StrongTypedef(
			static_cast<
				typename StrongTypedef::value_type
			>(
				_arg
			)
		);
}

}

#endif
