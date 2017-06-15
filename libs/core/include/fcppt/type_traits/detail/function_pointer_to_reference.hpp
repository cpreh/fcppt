//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_DETAIL_FUNCTION_POINTER_TO_REFERENCE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_DETAIL_FUNCTION_POINTER_TO_REFERENCE_HPP_INCLUDED


namespace fcppt
{
namespace type_traits
{
namespace detail
{

template<
	typename Type
>
struct function_pointer_to_reference;

template<
	typename Ret,
	typename ...Args
>
struct function_pointer_to_reference<
	Ret (*)(
		Args...
	)
>
{
	typedef
	Ret (&type)(
		Args...
	);
};

}
}
}

#endif
