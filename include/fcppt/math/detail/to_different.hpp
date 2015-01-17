//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_TO_DIFFERENT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_TO_DIFFERENT_HPP_INCLUDED


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Source
>
inline
Dest
to_different(
	Source const &_source
)
{
	static_assert(
		Dest::dim_wrapper::value
		==
		Source::dim_wrapper::value,
		"dim_wrappers must match"
	);

	return
		Dest(
			_source.begin(),
			_source.end()
		);
}

}
}
}

#endif
