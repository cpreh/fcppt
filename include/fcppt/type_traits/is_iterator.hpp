//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_ITERATOR_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/not.hpp>

namespace fcppt
{
namespace type_traits
{

template<
	typename IterT,
	bool IsPointer
		= boost::is_pointer<
			IterT
		>::value
>
struct is_iterator
:
boost::mpl::not_<
	boost::is_same<
		boost::remove_pointer<
			IterT
		>,
		void
	>
>
{};

template<
	typename IterT
>
struct is_iterator<
	IterT,
	false
>
{
//private: TODO: get rid of this warning
	typedef char true_t;

	struct false_t
	{
		true_t f[2];
	};

	static IterT *
	make();

	template<
		typename T
	>
	static true_t
	check(
		T *,
		typename T::iterator_category * = 0
	);

	static false_t
	check(...);
public:
	static bool const value =
		sizeof(
			check(
				make()
			)
		)
		== sizeof(true_t);
};

}
}

#endif
