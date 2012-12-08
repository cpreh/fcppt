//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_DETAIL_IS_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_DETAIL_IS_ITERATOR_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename IterT,
	bool IsPointer
		= std::is_pointer<
			IterT
		>::value
>
struct is_iterator
:
boost::mpl::not_<
	std::is_same<
		std::remove_cv<
			std::remove_pointer<
				std::remove_reference<
					IterT
				>
			>
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
private:
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
		typename T::iterator_category * = nullptr,
		typename T::value_type * = nullptr,
		typename T::difference_type * = nullptr,
		typename T::pointer * = nullptr
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

FCPPT_PP_POP_WARNING

}
}
}

#endif
