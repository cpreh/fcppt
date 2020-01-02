//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_FUNCTION_RESULT_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_FUNCTION_RESULT_HPP_INCLUDED


namespace fcppt
{
namespace type_traits
{

/**
\brief The return type of a function type.

\tparam F Must be a function type.
*/
template<
	typename F
>
struct function_result;

template<
	typename Result,
	typename... Args
>
struct function_result<
	Result(
		Args...
	)
>
{
	typedef
	Result
	type;
};

}
}

#endif
