//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_BRIGAND_VALUE_TYPE_HPP_INCLUDED


namespace fcppt
{
namespace brigand
{

/**
\brief value_type meta function

\ingroup fcpptbrigand

Calculates <code>Type::value_type</code>.

\tparam Type Any type that has a nested <code>value_type</code> typedef
*/
template<
	typename Type
>
struct value_type
{
	typedef
	typename
	Type::value_type
	type;
};

}
}

#endif
