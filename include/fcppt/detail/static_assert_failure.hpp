//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_STATIC_ASSERT_FAILURE_HPP_INCLUDED
#define FCPPT_DETAIL_STATIC_ASSERT_FAILURE_HPP_INCLUDED


namespace fcppt
{
namespace detail
{

template<
	bool
>
struct static_assert_failure;

template<>
struct static_assert_failure<
	true
>
{
};

}
}

#endif
