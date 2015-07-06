//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_REBIND_DELETER_HPP_INCLUDED
#define FCPPT_DETAIL_REBIND_DELETER_HPP_INCLUDED


namespace fcppt
{
namespace detail
{

template<
	typename Result,
	typename Deleter
>
struct rebind_deleter;

template<
	typename Result,
	template<
		typename
	> class Deleter,
	typename Inner
>
struct rebind_deleter<
	Result,
	Deleter<
		Inner
	>
>
{
	typedef
	Deleter<
		Result
	>
	type;
};

}
}

#endif
