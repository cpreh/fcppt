//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INNER_HPP_INCLUDED
#define FCPPT_MPL_INNER_HPP_INCLUDED


namespace fcppt
{
namespace mpl
{

/**
\brief Extracts the inner type of a type

\ingroup fcpptmpl

Extracts the type contained within \a Type. The result is the same type as
<code>typename Type::type</code>.

\snippet mpl/various.cpp mpl_inner

\tparam Type Can be any type containing a <code>type</code> typedef
*/
template<
	typename Type
>
struct inner
{
	typedef
	typename
	Type::type
	type;
};

}
}

#endif
